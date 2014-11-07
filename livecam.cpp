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
  load();
  start();

  /*
  QCameraCaptureBufferFormatControl *cap = qobject_cast<QCameraCaptureBufferFormatControl *>(service()->requestControl("org.qt-project.qt.cameracapturebufferformatcontrol/5.0"));
  qDebug() << cap->bufferFormat();
  cap->setBufferFormat(QVideoFrame::Format_YUYV);
  qDebug() << cap->bufferFormat();


  QCameraViewfinderSettingsControl *set = qobject_cast<QCameraViewfinderSettingsControl *>(service()->requestControl("org.qt-project.qt.cameraviewfindersettingscontrol/5.0"));
  for(int x=0; x<10; x++)
      qDebug() << x << set->isViewfinderParameterSupported((QCameraViewfinderSettingsControl::ViewfinderParameter)x);
  set->setViewfinderParameter(QCameraViewfinderSettingsControl::Resolution, QSize(1280,720));
  set->setViewfinderParameter(QCameraViewfinderSettingsControl::PixelFormat, QVideoFrame::Format_YV12);
  qDebug() << set->viewfinderParameter(QCameraViewfinderSettingsControl::Resolution);
  qDebug() << set->viewfinderParameter(QCameraViewfinderSettingsControl::PixelFormat);

  QCameraControl *ctrl = qobject_cast<QCameraControl *>(service()->requestControl("org.qt-project.qt.cameracontrol/5.0"));
  qDebug() << ctrl->state();
  for(int x=0; x<10; x++)
      qDebug() << x << ctrl->canChangeProperty((QCameraControl::PropertyChangeType)x, this->status());


  QImageEncoderControl *img = qobject_cast<QImageEncoderControl *>(service()->requestControl("org.qt-project.qt.imageencodercontrol/5.0"));
  qDebug() << img->imageSettings().codec();

//  QVideoEncoderSettingsControl *vctrl = qobject_cast<QVideoEncoderSettingsControl *>(service()->requestControl("org.qt-project.qt.videoencodersettingscontrol/5.0"));
  QVideoEncoderSettingsControl *vctrl = service()->requestControl<QVideoEncoderSettingsControl*>();
  qDebug() << vctrl->videoSettings().bitRate() << vctrl->supportedVideoCodecs();
  qDebug() << vctrl->videoSettings().frameRate() << vctrl->videoSettings().resolution();

  QVideoEncoderSettings sets = vctrl->videoSettings();
  sets.setResolution(160, 120);
*/



//  setVideoOutput(m_surface);
}

QAbstractVideoSurface* LiveCam::getVideoSurface()
{
  return m_surface;
}

void LiveCam::snap()
{
   QCameraImageCapture cap(this);
   qDebug() << cap.captureDestination();


   cap.capture();
}
