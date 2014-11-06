#include "databasehandler.h"



DatabaseHandler::DatabaseHandler(void)
    : QQuickImageProvider(QQmlImageProviderBase::Image)
{
    init = false;

    if (!QSqlDatabase::drivers().contains("QSQLITE"))
        {
        QMessageBox::critical(0, "Unable to load database", "This application needs the SQLITE driver");
        }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("QtLiveCam.db");

        if (db.open()) {
            QSqlQuery q;
            if (q.exec(QLatin1String("CREATE TABLE IF NOT EXISTS Images(id INTEGER PRIMARY KEY, uuid TEXT, image BLOB)"))) {
                qDebug() << "ok" << db.tables();
                init = true;
            }
            else showError(db.lastError());
        }
        else showError(db.lastError());
    }
}



QImage DatabaseHandler::requestImage(const QString &uuid, QSize *size, const QSize &requestedSize)
{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.

    QImage img(2,2, QImage::Format_RGB32);
    qDebug() << uuid;
    img.fill(QColor("#" + uuid.left(6)).rgb());
    return img;
}


QString DatabaseHandler::storeImage(const QUrl &path)
{
    QString uuid = QUuid::createUuid().toString().mid(1,36);

    if(init) {
        QSqlQuery q;
        q.prepare(QLatin1String("INSERT INTO Images(uuid, image)"
                                "VALUES (:uuid, :image)"));
        q.bindValue(":uuid", uuid);

//        QImage tmp(path);
//        QQmlEngine *engine = QQmlEngine::contextForObject(this)->engine();
//        QQmlImageProviderBase *imageProviderBase = engine->imageProvider(path.host());
//        QQuickImageProvider *imageProvider = static_cast<QQuickImageProvider*>(imageProviderBase);

//        qDebug() << imageProvider->flags();
/*
        QSize imageSize;
        QString imageId = path.path().remove(0,1);
        QImage image = imageProvider->requestImage(imageId, &imageSize, imageSize);
        if( !image.isNull()) {
            qDebug() << "ok";
        }
*/

        q.bindValue(":image", 0);
        if(!q.exec()) showError(db.lastError());
    }

    return("image://database/"+uuid);
}

void DatabaseHandler::showError(QSqlError error)
{
    QMessageBox::critical(0, "Database Error", error.databaseText());
}
