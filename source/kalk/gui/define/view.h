#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QListWidget>
#include <vector>
#include <QSignalMapper>

class view: public QWidget{
    Q_OBJECT
private:
    QLineEdit* constVideo;
    QListWidget* oggetti;
    QVBoxLayout* vista;

public:
    view();
    ~view();

public slots:
    void addToVideo(QString);
    void refreshFrazioni(std::vector<QString>);
    void refreshVideo();

signals:
    void sendChangeCheck(int);
    void sendSelectOperand(QListWidgetItem*);
    void sendOpenInput();
    void sendSomma();
    void sendSottrazione();
    void sendMoltiplicazione();
    void sendDivisione();
    void sendMaggiore();
    void sendMinore();
    void sendUgualianza();
    void sendComplementare();
    void sendClearElement();
    void sendClearAll();
    void sendCloseInput();

};

#endif // VIEW_H

