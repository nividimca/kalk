#include "m-c/define/check.h"

check::check(std::string s):type(s){}

std::list<QString> check::getParametri() const{
    return parametri;
}

check::~check(){
}


void check::addParemetro(const QString i){
    parametri.push_back(i);
}

std::string check::getType()const{
    return type;
}
