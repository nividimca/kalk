#ifndef LOGICSTRING_H
#define LOGICSTRING_H
#include <m-c/define/logic.h>


class logicString: public logic{
public:
    logicString();
    bool parser(QString, QString&);
    frazione* getFrazione(std::vector<QString>*) const;
};

#endif // LOGICSTRING_H
