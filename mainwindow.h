#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_radioButton_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_3_clicked(bool checked);

    void on_radioButton_4_clicked(bool checked);

    void reconnect();

    void reconnect2();





    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    VlcInstance* instance;
    VlcInstance* instance2;
    VlcMedia *media;
    VlcMedia *media2;
    VlcMedia *mediaPlayer;
    VlcMedia *mediaPlayer2;
    VlcMediaPlayer *player;
    VlcMediaPlayer *player2;
    QString urlPlayer;
    QString urlPlayer2;
};

#endif // MAINWINDOW_H
