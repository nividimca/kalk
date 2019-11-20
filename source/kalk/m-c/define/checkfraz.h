#ifndef CHECKFRAZ_H
#define CHECKFRAZ_H
#include<m-c/define/check.h>


class checkFraz:public check{
public:
    checkFraz();
    bool parser(QString, QString&)const;
    virtual frazione* getFrazione(std::vector<QString>*) const;
};

#endif // CHECKFRAZ_H
