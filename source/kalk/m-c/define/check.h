#ifndef CHECK_H
#define CHECK_H
#include <list>
#include <iostream>
#include <QString>
#include <vector>
#include <dati/define/frazione.h>
#include <dati/define/stringfraz.h>
#include <dati/define/triplefraz.h>
class check{
private:
    std::list<QString> parametri;
    std::string type;

public:
    check(std::string);
    virtual ~check();
    std::list<QString> getParametri() const;
    void addParemetro(const QString);
    virtual frazione* getFrazione(std::vector<QString>*)const=0;
    bool virtual parser(QString, QString&)const =0;
    std::string getType()const;

};

#endif // CHECK_H
