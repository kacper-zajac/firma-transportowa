

#include "Warehouse.h"
#include "functions.h"

void *__gxx_personality_v0;


int main() {
    class Warehouses main_warehouses;

    std::cout << "Witaj w swojej firmie transportowej!" << std::endl << std::endl;
    std::cout << "Co chcialbys zrobic?" << std::endl;
    std::cout << "1 - zarzadzanie magazynami" << std::endl;
    std::cout << "2 - zarzadzanie towarami" << std::endl;
    std::cout << "3 - transport towarow" << std::endl;
    std::cout << "0 - opusc program" << std::endl;

    int x = getint();
    while (x != 0) {
        switch (x) {
            case 1: {
                clearscreen();
                std::cout << "CENTRUM ZARZADZANIA MAGAZYNAMI" << std::endl << std::endl;
                std::cout << "1 - tworzenie nowego magazynu" << std::endl;
                std::cout << "2 - edytowanie istniejacego magazynu" << std::endl;
                std::cout << "3 - wyswietl magazyny" << std::endl;
                std::cout << "0 - opusc centrum zarzadzania magazynami" << std::endl;
                std::cout << std::endl;
                int y = getint();
                while (y != 0) {
                    switch (y) {
                        case 1: {
                            main_warehouses.createnew();
                            break;
                        }
                        case 2: {
                            std::cout << "Podaj nazwe magazynu do edycji - ";
                            std::string name;
                            std::cin.ignore(256, '\n');
                            getline(std::cin, name);
                            main_warehouses.edit(name);
                            break;
                        }
                        case 3: {
                            main_warehouses.list();
                            break;
                        }
                        default:
                            std::cout << "Wybierz jedna z opcji" << std::endl;
                            break;
                    }
                    std::cout << std::endl << "CENTRUM ZARZADZANIA MAGAZYNAMI!" << std::endl << std::endl;
                    std::cout << "1 - tworzenie nowego magazynu" << std::endl;
                    std::cout << "2 - edytowanie istniejacego magazynu" << std::endl;
                    std::cout << "3 - wyswietl magazyny" << std::endl;
                    std::cout << "0 - opusc centrum zarzadzania magazynami" << std::endl;
                    y = getint();
                    std::cout << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << std::endl;
                if (!main_warehouses.warehouses.empty()) {
                    clearscreen();
                    auto it = main_warehouses.getiterator();

                    std::cout << "CENTRUM ZARZADZANIA TOWARAMI MAGAZYNU \"" << it->name << "\"" << std::endl;
                    std::cout << std::endl <<  "1 - dodawanie towaru do magazynu" << std::endl;
                    std::cout << "2 - edytowanie istniejacego towaru" << std::endl;
                    std::cout << "3 - zmiena magazynu" << std::endl;
                    std::cout << "0 - opusc centrum zarzadzania towarami" << std::endl;
                    std::cout << std::endl;
                    int z = getint();
                    std::cin.ignore(256, '\n');
                    while (z != 0) {
                        switch (z) {
                            case 1: {
                                std::cout << std::endl;
                                it->currentcontent.addnew(it.operator*());
                                break;
                            }
                            case 2: {
                                if (!it->currentcontent.goods.empty()) {
                                    std::cout << std::endl;
                                    it->currentcontent.list();
                                    std::cin.ignore(256, '\n');
                                    std::cout << std::endl << "Towar do edycji - ";
                                    std::string name;
                                    getline(std::cin, name);
                                    std::cout << std::endl;
                                    it->currentcontent.edit(name);
                                } else std::cout << "W magazynie musi znajdowac sie choc jeden towar!" << std::endl;
                                break;
                            }
                            case 3: {
                                it = main_warehouses.getiterator();
                                break;
                            }
                            default:
                                std::cout << "Wybierz jedna z opcji" << std::endl;
                                break;
                        }
                        std::cout << std::endl << "CENTRUM ZARZADZANIA TOWARAMI MAGAZYNU \"" << it->name << "\""
                                  << std::endl << std::endl;
                        std::cout << "1 - dodawanie towaru do magazynu" << std::endl;
                        std::cout << "2 - edytowanie istniejacego towaru" << std::endl;
                        std::cout << "3 - zmiena magazynu" << std::endl;
                        std::cout << "0 - opusc centrum zarzadzania towarami" << std::endl;
                        z = getint();
                        std::cout << std::endl;
                    }
                } else {
                    std::cout << "Najpierw musisz posiadac chociaz jeden magazyn!" << std::endl;
                    getchar();
                    getchar();
                }
                break;
                case 3: {
                    clearscreen();
                    std::cout << "CENTRUM TRANSPORTOWE" << std::endl << std::endl;
                    std::cout << "Podaj nazwe magazynu z ktorego chcesz przetransportowac towary." << std::endl;
                    auto it = main_warehouses.getiterator();
                    std::cout << "Podaj nazwe magazynu docelowego." << std::endl;
                    auto it_destiny = main_warehouses.getiterator();
                    main_warehouses.forward(it, it_destiny);
                    break;
                }
                default: {
                    std::cout << "Wybierz jedna z opcji" << std::endl;
                    break;
                }
            }
        }

        clearscreen();
        std::cout << "MENU GLOWNE" << std::endl;
        std::cout << "Wybierz odpowiednia opcje:" << std::endl;
        std::cout << "1 - zarzadzanie magazynami" << std::endl;
        std::cout << "2 - zarzadzanie towarami" << std::endl;
        std::cout << "3 - transport towarow" << std::endl;
        std::cout << "0 - opusc program" << std::endl;
        x = getint();
    }
    return 0;
}

