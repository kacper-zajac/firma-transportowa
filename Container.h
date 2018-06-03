//
// Created by Kacper on 28.05.2018.
//

#ifndef PROJEKT_3_CONTAINER_H
#define PROJEKT_3_CONTAINER_H

#include "Goods.h"
class Warehouses;

class Container {
protected:
    Goods currentcontent;
    double capacity;
public:
    explicit Container(double x = 0){
        capacity = x;
    }
    friend Warehouses;
    friend Goods;
    friend int main();
};




#endif //PROJEKT_3_CONTAINER_H
