#ifndef FORMS_H
#define FORMS_H

#include <QMainWindow>
#include <grafic.h>
#include <QString>
namespace Ui {
class Forms;
}

class Forms : public QMainWindow
{
    Q_OBJECT

public:
    explicit Forms(QWidget *parent = 0);
    ~Forms();
    void moreTriangules(int n);
    void moreQuads(int n);
    void moreRounds(int n);

private:
    Ui::Forms *ui;

public slots:
    void Repaint();
};

#endif // FORMS_H
