//
// Created by Alden Ahern on 4/28/21.
//

#ifndef CS202HW3AGAIN_MONEY_H
#define CS202HW3AGAIN_MONEY_H

#include <iostream>
using std::cout;
using std::endl;

class Money{
public:
    Money();
    Money(int cash);
    Money(double cash);
    Money(const Money &mon);
    friend bool operator==(const Money &mon1, const Money &mon2);
    friend bool operator!=(const Money &mon1, const Money &mon2);
    friend bool operator<(const Money &mon1, const Money &mon2);
    friend bool operator<=(const Money &mon1, const Money &mon2);
    friend bool operator>(const Money &mon1, const Money &mon2);
    friend bool operator>=(const Money &mon1, const Money &mon2);
    Money &operator+=(const Money &mon);
    Money &operator-=(const Money &mon);
    Money &operator*=(const double &scalar);
    Money &operator/=(const double &scalar);


    friend Money operator+(const Money &mon1, const Money &mon2);
    friend Money operator-(const Money &mon1, const Money &mon2);
    friend Money operator*(const double &scalar, const Money &mon);
    friend Money operator*(const Money &mon, const double &scalar);
    friend Money operator/(const Money &mon, const double &divisor);
    friend std::ostream &operator<<(std::ostream &os, const Money &mon);


private:
    int _cents;
};
#endif //CS202HW3AGAIN_MONEY_H
