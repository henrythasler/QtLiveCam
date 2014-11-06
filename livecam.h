#ifndef LIVECAM_H
#define LIVECAM_H

#include <QCamera>
#include <QAbstractVideoSurface>
#include <QVideoSurfaceFormat>
#include <QCameraViewfinderSettingsControl>
#include <QMediaService>

class LiveCam : public QCamera
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ getVideoSurface WRITE setVideoSurface )
public:
    explicit LiveCam(QObject *parent = 0);

signals:

public slots:
    void setVideoSurface(QAbstractVideoSurface *surface);
    QAbstractVideoSurface* getVideoSurface();

private:
    QAbstractVideoSurface* m_surface;
};

#endif // LIVECAM_H
