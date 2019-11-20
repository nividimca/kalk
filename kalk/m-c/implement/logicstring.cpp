#include "m-c/define/logicstring.h"

logicString::logicString():logic("stringFraz"){
    addParemetro("numeratore");
    addParemetro("stringa");
    addParemetro("denominatore");
}

bool logicString::parser(QString v, QString& s){
    if(s.isEmpty()){
        s="nessun inserimento";
        return false;
    }
    else{
        if(v=="stringa"){
            for(int i=0; i<s.size(); ++i)
                if(!s[i].isNumber() && !s[i].isLetter()){
                    s="vanno inseriti solo numeri naturali e lettere";
                    return false;
                }
            return true;
        }
        else{
            int i = 0;
            if(s[0]=='-')
                i=1;
            for(int j=i; j<s.size(); ++j){
                if(s[j].isNumber()==false){
                    s="vanno inseriti solo numeri naturali";
                    return false;
                }
            }
            bool ok;
            int a =s.toInt(&ok);
            if(!ok){
                s="inserire un numero tra -2147483647 e +2147483647";
                return false;
            }
            if(v=="denominatore" && a==0){
                s="il denominatore nn puo essere zero";
                return false;
            }
        }
    }
    return true;
}

frazione* logicString::getFrazione(std::vector<QString>* v)const{
    auto x=*(v);
    stringFraz a(x[0].toInt(), x[2].toInt(), x[1].toStdString());
    return a.clone();

}

