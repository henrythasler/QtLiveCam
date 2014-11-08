#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QQuickImageProvider>
#include <QtDebug>
#include <QUuid>
#include <QMessageBox>
#include <QtSql>

#include <QQmlEngine>
#include <QQmlContext>

class DatabaseHandler : public QObject, public QQuickImageProvider
{
    Q_OBJECT
public:
    DatabaseHandler();
    QImage requestImage(const QString &uuid, QSize *size, const QSize &requestedSize);
    Q_INVOKABLE QString storeImage(const QUrl &path);
    Q_INVOKABLE QString storePixmap(const QPixmap &pixmap);

private:
    void showError(QSqlError error);

    QSqlDatabase db;
    bool init;
};

#endif // DATABASEHANDLER_H
