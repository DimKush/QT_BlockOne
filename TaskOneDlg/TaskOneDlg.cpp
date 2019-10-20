#include "TaskOneDlg.hpp"

#include <QMessageBox>
#include <QString>

#include <ui_taskonedlg.h>
#include <string>


TaskOneDlg::TaskOneDlg(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    TextEditsHideInInterface();
}

TaskOneDlg::~TaskOneDlg()
{
    delete ui;
}

//====slots description====//

void TaskOneDlg::on_returnButton_clicked()
{
    ui->~Dialog();
    close();
}

void TaskOneDlg::TextEditsHideInInterface()
{
    ui->DescText->hide();
    ui->X1Text->hide();
    ui->X2Text->hide();
}

void TaskOneDlg::setTextEditsThenDescMoreNull()
{
    TextEditsHideInInterface();

    std::string descString = "D = " + std::to_string(Logic.get_desc()),
                X1String = "X1 = "  + std::to_string(Logic.get_x1()),
                X2String = "X2 = "  + std::to_string(Logic.get_x2());

    QString descQStirngSample = QString::fromUtf8(descString.c_str()) ;
    QString x1QStirngSample   = QString::fromUtf8(X1String.c_str()) ;
    QString x2QStirngSample   = QString::fromUtf8(X2String.c_str()) ;

    ui->DescText->setText(descQStirngSample);
    ui->X1Text->setText(x1QStirngSample);
    ui->X2Text->setText(x2QStirngSample);

    ui->DescText->show();
    ui->X1Text->show();
    ui->X2Text->show();

}

void TaskOneDlg::setTextEditsThenDescIsNull()
{
    TextEditsHideInInterface();

    std::string descString = "D = " + std::to_string(Logic.get_desc()),
                XString = "X = "  + std::to_string(Logic.get_x());

    QString descQStirngSample = QString::fromUtf8(descString.c_str()) ;
    QString xQStirngSample   = QString::fromUtf8(XString.c_str()) ;

    ui->DescText->setText(descQStirngSample);
    ui->X1Text->setText(xQStirngSample);

    ui->DescText->show();
    ui->X1Text->show();
}

void TaskOneDlg::on_countButton_clicked()
{
    QMessageBox messageBox;

    messageBox.setFixedSize(500,200);

    int valAFromInterface = ui->lineEditA->text().toInt();
    int valBFromInterface = ui->lineEditB->text().toInt();
    int valCFromInterface = ui->lineEditC->text().toInt();

    if(valAFromInterface == NULL || valAFromInterface == 0)
    {
        messageBox.critical(0,"Ошибка заполнения","Значение a - пустое или равно 0.\nЗначение устанавливается как 1");
        valAFromInterface = 1;
    }

    if(valBFromInterface == NULL || valBFromInterface == 0)
    {
        messageBox.critical(0,"Ошибка заполнения","Значение b - пустое или равно 0.\nЗначение устанавливается как 1");
        valBFromInterface = 1;
    }

    if(valCFromInterface == NULL || valCFromInterface == 0)
    {
        messageBox.critical(0,"Ошибка заполнения","Значение c - пустое или равно 0.\nЗначение устанавливается как 1");
         valCFromInterface = 1;
    }

    Logic.set_a(valAFromInterface);
    Logic.set_b(valBFromInterface);
    Logic.set_c(valCFromInterface);

    Logic.count_Desc();

    if (Logic.get_desc() > 0)
    {
        Logic.count_XOne();
        Logic.count_XTwo();

        setTextEditsThenDescMoreNull();
    }
    else if(Logic.get_desc() == 0)
    {
        Logic.count_XSample();
        setTextEditsThenDescIsNull();
    }
    else
    {
        messageBox.critical(0,"Ошибка","Дискриминант меньше 0");
    }
}
