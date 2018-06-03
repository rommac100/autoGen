#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QString>
#include <QListWidget>
#include <generateauto.h>
#include <command.h>
#include <motorconfigw.h>
namespace Ui {
class MainWindow;
}

enum DeviceType
{
    MotorE, Servo, Sensor
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addDevBut_clicked();

    void on_deviceCombo_activated(int index);

    void on_MotorConfigDestroyed();

    void on_outputCBtn_clicked();

private:
    Ui::MainWindow *ui;
    QComboBox *deviceCombo;
    QString currentDeviceSelect;
    DeviceType currentDeviceType;
    QListWidget *deviceList;
    GenerateAuto generateAuto;
    MotorConfigW *motorConfigWin;
    void initializeDeviceCombo();
};

#endif // MAINWINDOW_H
