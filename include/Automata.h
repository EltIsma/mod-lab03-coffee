// Copyright 2024 EltIsma

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_


#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

class Automata {
 public:
    enum states {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };
    Automata();
    void on();
    void off();
    void coin(const int money);
    void getMenu();
    int getState();
    void choice(int number);
    bool check();
    void cancel();
    void cook();
    void finish();
    void Print(const std::string message);

 private:
    struct drink {
        std::string name;
        int price;
    };
    std::map<int, drink> menu;
    states state;
    int cash;
    drink product;
};

#endif //INCLUDE_AUTOMATA_H_
