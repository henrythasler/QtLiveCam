#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

//#include <QtQuick>
#include <QObject>
#include <QQuickImageProvider>
#include <QtDebug>
#include <QUuid>

class DatabaseHandler : public QObject, public QQuickImageProvider
{
    Q_OBJECT
public:
    DatabaseHandler();
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
    Q_INVOKABLE QString storeImage(const QString &id);

};

#endif // DATABASEHANDLER_H
