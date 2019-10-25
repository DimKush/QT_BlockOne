#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
   void on_ExitButton_clicked();
   void on_TaskOne_clicked();
   void on_TaskTwo_clicked();
   void on_TaskThree_clicked();
   void on_TaskFour_clicked();
};

#endif // MAINWINDOW_HPP
