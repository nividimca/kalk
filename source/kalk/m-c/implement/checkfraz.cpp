#include "m-c/define/checkfraz.h"

checkFraz::checkFraz():check("frazione"){
    addParemetro("numeratore");
    addParemetro("denominatore");
}

bool checkFraz::parser(QString v, QString& s)const {
    if(s.isEmpty()){
        s="nessun inserimento";
        return false;
    }
    else{
        int i = 0;
        if(s[0]=='-')
            i=1;
        for(int j=i; j<s.size(); ++j)
            if(!s[j].isNumber()){
                s="vanno inseriti solo numeri naturali";
                return false;
            }
        bool ok;
        int a=s.toInt(&ok);
        if(!ok){
            s="inserire un numero tra -2147483647 e +2147483647";
            return false;
        }
        if(v=="denominatore" && a==0){
            s="il denominatore nn puo essere zero";
            return false;
        }
    }
    return true;
}

frazione* checkFraz::getFrazione(std::vector<QString>* v)const{
    auto x=*(v);
    frazione a(x[0].toInt(), x[1].toInt());
    return a.clone();

}
