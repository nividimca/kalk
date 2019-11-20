#include "gui/define/view.h"

view::view(){
    //video
    constVideo = new QLineEdit();
    constVideo->setReadOnly(true);
    //seleziona oggetti esistenti
    oggetti = new QListWidget();
    connect (oggetti, SIGNAL(itemClicked(QListWidgetItem*)), this, SIGNAL(sendSelectOperand(QListWidgetItem*)));

    //pulsanti cambio check
    QSignalMapper* typeMapper = new QSignalMapper();
    QPushButton* frazione = new QPushButton( "frazione");
    QPushButton* stringFraz = new QPushButton( "stringFraz");
    QPushButton* tripleFraz = new QPushButton( "tripleFraz");
    connect ( frazione, SIGNAL( clicked()), typeMapper, SLOT(map()));
    connect ( stringFraz, SIGNAL( clicked()), typeMapper, SLOT(map()));
    connect ( tripleFraz, SIGNAL( clicked()), typeMapper, SLOT(map()));
    typeMapper -> setMapping ( frazione, 0);
    typeMapper -> setMapping ( stringFraz, 1);
    typeMapper -> setMapping ( tripleFraz, 2);
    connect ( typeMapper, SIGNAL( mapped(int)), this, SIGNAL(sendChangeCheck(int)));
    connect ( frazione, SIGNAL( clicked()), constVideo, SLOT( clear()));
    connect ( stringFraz, SIGNAL( clicked()), constVideo, SLOT(clear()));
    connect ( tripleFraz, SIGNAL( clicked()), constVideo, SLOT(clear()));
    //pulsanti tastiera
    QPushButton* clearElement = new QPushButton("CE");
    QPushButton* clearAll = new QPushButton("CA");
    QPushButton* nuovo = new QPushButton("nuovo");
    QPushButton* somma = new QPushButton("+");
    QPushButton* sottrazione = new QPushButton("-");
    QPushButton* moltiplicazione = new QPushButton("\303\227");
    QPushButton* divisione = new QPushButton("\303\267");
    QPushButton* maggiore = new QPushButton(">");
    QPushButton* minore = new QPushButton("<");
    QPushButton* ugualianza = new QPushButton("   equivalenti   ");
    QPushButton* complementare = new QPushButton("complementare");
    connect ( clearElement, SIGNAL( clicked()), this, SIGNAL( sendClearElement()));
    connect ( clearAll, SIGNAL( clicked()), this, SIGNAL( sendClearAll()));
    connect ( nuovo, SIGNAL( clicked()), this, SIGNAL( sendOpenInput()));
    connect ( somma, SIGNAL( clicked()), this, SIGNAL( sendSomma()));
    connect ( sottrazione, SIGNAL( clicked()), this, SIGNAL( sendSottrazione()));
    connect ( moltiplicazione, SIGNAL( clicked()), this, SIGNAL( sendMoltiplicazione()));
    connect ( divisione, SIGNAL( clicked()), this, SIGNAL( sendDivisione()));
    connect ( maggiore, SIGNAL( clicked()), this, SIGNAL( sendMaggiore()));
    connect ( minore, SIGNAL( clicked()), this, SIGNAL( sendMinore()));
    connect ( ugualianza, SIGNAL( clicked()), this, SIGNAL( sendUgualianza()));
    connect ( complementare, SIGNAL( clicked()), this, SIGNAL( sendComplementare()));


    //layout tastiera:
    QGridLayout* tasti = new QGridLayout();
    tasti->addWidget(clearElement, 0, 0);    tasti->addWidget(clearAll, 0, 1);
    tasti->addWidget(somma, 1, 0);    tasti->addWidget(sottrazione, 1, 1);
    tasti->addWidget(moltiplicazione, 2, 0);    tasti->addWidget(divisione, 2, 1);
    tasti->addWidget(maggiore, 3, 0);    tasti->addWidget(minore, 3, 1);
    tasti->addWidget(ugualianza, 4, 0);    tasti->addWidget(complementare, 4, 1);
    QVBoxLayout* tastiera = new QVBoxLayout();
    tastiera->addLayout(tasti);
    tastiera->addWidget(nuovo);
    //support layout view
    QGridLayout* up = new QGridLayout();
    up->addWidget(frazione, 0, 0);
    up->addWidget(stringFraz, 0, 1);
    up->addWidget(tripleFraz, 0, 2);
    QGridLayout* down = new QGridLayout();
    down->addLayout( tastiera, 0, 0);
    down->addWidget( oggetti, 0, 1);
    //layout view
    vista = new QVBoxLayout();
    vista->addLayout(up);
    vista->addWidget(constVideo);
    vista->addLayout(down);
    setLayout(vista);
}

view::~view(){
    emit sendCloseInput();
    delete vista;
}

void view::addToVideo(QString s){
    constVideo->clear();
    constVideo->setText(s);
}

void view::refreshFrazioni(std::vector<QString> v){
    oggetti->clear();
    for(unsigned int i=0; i<v.size(); ++i){
        oggetti->addItem(v[i]);
    }
}

void view::refreshVideo(){
    constVideo->clear();
}
