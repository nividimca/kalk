#ifndef LOGICFRAZ_H
#define LOGICFRAZ_H
#include<m-c/define/logic.h>


class logicFraz:public logic{
public:
    logicFraz();
    bool parser(QString, QString&);
    virtual frazione* getFrazione(std::vector<QString>*) const;
};

#endif // LOGICFRAZ_H
