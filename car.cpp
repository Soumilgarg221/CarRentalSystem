#include "car.h"

Car::Car(string reg, string mdl, string brd, double rent)
    : regNumber(reg), model(mdl), brand(brd), rentPerDay(rent), isAvailable(true) {}

void Car::displayDetails() const {
    cout << "Reg No: " << regNumber << ", Model: " << model
         << ", Brand: " << brand << ", Rent/Day: ₹" << rentPerDay << endl;
}

double Car::calculateRent(int days) const {
    return rentPerDay * days;
}

bool Car::available() const {
    return isAvailable;
}

void Car::setAvailability(bool status) {
    isAvailable = status;
}

string Car::getRegNumber() const {
    return regNumber;
}
