#ifndef MOTORCONFIG_H
#define MOTORCONFIG_H

#include <QMainWindow>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QDialog>

namespace Ui {
class MotorConfig;
}

class MotorConfig : public QDialog
{
    Q_OBJECT

public:
    explicit MotorConfig(QWidget *parent = 0);
    ~MotorConfig();
    QString getMotorName();
    bool getInversion();
    bool getDriveMotor();

private slots:
    void on_saveSetBtn_clicked();

    void on_driveMotBol_toggled(bool checked);

    void on_invertMotBol_toggled(bool checked);

    void on_motorNamEdit_returnPressed();

private:
    Ui::MotorConfig *ui;
    QCheckBox *invertMotChk;
    bool invertMotBol;
    QCheckBox *driveMotChk;
    bool driveMotBol;
    QString motorName;
    QPushButton *saveSetBtn;
    QLineEdit *motorNameEdit;
    bool closed;
};

#endif // MOTORCONFIG_H
