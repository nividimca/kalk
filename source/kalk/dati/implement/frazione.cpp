#include "dati/define/frazione.h"

frazione::frazione(int a, int b){
    if(b==0){
        throw std::string("il denominatore non puo essre 0");
    }
    if(b<0){
        a*=-1;
        b*=-1;
    }
    num = a;
    den = b;
    name="frazione";
}

frazione* frazione::clone() const{  return new frazione(*this);}

int frazione::getNum() const {    return num;}

void frazione::setNum(int a){    num=a;}

int frazione::getDen() const {     return den;}

void frazione::setDen(int a){    den=a;}

std::string frazione::getName()const{
    return name;
}

void frazione::setName(std::string s){
    name=s;
}

std::string frazione::toString()const{
    std::string s = std::to_string(num)+'/'+std::to_string(den);
    return s;
}

int frazione::MCD(int a, int b){ return b == 0  ? a : MCD(b, a % b);}

int frazione::getMCD() const{
    if(num<0)
        return frazione::MCD(-num,den);
    return frazione::MCD(num,den);
}

void frazione::reduce(){
    int a=getMCD();
    num=num/a;
    den=den/a;
}

frazione*  frazione::minima() const{
    frazione* a= new frazione(*this);
    a->reduce();
    return a;
}

double frazione::razionale() const{   return num/(double)den;}

frazione*  frazione::complementare() const{
    if(razionale()>1)
        throw std::string("frazione>1 non puo avere complementare");
    return new frazione(den-num, den);

}

frazione*  frazione::operator +(const frazione* b) const{
    long int n = (long int)num*b->den + (long int)b->num*den;
    long int d = (long int)den*b->den;
    if(n>INT_MAX ||n<INT_MIN ||  d>INT_MAX ||  d<INT_MIN){
        throw std::string("la somma non rispetta i limiti di INT");
    }
    frazione * a=new frazione(n,d);
    a->reduce();
    return a;
}

frazione*  frazione::operator -(const frazione*  b) const{
    long int n=(long int)num*b->den - (long int)b->num*den;
    long int d=(long int)den*b->den;
    if(n>INT_MAX ||n<INT_MIN ||  d> INT_MAX ||  d<INT_MIN)
        throw std::string("la differenza non rispetta i limiti di INT");
    frazione * a=new frazione(n, d);
    a->reduce();
    return a;
}

frazione*  frazione::operator *(const frazione*  b) const{
    long int n=(long int)num*b->num;
    long int d=(long int)den*b->den;
    if(n>INT_MAX ||n<INT_MIN ||  d> INT_MAX ||  d<INT_MIN){
        throw std::string("la moltiplicazione non rispetta i limiti di INT");
    }
    frazione * a=new frazione(n, d);
    a->reduce();
    return a;
}

frazione*  frazione::operator /(const frazione*  b) const{
    if(num==0)
        return new frazione();
    if(b->num==0)
        throw std::string("non si puo dividere per zero");
    long int n=(long int)num*b->den;
    long int d=(long int)den*b->num;
    if(n>INT_MAX ||n<INT_MIN ||  d> INT_MAX ||  d<INT_MIN){
        throw std::string("la divisione non rispetta i limiti di INT");
    }
    frazione * a=new frazione(n, d);
    a->reduce();
    return a;
}

bool frazione::operator==(const frazione*  a) const{    return razionale()==a->razionale();}

bool frazione::operator!=(const frazione*  a) const{    return razionale()!=a->razionale();}

bool frazione::operator<(const frazione*  a) const{    return razionale()<a->razionale();}

bool frazione::operator>(const frazione*  a) const{     return razionale()>a->razionale();}
