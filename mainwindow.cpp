#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <parser.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileName_.clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    fileName_ = QFileDialog::getOpenFileName(this,
        tr("Open input file"), "", tr("2416E Files (*.vnp)"));
}

void MainWindow::on_Run_clicked()
{
    //if (fileName_.) {
        Parser theParser(fileName_);
        //input_ = theParser.parse();
        theParser.parse(input_);
        ui->program->addItems(input_);
    //}
}
