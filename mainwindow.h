#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QString>
#include <QMap>

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
    void on_pushButton_clicked();

    void on_Run_clicked();

private:
    Ui::MainWindow *ui;
    QString fileName_;

    QList<QString> input_;
    QVector<bool> RAM_;
    QMap<QString, unsigned int> registers_;

};

#endif // MAINWINDOW_H
