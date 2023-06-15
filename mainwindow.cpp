#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList vlc_args = QStringList();
    instance = new VlcInstance(vlc_args, this);
    instance2 = new VlcInstance(vlc_args, this);
    player = new VlcMediaPlayer(instance);
    player2 = new VlcMediaPlayer(instance2);
    media = new VlcMedia("rtsp://admin:admin@192.168.1.10/1", instance);
    media2 = new VlcMedia("rtsp://admin:admin@192.168.1.168/1", instance2);
    player->setVideoWidget(ui->widget);
    player2->setVideoWidget(ui->widget_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    player->open(media);
}

void MainWindow::on_radioButton_2_clicked(bool checked)
{
    player->open(media2);
}

void MainWindow::on_radioButton_3_clicked(bool checked)
{
    player2->open(media);
}

void MainWindow::on_radioButton_4_clicked(bool checked)
{
    player2->open(media2);
}
