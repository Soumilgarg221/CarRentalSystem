#ifndef SUV_H
#define SUV_H

#include "car.h"

class SUV : public Car {
public:
    SUV(string reg, string mdl, string brd, double rent);
    void displayDetails() const override;
    double calculateRent(int days) const override;
};

#endif
