#include "TaskTwoDlg.hpp"

#include <QMessageBox>
#include <QString>
#include <string>

#include <ui_tasktwodialog.h>

TaskTwoDlg::TaskTwoDlg(QWidget *parent) : QDialog(parent), ui(new Ui::TaskTwoDialog)
{
    ui->setupUi(this);
}

TaskTwoDlg::~TaskTwoDlg()
{
    delete ui;
}

void TaskTwoDlg::on_returnButton_clicked()
{
    close();
    ui->BCLabel->hide();
}

void TaskTwoDlg::on_countButton_clicked()
{
    QMessageBox messageBox;

    messageBox .setFixedSize(500,200);

    int valABFromInterface = ui->ABEdit->text().toInt();
    int valACFromInterface = ui->ACEdit->text().toInt();
    int valCoronerFromInterface = ui->CornerEdit->text().toInt();

    if(valABFromInterface == NULL || valABFromInterface == 0)
    {
        messageBox.critical(0,"Ошибка заполнения","Значение AB - пустое или равно 0.\nЗначение устанавливается как 1");
        valABFromInterface = 1;
    }

    if(valACFromInterface == NULL || valACFromInterface == 0)
    {
        messageBox.critical(0,"Ошибка заполнения","Значение AC - пустое или равно 0.\nЗначение устанавливается как 1");
        valACFromInterface = 1;
    }

    if(valCoronerFromInterface == NULL || valCoronerFromInterface == 0)
    {
        messageBox.critical(0,"Ошибка заполнения","Значение угла A - пустое или равно 0.\nЗначение устанавливается как 90");
        valCoronerFromInterface = 90;
    }

    Logic.setABSide(valABFromInterface);
    Logic.setACSide(valACFromInterface);
    Logic.setCorner(valCoronerFromInterface);

    Logic.CountBCSide();

    showBCSide();
}

void TaskTwoDlg::showBCSide()
{
    std::string BCSideString = "BC = " + std::to_string(Logic.getBCSide()) + " cm";

    QString BCSideQString = QString::fromUtf8(BCSideString.c_str());

    ui->BCLabel->setText(BCSideQString);

    ui->BCLabel->show();
}

void TaskTwoDlg::on_RadianRadio_pressed()
{
    Logic.setCornerRadian(true);
    ui->CornerPrefix->setText(QString("R"));
}


void TaskTwoDlg::on_coronerRadio_pressed()
{
    Logic.setCornerRadian(false);
    ui->CornerPrefix->setText(QString("o"));
}
