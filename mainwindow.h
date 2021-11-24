#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <imgproc.h>
#include <QDir>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void imgReady(QString name);

private:
    Ui::MainWindow *ui;
    QVector<ImgProc*> threads;//Указатели на потоки

    QDir dir;//Рабочая папка
};
#endif // MAINWINDOW_H
