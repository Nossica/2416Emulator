#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <parser.hpp>
#include <instruction.hpp>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fileName_.clear();
    //RAM_.fill(false, 32767);

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
        int index = 0;
        PARSE_STATE currentState = VALID_FIELD;
        do {
            int instruction, parameter;
            // need to set up an object per instruction
            currentState = theParser.parse(instruction, parameter);

            if (currentState == VALID_FIELD) {
                // we now have the instruction and parameter to create the object
                Instruction* temp = factory(instruction, parameter);
                if (temp) {
                    instructions_[index] = temp;
                    ++index;
                }
            }
        }
        while (currentState != FILE_END);

        QStandardItemModel* model = new QStandardItemModel(instructions_.size(), 2, this);
        model->setHorizontalHeaderItem(0, new QStandardItem(QString("Instruction")));
        model->setHorizontalHeaderItem(1, new QStandardItem(QString("Parameter")));
//        model->setHorizontalHeaderItem(2, new QStandardItem(QString("Hex value")));
        ui->theProgram->setModel(model);

        for(int row = 0; row < instructions_.size(); row++) {
            QStandardItem *firstCol = new QStandardItem(instructions_[row]->getName());
            QStandardItem *secondCol = new QStandardItem(instructions_[row]->getParameter());

            model->setItem(row,0,firstCol);
            model->setItem(row,1,secondCol);
        }
    }
}

void MainWindow::on_Run_clicked() {
    //for (auto it = )
    //registers_["ACC"] = 1;
    do {
        instructions_[RAM_.current_]->execute();
    } while(1);
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

Instruction* MainWindow::factory(int index, int parameter) {
    switch (index){
        default:
        return NULL;

    case (0):
        return new JMP(parameter, registers_, flags_, RAM_);
    case (11):
        return new JPZ(parameter, registers_, flags_, RAM_);
    case (14):
        return new JPC(parameter, registers_, flags_, RAM_);
    case (7):
        return new JNZ(parameter, registers_, flags_, RAM_);
    case (10):
        return new JPE(parameter, registers_, flags_, RAM_);
    case (15):
        return new NOP(parameter, registers_, flags_, RAM_);
    case (63):
        return new DO(parameter, registers_, flags_, RAM_);
    case (64):
        return new DEC(parameter, registers_, flags_, RAM_);
    case (70):
        return new SUC(parameter, registers_, flags_, RAM_);
    case (73):
        return new ADD(parameter, registers_, flags_, RAM_);
    case (76):
        return new ASL(parameter, registers_, flags_, RAM_);
    case (79):
        return new NOF(parameter, registers_, flags_, RAM_);
    case (80):
        return new INV(parameter, registers_, flags_, RAM_);
    case (81):
        return new NAN(parameter, registers_, flags_, RAM_);
    case (83):
        return new SET(parameter, registers_, flags_, RAM_);
    case (85):
        return new LDC(parameter, registers_, flags_, RAM_);
    case (89):
        return new XOR(parameter, registers_, flags_, RAM_);
    case (90):
        return new LDA(parameter, registers_, flags_, RAM_);
    case (91):
        return new IOR(parameter, registers_, flags_, RAM_);
    case (92):
        return new CLR(parameter, registers_, flags_, RAM_);
    case (94):
        return new AND(parameter, registers_, flags_, RAM_);
    case (102):
        return new SUB(parameter, registers_, flags_, RAM_);
    case (105):
        return new ADI(parameter, registers_, flags_, RAM_);
    case (108):
        return new SFI(parameter, registers_, flags_, RAM_);
    case (111):
        return new INC(parameter, registers_, flags_, RAM_);
  }
}
