#include "dati/define/triplefraz.h"

tripleFraz::tripleFraz(int a, int b, int c){
    if(b==0){
        throw( std::string("denominatore uguale a zero"));
        a=0;
        b=1;
        c=1;
    }
    if(b<0){
        a*=-1;
        b*=-1;
        c*=-1;
    }
    setNum(a);
    setDen(b);

    triple=c;
    setName("tripleFraz");
}

tripleFraz::tripleFraz(const frazione& a, int b): frazione(a),triple(b){setName("tripleFraz");}

tripleFraz* tripleFraz::clone() const{  return new tripleFraz( *this);}

int tripleFraz::getTriple() const{    return triple;}

void tripleFraz::setTriple(int a){    triple=a;}

std::string tripleFraz::toString()const{
    return std::to_string(getNum())+'/'+std::to_string(getDen())+'/'+std::to_string(triple);
}

bool tripleFraz::positiva() const{
    return getNum()>=0 && triple>=0;
}

int tripleFraz::getMCD() const{
    if(triple<0)
        return frazione::MCD(frazione::getMCD(),-triple);
    return frazione::MCD(frazione::getMCD(),triple);
}

void tripleFraz::reduce(){
    int a=getMCD();
    setNum( getNum()/a);
    setDen( getDen()/a);
    triple=triple/a;
}

tripleFraz* tripleFraz::minima() const{
    tripleFraz* a= clone();
    a->reduce();
    return a;
}

double tripleFraz::razionale() const{   return getNum()/(double)getDen() + triple/(double)getDen();}


tripleFraz* tripleFraz::complementare() const{
    if(razionale()>1)
        throw std::string("frazione>=1 non puo avere complementare");
    return new tripleFraz( getDen()-getNum(), getDen(), triple-getDen());
}

tripleFraz* tripleFraz::operator +(const frazione* a) const{
    if(const tripleFraz* t=dynamic_cast<const tripleFraz*>(a)){
        frazione* x=frazione(*this)+t;
        long int l=(long int)triple*t->getDen() + (long int)t->triple*getDen();
        if( l> INT_MAX ||  l<INT_MIN)
            throw std::string("la somma non rispetta i limiti di INT");
        tripleFraz* b = new tripleFraz(*x, l);
        b->reduce();
        delete x;
        return b;
    }
    else
        throw("entrambi gli oggetti devono essere tripleFraz");

}

tripleFraz* tripleFraz::operator -(const frazione* a) const{
    if(const tripleFraz* t=dynamic_cast<const tripleFraz*>(a)){
        frazione* x=frazione(*this)-t;
        long int l=(long int)triple*t->getDen() - (long int)t->triple*getDen();
        if( l> INT_MAX ||  l<INT_MIN)
            throw std::string("la differenza non rispetta i limiti di INT");
        tripleFraz* b = new tripleFraz(*x,
                                       l);
        b->reduce();
        delete x;
        return b;
    }
    else
        throw("entrambi gli oggetti devono essere tripleFraz");

}

tripleFraz* tripleFraz::operator*(const frazione* a) const{
    if(const tripleFraz* t=dynamic_cast<const tripleFraz*>(a)){
        frazione* x=frazione(*this)*t;
        long int l=(long int)triple*t->triple;
        if( l> INT_MAX ||  l<INT_MIN)
            throw std::string("la moltiplicazione non rispetta i limiti di INT");
        tripleFraz* b = new tripleFraz(*x, l);
        b->reduce();
        delete x;
        return b;
    }
    else
        throw("entrambi gli oggetti devono essere tripleFraz");

}

tripleFraz* tripleFraz::operator/(const frazione* a) const{
    if(const tripleFraz* t=dynamic_cast<const tripleFraz*>(a)){
        long int x= (long int)getNum()*t->triple;
        long int y= (long int)getDen()*t->getDen();
        long int z= (long int)triple*t->getNum();
        if( x>INT_MAX ||x<INT_MIN || y> INT_MAX || y<INT_MIN || z> INT_MAX ||  z<INT_MIN)
            throw std::string("la divisione non rispetta i limiti di INT");
        tripleFraz* b = new tripleFraz(x, y, z);
        b->reduce();
        return b;
    }
    else
        throw("entrambi gli oggetti devono essere tripleFraz");

}

bool tripleFraz::operator==(const frazione* a) const{
    if(const tripleFraz* t=dynamic_cast<const tripleFraz*>(a)){
        return razionale()==t->razionale();
    }
    else
        throw("entrambi gli oggetti devono essere tripleFraz");
}

bool tripleFraz::operator!=(const frazione* a) const{
    if(const tripleFraz* t=dynamic_cast<const tripleFraz*>(a)){
        return razionale()!=t->razionale();
    }
    else
        throw("entrambi gli oggetti devono essere tripleFraz");
}

bool tripleFraz::operator<(const frazione* a) const{
    if(const tripleFraz* t=dynamic_cast<const tripleFraz*>(a)){
        return razionale()<t->razionale();
    }
    else
        throw("entrambi gli oggetti devono essere tripleFraz");
}

bool tripleFraz::operator>(const frazione* a) const{
    if(const tripleFraz* t=dynamic_cast<const tripleFraz*>(a)){
        return razionale()>t->razionale();
    }
    else
        throw("entrambi gli oggetti devono essere tripleFraz");
}
