#ifndef TRIPLEFRAZ_H
#define TRIPLEFRAZ_H

#include "frazione.h"
#include <vector>
#include <string>

class tripleFraz:public frazione{
private:
    int triple;

public:
    tripleFraz (int=0, int=1, int=0);
    tripleFraz (const frazione&, int =1);
    tripleFraz* clone() const;

    //dati privati
    int getTriple() const;
    void setTriple(int);
    std::string toString()const;

    //funzioni di supporto
    int getMCD() const;
    void reduce();
    tripleFraz* minima() const;
    double razionale() const;
    tripleFraz* complementare() const;

    //operazioni tra tripleFraz
    tripleFraz* operator +(const frazione* ) const;
    tripleFraz* operator -(const frazione* ) const;
    tripleFraz* operator*(const frazione* ) const;
    tripleFraz* operator/(const frazione* ) const;
    bool operator==(const frazione* ) const;
    bool operator!=(const frazione* ) const;
    bool operator<(const frazione* ) const;
    bool operator>(const frazione* ) const;


};
#endif // TRIPLEFRAZ_H

