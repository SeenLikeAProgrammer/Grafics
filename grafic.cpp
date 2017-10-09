#include "grafic.h"
#include <math.h>

#include <mainwindow.h>
Grafic::Grafic(QWidget *parent): QWidget(parent)
{
  QPainter paint;
  QPointF p1,p2;

}

void Grafic::paintEvent(QPaintEvent *p)
{

   painter=new QPainter(this);
    painter->setPen(Qt::black);
  //  painter.setBrush(Qt::yellow);

    QPoint pMiddle;
   // p0.setX(width()/2);
  //  p0.setY(height()/2+87.5);
    pMiddle.setX(width()/2);
    pMiddle.setY(height()/2);
    // painter.setBrush(color);
   painter->drawEllipse(pMiddle,radius,radius);
    painter->drawEllipse(pMiddle,1.5*radius,1.5*radius);
    painter->drawEllipse(pMiddle,2*radius,2*radius);
     painter->drawEllipse(pMiddle,2.5*radius,2.5*radius);
    painter->drawText(rect(), Qt::AlignCenter, "Lab_1");
    paintRounds();
    paintQuads();
    paintTriangle();
}




void Grafic::paintRounds()
{
    QPoint p0,pNext;

    //QRect p0,pNext;
    p0.setX(width()/2);
    p0.setY(height()/2-9*radius/4);
 //  painter->drawEllipse(p0,radius/4,radius/4);
    alpha=2*M_PI/roundCount;
    alphaNext=0;
    painter->setPen(Qt::red);
    if (roundCount>28)
        return;
    else
    {
        for (int i=1; i<roundCount+1; i++)
        {

            pNext.setX(p0.x()-(9*radius/4)*sin(alphaNext));
            pNext.setY(p0.y()+(9*radius/4)*(1-cos(alphaNext)));
            painter->setBrush(Qt::red);
            painter->drawEllipse(pNext,radius/4,radius/4);
            painter->setBrush(Qt::white);
            alphaNext+=alpha;
        }
    }
    painter->setPen(Qt::black);
}

void Grafic::paintQuads()
{

    int R=0,G=0,B=255;
    QPoint p0,pNext1,pNext2, pNext3, pNext4;
    QPoint p1,p2,p3,p4;
    p0.setX(width()/2);
    p0.setY(height()/2);
    float fi = 2*M_PI/quadsCount;
    float fiNext = 0;
    p1.setX(p0.x()+sqrt(2)*radius/8);
    p1.setY(p0.y()-sqrt(2)*radius/8-5*radius/4);

    p2.setX(p0.x()+sqrt(2)*radius/8);
    p2.setY(p0.y()+sqrt(2)*radius/8-5*radius/4);

    p4.setX(p0.x()-sqrt(2)*radius/8);
    p4.setY(p0.y()+sqrt(2)*radius/8-5*radius/4);

    p3.setX(p0.x()-sqrt(2)*radius/8);
    p3.setY(p0.y()-(5*radius/4-sqrt(2)*radius/8));

float r1,r2;
r1=sqrt((p1.x()-p0.x())*(p1.x()-p0.x())+(p1.y()-p0.y())*(p1.y()-p0.y()));
r2=sqrt((p3.x()-p0.x())*(p3.x()-p0.x())+(p3.y()-p0.y())*(p3.y()-p0.y()));

double psi1,psi2, psi3, psi4;
psi1=acos((p1.x()-p0.x())/r1);
psi2=acos((p3.x()-p0.x())/r2);
psi3=acos((p2.x()-p0.x())/r2);
psi4=acos((p4.x()-p0.x())/r1);
    if (quadsCount>28)
        return;
    else
    {
        for (int i=1; i<quadsCount+1; i++)
        {

            pNext1.setX(p0.x()+r1*cos(fiNext+psi1));
            pNext1.setY(p0.y()-r1*sin(fiNext+psi1));
            pNext2.setX(p0.x()+r2*cos(fiNext+psi2));
            pNext2.setY(p0.y()-r2*sin(fiNext+psi2));

            pNext3.setX(p0.x()+r2*cos(fiNext+psi3));
            pNext3.setY(p0.y()-r2*sin(fiNext+psi3));
            pNext4.setX(p0.x()+r1*cos(fiNext+psi4));
            pNext4.setY(p0.y()-r1*sin(fiNext+psi4));
            //painter->drawRect(QRectF(pNext1,pNext2));
            fiNext+=fi;
            QPolygon p;
            p.append(pNext2);
            p.append(pNext3);
            p.append(pNext1);
             p.append(pNext4);
             R+=255/quadsCount;
             B-=255/quadsCount;
             G+=255/quadsCount;
             painter->setBrush(QBrush(QColor(R,G,B)));

            painter->drawPolygon(p);
        painter->setBrush(Qt::white);
        }
    }


}

void Grafic::paintTriangle()
{

    QPoint p0,pNext1,pNext2, pNext3, pNext4;
    QPoint p1,p2,p3,p4;
    p0.setX(width()/2);
    painter->setPen(Qt::darkGreen);
    p0.setY(height()/2);
    float fi = 2*M_PI/triangleCount;
    float fiNext = 0;
    p1.setX(p0.x());//+sqrt(2)*radius/8);
    p1.setY(p0.y()-sqrt(2)*radius/8-7*radius/4);

    p2.setX(p0.x()+sqrt(2)*radius/8);
    p2.setY(p0.y()+sqrt(2)*radius/8-7*radius/4);

    //p4.setX(p0.x()-sqrt(2)*radius/8);
   // p4.setY(p0.y()+sqrt(2)*radius/8-7*radius/4);

    p3.setX(p0.x()-sqrt(2)*radius/8);
    p3.setY(p0.y()-(7*radius/4-sqrt(2)*radius/8));

float r1,r2;
r1=sqrt((p1.x()-p0.x())*(p1.x()-p0.x())+(p1.y()-p0.y())*(p1.y()-p0.y()));
r2=sqrt((p3.x()-p0.x())*(p3.x()-p0.x())+(p3.y()-p0.y())*(p3.y()-p0.y()));

double psi1,psi2, psi3, psi4;
psi1=acos((p1.x()-p0.x())/r1);
psi2=acos((p3.x()-p0.x())/r2);
psi3=acos((p2.x()-p0.x())/r2);
psi4=acos((p4.x()-p0.x())/r1);
psi1+=fia;
psi2+=fia;
psi3+=fia;
psi4+=fia;
    if (triangleCount>28)
        return;
    else
    {
        for (int i=1; i<triangleCount+1; i++)
        {

            pNext1.setX(p0.x()+r1*cos(fiNext+psi1));
            pNext1.setY(p0.y()-r1*sin(fiNext+psi1));
            pNext2.setX(p0.x()+r2*cos(fiNext+psi2));
            pNext2.setY(p0.y()-r2*sin(fiNext+psi2));

            pNext3.setX(p0.x()+r2*cos(fiNext+psi3));
            pNext3.setY(p0.y()-r2*sin(fiNext+psi3));
            pNext4.setX(p0.x()+r1*cos(fiNext+psi4));
            pNext4.setY(p0.y()-r1*sin(fiNext+psi4));
            //painter->drawRect(QRectF(pNext1,pNext2));
            fiNext+=fi;
            QPolygon p;
            p.append(pNext2);
            p.append(pNext3);
            p.append(pNext1);
          //  p.append(pNext4);
            painter->setBrush(Qt::yellow);
        painter->drawPolygon(p);
        painter->setBrush(Qt::white);
        }
    }

painter->setPen(Qt::black);
}
