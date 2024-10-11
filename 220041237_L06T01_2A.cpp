#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string make, model;         
    double fuelCapacity, fuelLevel;    

public:
    Car(string carMake = "", string carModel = "", double capacity = 0, double level = 0) 
        : make(carMake), model(carModel), fuelCapacity(capacity), fuelLevel((level > capacity) ? capacity : level) {}

    void display() const {
        cout << "Car Make: " << make << "\nModel: " << model
             << "\nFuel Capacity: " << fuelCapacity << " liters"
             << "\nFuel Level: " << fuelLevel << " liters" << endl;
    }

    void addFuel(double amount) {
        if (amount >= 0) {
            fuelLevel += amount;
            if (fuelLevel > fuelCapacity) fuelLevel = fuelCapacity;
        } else {
            cout << "Cannot add a negative amount of fuel!" << endl;
        }
    }

    void consumeFuel(double amount) {
        if (amount >= 0) {
            fuelLevel -= amount;
            if (fuelLevel < 0) fuelLevel = 0;
        } else {
            cout << "Cannot consume a negative amount of fuel!" << endl;
        }
    }
    Car operator+(double amount)const{
        Car newCar=*this;
        newCar.addFuel(amount);
        return newCar;
    }

    Car operator-(double amount)const{
        Car newCar=*this;
        newCar.consumeFuel(amount);
        return newCar;
    }

    Car& operator+=(double amount) {
        addFuel(amount);
        return *this;
    }

    bool operator==(const Car& other) const {
        return make == other.make && model == other.model && fuelCapacity == other.fuelCapacity;
    }

    bool operator<(const Car& other) const {
        return fuelLevel < other.fuelLevel;
    }

    bool operator>(const Car& other) const {
        return fuelLevel > other.fuelLevel;
    }

    friend ostream& operator<<(ostream& os, const Car& car) {
        os << "Car Make: " << car.make << "\nModel: " << car.model
           << "\nFuel Capacity: " << car.fuelCapacity << " liters"
           << "\nFuel Level: " << car.fuelLevel << " liters";
        return os;
    }

    friend istream& operator>>(istream& is, Car& car) {
        cout << "Enter car make: ";
        is >> car.make;
        cout << "Enter car model: ";
        is >> car.model;
        cout << "Enter fuel capacity (liters): ";
        is >> car.fuelCapacity;
        cout << "Enter fuel level (liters): ";
        is >> car.fuelLevel;
        if (car.fuelLevel > car.fuelCapacity) car.fuelLevel = car.fuelCapacity;
        return is;
    }

};

int main() {
    Car car1, car2;
    
    cout << "Input details for car1:" << endl;
    cin >> car1;

    cout << "Input details for car2:" << endl;
    cin >> car2;

    cout << "\nDetails of car1:\n" << car1 << endl;
    cout << "\nDetails of car2:\n" << car2 << endl;

    car1 = car1 + 15.0;
    cout << "\nAfter adding 15 liters of fuel to car1:\n" << car1 << endl;

    car2 = car2 - 10.0;
    cout << "\nAfter consuming 10 liters of fuel from car2:\n" << car2 << endl;

    car1 += 10.0;
    cout << "\nAfter incrementally adding 10 liters of fuel to car1:\n" << car1 << endl;

    if (car1 == car2) {
        cout << "\ncar1 and car2 are the same." << endl;
    } else {
        cout << "\ncar1 and car2 are different." << endl;
    }

    if (car1 > car2) {
        cout << "\ncar1 has more fuel than car2." << endl;
    } else if (car1 < car2) {
        cout << "\ncar1 has less fuel than car2." << endl;
    } else {
        cout << "\ncar1 and car2 have the same amount of fuel." << endl;
    }

    return 0;
}
