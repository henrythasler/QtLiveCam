#ifndef LIVECAM_H
#define LIVECAM_H

#include <QCamera>
#include <QAbstractVideoSurface>
#include <QVideoSurfaceFormat>
#include <QMediaService>

#include <QCameraImageCapture>
#include <QCameraCaptureBufferFormatControl>
#include <QCameraViewfinderSettingsControl>
#include <QCameraControl>
#include <QImageEncoderControl>
#include <QImageEncoderSettings>
#include <QVideoEncoderSettingsControl>


class LiveCam : public QCamera
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ getVideoSurface WRITE setVideoSurface )
public:
    explicit LiveCam(QObject *parent = 0);
    Q_INVOKABLE void snap();

signals:

public slots:
    void setVideoSurface(QAbstractVideoSurface *surface);
    QAbstractVideoSurface* getVideoSurface();

private:
    QAbstractVideoSurface* m_surface;
};

#endif // LIVECAM_H
