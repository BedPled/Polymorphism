//
// Created by BedTed on 5/15/2021.
//

#pragma once

#include "Pizza.h"
#include "Menu.h"
#include <fstream>
#include <clocale>
#include <vector>
#include <iostream>

using namespace std;



class Order : public Menu {
private:
    void Add(Pizza &pizza, int Cheese, int Salt, float buffPrice) { // overloar (Добавляет соль и сыр к пицце)
        pizza.setCheese(Cheese);
        pizza.setSalt(Salt);
        pizza.setPrice( (int)(buffPrice * (pizza.getPrice() + Cheese * 30 + Salt * 5))  ); // формирование цены
    };

    void Add(Pizza pizza) { // overloar (добавляет пиццу в заказ \)
        pizzaOrderList.push_back(pizza);
    };
public:
    vector<Pizza> pizzaOrderList;
    Order() {}

    void printPizzaList() { // override
        int sum = 0;
        for (int i = 0; i < pizzaOrderList.size(); ++i) {
            cout << i + 1 << ". " << pizzaOrderList[i].getName() << endl;
            cout << pizzaOrderList[i].getDescription() << endl;
            cout << "Размер пиццы: " << pizzaOrderList[i].getSize() << endl;
            cout << "Кол-во соли: " <<  pizzaOrderList[i].getSalt() << endl;
            cout << "Кол-во сыра: " <<  pizzaOrderList[i].getCheese() << endl;
            cout << "Итоговая цена: " << pizzaOrderList[i].getPrice() << endl;
            cout << endl;
            sum += pizzaOrderList[i].getPrice();
        }
        cout << endl << "Сумма заказа: " << sum << endl;
        cout << endl;
    }

    void makeOrder(Menu pizzaMenu) {
        int buffN;
        string buffOrder;

        string buffName;
        string buffDescription;
        unsigned int buffCheese;
        unsigned int buffSalt;
        unsigned int buffSize;
        float buffPrice;


        cout << "Здравствуйте!" << endl;
        do {
            do {
                cout << "Про какую пиццу вы хотите узнать?" << endl;
                pizzaMenu.printPizzaList();

                cout << "Ввод: ";
                cin >> buffN;
                cout << endl;

                cout << pizzaMenu.pizzaList[buffN - 1].getName() << endl;
                cout << pizzaMenu.pizzaList[buffN - 1].getDescription() << endl;
                cout << endl << "Цена за пиццу:" << endl;
                cout << "25 см - " << (int)(pizzaMenu.pizzaList[buffN - 1].getPrice() * 1) << endl;
                cout << "30 см - " << (int)(pizzaMenu.pizzaList[buffN - 1].getPrice() * 1.25) << endl;
                cout << "35 см - " << (int)(pizzaMenu.pizzaList[buffN - 1].getPrice() * 1.5) << endl;
                cout << "40 см - " << (int)(pizzaMenu.pizzaList[buffN - 1].getPrice() * 1.75) << endl;

                cout << endl << "Добавить к заказу? ( Да / Нет ) : ";
                cin >> buffOrder;
                cout << endl;
            } while (buffOrder != "Да" && buffOrder != "да");

            Pizza pizza(pizzaMenu.pizzaList[buffN - 1].getName(),
                        pizzaMenu.pizzaList[buffN - 1].getDescription(),
                        pizzaMenu.pizzaList[buffN - 1].getPrice());


            do { // размер + цена
                cout << endl << "Какого размера пиццу вы хотите добавить? (25 / 30 / 35 / 40) : ";
                cin >> buffSize;
                cout << endl;
            }  while (buffSize != 25 && buffSize != 30 && buffSize != 35 && buffSize != 40);

            switch (buffSize) {
                case 25 :
                    pizza.setSize(s25);
                    buffPrice = 1;
                    break;
                case 30 :
                    pizza.setSize(s30);
                    buffPrice = 1.25;
                    break;
                case 35 :
                    pizza.setSize(s35);
                    buffPrice = 1.5;
                    break;
                case 40 :
                    pizza.setSize(s40);
                    buffPrice = 1.75;
                    break;
            }

            cout << endl << "Добавить дополнительный сыр? ( Да / Нет ) : "; // сыр
            cin >> buffOrder;
            cout << endl;

            if (buffOrder == "Да" || buffOrder == "да") {
                cout << endl << "Введите кол-во: ";
                cin >> buffSalt;
                cout << endl;
            } else {
                buffSalt = 0;
            }

            cout << "Допольнительно посолить? ( Да / Нет ) : "; // соль
            cin >> buffOrder;
            cout << endl;

            if (buffOrder == "Да" || buffOrder == "да") {
                cout << endl << "Введите кол-во: ";
                cin >> buffCheese;
                cout << endl;
            } else {
                buffCheese = 0;
            }

            Add(pizza, buffCheese, buffSalt, buffPrice);
            Add(pizza);

        cout << "Добавить ещё? ( Да / Нет ) : ";
        cin >> buffOrder;
        cout << endl;

        } while (buffOrder != "Нет" && buffOrder != "нет");

        printPizzaList(); // вывод заказа
        cout << "Спасибо за заказа! Приходите ещё :)";
    }


};


