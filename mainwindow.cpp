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

    QString errorString = "<p style='color:red'>ERRORS:</p>";
    int errorCount = 0;

    for (int i = 1; i <= 12; i++) {
        QRadioButton* operatorButton = findChild<QRadioButton*>("radioButton_" + QString::number(i));

        if (operatorButton == 0) {
            errorString += "<br>Can't find the operator";
            errorCount++;
            break;
        }

        if (operatorButton->isChecked()) {
            int AX = ui->AXbeforeLineEdit->text().toInt();
            if (!AX) {
                errorString += "<br>Ax is not a number!";
                errorCount++;
            }
            int AY = ui->AYbeforeLineEdit->text().toInt();
            if (!AY) {
                errorString += "<br>Ay is not a number!";
                errorCount++;
            }
            int BX = ui->BXbeforeLineEdit->text().toInt();
            if (!BX) {
                errorString += "<br>Bx is not a number!";
                errorCount++;
            }
            int BY = ui->BYbeforeLineEdit->text().toInt();
            if (!BY) {
                errorString += "<br>By is not a number!";
                errorCount++;
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
            }

            if (AincrNumber == 1) A++;
            if (BincrNumber == 1) B++;
            if (AincrNumber == 2) A--;
            if (BincrNumber == 2) B--;

            if (errorCount > 0) {
                ui->errorLabel->setText(errorString);
            }

            ui->AXafterLineEdit->setText(QString::number(A.getRe()));
            ui->AYafterLineEdit->setText(QString::number(A.getIm()));
            ui->BXafterLineEdit->setText(QString::number(B.getRe()));
            ui->BYafterLineEdit->setText(QString::number(B.getIm()));
            ui->CXLineEdit->setText(QString::number(C.getRe()));
            ui->CYLineEdit->setText(QString::number(C.getIm()));
            break;
        }
    }
}
