#include "TaskThreeDlg.hpp"
#include "ui_taskthreedlg.h"

TaskThreeDlg::TaskThreeDlg(QWidget *parent) : QDialog(parent), ui(new Ui::TaskThreeDlg)
{
    ui->setupUi(this);
}

TaskThreeDlg::~TaskThreeDlg()
{
    delete ui;
}

void TaskThreeDlg::on_SetText_clicked()
{
    ui->plainTextEdit->setMaximumBlockCount(1000);
    ui->plainTextEdit->setPlainText(QString(SAMPLE_SET_TEXT));

    ui->textEditWithHTML->setHtml(QString(SAMPLE_SET_TEXT_WITH_HTML));
}

void TaskThreeDlg::on_ReturnButton_clicked()
{
    close();
}

void TaskThreeDlg::on_SymbBorderConfirm_clicked()
{
    int value = ui->TextSymbBoreder->text().toInt();
    value++;

    ui->plainTextEdit->setMaximumBlockCount(value);
    ui->plainTextEdit->setPlainText(QString(SAMPLE_SET_TEXT));

}
