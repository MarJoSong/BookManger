#include "skipitems.h"

QString skipItems(QTextStream& aStream)
{
    QString str;
    while((str = aStream.readLine()) != "")
    {
        continue;
    }
    while((str = aStream.readLine()) == "")
    {
        continue;
    }
    return str;
}
