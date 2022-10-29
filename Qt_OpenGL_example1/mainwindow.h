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
    void on_exit_btn_clicked();

    void on_up_clicked();

    void on_slower_clicked();

    void on_down_clicked();

    void on_faster_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
