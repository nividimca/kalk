#include "m-c/define/model.h"

model::model(){
    logiche.push_back(new logicFraz() );
    logiche.push_back(new logicString() );
    logiche.push_back(new logicTriple() );
    valori= new std::vector<QString>();
    operand1=0;
    operand2=0;
    result=0;
    currentData = logiche[0];
    frazioni.push_back(new frazione(1,5) );
    frazioni.push_back(new stringFraz(1, 5, "asd") );
    frazioni.push_back(new tripleFraz(1, 5, 3) );
    frazioni.push_back(new frazione(1, 10) );
    frazioni.push_back(new stringFraz(1, 10, "asd") );
    frazioni.push_back(new tripleFraz(1, 10, 3) );
}

model::~model(){
    delete currentData;
    for(unsigned int i=0; i<logiche.size(); ++i)
        delete logiche[i];
    for(unsigned int i=0; i<frazioni.size(); ++i){
        delete frazioni[i];
    }
    delete valori;
    if(operand1){
        delete operand1;
    }
    if(operand2){
        delete operand2;
    }
    if(result){
        delete result;
    }
}

void model::nameParametro(){
    if(support.size()!=0){
        QString q = support.front();
        support.pop_front();
        emit sendNameParametro(q);
    }
    else{
        emit sendCloseInput();
        addFrazione();
        valori->clear();
    }
}

void model::addFrazione(){
    frazione* f=currentData->getFrazione(valori);
    frazioni.push_back(f);
    sendToVideo(QString::fromStdString(f->toString()));
    getFrazioni();

}

frazione* model::selectOperand(QString q)const{
    for(unsigned int i=0; i<frazioni.size(); ++i){
        if(q==QString::fromStdString(frazioni[i]->toString()))
            return frazioni[i]->clone();
    }
    return 0;
}

void model::clearElement(){
    if(operand1){
        delete operand1;
        operand1=0;
        getFrazioni();
    }
    if(operand2){
        delete operand2;
        operand2=0;
        getFrazioni();
    }
    emit sendRefreshVideo();
}

void model::clearAll(){
    for(unsigned int i=0; i<frazioni.size(); ++i){
        delete frazioni[i];
    }
    frazioni.clear();
    getFrazioni();
    clearElement();
    emit sendToVideo(QString("Calcolatrice resettata."));
}

void model::getFrazioni(){
    std::vector<QString> s;
    for(unsigned int i=0; i<frazioni.size(); ++i){
        if(frazioni[i]->getName()==currentData->getType()){
            s.push_back(QString::fromStdString(frazioni[i]->toString()));
        }
    }
    emit sendFrazioni(s);
}

void model::refresh(){
        frazioni.push_back(result->clone());
        emit sendToVideo(QString::fromStdString(result->toString()));
        delete result;
        result=0;
        getFrazioni();
        clearElement();
}

void model::setOperand(QListWidgetItem* q){
    frazione* f = selectOperand(q->text());
    if(!operand1){
        operand1=f;
    }
    else{
        if(operand2){
            delete operand1;
            operand1 = operand2;
            operand2=0;
        }
        operand2=f;
    }
    emit sendToVideo(QString::fromStdString(f->toString()));
}

void model::changeLogic(int i){
    currentData = logiche[i];
    getFrazioni();
    emit sendChangedLogic();
}

void model::getRefreshValori(){
    valori->clear();
    openInput();
}

void model::openInput(){
    valori->clear();
    support=currentData->getParametri();
    nameParametro();
}

void model::getNewValore(QString p, QString v){
    if(currentData->parser(p,v)){
        valori->push_back(v);
        nameParametro();
    }
    else{
         emit sendInputKo(v);
    }
}

void model::somma(){
    if(!operand1 || !operand2)
        emit sendToVideo(QString("si devono selezionare 2 operandi "));
    else{
        try{
        result=(*operand1)+operand2;
        refresh();
        }
        catch(std::string s){
            emit sendToVideo(QString::fromStdString(s));
        }
    }
}

void model::sottrazione(){
    if(!operand1 || !operand2)
        emit sendToVideo(QString("si devono selezionare 2 operandi "));
    else{
        try{
        result=(*operand1)-operand2;
        refresh();
        }
        catch(std::string s){
            emit sendToVideo(QString::fromStdString(s));
        }
    }
}

void model::moltiplicazione(){
    if(!operand1 || !operand2)
        emit sendToVideo(QString("si devono selezionare 2 operandi "));
    else{
        try{
        result=(*operand1)*operand2;
        refresh();
        }
        catch(std::string s){
            emit sendToVideo(QString::fromStdString(s));
        }
    }
}

void model::divisione(){
    if(!operand1 || !operand2)
        emit sendToVideo(QString("si devono selezionare 2 operandi "));
    else{
        try{
        result=(*operand1)/operand2;
        refresh();
        }
        catch(std::string s){
            emit sendToVideo(QString::fromStdString(s));
        }
    }
}

void model::maggiore(){
    if(!operand1 || !operand2)
        emit sendToVideo(QString("si devono selezionare 2 operandi "));
    else{
        try{
            if(*operand1>operand2)
                sendToVideo(QString::fromStdString(operand1->toString()+" > "+operand2->toString()));
            else
                sendToVideo(QString("non è maggiore"));
            clearElement();
        }
        catch(std::string s){
            emit sendToVideo(QString::fromStdString(s));
        }
    }
}

void model::minore(){
    if(!operand1 || !operand2)
        emit sendToVideo(QString("si devono selezionare 2 operandi "));
    else{
        try{
            if(*operand1<operand2)
                sendToVideo(QString::fromStdString(operand1->toString()+" < "+operand2->toString()));
            else
                sendToVideo(QString("non è minore"));
            clearElement();
        }
        catch(std::string s){
            emit sendToVideo(QString::fromStdString(s));
        }
    }
}

void model::ugualianza(){
    if(!operand1 || !operand2)
        emit sendToVideo(QString("si devono selezionare 2 operandi "));
    else{
        try{
            if(*operand1==operand2)
                sendToVideo(QString::fromStdString(operand1->toString()+" = "+operand2->toString()));
            else
                sendToVideo(QString("non sono equivalenti"));
            clearElement();
        }
        catch(std::string s){
            emit sendToVideo(QString::fromStdString(s));
        }
    }
}

void model::complementare(){
    if(!operand1)
        emit sendToVideo(QString("deve selezionare un operando "));
    else{
        try{
        result=operand1->complementare();
        refresh();
        }
        catch(std::string s){
            emit sendToVideo(QString::fromStdString(s));
        }
    }
}
