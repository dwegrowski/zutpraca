/********************************************************************************
** Form generated from reading UI file 'main_app.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_APP_H
#define UI_MAIN_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_appClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget_2;
    QListWidget *toAddGesturesListWidget;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *main_appClass)
    {
        if (main_appClass->objectName().isEmpty())
            main_appClass->setObjectName(QStringLiteral("main_appClass"));
        main_appClass->resize(697, 587);
        main_appClass->setStyleSheet(QLatin1String("QListWidget#listWidget_2 {\n"
"background-color: rgba(0,0,0,0);\n"
"border: none;\n"
"}\n"
"QListWidget#listWidget_2::item {\n"
"background-color: rgba(222,222,222,255);\n"
"border: 1px solid rgba(150,150,150,255);\n"
"width: 40px;\n"
"height: 40px;\n"
"alignment: center;\n"
"}\n"
"QListWidget#toAddGesturesListWidget::item {\n"
"background-color: rgba(230,230,230,255);\n"
"border: 1px solid rgba(250,250,250,255);\n"
"width: 40px;\n"
"height: 40px;\n"
"alignment: center;\n"
"}\n"
"QListWidget#toAddGesturesListWidget::item:hover {\n"
"background-color: rgba(255,114,114,255);\n"
"}"));
        centralWidget = new QWidget(main_appClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        listWidget->setViewMode(QListView::ListMode);

        verticalLayout->addWidget(listWidget);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 1, -1, -1);
        verticalWidget = new QWidget(groupBox);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy1);
        verticalWidget->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(verticalWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 3, -1, -1);
        listWidget_2 = new QListWidget(verticalWidget);
        QIcon icon;
        icon.addFile(QStringLiteral("E:/Pobrane/Icons8-Ios7-Arrows-Down.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QBrush brush(QColor(222, 222, 222, 255));
        brush.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qlistwidgetitem->setBackground(brush);
        __qlistwidgetitem->setIcon(icon);
        __qlistwidgetitem->setFlags(Qt::ItemIsEnabled);
        QIcon icon1;
        icon1.addFile(QStringLiteral("E:/Pobrane/Icons8-Ios7-Arrows-Up.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QStringLiteral("E:/Pobrane/Icons8-Ios7-Arrows-Left.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem2->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QStringLiteral("E:/Pobrane/Icons8-Ios7-Arrows-Right.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem3->setIcon(icon3);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidget_2->sizePolicy().hasHeightForWidth());
        listWidget_2->setSizePolicy(sizePolicy2);
        listWidget_2->setMinimumSize(QSize(0, 50));
        listWidget_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        listWidget_2->setStyleSheet(QStringLiteral(""));
        listWidget_2->setFrameShape(QFrame::NoFrame);
        listWidget_2->setFrameShadow(QFrame::Sunken);
        listWidget_2->setProperty("showDropIndicator", QVariant(false));
        listWidget_2->setDragDropMode(QAbstractItemView::NoDragDrop);
        listWidget_2->setDefaultDropAction(Qt::CopyAction);
        listWidget_2->setAlternatingRowColors(false);
        listWidget_2->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget_2->setIconSize(QSize(34, 34));
        listWidget_2->setFlow(QListView::LeftToRight);
        listWidget_2->setProperty("isWrapping", QVariant(false));
        listWidget_2->setResizeMode(QListView::Fixed);
        listWidget_2->setSpacing(3);
        listWidget_2->setViewMode(QListView::ListMode);
        listWidget_2->setUniformItemSizes(false);
        listWidget_2->setBatchSize(100);
        listWidget_2->setSelectionRectVisible(true);

        verticalLayout_2->addWidget(listWidget_2);

        toAddGesturesListWidget = new QListWidget(verticalWidget);
        toAddGesturesListWidget->setObjectName(QStringLiteral("toAddGesturesListWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toAddGesturesListWidget->sizePolicy().hasHeightForWidth());
        toAddGesturesListWidget->setSizePolicy(sizePolicy3);
        toAddGesturesListWidget->setMinimumSize(QSize(0, 50));
        toAddGesturesListWidget->setBaseSize(QSize(0, 0));
        toAddGesturesListWidget->setFocusPolicy(Qt::StrongFocus);
        toAddGesturesListWidget->setFrameShadow(QFrame::Plain);
        toAddGesturesListWidget->setProperty("showDropIndicator", QVariant(false));
        toAddGesturesListWidget->setIconSize(QSize(34, 34));
        toAddGesturesListWidget->setFlow(QListView::LeftToRight);
        toAddGesturesListWidget->setResizeMode(QListView::Fixed);
        toAddGesturesListWidget->setSelectionRectVisible(true);

        verticalLayout_2->addWidget(toAddGesturesListWidget);

        comboBox = new QComboBox(verticalWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 25));

        verticalLayout_2->addWidget(comboBox);


        horizontalLayout->addWidget(verticalWidget);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(60, 60));
        QIcon icon4;
        icon4.addFile(QStringLiteral("E:/Pobrane/icons8-checkmark-filled.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon4);
        pushButton->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(groupBox);

        main_appClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(main_appClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 697, 21));
        main_appClass->setMenuBar(menuBar);

        retranslateUi(main_appClass);
        QObject::connect(listWidget_2, SIGNAL(itemClicked(QListWidgetItem*)), main_appClass, SLOT(addToGesturesToBeAdded(QListWidgetItem*)));
        QObject::connect(toAddGesturesListWidget, SIGNAL(itemClicked(QListWidgetItem*)), main_appClass, SLOT(removeFromGesturesToBeAdded(QListWidgetItem*)));

        QMetaObject::connectSlotsByName(main_appClass);
    } // setupUi

    void retranslateUi(QMainWindow *main_appClass)
    {
        main_appClass->setWindowTitle(QApplication::translate("main_appClass", "main_app", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("main_appClass", "Add new gesture", Q_NULLPTR));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        listWidget_2->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class main_appClass: public Ui_main_appClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_APP_H
