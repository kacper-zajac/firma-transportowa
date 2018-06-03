//
// Created by Kacper on 28.05.2018.
//

#ifndef PROJEKT_3_VEHICLE_H
#define PROJEKT_3_VEHICLE_H


#include <string>

class Vehicle {
protected:
    std::string type;
    double capacity = 0;
public:
    friend class Warehouse;

    friend class Warehouses;
};

class Car : public Vehicle {
public:
    explicit Car(double x = 10) {
        capacity = x;
        type = "Samochod dostawczy";
    }
};

class Car_L : public Vehicle {
public:
    explicit Car_L(double x = 30) {
        capacity = x;
        type = "Maly samochod ciezarowy";
    }
};

class Truck : public Vehicle {
public:
    explicit Truck(double x = 100) {
        capacity = x;
        type = "Duzy samochod ciezarowy";
    }
};

#endif //PROJEKT_3_VEHICLE_H
