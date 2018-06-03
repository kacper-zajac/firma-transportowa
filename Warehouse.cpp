//
// Created by Kacper on 30.05.2018.
//

#include "Warehouse.h"
#include "functions.h"


void Warehouse::createnewvehicle() {

    std::cout << std::endl << "Jaki pojazd chcesz stworzy?" << std::endl;
    std::cout << "1 - maly samochod dostawczy (pojemnosc 10m^3)" << std::endl;
    std::cout << "2 - mala samochod ciezarowy (pojemnosc 30m^3)" << std::endl;
    std::cout << "3 - samochod ciezarowy (pojemnosc 100m^3)" << std::endl;
    while (true) {
        int capacity = getint();
        switch (capacity) {
            case 3: {
                Truck t(100);
                currentvehicles.push_back(t);
                return;
            }
            case 2: {
                Car_L d(30);
                currentvehicles.push_back(d);
                return;
            }
            case 1: {
                Car a(10);
                currentvehicles.push_back(a);
                return;
            }
            default:
                std::cout << "Wybierz istniejaca opcje!" << std::endl;
                break;
        }
    }
}

void Warehouses::createnew() {
    std::cin.ignore(256, '\n');
    std::string name;
    std::cout << std::endl << "Podaj nazwe nowego magazynu." << std::endl;
    getline(std::cin, name);
    Warehouse w(name);
    warehouses.push_back(w);
}

void Warehouses::edit(std::string &wh) {
    // std::cin.ignore(256, '\n');
    std::vector<Warehouse>::iterator it;
    it = warehouses.begin();
    while (it->name != wh) {
        if (it == warehouses.end()) {
            std::cout << "Podanego magazynu nie ma na liscie." << std::endl;
            return;
        } else {
            it++;
        }
    }
    std::cout << "Ktora wartosc \"" << it->name << "\" chcesz zmienic?" << std::endl;
    std::cout << "1 - dodac pojazd" << std::endl;
    std::cout << "2 - nazwe" << std::endl;
    std::cout << "3 - zawartosc" << std::endl;
    std::cout << "0 - wyjscie" << std::endl;

    int x;
    while ((x = getint()) != 0) {
        std::cin.ignore(1000, '\n');
        switch (x) {
            case 1: {
                it->createnewvehicle();
                break;
            }
            case 2: {
                std::cout << std::endl << "EDYTOR NAZWY MAGAZYNU" << std::endl;
                std::cout << "Obecna nazwa magazynu - " << it->name << std::endl;
                std::cout << "Na jaka nazwe chcesz zmienic? Jesli chcesz pozostawic bez zmian, podaj te sama nazwe."
                          << std::endl;
                std::cout << "Twoj wybor - ";
                getline(std::cin, it->name);
                break;
            }
            case 3: {
                if (!it->currentcontent.goods.empty()) {
                    std::cout << "Ktory towar chcesz edytowac?" << std::endl;
                    it->currentcontent.list();
                    std::string xyz;
                    std::cin.ignore(256, '\n');
                    getline(std::cin, xyz);
                    it->currentcontent.edit(xyz);
                } else std::cout << "Wybrany magazyn jest pusty!" << std::endl;
                break;
            }
            default: {
                std::cout << "Wybierz jedna z opcji" << std::endl;
                break;
            }
        }
        std::cout << std::endl << "Ktory element \"" << it->name << "\" chcesz jeszcze edytowac?" << std::endl;
        std::cout << "1 - nowy pojazd" << std::endl;
        std::cout << "2 - nazwa" << std::endl;
        std::cout << "3 - zawartosc" << std::endl;
        std::cout << "0 - wyjscie" << std::endl;
    }
}

void Warehouses::list() {

    std::cout << std::endl << std::endl << "Spis magazynow:" << std::endl;
    std::cout << "Czy chcesz poznac rowniez ich zawartosc? 1 - tak / 0 - nie" << std::endl;
    int x = getint();
    while (x > 1) {
        std::cout << "Podaj wartosc 1 lub 0" << std::endl;
        x = getint();
    }
    std::vector<Warehouse>::iterator iterator;
    int num = 0;
    if (!warehouses.empty()) {
        for (iterator = warehouses.begin(); iterator != warehouses.end(); iterator++) {
            std::cout << std::endl << ++num << ". \"" << iterator->name << "\"" << std::endl;
            if (x) examine(iterator->name);
        }
    }
}

void Warehouses::examine(std::string &name) {
    std::vector<Warehouse>::iterator it;
    it = warehouses.begin();
    while (it->name != name) {
        if (it != warehouses.end())
            it++;
        else {
            std::cout << "Podanego magazynu nie ma na liscie." << std::endl;
            list();
            return;
        }
    }
    Car S(0);
    int s = 0;
    Car_L L(0);
    int l = 0;
    Truck T(0);
    int t = 0;
    std::cout << "Zawartosc magazynu:" << std::endl;
    it->currentcontent.list();
    std::cout << std::endl << "Pojazdy dostepne w magazynie:" << std::endl;
    for (auto it2 = it->currentvehicles.begin(); it2 != it->currentvehicles.end(); it2++) {
        if (it2->type == S.type) { s++; }
        else if (it2->type == L.type) { l++; }
        else if (it2->type == T.type) { t++; }
    }
    if (s) {
        std::cout << s << " - ilosc samochodow dostawczych" << std::endl;
    } else std::cout << "Brak samochodow dostawczych!" << std::endl;
    if (l) {
        std::cout << l << " - ilosc malych samochodow ciezarowych" << std::endl;
    } else std::cout << "Brak malych samochodow ciezarowych!" << std::endl;
    if (t) {
        std::cout << t << " - ilosc samochodow ciezarowych" << std::endl;
    } else std::cout << "Brak samochodow ciezarowych!" << std::endl;
}

std::vector<Warehouse>::iterator Warehouses::getiterator() {
    std::cin.ignore(256, '\n');
    std::string name;
    std::cout << "Nazwa magazynu - ";
    getline(std::cin, name);
    std::cout << std::endl;
    std::vector<Warehouse>::iterator it;
    it = warehouses.begin();
    while (1) {
        if (it->name == name) {
            return it;
        } else if (it == warehouses.end()) {
            std::cout << "Podany magazyn nie istnieje!" << std::endl;
            list();
            return it = getiterator();
        } else it++;
    }
}

void Warehouses::forward(std::vector<Warehouse>::iterator it, std::vector<Warehouse>::iterator it2) {
    std::string name;
    std::cout << "Co i ile chcesz przekazac?" << std::endl;
    it->currentcontent.list();
    std::cout << std::endl << "Nazwa - ";
    getline(std::cin, name);
    std::cout << std::endl << "Objetosc - ";
    double y = getdouble();
    std::cout << std::endl << "Ilosc -";
    int x = getint();
    std::cout << std::endl;
    double sum_car = 0;
    for (auto cars = it->currentvehicles.begin(); cars != it->currentvehicles.end(); cars++) {
        sum_car += cars->capacity;
    }
    int z;
    while ((z = it->currentcontent.minus(x, y, name)) != 1) {
        if (z == 0) {
            std::cout << "Nowa ilosc - ";
            x = getint();
        }
        if (z == 2) {
            std::cout << "Podaj dane ponownie." << std::endl;
            std::cout << "Nazwa - ";
            getline(std::cin, name);
            std::cout << std::endl << "Objetosc - ";
            y = getdouble();
        }
    }
    while (x * y > sum_car) {
        std::cout << std::endl << "Nie posiadasz wystarczajacej ilosci samochodow. (objetosc towarow - " << x * y
                  << ", mozliwa objetosc - " << sum_car << ")" << std::endl
                  << "Podaj nowa ilosc towarow do przekazania - ";
        x = getint();
    }

    double cap = x * y;

    this->transfer_opt(it, it2, cap);

    it2->currentcontent.plus(x, y, name);
}

void Warehouses::transfer_opt(std::vector<Warehouse>::iterator it, std::vector<Warehouse>::iterator it2, double cap) {
    Truck ciezarowka(0);
    Car_L dostawczy(0);
    Car osobowy(0);
    if (cap <= 15) {
        for (auto cars = it->currentvehicles.begin(); cars != it->currentvehicles.end(); cars++) {
            if (cars->type == osobowy.type) {
                osobowy.capacity = cars->capacity;
                it2->currentvehicles.push_back(osobowy);
                it->currentvehicles.erase(cars);
                return;
            }
        }
    } else if (cap <= 30) {
        for (auto cars = it->currentvehicles.begin(); cars != it->currentvehicles.end(); cars++) {
            if (cars->type == dostawczy.type) {
                dostawczy.capacity = cars->capacity;
                it2->currentvehicles.push_back(dostawczy);
                it->currentvehicles.erase(cars);
                return;
            }
        }
    } else if (cap <= 100) {
        for (auto cars = it->currentvehicles.begin(); cars != it->currentvehicles.end(); cars++) {
            if (cars->type == ciezarowka.type) {
                ciezarowka.capacity = cars->capacity;
                it2->currentvehicles.push_back(ciezarowka);
                it->currentvehicles.erase(cars);
                return;
            }
        }
    } else
        while (true) {
            for (auto cars = it->currentvehicles.begin(); cars != it->currentvehicles.end(); cars++) {
                if (cars->type == ciezarowka.type) {
                    ciezarowka.capacity = cars->capacity;
                    it2->currentvehicles.push_back(ciezarowka);
                    cap -= ciezarowka.capacity;
                    it->currentvehicles.erase(cars);
                    if (cap <= 100) {
                        transfer_opt(it, it2, cap);
                        return;
                    }
                }
            }
            for (auto cars = it->currentvehicles.begin(); cars != it->currentvehicles.end(); cars++) {
                if (cars->type == dostawczy.type) {
                    dostawczy.capacity = cars->capacity;
                    it2->currentvehicles.push_back(dostawczy);
                    cap -= dostawczy.capacity;
                    it->currentvehicles.erase(cars);
                    if (cap <= 30) {
                        transfer_opt(it, it2, cap);
                        return;
                    }
                    return;


                }
            }
            for (auto cars = it->currentvehicles.begin(); cars != it->currentvehicles.end(); cars++) {
                if (cars->type == osobowy.type) {
                    osobowy.capacity = cars->capacity;
                    it2->currentvehicles.push_back(osobowy);
                    cap -= osobowy.capacity;
                    it->currentvehicles.erase(cars);
                    if (cap <= 15) {
                        transfer_opt(it, it2, cap);
                        return;
                    }
                }
            }
        }
}