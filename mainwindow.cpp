#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QDateTime>
#include <QPixmap>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList vlc_args = VlcCommon::args();
    vlc_args << "--network-caching=150";

    instance = new VlcInstance(vlc_args, this);
    player = new VlcMediaPlayer(instance);
    player2 = new VlcMediaPlayer(instance);
    urlPlayer = "rtsp://admin:admin@192.168.1.10/1";
    urlPlayer2 = "rtsp://admin:admin@192.168.1.168/1";
    media = new VlcMedia("rtsp://admin:admin@192.168.1.10/1", instance);
    media2 = new VlcMedia("rtsp://admin:admin@192.168.1.168/1", instance);
    mediaPlayer = media;
    mediaPlayer2 = media2;
    player->setVideoWidget(ui->widget);
    player2->setVideoWidget(ui->widget_2);
    ui->radioButton->setChecked(true);
    ui->radioButton_4->setChecked(true);
    player->open(media);
    player2->open(media2);

    connect(player, SIGNAL(error()), this, SLOT(reconnect()));
    connect(player, SIGNAL(end()), this, SLOT(reconnect()));
    connect(player2, SIGNAL(error()), this, SLOT(reconnect2()));
    connect(player2, SIGNAL(end()), this, SLOT(reconnect2()));
}

MainWindow::~MainWindow()
{
    delete player;
    delete player2;
    delete media;
    delete media2;
    delete instance;
    delete instance2;
    delete ui;
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    player->stop();
    if(checked){
        player->openOnly(media);
        player->play();
        mediaPlayer = media;
        urlPlayer = "rtsp://admin:admin@192.168.1.10/1";
    }

}

void MainWindow::on_radioButton_2_clicked(bool checked)
{
    player->stop();
    if(checked){
        player->openOnly(media2);
        player->play();
        mediaPlayer = media2;
        urlPlayer = "rtsp://admin:admin@192.168.1.168/1";
    }
}

void MainWindow::on_radioButton_3_clicked(bool checked)
{
    player2->stop();
    if(checked){
        player2->openOnly(media);
        player2->play();
        mediaPlayer2 = media;
        urlPlayer2 = "rtsp://admin:admin@192.168.1.10/1";

    }
}

void MainWindow::on_radioButton_4_clicked(bool checked)
{
    player2->stop();
    if(checked){
        player2->openOnly(media2);
        player2->play();
        mediaPlayer2 = media2;
        urlPlayer2 = "rtsp://admin:admin@192.168.1.168/1";
    }
}


void MainWindow::reconnect(){

    if (player->state() == Vlc::Error || player->state() == Vlc::Ended)
    {
        player->open(mediaPlayer);
    }
}

void MainWindow::reconnect2(){

    if(player2->state() == Vlc::Error || player2->state() == Vlc::Ended){
        player2->open(mediaPlayer2);
    }
}



//void MainWindow::on_pushButton_toggled(bool checked)
//{
//    QProcess* process = new QProcess(this);
//    QDir dir("b:/Videos/");

//    if(!dir.exists()){
//        QDir().mkdir("b:/Videos/");
//    }

//    QString fileName = "b:/Videos/" + QDateTime::currentDateTime().toString("dd-MM-yy_hh-mm-ss") + ".avi";
//    if(checked){
//    process->start("ffmpeg -i "+urlPlayer+"b:/Videos/ -vcodec copy -acodec copy -y "+fileName);
//    ui->pushButton->setText("STOP");
//    } else {
//        process->close();
//        delete process;
//        ui->pushButton->setText("START");
//    }

//}

void MainWindow::on_pushButton_clicked()
{
//    QProcess* process = new QProcess(this);
//    QDir dir("b:/Videos/");

//    if(!dir.exists()){
//        QDir().mkdir("b:/Videos/");
//    }

//    QString fileName = "b:/Videos/" + QDateTime::currentDateTime().toString("dd-MM-yy_hh-mm-ss") + ".mp4";
//    if(checked){
//    process->start("ffmpeg -i rtsp://admin:admin@192.168.1.10/1 -c:v copy -an -f mp4 b:/Videos/output.mp4");
//    ui->pushButton->setText("STOP");
//    } else {
//        process->close();
//        delete process;
//        ui->pushButton->setText("START");
//    }

}
