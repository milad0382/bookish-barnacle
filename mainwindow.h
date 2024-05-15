#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_le_sha_textChanged(const QString &arg1);
    void clear_var();
    void on_bt_sha_gen_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
