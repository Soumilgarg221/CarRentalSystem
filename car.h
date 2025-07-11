#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string regNumber;
    string model;
    string brand;
    double rentPerDay;
    bool isAvailable;

public:
    Car(string reg, string mdl, string brd, double rent);
    virtual void displayDetails() const;
    virtual double calculateRent(int days) const;
    bool available() const;
    void setAvailability(bool status);
    string getRegNumber() const;
};

#endif
