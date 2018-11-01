#include "showtablecontent.h"
#include <QFile>
#include <QTextStream>
#include <QModelIndex>

void showTableContent(QString aFileName, const QModelIndex &index, QStandardItemModel *readInfoModel)
{
    readInfoModel->removeRows(0,readInfoModel->rowCount());
    QString aReadFileName = aFileName.split('.').at(0);
    aReadFileName.append(".record");

    QStringList ReadingInfo;
    QStandardItem *aItem;
    QString readInfo;

    QFile aFile(aReadFileName);
    if(aFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream aStream(&aFile);       //用文本流读取文件

        for(int i=0;i<=index.row();i++)
        {
            if((readInfo = aStream.readLine()) == "")
            {
                QStringList singleReadingInfo;
                singleReadingInfo << "无记录" << "无记录" << "无记录" <<"无记录";

                for(int j=0; j<singleReadingInfo.count(); j++)
                {
                    aItem = new QStandardItem(singleReadingInfo.at(j));
                    readInfoModel->setItem(i-1, j ,aItem);
                }
                return;
            }
        }

        ReadingInfo = readInfo.split(';',QString::SkipEmptyParts);
        for(int i=0; i<ReadingInfo.count(); i++)
        {
            QStringList singleReadingInfo = ReadingInfo.at(i).split(',');
            for(int j=0; j<singleReadingInfo.count(); j++)
            {
                aItem = new QStandardItem(singleReadingInfo.at(j));
                readInfoModel->setItem(i, j ,aItem);
            }
        }
    }
    aFile.close();
}
