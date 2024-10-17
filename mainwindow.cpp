#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <QDebug>
int curr_val = 0;
std::vector<QString> CALC;
Ui::MainWindow* ui_;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui_ = ui;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// Assuming CALC is a std::vector<QString> and curr_val is a valid index

void addVal(QString v) {
    if (curr_val >= 0 && static_cast<size_t>(curr_val) < CALC.size()) {
        // If the element at CALC[curr_val] is empty, create a new element
        if (CALC[curr_val].isEmpty()) {
            CALC[curr_val] = v;
        } else {
            // If the element is not empty, append to it
            CALC[curr_val] += v;
        }
    } else {
        // Handle invalid index or other conditions
        // You may want to throw an exception, return an error code, or take appropriate action.
    }
}

void modVal(char v) {
    // Increment curr_val
    curr_val++;

    // Check if curr_val is within the bounds of CALC
    if (curr_val < int(CALC.size())) {
        // Assign QString representation of char to CALC[curr_val]
        CALC[curr_val] = QString(v);

        // Increment curr_val again
        curr_val++;
    } else {
        // Handle the case where curr_val is out of bounds
        // You may want to throw an exception, return an error code, or take appropriate action.
    }
}
int calculateResult() {
    int result = 0;
    ui_->DISP_RESULT->setPlainText("Fuck");
    for (int i = 0; i < CALC.size(); i +2) {
        qDebug() << "Debugging information: " << CALC[i];

        if (i + 1 < CALC.size()) {
            bool conversionOk;
            int operand = CALC[i + 1].toInt(&conversionOk);

            if (!conversionOk) {
                // Handle error: unable to convert the operand to an int
                ui_->DISP_RESULT->setPlainText("Error: Invalid operand at index " + QString::number(i + 1));
                qDebug() << "Error: Invalid operand at index " + QString::number(i + 1);
                return 0;  // or another suitable error code
            }

            if (CALC[i] == "A") {
                result += operand;
            } else if (CALC[i] == "S") {
                result -= operand;
            } else if (CALC[i] == "M") {
                result *= operand;
            } else if (CALC[i] == "D") {
                if (operand != 0) {
                    result /= operand;
                } else {
                    // Handle error: division by zero
                    ui_->DISP_RESULT->setPlainText("Error: Division by zero at index " + QString::number(i + 1));
                    qDebug() << "Error: Division by zero at index " + QString::number(i + 1);
                    return 0;  // or another suitable error code
                }
            } else {
                // Handle error: unknown operation
                ui_->DISP_RESULT->setPlainText("Error: Unknown operation at index " + QString::number(i));
                qDebug() << "Error: Unknown operation at index " + QString::number(i);
                return 0;  // or another suitable error code
            }
        } else {
            // Handle error: missing operand for the last operation
            ui_->DISP_RESULT->setPlainText("Error: Missing operand for the operation at index " + QString::number(i));
            qDebug() << "Error: Missing operand for the operation at index " + QString::number(i);
            return 0;  // or another suitable error code
        }
    }

    // Clear any previous error message if there was one
    ui_->DISP_RESULT->setPlainText("");

    return result;
}
void MainWindow::on_META_CLEAR_clicked()
{
    ui->DISP_RESULT->clear();
    CALC.clear();
    curr_val = 0;
}

void MainWindow::on_SEVEN_clicked()
{
    addVal("7");
    ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + "7");
}

void MainWindow::on_EIGHT_clicked()
{
   addVal("8");
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + "8");
}

void MainWindow::on_NINE_clicked()
{
   addVal("9");
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + "9");
}

void MainWindow::on_FOUR_clicked()
{
   addVal("4");
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + "4");
}

void MainWindow::on_FIVE_clicked()
{
   addVal("5");
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + "5");
}

void MainWindow::on_SIX_clicked()
{
   addVal("6");
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + "6");
}

void MainWindow::on_THREE_clicked()
{
   addVal("3");
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + "3");
}

void MainWindow::on_TWO_clicked()
{
   addVal("2");
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + "2");
}

void MainWindow::on_ONE_clicked()
{
   addVal("1");
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + "1");
}

void MainWindow::on_ZERO_clicked()
{
   addVal("0");
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + "0");
}

void MainWindow::on_OP_ADD_clicked()
{
   modVal('A');
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + " + ");
}

void MainWindow::on_OP_SUBT_clicked()
{
   modVal('S');
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + " - ");
}

void MainWindow::on_OP_DIV_clicked()
{
   modVal('D');
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + " / ");
}

void MainWindow::on_OP_MULT_clicked()
{
   modVal('M');
   ui->DISP_RESULT->setPlainText(ui->DISP_RESULT->toPlainText() + " x ");
}

void MainWindow::on_META_EQU_clicked()
{
    const int result = calculateResult();
    ui->DISP_RESULT->setPlainText(QString::number(result));
}
