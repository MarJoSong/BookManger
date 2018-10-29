/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actAddBook;
    QAction *actImportLibrary;
    QAction *actEditUnable;
    QAction *actSave;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *bookSnap;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *author;
    QLabel *translator;
    QLabel *section;
    QLabel *PageNum;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(626, 552);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        actAddBook = new QAction(MainWindow);
        actAddBook->setObjectName(QStringLiteral("actAddBook"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icons/new.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actAddBook->setIcon(icon);
        actImportLibrary = new QAction(MainWindow);
        actImportLibrary->setObjectName(QStringLiteral("actImportLibrary"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/icons/import.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actImportLibrary->setIcon(icon1);
        actEditUnable = new QAction(MainWindow);
        actEditUnable->setObjectName(QStringLiteral("actEditUnable"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/icons/Uneditabl.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actEditUnable->setIcon(icon2);
        actSave = new QAction(MainWindow);
        actSave->setObjectName(QStringLiteral("actSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/icons/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listView = new QListView(groupBox);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        bookSnap = new QLabel(groupBox_2);
        bookSnap->setObjectName(QStringLiteral("bookSnap"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bookSnap->sizePolicy().hasHeightForWidth());
        bookSnap->setSizePolicy(sizePolicy);
        bookSnap->setFrameShape(QFrame::NoFrame);
        bookSnap->setFrameShadow(QFrame::Plain);
        bookSnap->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(bookSnap);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        author = new QLabel(groupBox_3);
        author->setObjectName(QStringLiteral("author"));

        verticalLayout_6->addWidget(author);

        translator = new QLabel(groupBox_3);
        translator->setObjectName(QStringLiteral("translator"));

        verticalLayout_6->addWidget(translator);

        section = new QLabel(groupBox_3);
        section->setObjectName(QStringLiteral("section"));

        verticalLayout_6->addWidget(section);

        PageNum = new QLabel(groupBox_3);
        PageNum->setObjectName(QStringLiteral("PageNum"));

        verticalLayout_6->addWidget(PageNum);


        horizontalLayout_2->addWidget(groupBox_3);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView = new QTableView(groupBox_4);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);


        verticalLayout_3->addWidget(groupBox_4);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 626, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actImportLibrary);
        mainToolBar->addAction(actAddBook);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actEditUnable);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Qt\350\257\273\344\271\246\347\256\241\347\220\206\345\231\250", Q_NULLPTR));
        actAddBook->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\271\246\347\261\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAddBook->setToolTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\271\246\347\261\215", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actAddBook->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actImportLibrary->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\344\271\246\345\272\223", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actImportLibrary->setToolTip(QApplication::translate("MainWindow", "\345\257\274\345\205\245\344\271\246\345\272\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actImportLibrary->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actEditUnable->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210\347\274\226\350\276\221", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actEditUnable->setToolTip(QApplication::translate("MainWindow", "\345\217\226\346\266\210\347\274\226\350\276\221", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\271\246\345\215\225", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSave->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\271\246\345\215\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\234\250\350\257\273\344\271\246\347\261\215\345\210\227\350\241\250", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\344\271\246\347\261\215\351\230\205\350\257\273\344\277\241\346\201\257", Q_NULLPTR));
        bookSnap->setText(QApplication::translate("MainWindow", "\344\271\246\347\261\215\344\277\241\346\201\257", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\233\276\344\271\246\344\277\241\346\201\257", Q_NULLPTR));
        author->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        translator->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        section->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        PageNum->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\351\230\205\350\257\273\345\216\206\345\217\262", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
