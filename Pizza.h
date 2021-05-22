//
// Created by BedTed on 5/15/2021.
//

#ifndef POLYMORPHISM_PIZZA_H
#define POLYMORPHISM_PIZZA_H
#include <string>

using namespace std;
enum Size {
    s25,
    s30,
    s35,
    s40,
};

class Pizza {
protected:
    string name_;
    string description_;
    Size size_;
    unsigned int price_;
    unsigned int cheese_;
    unsigned int salt_;

public:
    void setSize(Size size) {
        size_ = size;
    }

    unsigned int getCheese() const {
        return cheese_;
    }

    unsigned int getSalt() const {
        return salt_;
    }

    const string &getName() const {
        return name_;
    }

    const string &getDescription() const {
        return description_;
    }

    int getSize() {
        switch (size_) {
            case s25 :
                return 25;
            case s30 :
                return 30;
            case s35 :
                return 35;
            case s40 :
                return 40;
        }
        return 25;
    }

    unsigned int getPrice() const {
        return price_;
    }

    void setCheese(unsigned int cheese) {
        cheese_ = cheese;
    }

    void setSalt(unsigned int salt) {
        salt_ = salt;
    }

    void setPrice(unsigned int price) {
        price_ = price;
    }

    Pizza(string name, string description, unsigned int price) {
        name_ = name;
        description_ = description;
        price_ = price;
    }

    Pizza(const string &name, const string &description, Size size, unsigned int price, unsigned int cheese,
          unsigned int salt) : name_(name), description_(description), size_(size), price_(price), cheese_(cheese),
                               salt_(salt) {}

};


#endif //POLYMORPHISM_PIZZA_H
