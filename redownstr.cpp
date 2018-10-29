#include "redownstr.h"
#include <QFile>
#include <QTextStream>
#include "skipitems.h"

QString reDownStr(QString aFileName, const QModelIndex & index)
{
    QFile aFile(aFileName);
    QString str;
    if(aFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream aStream(&aFile);       //用文本流读取文件

        str = skipItems(aStream);

        for(int i=1;i<=index.row();i++)
            str = aStream.readLine();
    }
    aFile.close();
    return str;
}
