#ifndef TASKFOURDIALOG_HPP
#define TASKFOURDIALOG_HPP

#include <QDialog>

namespace Ui {
class TaskFourDialog;
}

class TaskFourDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskFourDialog(QWidget *parent = nullptr);
    virtual ~TaskFourDialog();

private slots:
    void on_ReturnButton_clicked();

    void on_CheckButton_clicked();

private:
    Ui::TaskFourDialog *ui;
};

#endif // TASKFOURDIALOG_HPP
