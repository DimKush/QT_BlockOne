#ifndef TASK_ONE_DLG_HPP
#define TASK_ONE_DLG_HPP

#include <QDialog>
#include "TaskOneLogic.hpp"

namespace Ui { class Dialog; }


class TaskOneDlg : public QDialog
{
    Q_OBJECT

public:
    TaskOneDlg (QWidget * parent = nullptr);
    ~TaskOneDlg();

private:
    Ui::Dialog *ui;
    TaskOneLogic Logic;

    void setTextEditsThenDescMoreNull();
    void setTextEditsThenDescIsNull();
    void TextEditsHideInInterface();

private slots:
    void on_returnButton_clicked();
    void on_countButton_clicked();
};

#endif
