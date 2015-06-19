#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QString>
#include <QMap>

#include <ram.h>

class Instruction;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
signals:
    void ACCChanged(int newVal);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

    void on_Run_clicked();

private:
    Ui::MainWindow *ui;
    QString fileName_;

    QList<QString> input_;
    RAM RAM_;
    QMap<QString, unsigned int> registers_;
    QMap<QString, bool> flags_;
    QMap<int, Instruction*> instructions_;

    Instruction* factory(int index, int parameter);

    void updateGUI();
};

#endif // MAINWINDOW_H
