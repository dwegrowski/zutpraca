#include "GestureModel.h"
#include <qfile.h>
#include <qtextstream.h>
#include <exception>

GestureModel::GestureModel()
{
}

GestureModel::~GestureModel()
{
}

void GestureModel::add(Gesture gest)
{
    list.append(gest);
}
void GestureModel::saveToFile(Gesture gest)
{
    QFile f(filename);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&f);
    out << gest.gestures.count();
    for (auto &g : gest.gestures)
    {
        out << (int)g;
    }
    out << static_cast<int>(gest.action)<< "\n";
    f.close();
}
QList<Gesture> GestureModel::readFromFile()
{
    QFile f(filename);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
        throw std::bad_exception();
    char count_char;
    QTextStream in(&f);
    QList<Gesture> listOfReadedGestures;
    while(!in.atEnd())
    {
        in >> count_char;
        int count_int = count_char - '0';
        QVector<HandMovement> handMovements;
        for (int i = 0; i < count_int; i++)
        {
            char readed_char;
            in >> readed_char;
            int readed_int = readed_char - '0';
            handMovements.append(static_cast<HandMovement>(readed_int));
        }
        int action;
        in >> action;
        Gesture g;
        g.gestures = handMovements;
        g.action = static_cast<Action>(action);
        listOfReadedGestures.append(g);
        in.skipWhiteSpace();
    } 
    f.close();
    return listOfReadedGestures;
}

void GestureModel::removeFromFile(int row)
{
    QFile f(filename);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
        throw std::bad_exception();
    
    QFile ft("temporary.txt");
    if (!ft.open(QIODevice::WriteOnly | QIODevice::Text))
        throw std::bad_exception();

    QTextStream in(&f);
    QTextStream out(&ft);
    int i = 0;
    while(!in.atEnd())
    {
        QString line = in.readLine();
        if (i++ == row)
            continue;
        out << line << "\n";
    }
    f.remove();
    f.close();
    ft.rename("user_gestures.txt");
    ft.close();
}