#ifndef CHECKSTRING_H
#define CHECKSTRING_H
#include <m-c/define/check.h>


class checkString: public check{
public:
    checkString();
    bool parser(QString, QString&)const;
    frazione* getFrazione(std::vector<QString>*) const;
};

#endif // CHECKSTRING_H
