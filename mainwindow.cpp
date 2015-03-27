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
    RAM_.fill(false, 32767);

    connect(ui->ALU, SIGNAL(textChanged()), this, SLOT(updateALU()));
    connect(ui->ACC, SIGNAL(textChanged()), this, SLOT(updateACC()));
    connect(ui->Carry, SIGNAL(textChanged()), this, SLOT(updateCarry()));
    connect(ui->Zero, SIGNAL(textChanged()), this, SLOT(updateZero()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    fileName_ = QFileDialog::getOpenFileName(this,
        tr("Open input file"), "", tr("2416E Files (*.vnp)"));

    if (fileName_.isEmpty() == false) {
        Parser theParser(fileName_);
        //input_ = theParser.parse();
        theParser.parse(input_);
        ui->program->addItems(input_);
    }
}

void MainWindow::on_Run_clicked()
{
    registers_["ACC"] = 1;
}

void MainWindow::updateALU() {
    registers_["ALU"] = ui->ALU->toPlainText().toInt(0,16);
}

void MainWindow::updateACC() {
    registers_["ACC"] = ui->ACC->toPlainText().toInt(0,16);
}

void MainWindow::updateZero() {
    flags_["Zero"] = ui->ALU->toPlainText().toInt(0,2);
}

void MainWindow::updateCarry() {
    flags_["Carry"] = ui->ALU->toPlainText().toInt(0,2);
}
