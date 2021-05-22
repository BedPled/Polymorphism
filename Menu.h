//
// Created by BedTed on 5/20/2021.
//

#ifndef POLYMORPHISM_MENU_H
#define POLYMORPHISM_MENU_H

#include "Pizza.h"
#include <fstream>
#include <clocale>
#include <vector>
#include <iostream>

class Menu {
protected:

public:
    vector<Pizza> pizzaList;
    void readPizzaList() {
        setlocale(LC_ALL, "Rus");
        ifstream fin(R"(C:\Users\BedTed\CLionProjects\Polymorphism\pizzaList.txt)");

        string buff;
        string name;
        string description;
        unsigned int price;


        if (fin.is_open()) {
            while (!fin.eof()) {
                getline(fin, name);
                getline(fin, description);
                fin >> price;
                getline(fin, buff);
                getline(fin, buff);
                Pizza pizza(name, description, price);
                pizzaList.push_back(pizza);
            }
        }
        fin.close();
    }

    virtual void printPizzaList() {  // override
        for (int i = 0; i < pizzaList.size(); ++i) {
            cout << i + 1 << ". " << pizzaList[i].getName() << endl;
            cout << pizzaList[i].getDescription() << endl;
            cout << "Минимальная цена: " << pizzaList[i].getPrice() << endl;
            cout << endl;
        }
    }
};


#endif //POLYMORPHISM_MENU_H
