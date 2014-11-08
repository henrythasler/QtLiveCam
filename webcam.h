#ifndef WEBCAM_H
#define WEBCAM_H

#include <QQuickPaintedItem>
#include <QPainter>
#include <QCamera>
#include "videosurface.h"
#include "databasehandler.h"

class Webcam : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QSize frameSize READ frameSize WRITE setframeSize);
    Q_PROPERTY(DatabaseHandler* database WRITE setDatabase);

public:
    explicit Webcam(QQuickItem *parent = 0);

    Q_INVOKABLE void start(QSize res = QSize());
    Q_INVOKABLE void stop();
    Q_INVOKABLE void snap();

    QSize frameSize(){return m_frameSize;};
    void setframeSize(QSize val);

//    DatabaseHandler database(){return m_database;};
    void setDatabase(DatabaseHandler* db){m_database = db;};

private:
    virtual void paint(QPainter *painter);
    QPixmap m_currentFrame;
    QImage m_currentImage;
    VideoSurface m_surface;
    QCamera* m_camera;
    QSize m_frameSize;
    DatabaseHandler* m_database;

private slots:
    void frameReady();

signals:
    void snapshotAvailable(QString uuid);

public slots:

};

#endif // WEBCAM_H
