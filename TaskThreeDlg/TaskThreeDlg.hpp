#ifndef TASKTHREEDLG_H
#define TASKTHREEDLG_H

#include <QDialog>

namespace Ui {
class TaskThreeDlg;
}

class TaskThreeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit TaskThreeDlg(QWidget *parent = nullptr);
    ~TaskThreeDlg();

private slots:
    void on_SetText_clicked();

    void on_ReturnButton_clicked();

    void on_SymbBorderConfirm_clicked();

private:
    Ui::TaskThreeDlg *ui;
};


#define SAMPLE_SET_TEXT \
    "FIRST WITCH.\n" \
    "When shall we three meet again?\n" \
    "In thunder, lightning, or in rain?\n" \
    "SECOND WITCH.\n" \
    "When the hurlyburly's done,\n" \
    "When the battle's lost and won.\n"


#define SAMPLE_SET_TEXT_WITH_HTML \
    "<font color = 'red'>FIRST WITCH.</font><br/>" \
    "When shall we three meet again?<br/>" \
    "In thunder, lightning, or in rain?<br/>" \
    "<font color = 'red'>SECOND WITCH.</font><br/>" \
    "When the hurlyburly's done,<br/>" \
    "When the battle's lost and won.<br/>"


#endif // TASKTHREEDLG_H
