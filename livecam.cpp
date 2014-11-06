#include "livecam.h"

LiveCam::LiveCam(QObject *parent) :
    QCamera(parent)
{
}

void LiveCam::setVideoSurface(QAbstractVideoSurface* surface)
{
  qDebug() << "Changing surface: " << surface->supportedPixelFormats();
  m_surface = surface;
  setViewfinder(m_surface);

//  QVideoEncoderSettingsControl *enc = service()->requestControl<QVideoEncoderSettingsControl*>();
//  QVideoEncoderSettings sets = enc->videoSettings();
//  sets.setResolution(100, 100);
//  enc->setVideoSettings(sets);
//  load();
  start();
  QCameraViewfinderSettingsControl *set = qobject_cast<QCameraViewfinderSettingsControl *>(service()->requestControl("org.qt-project.qt.cameraviewfindersettingscontrol/5.0"));
  qDebug() << set->viewfinderParameter(QCameraViewfinderSettingsControl::Resolution);

//  setVideoOutput(m_surface);
}

QAbstractVideoSurface* LiveCam::getVideoSurface()
{
  return m_surface;
}
