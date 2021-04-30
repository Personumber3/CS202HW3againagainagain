//
// Created by Alden Ahern on 4/28/21.
//

#include "Money.h"

Money::Money():_cents(0){};
Money::Money(int cash):_cents(cash){};
Money::Money(double cash):_cents(round(100*cash)){};
Money::Money(const Money &mon):_cents(mon._cents){}

bool operator==(const Money &mon1, const Money &mon2){return (mon1._cents == mon2._cents);}
bool operator!=(const Money &mon1, const Money &mon2){return !(mon1==mon2);}
bool operator<(const Money &mon1, const Money &mon2){return (mon1._cents < mon2._cents);}
bool operator<=(const Money &mon1, const Money &mon2){return !(mon1 > mon2);}
bool operator>(const Money &mon1, const Money &mon2){return (mon1._cents > mon2._cents);}
bool operator>=(const Money &mon1, const Money &mon2){return !(mon1 < mon2);}
Money &Money::operator+=(const Money &mon){_cents += mon._cents; return *this;}
Money &Money::operator-=(const Money &mon){_cents -= mon._cents; return *this;}
Money &Money::operator*=(const double &scalar){_cents *= scalar; return *this;}
Money &Money::operator/=(const double &scalar){_cents /= scalar; return *this;}

Money operator+(const Money &mon1, const Money &mon2){auto holder(mon1); return holder+=mon2;}
Money operator-(const Money &mon1, const Money &mon2){auto holder(mon1); return holder-=mon2;}
Money operator*(const double &scalar, const Money &mon){auto holder(mon); return (holder*=scalar);}
Money operator*(const Money &mon, const double &scalar){auto holder(mon); return (holder*=scalar);}
Money operator/(const Money &mon, const double &divisor){auto holder(mon); return (holder/=divisor);}
std::ostream &operator<<(std::ostream &os, const Money &mon){
    double holder = mon._cents;
    double cash = abs(holder/100);

    if (cash > mon._cents){os << "-$" << cash;}
    else {
        os << "$" << cash;}
    if (mon._cents%10==0){
        if(mon._cents%100 == 0){os << ".0";}
    os << "0";
    }
    return os;
}