#include "downpic.h"
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QObject>

QPixmap downPicture(QString str)
{
    QUrl url(str);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply = manager.get(QNetworkRequest(url));
    //请求结束并下载完成后，退出子事件循环
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    //在别的源文件中引用connect需要添加QObject

    //开启子事件循环
    loop.exec();
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    pixmap = pixmap.scaledToWidth(150, Qt::FastTransformation);
    pixmap = pixmap.scaledToHeight(215, Qt::FastTransformation);
    return pixmap;
}
