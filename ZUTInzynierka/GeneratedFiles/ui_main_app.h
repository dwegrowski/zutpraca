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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_appClass
{
public:
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionInfo;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *gesturesList;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *threeButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QListWidget *toAddGesturesListWidget;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuStart;

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
"border: none;\n"
"}"));
        actionStart = new QAction(main_appClass);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionStop = new QAction(main_appClass);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionInfo = new QAction(main_appClass);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        centralWidget = new QWidget(main_appClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gesturesList = new QListWidget(centralWidget);
        gesturesList->setObjectName(QStringLiteral("gesturesList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gesturesList->sizePolicy().hasHeightForWidth());
        gesturesList->setSizePolicy(sizePolicy);
        gesturesList->setStyleSheet(QStringLiteral(""));
        gesturesList->setFrameShadow(QFrame::Plain);
        gesturesList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        gesturesList->setProperty("showDropIndicator", QVariant(false));
        gesturesList->setIconSize(QSize(34, 34));
        gesturesList->setResizeMode(QListView::Adjust);
        gesturesList->setSpacing(5);
        gesturesList->setViewMode(QListView::ListMode);

        verticalLayout->addWidget(gesturesList);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 1, -1, 3);
        verticalWidget = new QWidget(groupBox);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy2);
        verticalWidget->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(verticalWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 3, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        oneButton = new QPushButton(verticalWidget);
        oneButton->setObjectName(QStringLiteral("oneButton"));
        oneButton->setMinimumSize(QSize(42, 42));
        oneButton->setMaximumSize(QSize(42, 42));
        QFont font;
        font.setPointSize(15);
        oneButton->setFont(font);

        horizontalLayout_2->addWidget(oneButton);

        twoButton = new QPushButton(verticalWidget);
        twoButton->setObjectName(QStringLiteral("twoButton"));
        twoButton->setMaximumSize(QSize(42, 42));
        twoButton->setFont(font);

        horizontalLayout_2->addWidget(twoButton);

        threeButton = new QPushButton(verticalWidget);
        threeButton->setObjectName(QStringLiteral("threeButton"));
        threeButton->setMaximumSize(QSize(42, 42));
        threeButton->setFont(font);

        horizontalLayout_2->addWidget(threeButton);

        fourButton = new QPushButton(verticalWidget);
        fourButton->setObjectName(QStringLiteral("fourButton"));
        fourButton->setMaximumSize(QSize(42, 42));
        fourButton->setFont(font);

        horizontalLayout_2->addWidget(fourButton);

        fiveButton = new QPushButton(verticalWidget);
        fiveButton->setObjectName(QStringLiteral("fiveButton"));
        fiveButton->setMaximumSize(QSize(42, 42));
        fiveButton->setFont(font);

        horizontalLayout_2->addWidget(fiveButton);

        pushButton_5 = new QPushButton(verticalWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy3);
        pushButton_5->setMinimumSize(QSize(42, 42));
        pushButton_5->setMaximumSize(QSize(42, 42));
        QIcon icon;
        icon.addFile(QStringLiteral(":/main_app/upArrow"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon);
        pushButton_5->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(verticalWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy4);
        pushButton_4->setMinimumSize(QSize(42, 42));
        pushButton_4->setMaximumSize(QSize(42, 42));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/main_app/downArrow"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(verticalWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy5);
        pushButton_3->setMaximumSize(QSize(42, 42));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/main_app/leftArrow"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(verticalWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(42, 42));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/main_app/rightArrow"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);
        pushButton_2->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        toAddGesturesListWidget = new QListWidget(verticalWidget);
        toAddGesturesListWidget->setObjectName(QStringLiteral("toAddGesturesListWidget"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(toAddGesturesListWidget->sizePolicy().hasHeightForWidth());
        toAddGesturesListWidget->setSizePolicy(sizePolicy6);
        toAddGesturesListWidget->setMinimumSize(QSize(0, 50));
        toAddGesturesListWidget->setBaseSize(QSize(0, 0));
        toAddGesturesListWidget->setFocusPolicy(Qt::StrongFocus);
        toAddGesturesListWidget->setFrameShadow(QFrame::Plain);
        toAddGesturesListWidget->setProperty("showDropIndicator", QVariant(false));
        toAddGesturesListWidget->setIconSize(QSize(34, 34));
        toAddGesturesListWidget->setFlow(QListView::LeftToRight);
        toAddGesturesListWidget->setResizeMode(QListView::Fixed);
        toAddGesturesListWidget->setSelectionRectVisible(false);

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
        menuStart = new QMenu(menuBar);
        menuStart->setObjectName(QStringLiteral("menuStart"));
        main_appClass->setMenuBar(menuBar);

        menuBar->addAction(menuStart->menuAction());
        menuStart->addAction(actionStart);
        menuStart->addAction(actionStop);
        menuStart->addAction(actionInfo);

        retranslateUi(main_appClass);
        QObject::connect(toAddGesturesListWidget, SIGNAL(itemClicked(QListWidgetItem*)), main_appClass, SLOT(removeFromGesturesToBeAdded(QListWidgetItem*)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), main_appClass, SLOT(addToGesturesToBeAdded()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), main_appClass, SLOT(addToGesturesToBeAdded()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), main_appClass, SLOT(addToGesturesToBeAdded()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), main_appClass, SLOT(addToGesturesToBeAdded()));
        QObject::connect(pushButton, SIGNAL(clicked()), main_appClass, SLOT(addGesture()));
        QObject::connect(actionStop, SIGNAL(triggered()), main_appClass, SLOT(actionStop()));
        QObject::connect(actionStart, SIGNAL(triggered()), main_appClass, SLOT(actionStart()));
        QObject::connect(actionInfo, SIGNAL(triggered()), main_appClass, SLOT(actionInfo()));
        QObject::connect(fiveButton, SIGNAL(clicked()), main_appClass, SLOT(addToGesturesToBeAdded()));
        QObject::connect(fourButton, SIGNAL(clicked()), main_appClass, SLOT(addToGesturesToBeAdded()));
        QObject::connect(threeButton, SIGNAL(clicked()), main_appClass, SLOT(addToGesturesToBeAdded()));
        QObject::connect(twoButton, SIGNAL(clicked()), main_appClass, SLOT(addToGesturesToBeAdded()));
        QObject::connect(oneButton, SIGNAL(clicked()), main_appClass, SLOT(addToGesturesToBeAdded()));

        QMetaObject::connectSlotsByName(main_appClass);
    } // setupUi

    void retranslateUi(QMainWindow *main_appClass)
    {
        main_appClass->setWindowTitle(QApplication::translate("main_appClass", "main_app", Q_NULLPTR));
        actionStart->setText(QApplication::translate("main_appClass", "Start", Q_NULLPTR));
        actionStop->setText(QApplication::translate("main_appClass", "Stop", Q_NULLPTR));
        actionInfo->setText(QApplication::translate("main_appClass", "Info", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("main_appClass", "Add new gesture", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        oneButton->setAccessibleName(QApplication::translate("main_appClass", "tone", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        oneButton->setText(QApplication::translate("main_appClass", "1", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        twoButton->setAccessibleName(QApplication::translate("main_appClass", "ttwo", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        twoButton->setText(QApplication::translate("main_appClass", "2", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        threeButton->setAccessibleName(QApplication::translate("main_appClass", "tthree", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        threeButton->setText(QApplication::translate("main_appClass", "3", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        fourButton->setAccessibleName(QApplication::translate("main_appClass", "tfour", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        fourButton->setText(QApplication::translate("main_appClass", "4", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        fiveButton->setAccessibleName(QApplication::translate("main_appClass", "tfive", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        fiveButton->setText(QApplication::translate("main_appClass", "5", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        pushButton_5->setAccessibleName(QApplication::translate("main_appClass", "upArrow", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        pushButton_5->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        pushButton_4->setAccessibleName(QApplication::translate("main_appClass", "downArrow", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        pushButton_4->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        pushButton_3->setAccessibleName(QApplication::translate("main_appClass", "leftArrow", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        pushButton_3->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        pushButton_2->setAccessibleName(QApplication::translate("main_appClass", "rightArrow", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        pushButton_2->setText(QString());
        pushButton->setText(QString());
        menuStart->setTitle(QApplication::translate("main_appClass", "Opcje", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class main_appClass: public Ui_main_appClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_APP_H
