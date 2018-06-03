//
// Created by Kacper on 30.05.2018.
//

#ifndef PROJEKT_3_WAREHOUSE_H
#define PROJEKT_3_WAREHOUSE_H


#include "Container.h"
#include "Vehicle.h"

class Warehouse : public Container {
    std::string name;
    std::vector<Vehicle> currentvehicles;
public:
    Warehouse(std::string x) {
        name = x;
    }

    friend int main();

    friend Warehouses;

    void createnewvehicle();

};

class Warehouses {
    std::vector<Warehouse> warehouses;
public:
    void createnew();

    std::vector<Warehouse>::iterator getiterator();

    void list();

    friend int main();

    void edit(std::string &wh);

    void examine(std::string &name);

    void transfer_opt(std::vector<Warehouse>::iterator it, std::vector<Warehouse>::iterator it2, double cap);

    void forward(std::vector<Warehouse>::iterator it, std::vector<Warehouse>::iterator it2);
};

#endif //PROJEKT_3_WAREHOUSE_H
