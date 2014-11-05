#include "databasehandler.h"

DatabaseHandler::DatabaseHandler(void)
    : QQuickImageProvider(QQmlImageProviderBase::Image)
{
}


QImage DatabaseHandler::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    QImage img(2,2, QImage::Format_RGB32);
    img.fill(QColor(id).rgb());
    return img;
}


QString DatabaseHandler::storeImage(const QString &id)
{
    return("image://database/#"+QUuid::createUuid().toString().mid(1,6));
}
