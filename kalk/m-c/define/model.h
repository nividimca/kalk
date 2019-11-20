#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <QWidget>
#include <QString>
#include <list>
#include <QLineEdit>
#include <QGridLayout>
#include <QTextStream>
#include <QList>
#include <QListWidgetItem>
#include <m-c/define/logic.h>
#include <m-c/define/logicfraz.h>
#include <m-c/define/logicstring.h>
#include <m-c/define/logictriple.h>
#include <dati/define/frazione.h>

class model: public QWidget{
    Q_OBJECT
private:
    std::vector<logic*> logiche;
    std::list<QString> support;
    std::vector<frazione*> frazioni;
    std::vector<QString>* valori;
    logic* currentData;
    frazione* operand1;
    frazione* operand2;
    frazione* result;

public:
    model();
    ~model();
    void nameParametro();
    void addFrazione();
    frazione* selectOperand(QString)const;
    void getFrazioni();
    void refresh();

public slots:
    void setOperand(QListWidgetItem*);
    void changeLogic(int);
    void getRefreshValori();
    void openInput();
    void getNewValore(QString, QString);
    void somma();
    void sottrazione();
    void moltiplicazione();
    void divisione();
    void maggiore();
    void minore();
    void ugualianza();
    void complementare();
    void clearElement();
    void clearAll();


signals:
    void sendNameParametro(QString);
    void sendInputKo(QString);
    void sendCloseInput();
    void sendToVideo(QString);
    void sendFrazioni(std::vector<QString>);
    void sendRefreshVideo();
    void sendChangedLogic();

};

#endif // MODEL_H
