#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QString>
#include <QMap>
#include <QFile>

#include <registers.h>
#include <flags.h>
#include <ram.h>

class Instruction;
class QStandardItemModel;
class QTextStream;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
signals:
    void ACCChanged(int newVal);

public:
    explicit MainWindow(std::string parameter, QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_Run_clicked();

    void on_logging_clicked(bool checked);

    void on_MemoryWrite_clicked();

    void on_LoadFile_clicked();

private:
    Ui::MainWindow *ui;
    QString fileName_;
    QStandardItemModel* memoryModel_;
    QList<QString> input_;
    RAM RAM_;
    Registers registers_;
    Flags flags_;
    QMap<int, Instruction*> instructions_;
    QFile logger_;
    Instruction* factory(int index, int parameter);
    bool logToFile_;
    bool testMode_;
    void updateGUI();
    void runInBatchTestMode();
    void outputToLog(QTextStream& destination, const Token* current);
    bool processToken();
};

#endif // MAINWINDOW_H
