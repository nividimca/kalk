#include "gui/define/input.h"

input::input(){
    layout = new QVBoxLayout();
    dataInput = new QLineEdit();
    QPushButton* invio = new QPushButton("invio");
    connect( invio, SIGNAL(clicked()), this, SLOT(clickedInvio()));

    label = new QLabel();
    layout->addWidget(label);
    layout->addWidget(dataInput);
    layout->addWidget(invio);
    setLayout(layout);
    show();
}

input::~input(){
    delete layout;
}

void input::refresh(){
    dataInput->clear();
}

void input::newLabel(QString i){
    label->setText(i);
    dataInput->clear();
}

void input::clickedInvio(){
    emit sendNewValore( label->text(), dataInput->text());
}
