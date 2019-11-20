#ifndef LOGIC_H
#define LOGIC_H
#include <list>
#include <iostream>
#include <QString>
#include <vector>
#include <dati/define/frazione.h>
#include <dati/define/stringfraz.h>
#include <dati/define/triplefraz.h>
class logic{
private:
    std::list<QString> parametri;
    std::string type;

public:
    logic(std::string);
    virtual ~logic();
    std::list<QString> getParametri() const;
    void addParemetro(const QString);
    virtual frazione* getFrazione(std::vector<QString>*)const=0;
    bool virtual parser(QString, QString&) =0;
    std::string getType()const;

};

#endif // LOGIC_H
