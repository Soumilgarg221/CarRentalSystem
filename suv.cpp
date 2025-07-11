#include "suv.h"

SUV::SUV(string reg, string mdl, string brd, double rent)
    : Car(reg, mdl, brd, rent) {}

void SUV::displayDetails() const {
    cout << "[SUV] Reg No: " << getRegNumber()
         << ", Model: " << model
         << ", Brand: " << brand
         << ", Rent/Day: ₹" << rentPerDay << endl;
}

double SUV::calculateRent(int days) const {
    return rentPerDay * days + 500; // SUV has a flat service fee
}
