#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_META_CLEAR_clicked();

    void on_SEVEN_clicked();

    void on_EIGHT_clicked();

    void on_NINE_clicked();

    void on_FOUR_clicked();

    void on_FIVE_clicked();

    void on_SIX_clicked();

    void on_THREE_clicked();

    void on_TWO_clicked();

    void on_ONE_clicked();

    void on_ZERO_clicked();

    void on_OP_ADD_clicked();

    void on_OP_SUBT_clicked();

    void on_OP_DIV_clicked();

    void on_OP_MULT_clicked();

    void on_META_EQU_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
