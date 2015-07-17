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
    ui->theProgram->verticalHeader()->setVisible(false);

    fileName_.clear();
    updateGUI();
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
                    //////////////////////
                    // TODO
                    // this needs to update the actual RAM rather than the instructions
                    //////////////////////
                    instructions_[index] = temp;
                    ++index;
                }
            }
        }
        while (currentState != FILE_END);

        QStandardItemModel* model = new QStandardItemModel(instructions_.size(), 3, this);
        model->setHorizontalHeaderItem(0, new QStandardItem(QString("Index")));
        model->setHorizontalHeaderItem(1, new QStandardItem(QString("Instruction")));
        model->setHorizontalHeaderItem(2, new QStandardItem(QString("Parameter")));
        ui->theProgram->setModel(model);

        for(int row = 0; row < instructions_.size(); row++) {
            QStandardItem *firstCol = new QStandardItem(QString::number(row));
            QStandardItem *secondCol = new QStandardItem(instructions_[row]->getName());
            QStandardItem *thirdCol = new QStandardItem(instructions_[row]->getParameter());

            model->setItem(row,0,firstCol);
            model->setItem(row,1,secondCol);
            model->setItem(row,2,thirdCol);
        }
    }
    updateGUI();
}

void MainWindow::on_Run_clicked() {
   // do {
        if (instructions_[RAM_.getCurrent()] == NULL)
            return;

        if (instructions_[RAM_.getCurrent()]->execute())
            RAM_.setCurrent(RAM_.getCurrent()+1);
        updateGUI();
    //} while(1);
}

void MainWindow::updateGUI() {
    ui->ACC->setText(QString::number(registers_.getACC()));
    ui->ALU->setText(QString::number(registers_.getALU()));
    ui->Carry->setText(QString::number(flags_.getCarry()));
    ui->Zero->setText(QString::number(flags_.getZero()));
    ui->RAR->setText(QString::number(RAM_.getRAR()));
    ui->theProgram->selectRow(RAM_.getCurrent());
}

Instruction* MainWindow::factory(int index, int parameter) {
    switch (index){
        default:
        return NULL;

    case (0x00):
        return new JMP(parameter, registers_, flags_, RAM_);
    case (0x30):
        return new RJMP(parameter, registers_, flags_, RAM_);
    case (0x0B):
        return new JPZ(parameter, registers_, flags_, RAM_);
    case (0x3B):
        return new RJPZ(parameter, registers_, flags_, RAM_);
    case (0x0E):
        return new JPC(parameter, registers_, flags_, RAM_);
    case (0x3E):
        return new NJPC(parameter, registers_, flags_, RAM_);
    case (0x0D):
        return new JNC(parameter, registers_, flags_, RAM_);
    case (0x3D):
        return new RJNC(parameter, registers_, flags_, RAM_);
    case (0x07):
        return new JNZ(parameter, registers_, flags_, RAM_);
    case (0x37):
        return new RJNZ(parameter, registers_, flags_, RAM_);
    case (0x0A):
        return new JPE(parameter, registers_, flags_, RAM_);
    case (0x3A):
        return new RJPE(parameter, registers_, flags_, RAM_);
    case (0x0F):
        return new NOP(parameter, registers_, flags_, RAM_);
    case (0x3F):
        return new DO(parameter, registers_, flags_, RAM_);
    case (0x40):
        return new DEC(parameter, registers_, flags_, RAM_);
    case (0x46):
        return new SUC(parameter, registers_, flags_, RAM_);
    case (0x49):
        return new ADD(parameter, registers_, flags_, RAM_);
    case (0x4C):
        return new ASL(parameter, registers_, flags_, RAM_);
    case (0x4F):
        return new NOF(parameter, registers_, flags_, RAM_);
    case (0x50):
        return new INV(parameter, registers_, flags_, RAM_);
    case (0x51):
        return new NAN(parameter, registers_, flags_, RAM_);
    case (0x52):
        return new SET(parameter, registers_, flags_, RAM_);
    case (0x54):
        return new LDC(parameter, registers_, flags_, RAM_);
    case (0x59):
        return new XOR(parameter, registers_, flags_, RAM_);
    case (0x5A):
        return new LDA(parameter, registers_, flags_, RAM_);
    case (0x5B):
        return new IOR(parameter, registers_, flags_, RAM_);
    case (0x5C):
        return new CLR(parameter, registers_, flags_, RAM_);
    case (0x5E):
        return new AND(parameter, registers_, flags_, RAM_);
    case (0x66):
        return new SUB(parameter, registers_, flags_, RAM_);
    case (0x69):
        return new ADI(parameter, registers_, flags_, RAM_);
    case (0x6C):
        return new SFI(parameter, registers_, flags_, RAM_);
    case (0x6F):
        return new INC(parameter, registers_, flags_, RAM_);
    case (0x80):
        return new STA(parameter, registers_, flags_, RAM_);
    case (0xB0):
        return new RSTA(parameter, registers_, flags_, RAM_);
    }
}
