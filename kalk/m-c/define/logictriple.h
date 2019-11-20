#ifndef LOGICTRIPLE_H
#define LOGICTRIPLE_H
#include<m-c/define/logic.h>

class logicTriple: public logic{
public:
    logicTriple();
    bool parser(QString, QString&);
    frazione* getFrazione(std::vector<QString>*)const;
};

#endif // LOGICTRIPLE_H
