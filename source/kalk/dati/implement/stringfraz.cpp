#include "dati/define/stringfraz.h"

stringFraz::stringFraz(int a, int b, std::string c): frazione(a,b),mid(c){setName("stringFraz");}

stringFraz::stringFraz(const frazione& a, std::string b): frazione(a),mid(b){setName("stringFraz");}

stringFraz* stringFraz::clone() const{
    return new stringFraz(*this);
}

std::string stringFraz::getMid() const{
    return mid;
}

void stringFraz::setMid( std::string a){
    mid=a;
}

std::string stringFraz::toString()const{
    return std::to_string(getNum())+'/'+mid+'/'+std::to_string(getDen());
}

stringFraz* stringFraz::minima() const{
    frazione a=*this;
    a.reduce();
    return new stringFraz( a, mid);
}

stringFraz* stringFraz::complementare() const{
    frazione a=*this;
    if(razionale()>1)
        throw(std::string("stringFraz>=1 non puo avere complementare"));
    frazione* b=a.complementare();
    stringFraz* s=new stringFraz( *b, mid);
    delete b;
    return s;
}

stringFraz* stringFraz::operator +(const frazione* a) const{
    if(const stringFraz* st=dynamic_cast<const stringFraz*>(a)){
        frazione* f=frazione(*this)+a;
        stringFraz* s=0;
        if(frazione(*st)<this)
            s=new stringFraz( *f, st->mid);
        else
            s=new stringFraz( *f, mid);
        delete f;
        f=0;
        return s;
    }
    else
        throw("entrambi gli oggetti devono essere stringFraz");

}

stringFraz* stringFraz::operator -(const frazione* a) const{
    if(const stringFraz* st=dynamic_cast<const stringFraz*>(a)){
        frazione* f=0;
        stringFraz* s=0;
        if(*st<this){
            f=frazione(*this)-st;
            s=new stringFraz( *f, mid);
        }
        else{
            f=frazione(*st)-this;
            s= new stringFraz( *f, st->mid);
        }
        delete f;
        f=0;
        return s;
    }
    else
        throw("entrambi gli oggetti devono essere stringFraz");
}

stringFraz* stringFraz::operator *(const frazione* a) const{
    if(const stringFraz* st=dynamic_cast<const stringFraz*>(a)){
        frazione* f=frazione(*this) * st;
        stringFraz* s=0;
        if(*st<this)
            s=new stringFraz( *f, mid);
        else
            s=new stringFraz( *f, st->mid);
        delete f;
        f=0;
        return s;
    }
    else
        throw("entrambi gli oggetti devono essere stringFraz");
}

stringFraz* stringFraz::operator /(const frazione* a) const{
    if(const stringFraz* st=dynamic_cast<const stringFraz*>(a)){
        frazione* f=0;
        stringFraz* s=0;
        if(*st<this){
            f=frazione(*this)/st;
            s=new stringFraz( *f, st->mid);
        }
        else{
            f=frazione(*st)/this;
            s=new stringFraz( *f, mid);
        }
        delete f;
        f=0;
        return s;
    }
    else
        throw("entrambi gli oggetti devono essere stringFraz");
}

bool stringFraz::operator ==(const frazione* a) const{
    if(const stringFraz* st=dynamic_cast<const stringFraz*>(a)){
        return razionale()==st->razionale() && mid==st->mid;
    }
    else
        throw("entrambi gli oggetti devono essere stringFraz");
}

bool stringFraz::operator !=(const frazione* a) const{
    if(const stringFraz* st=dynamic_cast<const stringFraz*>(a)){
        return razionale()!=st->razionale() && mid!=st->mid;
    }
    else
        throw("entrambi gli oggetti devono essere stringFraz");

}

bool stringFraz::operator <(const frazione* a) const{
    if(const stringFraz* st=dynamic_cast<const stringFraz*>(a)){
        return razionale()<st->razionale() && mid<st->mid;
    }
    else
        throw("entrambi gli oggetti devono essere stringFraz");
}

bool stringFraz::operator >(const frazione* a) const{
    if(const stringFraz* st=dynamic_cast<const stringFraz*>(a)){
        return razionale()>st->razionale() && mid>st->mid;
    }
    else
        throw("entrambi gli oggetti devono essere stringFraz");

}
