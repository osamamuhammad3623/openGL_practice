#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "square.h"

Square square;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_btn_clicked()
{
    exit(0);
}


void MainWindow::on_up_clicked()
{
    square.y_pos += 1;
}

void MainWindow::on_down_clicked()
{
    square.y_pos -= 1;
}

void MainWindow::on_faster_clicked()
{
    square.speed += 0.1;
}

void MainWindow::on_slower_clicked()
{
    square.speed -= 0.1;
}
