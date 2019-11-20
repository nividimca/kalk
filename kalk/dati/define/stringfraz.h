#ifndef STRINGFRAZ_H
#define STRINGFRAZ_H

#include "frazione.h"
#include <vector>
#include <string>
#include <QString>
#include <iostream>

class stringFraz:public frazione{
private:
    std::string mid;

public:
    stringFraz (int=0, int=1, std::string= "a");
    stringFraz (const frazione&, std::string= "a");
    stringFraz* clone() const;

    // dati privati
    std::string getMid() const;
    void setMid(std::string);
    std::string toString()const;

    //funzioni di supporto
    stringFraz* minima() const;
    stringFraz* complementare() const;

    //operazioni tra stringFraz
    stringFraz* operator +(const frazione* ) const override;
    stringFraz* operator -(const frazione* ) const override;
    stringFraz* operator *(const frazione* ) const override;
    stringFraz* operator /(const frazione* ) const override;
    bool operator==(const frazione* ) const override;
    bool operator!=(const frazione* ) const override;
    bool operator<(const frazione* ) const override;
    bool operator>(const frazione* ) const override;

};
#endif // STRINGFRAZ_H
