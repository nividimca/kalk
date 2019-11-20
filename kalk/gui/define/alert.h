#ifndef ALERT_H
#define ALERT_H

#include <QMessageBox>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class alert: public QMessageBox{
    Q_OBJECT

public:
    alert(QString);
    ~alert() = default;
};

#endif // ALERT_H
