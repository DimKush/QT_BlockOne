#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "TaskOneDlg/TaskOneDlg.hpp"
#include "TaskTwoDlg/TaskTwoDlg.hpp"
#include "TaskThreeDlg/TaskThreeDlg.hpp"
#include "TaskFourDlg/TaskFourDlg.hpp"

#include <QApplication>
#include <QWindow>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ExitButton_clicked()
{
    QApplication::quit();
}

void MainWindow::on_TaskOne_clicked()
{
    TaskOneDlg tskOneDlgSample;

    tskOneDlgSample.setModal(true);

    tskOneDlgSample.exec();
}

void MainWindow::on_TaskTwo_clicked()
{
    TaskTwoDlg tskTwoDlgSample;

    tskTwoDlgSample.setModal(true);

    tskTwoDlgSample.exec();
}

void MainWindow::on_TaskThree_clicked()
{
    TaskThreeDlg tskThreeDlgSample;

    tskThreeDlgSample.setModal(true);

    tskThreeDlgSample.exec();
}

void MainWindow::on_TaskFour_clicked()
{
    TaskFourDialog tskFourDlgSample;

    tskFourDlgSample.setModal(true);

    tskFourDlgSample.exec();
}
