#ifndef WEBCAM_H
#define WEBCAM_H

#include <QQuickPaintedItem>
#include <QPainter>
#include <QCamera>
#include "videosurface.h"

class Webcam : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QSize frameSize READ frameSize WRITE setframeSize);

public:
    explicit Webcam(QQuickItem *parent = 0);

    Q_INVOKABLE void start(QSize res = QSize());
    Q_INVOKABLE void stop();

    QSize frameSize(){return m_frameSize;};
    void setframeSize(QSize val);

private:
    virtual void paint(QPainter *painter);
    QPixmap m_currentFrame;
    QImage m_currentImage;
    VideoSurface m_surface;
    QCamera* m_camera;
    QSize m_frameSize;

private slots:
    void frameReady();

signals:

public slots:

};

#endif // WEBCAM_H
