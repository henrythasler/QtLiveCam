#include "webcam.h"

#include <QCameraViewfinderSettingsControl>

Webcam::Webcam(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    m_frameSize(QSize()),
    m_currentFrame(QPixmap())

{
    connect(&m_surface, SIGNAL(frameAvailable()), this, SLOT(frameReady()));

    m_camera = new QCamera(this);
    m_camera->load();
    m_camera->setViewfinder( static_cast<QAbstractVideoSurface*>( &m_surface ) );

//    start();
}

void Webcam::start(QSize res)
{
    if(res.isValid()) m_frameSize = res;

    m_camera->stop();

    QCameraViewfinderSettingsControl *set = qobject_cast<QCameraViewfinderSettingsControl *>(m_camera->service()->requestControl("org.qt-project.qt.cameraviewfindersettingscontrol/5.0"));
    set->setViewfinderParameter(QCameraViewfinderSettingsControl::Resolution, m_frameSize);

    m_camera->start();
}

void Webcam::stop()
{
    m_camera->stop();
}

void Webcam::paint(QPainter *painter)
{
    if (painter)
    {
        if (m_currentFrame.isNull())
        {
            painter->fillRect(boundingRect(), Qt::darkRed);
        }
        else
        {
            painter->drawPixmap(boundingRect().toRect(), m_currentFrame);
//            painter->drawImage(boundingRect(), m_currentImage.mirrored(false,true) );
        }
    }
}

void Webcam::setframeSize(QSize res)
{
    if(res.isValid())
    {
        m_frameSize = res;
        m_camera->stop();
        QCameraViewfinderSettingsControl *set = qobject_cast<QCameraViewfinderSettingsControl *>(m_camera->service()->requestControl("org.qt-project.qt.cameraviewfindersettingscontrol/5.0"));
        set->setViewfinderParameter(QCameraViewfinderSettingsControl::Resolution, m_frameSize);
        m_camera->start();
    }
}


void Webcam::frameReady()
{
    m_currentFrame = QPixmap::fromImage(m_surface.frame());
//    m_currentImage = m_surface.frame();
    update();
}
