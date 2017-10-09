#ifndef GRAFIC_H
#define GRAFIC_H
#include <QGLWidget>
#include<QPainter>
#include <GL/gl.h>
#include <GL/glu.h>
#define MAXCOUNTROUND 60;
class Grafic: public QWidget
{

public:

    Grafic(QWidget *parent = 0);
   void paintEvent(QPaintEvent *p);
   void paintQuads();
   void paintRounds();
   void paintTriangle();
   QPainter *painter;
  float radius=85;
  float fia=0.01;
  float alpha,alphaNext;
  int roundCount=5, quadsCount=10, triangleCount=5;


};

#endif // GRAFIC_H
