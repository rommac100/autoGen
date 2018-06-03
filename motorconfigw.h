#ifndef MOTORCONFIGW_H
#define MOTORCONFIGW_H

#include <QDialog>
#include <QCheckBox>
#include <QString>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class MotorConfigW;
}

class MotorConfigW : public QDialog
{
    Q_OBJECT

public:
    explicit MotorConfigW(QWidget *parent = 0);
    ~MotorConfigW();
    QString getMotorName();
    bool getInversion();
    bool getDriveMotor();
private slots:
    void on_saveSetBtn_clicked();

    void on_driveMotBol_toggled(bool checked);

    void on_invertMotBol_toggled(bool checked);

    void on_motorNamEdit_editingFinished();

private:
    Ui::MotorConfigW *ui;
    QCheckBox *invertMotChk;
    bool invertMotBol;
    QCheckBox *driveMotChk;
    bool driveMotBol;
    QString motorName;
    QPushButton *saveSetBtn;
    QLineEdit *motorNameEdit;
    bool closed;
};

#endif // MOTORCONFIGW_H
