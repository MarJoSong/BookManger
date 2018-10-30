#include "readindex.h"
#include <QFile>
#include <QTextStream>


QStringList readIndex(QString aFileName, int &bookNum, QStringListModel *indexModel)
{
    QStringList readBookLib;
    bookNum = 0;

    if(aFileName.isEmpty())
            return readBookLib << "空";

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
    }
    return readBookLib;
}
