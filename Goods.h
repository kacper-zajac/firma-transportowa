//
// Created by Kacper on 28.05.2018.
//

#ifndef PROJEKT_3_GOODS_H
#define PROJEKT_3_GOODS_H


#include <vector>
#include <iostream>


class Goods;
class Warehouse;

class Good {
    std::string code;
    double size;
    int amount;
    std::string name;
public:
//    Good(Good &g, int x) {
//        code = g.code;
//        size = g.size;
//        name = g.name;
//        amount = x;
//    }

    explicit Good(int = 0, int = 0, std::string x = "s");

    friend Goods;

    int checkif_exist();

    friend class Container;

    void edit();
};

class Goods {
    int ObjectCounter;
    std::vector<Good> goods;        // zbior wszystkich towarow
public:
    explicit Goods(int x = 0) {
        ObjectCounter = x;
        goods.clear();
    }

    void addnew(Warehouse &wh);

    void edit(std::string &goodtype);

    void sum();

    int minus(int x, double y, std::string name);

    int plus(int x, double y,std::string &name);

 //   void delete_type();

    void list();

    friend int main();

    friend class Container;

    friend class Warehouses;

    friend int Good::checkif_exist();
};


#endif //PROJEKT_3_GOODS_H
