#ifndef FRAZIONE_H
#define FRAZIONE_H
#include <vector>
#include <string>
#include <climits>
#include <iostream>

class frazione{
private:
    int num;
    int den;
    std::string name;

public:
    frazione(int=0, int=1);
    virtual ~frazione() = default;
    virtual frazione* clone() const;

    // dati privati
    int getNum() const;
    void setNum(int);
    int getDen() const;
    void setDen(int);
    std::string getName()const;
    void setName(std::string);
    virtual std::string toString()const;

    //funzioni di supporto
    static int MCD(int, int);
    bool positiva() const;
    virtual int getMCD() const;
    virtual void reduce();
    virtual frazione*  minima() const;
    virtual double razionale() const;
    virtual frazione*  complementare() const;

    //operazioni tra frazioni
    virtual frazione*  operator +(const frazione*  ) const;
    virtual frazione*  operator -(const frazione*  ) const;
    virtual frazione*  operator*(const frazione*  ) const;
    virtual frazione*  operator/(const frazione*  ) const;
    virtual bool operator==(const frazione*  ) const;
    virtual bool operator!=(const frazione*  ) const;
    virtual bool operator<(const frazione*  ) const;
    virtual bool operator>(const frazione*  ) const;

};
#endif // FRAZIONE_H
