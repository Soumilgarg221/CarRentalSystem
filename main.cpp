//Car Rental System implementing Oops Concepts
#include <iostream>
#include <vector>
#include <memory>
#include "car.h"
#include "suv.h"

using namespace std;

vector<unique_ptr<Car>> carList;

void preloadCars() {
    carList.push_back(make_unique<SUV>("MH12AB1234", "Fortuner", "Toyota", 3000));
    carList.push_back(make_unique<SUV>("CG10CD5678", "Scorpio", "Mahindra", 2500));
    carList.push_back(make_unique<Car>("KA03XY9999", "Ciaz", "Maruti", 1800)); // Generic sedan
}

void showAvailableCars() {
    cout << "\n--- Available Cars ---\n";
    for (const auto& car : carList) {
        if (car->available()) {
            car->displayDetails();
        }
    }
}

void rentCar() {
    string reg;
    int days;
    cout << "\nEnter registration number of the car to rent: ";
    cin >> reg;

    bool found = false;
    for (auto& car : carList) {
        if (car->available() && reg == car->getRegNumber()) {
            found = true;
            cout << "Enter number of rental days: ";
            cin >> days;
            double cost = car->calculateRent(days);
            cout << "Total Rent = ₹" << cost << endl;
            car->setAvailability(false);
            cout << "Car rented successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "Car not found or already rented.\n";
    }
}


void returnCar() {
    string reg;
    cout << "\nEnter registration number of the car to return: ";
    cin >> reg;

    for (auto& car : carList) {
        if (!car->available() && reg == car->getRegNumber()) {
            car->setAvailability(true);
            cout << "Car returned successfully.\n";
            return;
        }
    }
    cout << "Car not found or it was not rented.\n";
}

int main() {
    preloadCars();

    int choice;
do {
    cout << "\n========== Car Rental System ==========\n";
    cout << "1. Show Available Cars\n";
    cout << "2. Rent a Car\n";
    cout << "3. Return a Car\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            showAvailableCars();
            break;
        case 2:
            rentCar();
            break;
        case 3:
            returnCar();
            break;
        case 4:
            cout << "Thank you for using Car Rental System.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
    }
} while (choice != 4);

    return 0;
}


