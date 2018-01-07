#include "main_app.h"
#include "Gesture.h"
#include "ui_GestureWidget.h"
#include "qmessagebox.h"
#include "VideoThread.h"

static const QMap<QString, QString> numbers{ {"tone", "1"}, {"ttwo", "2"}, {"tthree", "3"}, {"tfour", "4"}, {"tfive", "5" } };

main_app::main_app(QWidget *parent)
    : QMainWindow(parent), vid(&data)
{
    ui.setupUi(this);
    enumMap_action.insert("Shutdown", Action::SHUTDOWN);
    enumMap_action.insert("Lock", Action::LOCK);
    enumMap_action.insert("Log out", Action::LOGOUT);
    enumMap_action.insert("Volume up", Action::VOLUME_UP);
    enumMap_action.insert("Volume down", Action::VOLUME_DOWN);
    enumMap_action.insert("Restart", Action::RESTART);
    enumMap_action.insert("Mute", Action::MUTE);
    ui.comboBox->addItems(enumMap_action.keys());

    ui.comboBox->insertItem(0, "Select an action");
    ui.comboBox->setCurrentIndex(0);
    enumMap_action.insert("Select an action", Action::NOTHING);

    enumMap_hand.insert("upArrow", HandMovement::UP);
    enumMap_hand.insert("downArrow", HandMovement::DOWN);
    enumMap_hand.insert("leftArrow", HandMovement::LEFT);
    enumMap_hand.insert("rightArrow", HandMovement::RIGHT);
    enumMap_hand.insert("tone", HandMovement::ONE);
    enumMap_hand.insert("ttwo", HandMovement::TWO);
    enumMap_hand.insert("tthree", HandMovement::THREE);
    enumMap_hand.insert("tfour", HandMovement::FOUR);
    enumMap_hand.insert("tfive", HandMovement::FIVE);

    try 
    {
        QList<Gesture> list = data.readFromFile();
        for (auto &item : list)
        {
            addGesture(item);
            data.add(item);
        }
    }
    catch(std::exception &e)
    {

    }
}

void main_app::actionStart()
{
    vid.start();
}

void main_app::actionStop()
{
}

void main_app::actionInfo()
{
}

void main_app::addToGesturesToBeAdded()
{
    QPushButton* button = static_cast<QPushButton*>(QObject::sender());
    QPushButton *button_2;
    if (button->icon().isNull())
    {
        button_2 = new QPushButton();
        button_2->setText(button->text());
        QFont f;
        f.setPointSize(15);
        button_2->setFont(f);
    }
    else
    {
        button_2 = new QPushButton(button->icon(), nullptr);
    }
    button_2->setAccessibleName(button->accessibleName());
    button_2->setIconSize({ 32,32 });
    button_2->setStyleSheet("QPushButton:hover {\n"
        "background-color: rgba(255,114,114,255);\n"
        "border: none;\n }");
    QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(ui.toAddGesturesListWidget);
    ui.toAddGesturesListWidget->setItemWidget(__qlistwidgetitem1, button_2);
    QObject::connect(button_2, &QAbstractButton::clicked, this, [this,__qlistwidgetitem1] { removeFromGesturesToBeAdded(__qlistwidgetitem1); });
}

void main_app::removeFromGesturesToBeAdded(QListWidgetItem* item)
{
    delete ui.toAddGesturesListWidget->takeItem(ui.toAddGesturesListWidget->row(item));
}

void main_app::removeFromGestures(QListWidgetItem* item)
{
    int row = ui.gesturesList->row(item);
    delete ui.gesturesList->takeItem(row);
    data.removeFromFile(row);
}

void main_app::addGesture()
{
    QString action = ui.comboBox->currentText();
    if (action == "Select an action")
    {
        QMessageBox msgBox;
        msgBox.setText("Please select an action");
        msgBox.exec();
        return;
    }
    else if (ui.toAddGesturesListWidget->count() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Please select some gestures");
        msgBox.exec();
        return;
    }
    Gesture gesture;
    for (int i = 0; i < ui.toAddGesturesListWidget->count(); i++)
    {
        QPushButton* button = static_cast<QPushButton*>(ui.toAddGesturesListWidget->itemWidget(ui.toAddGesturesListWidget->item(i)));
        QString a = button->accessibleName();
        gesture.gestures.append(enumMap_hand[button->accessibleName()]);
    }
    gesture.action = enumMap_action[action];
    data.add(gesture);

    createGestureWidget(gesture);

    ui.toAddGesturesListWidget->clear();
    ui.comboBox->setCurrentIndex(0);
    data.saveToFile(gesture);
}

void main_app::addGesture(Gesture g)
{
    createGestureWidget(g);
}

void main_app::createGestureWidget(Gesture &g)
{
    QWidget* my_gesture = new QWidget;
    my_gesture->resize(400, 97);
    my_gesture->setStyleSheet(".QWidget {\n"
        "border-radius: 8px;\n"
        "border: 1px solid;\n"
        "background-color:rgb(195,195,195); }\n"
        "QListWidget {\n"
        "border-radius: 0px;\n"
        "border: 1px solid }\n"
        "QListWidget#listofgestures::item{\n"
        "border: 1px solid rgba(250,250,250,255);\n"
        "alignment: center;\n"
        "}");
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(my_gesture->sizePolicy().hasHeightForWidth());
    my_gesture->setSizePolicy(sizePolicy);
    QHBoxLayout* horizontalLayout_2 = new QHBoxLayout(my_gesture);
    QHBoxLayout* horizontalLayout = new QHBoxLayout();

    QVBoxLayout* verticalLayout = new QVBoxLayout();
    QListWidget* listWidget = new QListWidget(my_gesture);
    listWidget->setObjectName("listofgestures");

    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
    listWidget->setSizePolicy(sizePolicy1);
    listWidget->setMinimumSize(QSize(0, 50));
    //listWidget->setMaximumSize(QSize(16777215, 44));
    //listWidget->setFrameShape(QFrame::Box);
    listWidget->setIconSize(QSize(34, 34));
    listWidget->setFlow(QListView::LeftToRight);
    listWidget->setResizeMode(QListView::Fixed);
    listWidget->setSpacing(1);
    /*for (int i = 0; i < ui.toAddGesturesListWidget->count(); i++)
    {
        QPushButton* button = static_cast<QPushButton*>(ui.toAddGesturesListWidget->itemWidget(ui.toAddGesturesListWidget->item(i)));
        QPushButton *button_2 = new QPushButton(button->icon(), nullptr);
        button_2->setAccessibleName(button->accessibleName());
        button_2->setIconSize({ 36,36 });
        button_2->setFixedSize({ 44,44 });
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setSizeHint({ 44,44 });
        listWidget->setItemWidget(__qlistwidgetitem1, button_2);
    }*/
    for (int i = 0; i < g.gestures.count(); i++)
    {
        QString value = enumMap_hand.key(g.gestures[i]);
        QPushButton *button;
        if (value[0] == 't')
        {
            button = new QPushButton();
            button->setText(numbers[value]);
            QFont f;
            f.setPointSize(15);
            button->setFont(f);
        }
        else
        {
            QString str = ":/main_app/" + value;
            button = new QPushButton(QIcon(str), nullptr);
        }
        button->setAccessibleName(button->accessibleName());
        button->setIconSize({ 36,36 });
        button->setFixedSize({ 44,44 });
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setSizeHint({ 44,44 });
        listWidget->setItemWidget(__qlistwidgetitem1, button);
    }

    verticalLayout->addWidget(listWidget);

    QLabel* label = new QLabel(my_gesture);
    label->setMinimumSize(QSize(0, 25));
    label->setMaximumSize(QSize(16777215, 25));
    QFont font;
    font.setPointSize(11);
    label->setFont(font);
    label->setStyleSheet("background-color:rgb(230,230,230);\n"
        "border-radius:10px;");
    label->setFrameShape(QFrame::Box);
    label->setFrameShadow(QFrame::Sunken);
    label->setText(enumMap_action.key(g.action));
    label->setContentsMargins(12, 0, 0, 0);

    verticalLayout->addWidget(label);

    horizontalLayout->addLayout(verticalLayout);

    QPushButton* pushButton = new QPushButton(my_gesture);
    pushButton->setStyleSheet(QStringLiteral("background-color: rgb(255,70,70);"));
    QIcon icon;
    icon.addFile(QStringLiteral(":/main_app/deleteButton"), QSize(), QIcon::Normal, QIcon::Off);
    pushButton->setIcon(icon);
    pushButton->setIconSize(QSize(36, 36));
    pushButton->setAutoDefault(true);
    pushButton->setFlat(false);
    horizontalLayout->addWidget(pushButton);

    horizontalLayout_2->addLayout(horizontalLayout);

    QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(ui.gesturesList);
    __qlistwidgetitem1->setSizeHint({ 400, 97 });
    ui.gesturesList->setItemWidget(__qlistwidgetitem1, my_gesture);
    connect(pushButton, &QAbstractButton::clicked, this, [this, __qlistwidgetitem1] { removeFromGestures(__qlistwidgetitem1); });
}
