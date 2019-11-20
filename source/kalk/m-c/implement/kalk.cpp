#include "m-c/define/kalk.h"

kalk::kalk(){
    viewK = new view();
    modelK = new model();
    inputView = 0;
    alertK = 0;
    //connect signals view
    connect( viewK, SIGNAL( sendSelectOperand(QListWidgetItem*)), modelK, SLOT( setOperand(QListWidgetItem*)));
    connect( viewK, SIGNAL( sendChangeCheck(int)), modelK, SLOT(changeCheck(int)));
    connect( viewK, SIGNAL( sendOpenInput()), this, SLOT(getOpenInput()));
    connect( viewK, SIGNAL( sendClearElement()), modelK, SLOT( cleanVideoElement()));
    connect( viewK, SIGNAL( sendClearAll()), modelK, SLOT( clearAll()));
    connect( viewK, SIGNAL( sendSomma()), modelK, SLOT( somma()));
    connect( viewK, SIGNAL( sendSottrazione()), modelK, SLOT( sottrazione()));
    connect( viewK, SIGNAL( sendMoltiplicazione()), modelK, SLOT( moltiplicazione()));
    connect( viewK, SIGNAL( sendDivisione()), modelK, SLOT( divisione()));
    connect( viewK, SIGNAL( sendMaggiore()), modelK, SLOT( maggiore()));
    connect( viewK, SIGNAL( sendMinore()), modelK, SLOT( minore()));
    connect( viewK, SIGNAL( sendUgualianza()), modelK, SLOT( ugualianza()));
    connect( viewK, SIGNAL( sendComplementare()), modelK, SLOT( complementare()));
    connect( viewK, SIGNAL( sendCloseInput()), this, SLOT( closeInputView()));
    //connect signals kalk
    connect( this, SIGNAL( sendRefreshValori()), modelK, SLOT(getRefreshValori()));
    connect( this, SIGNAL( sendCheckedInput()), modelK, SLOT(openInput()));
    //connect signals model
    connect( modelK, SIGNAL( sendNameParametro(QString)), this, SLOT(setNewParametro(QString)));
    connect( modelK, SIGNAL( sendInputKo(QString)), this, SLOT(openAlert(QString)));
    connect( modelK, SIGNAL( sendCloseInput()), this, SLOT(closeInputView()));
    connect( modelK, SIGNAL( sendToVideo(QString)), viewK, SLOT(addToVideo(QString)));
    connect( modelK, SIGNAL( sendFrazioni(std::vector<QString>)), viewK, SLOT( refreshFrazioni(std::vector<QString>)));
    connect( modelK, SIGNAL( sendRefreshVideo()), viewK, SLOT( refreshVideo()));
    connect( modelK, SIGNAL( sendChangedCheck()), this, SLOT( refreshKalk()));
}

void kalk::startKalk(){
    viewK->show();
}

kalk::~kalk(){
    delete modelK;
    delete viewK;
}
void kalk::getOpenInput(){
    if(inputView){
        inputView->close();
        delete inputView;
        inputView = 0;
        emit sendRefreshValori();
    }
    else
        emit sendCheckedInput();
}
void kalk::setNewParametro(QString i){
    if(!inputView){
        inputView = new input();
        connect( inputView, SIGNAL( sendNewValore(QString, QString)), modelK, SLOT(getNewValore(QString, QString)));
    }
    inputView->newLabel(i);
}

void kalk::closeInputView(){
    if(inputView){
        inputView->close();
        delete inputView;
        inputView = 0;
    }
}

void kalk::openAlert(QString s){
    if(!alertK){
        alertK=new alert(s);
        connect ( alertK, SIGNAL( buttonClicked(QAbstractButton*)), this, SLOT(closeAlert()));
    }
}

void kalk::closeAlert(){
    if(alertK){
    alertK->close();
    delete alertK;
    alertK=0;
    inputView->refresh();
    }
}

void kalk::refreshKalk(){
    closeAlert();
    closeInputView();
}
