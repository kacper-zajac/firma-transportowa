//
// Created by Kacper on 30.05.2018.
//

#include "functions.h"
#include <algorithm>

std::set<std::string> codeset;

void clearscreen() {
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif
}

int getint() {
    std::cin.clear();
    int x = 0;
    std::cin >> x;
    while (std::cin.fail() || x < 0) {

        std::cout << std::endl << "Podaj poprawna wartosc!" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> x;

    }
    return x;
}

double getdouble() {
    std::cin.clear();
    double x = 0;
    std::cin >> x;
    while (std::cin.fail() || x <= 0) {

        std::cout << std::endl << "Podaj poprawna wartosc!" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> x;

    }
    return x;
}

std::string random_string() {
    auto randchar = []() -> char {
        const char chars[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(chars) - 1);
        return chars[rand() % max_index];
    };
    std::string s(10, 0);
    std::generate_n(s.begin(), 10, randchar);
    while (!codeset.insert(s).second) std::generate_n(s.begin(), 10, randchar);
    return s;
}

