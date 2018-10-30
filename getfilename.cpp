#include "getfilename.h"
#include <QCoreApplication>
#include <QFileDialog>
#include "mainwindow.h"

QString getFileName(QString &aFileName)
{
    QString curPath = QCoreApplication::applicationDirPath();//获取程序当前所在路径
    return aFileName = QFileDialog::getOpenFileName(0, "选择一个文件", curPath,
                                             "书库文件(*.book)");

}

