#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <grafic.h>
#include <QMessageBox>
#include <QTimer>
#include <QtMultimedia/QAudio>
#include <QSound>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    fm = new Forms();
    ui->setupUi(this);
    QTimer *time = new QTimer();
    time->start(10);
    connect(time,SIGNAL(timeout()),this,SLOT(Repaint()));
    fm->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
 }

void MainWindow::on_horizontalSlider_actionTriggered(int action)
{

}

void MainWindow::on_pushButton_2_clicked()
{
}
void MainWindow::Repaint()
{

}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{


}

void MainWindow::on_quadsButton_clicked()
{
fm->moreQuads(ui->QuadsEdit->text().toInt());
}

void MainWindow::on_roundButton_clicked()
{
fm->moreRounds(ui->RoundEdit->text().toInt());


}

void MainWindow::on_TriangleButton_clicked()
{
  fm->moreTriangules(ui->TriangleEdit->text().toInt());
  fm->repaint();
}

void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{

}
