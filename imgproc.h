#ifndef IMGPROC_H
#define IMGPROC_H

#include <QThread>
#include <QImage>

class ImgProc: public QThread
{
    Q_OBJECT
public:
    explicit ImgProc(QString name, QString path);
    void run() override;
signals:
    void ready(QString name);//Готовность изображения
private:
    QString path;//Путь к картинке
    QString name;//Название потока
    QImage image;//Картинка
};

#endif // IMGPROC_H
