#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "complex.h"

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

    QString errorString = "<font style='color:red'>ERRORS:</font>";
    bool errorBool = false;
    bool compareBool = false;
    bool toDoubleBool = false;

    for (int i = 1; i <= 12; i++) {
        QRadioButton* operatorButton = findChild<QRadioButton*>("radioButton_" + QString::number(i));

        if (operatorButton == 0) {
            errorString += "<br>Can't find the operator";
            errorBool = true;
            break;
        }

        if (operatorButton->isChecked()) {
            int AX = ui->AXbeforeLineEdit->text().toDouble(&toDoubleBool);
            if (!toDoubleBool) {
                errorString += "<br>Ax is not a number!";
                errorBool = true;
            }
            int AY = ui->AYbeforeLineEdit->text().toInt(&toDoubleBool);
            if (!toDoubleBool) {
                errorString += "<br>Ay is not a number!";
                errorBool = true;
            }
            int BX = ui->BXbeforeLineEdit->text().toInt(&toDoubleBool);
            if (!toDoubleBool) {
                errorString += "<br>Bx is not a number!";
                errorBool = true;
            }
            int BY = ui->BYbeforeLineEdit->text().toInt(&toDoubleBool);
            if (!toDoubleBool) {
                errorString += "<br>By is not a number!";
                errorBool = true;
            }

            Complex A(AX, AY),
                    B(BX, BY),
                    C;

            int AincrNumber = 0;
            int BincrNumber = 0;

            for (int j = 0; j < 5; j++) {
                QRadioButton* AincrButton = findChild<QRadioButton*>("AincrRadioButton_" + QString::number(j));
                QRadioButton* BincrButton = findChild<QRadioButton*>("BincrRadioButton_" + QString::number(j));

                if (AincrButton->isChecked()) {
                    AincrNumber = j;
                    //break;
                }
                if (BincrButton->isChecked()) {
                    BincrNumber = j;
                    //break;
                }
            }

            if (AincrNumber == 3) ++A;
            if (BincrNumber == 3) ++B;
            if (AincrNumber == 4) --A;
            if (BincrNumber == 4) --B;

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
            case 4: // /
                C = A / B;
                break;
            case 5: // +=
                A += B;
                break;
            case 6: // -=
                A -= B;
                break;
            case 7: // *=
                A *= B;
                break;
            case 8: // /=
                A /= B;
                break;
            case 9: // <
                compareBool = A<B ? true : false;
                break;
            case 10: // >
                compareBool = A>B ? true : false;
                break;
            case 11: // <=
                compareBool = A<=B ? true : false;
                break;
            case 12: // >=
                compareBool = A>=B ? true : false;
                break;
            }

            if (AincrNumber == 1) A++;
            if (BincrNumber == 1) B++;
            if (AincrNumber == 2) A--;
            if (BincrNumber == 2) B--;

            if (errorBool == true) {
                ui->errorLabel->setText(errorString);
            }
            else {
                ui->AXafterLineEdit->setText(QString::number(A.getRe()));
                ui->AYafterLineEdit->setText(QString::number(A.getIm()));
                ui->BXafterLineEdit->setText(QString::number(B.getRe()));
                ui->BYafterLineEdit->setText(QString::number(B.getIm()));
                if (i >= 1 && i <=8) {
                    ui->CXLineEdit->setText(QString::number(C.getRe()));
                    ui->CYLineEdit->setText(QString::number(C.getIm()));
                }
                else if (i >= 9 && i <= 12){
                    if (compareBool == true) {
                        ui->errorLabel->setText("<p style='color:green'>TRUE</p>");
                    }
                    else {
                        ui->errorLabel->setText("<p style='color:red'>FALSE</p>");
                    }
                }
            }

            break;
        }
    }
}
