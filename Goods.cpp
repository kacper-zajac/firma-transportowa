//
// Created by Kacper on 28.05.2018.
//




#include "Goods.h"
#include "functions.h"
#include "Warehouse.h"

Goods codes_list(0);                     // lista wszystkich towarow i ich kody"

int Good::checkif_exist() {
    for (auto it = codes_list.goods.begin(); it != codes_list.goods.end(); ++it) {
        if (code == it->code) return 0;
    }
    for (auto it = codes_list.goods.begin(); it != codes_list.goods.end(); ++it) {
        if ((it->name == name) && (it->size == size)) {
            code = it->code;
            return 0;
        }
    }
    codes_list.goods.push_back(*this);
    codes_list.sum();
    codes_list.ObjectCounter++;
    return 1;
}

Good::Good(int x, int y, std::string s) {
    size = x;
    amount = y;
    name = s;
    code = random_string();
}

void Goods::sum() {
    for (auto it = goods.begin(); it != goods.end(); it++) {
        for (auto it2 = goods.begin(); (it2 + 1) != goods.end(); it2++) {
            if (it != it2 && it->code == it2->code && it->size == it2->size) {
                it->amount += it2->amount;
                goods.erase(it2);
                ObjectCounter--;
                sum();                      // jesli jedno wywolanie fukncji mialo usunac wszystkie elementy to jesli
                return;
            }
        }
    }
}

/*void Good::edit() {
    std::cout << "Ktora wartosc \"" << name << "\" chcesz zmienic?" << std::endl;
    std::cout << "1 - rozmiar" << std::endl;
    std::cout << "2 - dostepna ilosc" << std::endl;
    std::cout << "3 - nazwa" << std::endl;
    std::cout << "0 - wyjscie" << std::endl;

    int x;
    while ((x = getint()) != 0) {
        std::cin.ignore(1000, '\n');
        switch (x) {
            case 1: {
                std::cout << std::endl << "EDYTOR ROZMIARU TOWARU" << std::endl;
                std::cout << "Obecna wartosc wynosi - " << size << std::endl;
                std::cout
                        << "Na jaka wartosc chcesz zmienic? Jesli chcesz pozostawic bez zmian, podaj te sama wartosc."
                        << std::endl;
                std::cout << "Twoj wybor - ";
                size = getdouble();
                break;
            }
            case 2: {
                std::cout << std::endl << "EDYTOR ILOSCI TOWARU" << std::endl;
                std::cout << "Obecna wartosc wynosi - " << amount << std::endl;
                std::cout
                        << "Na jaka wartosc chcesz zmienic? Jesli chcesz pozostawic bez zmian, podaj te sama wartosc."
                        << std::endl;
                std::cout << "Twoj wybor - ";
                amount = getint();
                break;
            }
            case 3: {
                std::cout << std::endl << "EDYTOR NAZWY TOWARU" << std::endl;
                std::cout << "Obecna nazwa towaru - " << name << std::endl;
                std::cout << "Na jaka nazwe chcesz zmienic? Jesli chcesz pozostawic bez zmian, podaj te sama nazwe."
                          << std::endl;
                std::cout << "Twoj wybor - ";
                getline(std::cin, name);
                // tutaj trzeba żeby zmieniały się wszystkie nazwy na raz
                break;
            }
            default: {
                std::cout << "Wybierz jedna z opcji" << std::endl;
                break;
            }
        }
        std::cout << std::endl << "Ktory element \"" << name << "\" chcesz jeszcze edytowac?" << std::endl;
        std::cout << "1 - rozmiar" << std::endl;
        std::cout << "2 - dostepna ilosc" << std::endl;
        std::cout << "3 - nazwa" << std::endl;
        std::cout << "0 - wyjscie" << std::endl;
    }
    checkif_exist();
} */

void Goods::addnew(Warehouse &wh) {
    Good G;
    double x, y, z;
    std::cout << "Podaj nazwe nowego towaru - ";
    getline(std::cin, G.name);
    std::cout << std::endl << "Podaj wymiary towaru \"" << G.name << "\" w metrach.";
    std::cout << std::endl << "Dlugosc - ";
    x = getdouble();
    std::cout << std::endl << "Szerokosc - ";
    y = getdouble();
    std::cout << std::endl << "Wysokosc - ";
    z = getdouble();
    G.size = x * y * z;
    G.checkif_exist();                                                  // sprawdza czy podana nazwa byla juz uzyta, jesli tak przypisuje jej ten sam kod produktu
    std::cout << std::endl << "Podaj ilosc towaru \"" << G.name << "\" - ";
    G.amount = getint();
    ObjectCounter++;
    std::cout << std::endl << "Czy chcesz cos poprawic? 1 - tak / 0 - nie"
              << std::endl << "Twoj wybor - ";
    int decision = getint();
    while (decision != 1 && decision != 0) {
        std::cout << std::endl << "Wybierz jedna z opcji!" << std::endl;
        decision = getint();
    }
    if (decision == 1) edit(G.name);
    std::cout << std::endl;
    std::cin.ignore(1000, '\n');
    wh.currentcontent.goods.push_back(G);
    sum();
}

void Goods::edit(std::string &goodtype) {
    std::vector<Good>::iterator it;
    it = goods.begin();
    while (it->name != goodtype) {
        if (it != goods.end())
            it++;
        else {
            std::cout << "Podanego towaru nie ma na liscie." << std::endl;
            return;
        }
    }
    std::cout << "Ktora wartosc \"" << goodtype << "\" chcesz zmienic?" << std::endl;
    std::cout << "1 - rozmiar" << std::endl;
    std::cout << "2 - dostepna ilosc" << std::endl;
    std::cout << "3 - nazwa" << std::endl;
    std::cout << "0 - wyjscie" << std::endl;

    int x;
    while ((x = getint()) != 0) {
        std::cin.ignore(1000, '\n');
        switch (x) {
            case 1: {
                std::cout << std::endl << "EDYTOR ROZMIARU TOWARU" << std::endl;
                std::cout << "Obecna wartosc wynosi - " << it->size << std::endl;
                std::cout
                        << "Na jaka wartosc chcesz zmienic? Jesli chcesz pozostawic bez zmian, podaj te sama wartosc."
                        << std::endl;
                std::cout << "Twoj wybor - ";
                it->size = getdouble();
                break;
            }
            case 2: {
                std::cout << std::endl << "EDYTOR ILOSCI TOWARU" << std::endl;
                std::cout << "Obecna wartosc wynosi - " << it->amount << std::endl;
                std::cout
                        << "Na jaka wartosc chcesz zmienic? Jesli chcesz pozostawic bez zmian, podaj te sama wartosc."
                        << std::endl;
                std::cout << "Twoj wybor - ";
                it->amount = getint();
                break;
            }
            case 3: {
                std::cout << std::endl << "EDYTOR NAZWY TOWARU" << std::endl;
                std::cout << "Obecna nazwa towaru - " << it->name << std::endl;
                std::cout << "Na jaka nazwe chcesz zmienic? Jesli chcesz pozostawic bez zmian, podaj te sama nazwe."
                          << std::endl;
                std::cout << "Twoj wybor - ";
                getline(std::cin, it->name);
                // tutaj trzeba żeby zmieniały się wszystkie nazwy na raz
                break;
            }
            default: {
                std::cout << "Wybierz jedna z opcji" << std::endl;
                break;
            }
        }
        std::cout << std::endl << "Ktory element \"" << it->name << "\" chcesz jeszcze edytowac?" << std::endl;
        std::cout << "1 - rozmiar" << std::endl;
        std::cout << "2 - dostepna ilosc" << std::endl;
        std::cout << "3 - nazwa" << std::endl;
        std::cout << "0 - wyjscie" << std::endl;
    }

    if (it->amount == 0) goods.erase(it); else it->checkif_exist();
}

/*void Goods::delete_type() {
    std::string goodtype;

    std::cout << std::endl << "Nazwa towaru do likwidacji - ";      // czasem pomija druga nazwe z kolei (
    getline(std::cin, goodtype);
    std::cout << std::endl << "Rozmiar towaru do likwidacji - ";
    auto y = getdouble();
    auto it = goods.begin();
    for (; (it->name != goodtype) || (it->size != y); it++) {
        if (it == goods.end()) {
            std::cout << "Podanego towaru nie ma na liscie." << std::endl;
            list();
            return;
        }
    }
    std::cout << std::endl << "Czy na pewno chcesz zlikwidowac towar - \"" << it->name
              << "\"? " << "1 - tak / 0 - nie" << std::endl << "Twoj wybor - ";
    int x = getint();
    std::cout << std::endl;
    if (!x) return;
    goods.erase(it);
    ObjectCounter--;
}*/   // dodac ze usuwa takze z tablicy glownej - ta funck bedzie usuwala calkowicie jakis typ + dodac ze nie mozna stworzyc tej samej nazwy produktu

void Goods::list() {
    std::cout << std::endl << std::endl << "Obecne na liscie towary:" << std::endl;
    std::vector<Good>::iterator iterator;
    for (iterator = goods.begin(); iterator != goods.end(); iterator++) {
        std::cout << std::endl << "\"" << iterator->name << "\"" << std::endl;
        std::cout << "Ilosc: " << iterator->amount << std::endl;
        std::cout << "Objetosc: " << iterator->size << std::endl;
        std::cout << "Kod produktu: " << iterator->code << std::endl;
    }
}

int Goods::minus(int x, double y, std::string name) {
    auto it = goods.begin();
    for (; (it->name != name) || (it->size != y); it++) {
        if (it == goods.end()) {
            std::cout << "Podanego towaru nie ma na liscie." << std::endl;
            list();
            return 0;                                                                  // kod bledu do jednej ze zmiennych
        }
    }
    if (x > it->amount) {
        std::cout << "Nie mozesz zabrac wiecej niz posiadasz!" << std::endl;
        return 2;                                                                       // kod bledu to ilosci
    }

    it->amount -= x;
    if (it->amount == 0) goods.erase(it);
    ObjectCounter--;
    return 1;                                                                           // kod - wszystko dobrze
}

int Goods::plus(int x, double y, std::string &name) {
    Good f(x, y, name);
    goods.push_back(f);
    sum();
}
