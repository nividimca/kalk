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
#include <m-c/define/check.h>
#include <m-c/define/checkfraz.h>
#include <m-c/define/checkstring.h>
#include <m-c/define/checktriple.h>
#include <dati/define/frazione.h>

class model: public QWidget{
    Q_OBJECT
private:
    std::vector<check*> checkS;
    std::list<QString> support;
    std::vector<frazione*> frazioni;
    std::vector<QString>* valori;
    check* currentData;
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
    void changeCheck(int);
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
    void cleanVideoElement();


signals:
    void sendNameParametro(QString);
    void sendInputKo(QString);
    void sendCloseInput();
    void sendToVideo(QString);
    void sendFrazioni(std::vector<QString>);
    void sendRefreshVideo();
    void sendChangedCheck();

};

#endif // MODEL_H
