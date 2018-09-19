/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication7.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION7_H
#define UI_QTGUIAPPLICATION7_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication7Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication7Class)
    {
        if (QtGuiApplication7Class->objectName().isEmpty())
            QtGuiApplication7Class->setObjectName(QStringLiteral("QtGuiApplication7Class"));
        QtGuiApplication7Class->resize(600, 400);
        menuBar = new QMenuBar(QtGuiApplication7Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtGuiApplication7Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplication7Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiApplication7Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtGuiApplication7Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtGuiApplication7Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGuiApplication7Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiApplication7Class->setStatusBar(statusBar);

        retranslateUi(QtGuiApplication7Class);

        QMetaObject::connectSlotsByName(QtGuiApplication7Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication7Class)
    {
        QtGuiApplication7Class->setWindowTitle(QApplication::translate("QtGuiApplication7Class", "QtGuiApplication7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication7Class: public Ui_QtGuiApplication7Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION7_H
