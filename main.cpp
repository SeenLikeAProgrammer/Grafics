#include "mainwindow.h"
#include <QApplication>
#include <forms.h>
#include <grafic.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 // Forms *fm = new Forms();
    MainWindow *gr=new MainWindow();
       gr->show();
     //  fm->show();
    return a.exec();
}
