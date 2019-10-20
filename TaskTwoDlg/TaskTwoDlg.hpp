#ifndef TASK_TWO_DLG_HPP
#define TASK_TWO_DLG_HPP

#include <QDialog>
#include "TaskTwoDlg/TaskTwoLogic.hpp"

namespace Ui { class TaskTwoDialog; }


class TaskTwoDlg : public QDialog
{
    Q_OBJECT

public:
     explicit TaskTwoDlg(QWidget *parent = nullptr);
     ~TaskTwoDlg();

private:
    Ui::TaskTwoDialog *ui;
    TaskTwoLogic Logic;
    void showBCSide();

private slots:
    void on_returnButton_clicked();
    void on_countButton_clicked();
    void on_RadianRadio_pressed();
    void on_coronerRadio_pressed();
};

#endif
