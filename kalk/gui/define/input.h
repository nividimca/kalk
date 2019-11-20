#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class input: public QWidget{
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QLineEdit* dataInput;
    QLabel* label;

public:
    input();
    ~input();
    void refresh();
    void newLabel(QString);

public slots:
    void clickedInvio();

signals:
    void sendNewValore(QString, QString);

};

#endif // INPUT_H
