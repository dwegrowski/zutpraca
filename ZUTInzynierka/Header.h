//#pragma once
//
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
//class Ui_GestureWidget
//{
//public:
//    QHBoxLayout *horizontalLayout_2;
//    QHBoxLayout *horizontalLayout;
//    QVBoxLayout *verticalLayout;
//    QListWidget *listWidget;
//    QLabel *label;
//    QPushButton *pushButton;
//
//    void setupUi(QWidget *GestureWidget)
//    {
//        if (GestureWidget->objectName().isEmpty())
//            GestureWidget->setObjectName(QStringLiteral("GestureWidget"));
//        GestureWidget->setWindowModality(Qt::ApplicationModal);
//        GestureWidget->resize(400, 97);
//        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
//        sizePolicy.setHorizontalStretch(0);
//        sizePolicy.setVerticalStretch(0);
//        sizePolicy.setHeightForWidth(GestureWidget->sizePolicy().hasHeightForWidth());
//        GestureWidget->setSizePolicy(sizePolicy);
//        horizontalLayout_2 = new QHBoxLayout(GestureWidget);
//        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
//        horizontalLayout = new QHBoxLayout();
//        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
//        verticalLayout = new QVBoxLayout();
//        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
//        listWidget = new QListWidget(GestureWidget);
//        listWidget->setObjectName(QStringLiteral("listWidget"));
//        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
//        sizePolicy1.setHorizontalStretch(0);
//        sizePolicy1.setVerticalStretch(0);
//        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
//        listWidget->setSizePolicy(sizePolicy1);
//        listWidget->setMinimumSize(QSize(0, 44));
//        listWidget->setMaximumSize(QSize(16777215, 44));
//        listWidget->setFrameShape(QFrame::Box);
//
//        verticalLayout->addWidget(listWidget);
//
//        label = new QLabel(GestureWidget);
//        label->setObjectName(QStringLiteral("label"));
//        label->setMinimumSize(QSize(0, 25));
//        label->setMaximumSize(QSize(16777215, 25));
//        QFont font;
//        font.setPointSize(11);
//        label->setFont(font);
//        label->setAutoFillBackground(true);
//        label->setFrameShape(QFrame::Box);
//        label->setFrameShadow(QFrame::Sunken);
//        label->setTextFormat(Qt::AutoText);
//
//        verticalLayout->addWidget(label);
//
//
//        horizontalLayout->addLayout(verticalLayout);
//
//        pushButton = new QPushButton(GestureWidget);
//        pushButton->setObjectName(QStringLiteral("pushButton"));
//        QFont font1;
//        font1.setPointSize(8);
//        pushButton->setFont(font1);
//        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(255,170,170);"));
//        QIcon icon;
//        icon.addFile(QStringLiteral(":/main_app/E:/Pobrane/icons8-delete-filled-50.png"), QSize(), QIcon::Normal, QIcon::Off);
//        pushButton->setIcon(icon);
//        pushButton->setIconSize(QSize(36, 36));
//        pushButton->setAutoDefault(true);
//        pushButton->setFlat(false);
//
//        horizontalLayout->addWidget(pushButton);
//
//
//        horizontalLayout_2->addLayout(horizontalLayout);
//
//
//        retranslateUi(GestureWidget);
//
//        pushButton->setDefault(false);
//
//
//        QMetaObject::connectSlotsByName(GestureWidget);
//    } // setupUi
//
//    void retranslateUi(QWidget *GestureWidget)
//    {
//        GestureWidget->setWindowTitle(QApplication::translate("GestureWidget", "Form", Q_NULLPTR));
//        label->setText(QString());
//        pushButton->setText(QString());
//    } // retranslateUi
//
//};