#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString path = "C:\\tmp\\1";
    ext = "*.png";
    dir = QDir(path);
    qDebug() << "Files number: " << dir.count();
    ui->label->setText(QString::number(dir.count()));
    foreach(QString path, dir.entryList(QStringList(ext))){
        ui->listWidget->addItem(path);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::imgReady(QString name)
{
    qDebug() << name << " ready!";
    N+=1;
    int p = N/dir.count() * 100;
    ui->progressBar->setValue(p);
}


void MainWindow::on_pushButton_clicked()
{
    N=0;
    ui->progressBar->setEnabled(true);
    //Запуск потоков обработки изображений
    foreach(QString path, dir.entryList(QStringList(ext))){
        ImgProc *imgProc = new ImgProc(path,dir.path()+"\\"+path);
        connect(imgProc,SIGNAL(ready(QString)),this,SLOT(imgReady(QString)));
        imgProc->start();
        threads.append(imgProc);

    }
}
