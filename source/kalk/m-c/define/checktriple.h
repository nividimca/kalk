#ifndef CHECKTRIPLE_H
#define CHECKTRIPLE_H
#include<m-c/define/check.h>

class checkTriple: public check{
public:
    checkTriple();
    bool parser(QString, QString&) const;
    frazione* getFrazione(std::vector<QString>*)const;
};

#endif // CHECKTRIPLE_H
