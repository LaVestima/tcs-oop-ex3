#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "complex.h"

//#define O+ 1

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    ui->errorLabel->setText("");
    ui->CXLineEdit->setText("");
    ui->CYLineEdit->setText("");
    ui->AXafterLineEdit->setText("");
    ui->AYafterLineEdit->setText("");
    ui->BXafterLineEdit->setText("");
    ui->BYafterLineEdit->setText("");

    for (int i = 1; i <= 12; i++) {
        QRadioButton* operatorButton = findChild<QRadioButton*>("radioButton_" + QString::number(i));
        if (operatorButton==0) {
            ui->errorLabel->setText("Error<br>Can't find the operator");
            break;
        }
        if (operatorButton->isChecked()) {
            int AX = ui->AXbeforeLineEdit->text().toInt();
            if (!AX) {
                ui->errorLabel->setText("Error<br>Ax not a number");
                break;
            }
            int AY = ui->AYbeforeLineEdit->text().toInt();
            if (!AY) {
                ui->errorLabel->setText("Error<br>Ay not a number");
                break;
            }
            int BX = ui->BXbeforeLineEdit->text().toInt();
            if (!BX) {
                ui->errorLabel->setText("Error<br>Bx not a number");
                break;
            }
            int BY = ui->BYbeforeLineEdit->text().toInt();
            if (!BY) {
                ui->errorLabel->setText("Error<br>By not a number");
                break;
            }

            Complex A(AX, AY),
                    B(BX, BY),
                    C;

            // ###
            switch (i) {
            case 1: // +
                C = A + B;
                break;
            case 2: // -
                C = A - B;
                break;
            case 3: // *
                C = A * B;
                break;
            }

            ui->CXLineEdit->setText(QString::number(C.getRe()));
            ui->CYLineEdit->setText(QString::number(C.getIm()));
            break;
        }
    }
}
