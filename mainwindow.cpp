#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bookName = new QLabel("书名: ", this);
    progress = new QLabel("进度: ", this);
    bookCount = new QLabel("书籍总数: ", this);
    ui->statusBar->addWidget(bookName, 1);
    ui->statusBar->addWidget(progress, 1);
    ui->statusBar->addWidget(bookCount, 1);


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
    QString curPath = QCoreApplication::applicationDirPath();//获取程序当前所在路径
    aFileName = QFileDialog::getOpenFileName(this, "选择一个文件", curPath,
                                             "书库文件(*.book)");
    bookNum = 0;

    if(aFileName.isEmpty())
        return;

    QStringList readBookLib;
    QFile aFile(aFileName);

    if(aFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream aStream(&aFile);       //用文本流读取文件
        indexModel->removeRows(0,indexModel->rowCount());//清空列表

        while(!aStream.atEnd())
        {
            QString str;
            if((str = aStream.readLine()) == "")
                break;

            //读取一行，自动去掉行尾的多余空格，类似于QString::trimmed()
            readBookLib.append(str);
            bookNum++;
        }
        aFile.close();
        bookCount->setText(QString::asprintf("书籍总数: %d册",bookNum));
        indexModel->setStringList(readBookLib);
        //ui->listView->setModel(bookModel);
        ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
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
    QFile aFile(aFileName);
    QString str;
    if(aFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream aStream(&aFile);       //用文本流读取文件
        while((str = aStream.readLine()) != "")
        {
            continue;
        }
        while((str = aStream.readLine()) == "")
        {
            continue;
        }
        for(int i=1;i<=index.row();i++)
            str = aStream.readLine();
    }
    aFile.close();
    QUrl url(str);
    bookName->setText(str);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply = manager.get(QNetworkRequest(url));
    //请求结束并下载完成后，退出子事件循环
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    //开启子事件循环
    loop.exec();
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    pixmap = pixmap.scaledToWidth(120, Qt::FastTransformation);
    ui->bookSnap->setPixmap(pixmap);
    ui->bookSnap->setScaledContents(false);
}
