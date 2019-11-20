#ifndef KALK_H
#define KALK_H
#include <gui/define/view.h>
#include <gui/define/input.h>
#include <gui/define/alert.h>
#include <m-c/define/model.h>
#include <QWidget>

class kalk: public QWidget{
    Q_OBJECT
private:
    view* viewK;
    model* modelK;
    input* inputView;
    alert* alertK;

public:
    kalk();
    ~kalk();
    void startKalk();

public slots:
    void getOpenInput();
    void setNewParametro(QString);
    void closeInputView();
    void openAlert(QString);
    void closeAlert();
    void refreshKalk();

signals:
    void sendRefreshValori();
    void sendCheckedInput();
};

#endif // KALK_H
