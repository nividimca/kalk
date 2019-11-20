#include "m-c/define/logic.h"

logic::logic(std::string s):type(s){}

std::list<QString> logic::getParametri() const{
    return parametri;
}

logic::~logic(){
}


void logic::addParemetro(const QString i){
    parametri.push_back(i);
}

std::string logic::getType()const{
    return type;
}
