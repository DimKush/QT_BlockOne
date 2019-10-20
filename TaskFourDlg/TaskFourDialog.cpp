#include "TaskFourDialog.hpp"
#include "ui_taskfourdialog.h"

#include <QMessageBox>
#include <QString>
#include <QTextDocument>
#include <QFont>

TaskFourDialog::TaskFourDialog(QWidget *parent) : QDialog(parent), ui(new Ui::TaskFourDialog)
{
    ui->setupUi(this);
}

TaskFourDialog::~TaskFourDialog()
{
    delete ui;
}

void TaskFourDialog::on_ReturnButton_clicked()
{
    close();
}

void TaskFourDialog::on_CheckButton_clicked()
{
    QMessageBox message;
    QFont fontSample("Courier New");

    QTextDocument *doc = ui->textEdit->document();
    doc->setDefaultFont(fontSample);

   // ui->textEdited->insertPlainText(doc->QString);
}
