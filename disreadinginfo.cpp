#include "disreadinginfo.h"
#include <QFile>
#include <QTextStream>
#include "skipitems.h"
#include <QStandardItem>

QStringList disReadingInfo(QString aFileName, const QModelIndex &index, QStandardItemModel *readInfoModel)
{
    QStringList ReadingInfo;
    QStandardItem *aItem;

//    if(aFileName.isEmpty())
//            return readingInfo << "空";

    QFile aFile(aFileName);

    if(aFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream aStream(&aFile);       //用文本流读取文件

        skipItems(aStream);
        skipItems(aStream);
        QString str = skipItems(aStream);

        for(int i=1;i<=index.row();i++)
            if((str = aStream.readLine()) == "")
                str.append("None,None,None,None;");

        ReadingInfo = str.split(';');
        for(int i=0; i<ReadingInfo.count(); i++)
        {
            QStringList singleReadingInfo = ReadingInfo.at(i).split(',');
            for(int j=0; j<singleReadingInfo.count(); i++)
            {
                aItem = new QStandardItem(singleReadingInfo.at(j));
                readInfoModel->setItem(i-1, j ,aItem);
            }
        }
    }
    aFile.close();
}
