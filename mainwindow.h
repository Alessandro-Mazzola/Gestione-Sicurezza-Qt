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

private slots:
    void on_aggTelecamera_clicked();

    void on_aggAllarme_clicked();

    void on_visualizza_clicked();

    void on_aggSensore_clicked();

    void on_visualizzaAccesi_clicked();

    void on_elimDispositivo_clicked();

    void on_accendi_clicked();

    void on_spegni_clicked();

    void on_aggiungiDati_clicked();

    void on_simulaMovimento_clicked();

    void on_aggTelAll_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
