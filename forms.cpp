#include "forms.h"
#include "ui_forms.h"
#include <QTimer>
Forms::Forms(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Forms)
{
    ui->setupUi(this);
    QTimer *time = new QTimer();
    time->start(10);
    connect(time,SIGNAL(timeout()),this,SLOT(Repaint()));
}

Forms::~Forms()
{
    delete ui;
}


void Forms::Repaint()
{
    ui->widget->fia+=0.03;
    ui->widget->repaint();
    ui->widget->radius=(this->width()+this->height())/16;
}


void Forms::moreQuads(int n)
{
    ui->widget->roundCount=n;
    ui->widget->repaint();
}

void Forms::moreRounds(int n)
{
    ui->widget->quadsCount=n;
    ui->widget->repaint();
}

void Forms::moreTriangules(int n)
{
    ui->widget->triangleCount=n;
    ui->widget->repaint();
}
