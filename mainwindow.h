#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <forms.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString str;
    Forms *fm;
private slots:
    void on_pushButton_clicked();
    
    void on_horizontalSlider_actionTriggered(int action);

    void on_pushButton_2_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_quadsButton_clicked();

    void on_roundButton_clicked();

    void on_TriangleButton_clicked();

    void on_MainWindow_iconSizeChanged(const QSize &iconSize);

private:
    Ui::MainWindow *ui;
public slots:
    void Repaint();
};

#endif // MAINWINDOW_H
