#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include "redownstr.h"
#include "downpic.h"
#include "readsnapshot.h"
#include "readindex.h"
#include "getfilename.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    softInfo = new QLabel("基于Qt 5.9.1");
    readTime = new QLabel("阅读时间: ", this);
    readProcess = new QLabel("阅读进度: ", this);
    ui->statusBar->addWidget(softInfo, 1);
    ui->statusBar->addWidget(readTime, 1);
    ui->statusBar->addWidget(readProcess, 1);


    QStringList bookList;
    bookList << "C++ Prime Plus" << "Qt 5.9 C++开发指南";
    indexModel = new QStringListModel(this);        //创建数据模型
    indexModel->setStringList(bookList);            //为模型设置字符列表
    ui->listView->setModel(indexModel);     //关联数据模型和listView
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置listView条目编辑c触发条件，如QAbstractItemView::DoubleClicked或
    //QAbstractItemView::SelectedClicked
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actImportLibrary_triggered()
{
    QString aFileName = getFileName(aFileName);

    QStringList readBookLib = readIndex(aFileName, bookNum, indexModel);

    indexModel->setStringList(readBookLib);
    //ui->listView->setModel(bookModel);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void MainWindow::on_actAddBook_triggered()
{
    indexModel->insertRow(indexModel->rowCount());      //尾部插入一行
    QModelIndex index = indexModel->index(indexModel->rowCount()-1, 0,QModelIndex());
    //获取最后新加行的模型索引，三个参数，第一个为最后一行，0为第0列，第三项为父项模型索引
    //对于列表和表格模型，顶层节点总使用QModelIndex()表示，可以缺省

    indexModel->setData(index, "新书籍Got！", Qt::DisplayRole);
    //设置文本渲染角色显示内容,DisplayRole为文本渲染角色
    ui->listView->setCurrentIndex(index);//设置当前选中的行
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked);
    //双击触发编辑
}

void MainWindow::on_actEditUnable_triggered()
{
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_actSave_triggered()
{
    QFile aFile(aFileName);
    if(!(aFile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)))
        return;
    QTextStream aStream(&aFile);
    QString str = "";
    QStringList tmpList = indexModel->stringList();
    for(int i=0; i<tmpList.count(); i++)
    {
        str.append(tmpList.at(i));
        str = str + "\n";
    }
    aStream << str;
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    QString str = reDownStr(aFileName, index);//调用showPicture返回图片地址字符串
    QPixmap pixmap = downPicture(str);      //下载图片
    ui->bookSnap->setPixmap(pixmap);        //设置图片


    QStringList snapList = readSnapShot(aFileName, index);

    ui->author->setText("作者: " + snapList.at(0));
    ui->translator->setText("译者: " + snapList.at(1));
    ui->section->setText("出版日期: " + snapList.at(2));
    ui->PageNum->setText("页数: " + snapList.at(3));
}


