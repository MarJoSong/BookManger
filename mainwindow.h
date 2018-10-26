#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actImportLibrary_triggered();

    void on_actAddBook_triggered();

    void on_actEditUnable_triggered();

    void on_actSave_triggered();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QStringListModel *indexModel;       //声明目录索引数据模型变量
    QString aFileName;                  //声明书籍文件路径存储变量
    QLabel *bookName;
    QLabel *progress;
    QLabel *bookCount;
    int bookNum;
};

#endif // MAINWINDOW_H
