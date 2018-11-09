#include "readsnapshot.h"
#include <QFile>
#include "QTextStream"
#include "skipitems.h"

QStringList readSnapShot(QString aFileName, const QModelIndex &index)
{
    QString snap;
    QStringList snapList;
    QFile aFile(aFileName);
    if(aFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream aStream(&aFile);
        aStream.setAutoDetectUnicode(true);

        skipItems(aStream);
        snap = skipItems(aStream);

        for(int i=1;i<=index.row();i++)
            if((snap = aStream.readLine()) == "")
                    snap =  "None;None;None;None";
        snapList = snap.split(';');
    }
    else
        snapList << "None" << "None" << "None" << "None";
    aFile.close();
    return snapList;
}
