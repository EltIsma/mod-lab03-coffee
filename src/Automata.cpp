// Copyright 2024 EltIsma

#include "../include/Automata.h"

Automata::Automata() {
    state = states::OFF;
    cash = 0;
    menu = {
        { 1, { "Espresso", 75 } },
        { 2, { "Americano", 60 } },
        { 4, { "Cappuccino", 65 } },
        { 5, { "Latte", 80 } },
        { 6, { "Raf", 90 } },
    };
}

void Automata::on() {
    if (state == states::OFF) {
        Print("Ready for work");
        state = states::WAIT;
    }
}
void Automata::off() {
    if (state == states::WAIT) {
        Print("Shutdown");
        state = states::OFF;
    }
}
void Automata::coin(const int money) {
    if (state == Automata::WAIT) {
        state = Automata::ACCEPT;
    }

    if (state == Automata::ACCEPT) {
        cash += money;
        Print("+");
    }
}
void Automata::choice(int number) {
    if (!(0 < number && number < menu.size()+1))
        throw std::out_of_range("uncorrect data");

    if (state == states::ACCEPT) {
        product = menu.at(number);
        std::cout << product.name << " - " << product.price << std::endl;
        state = states::CHECK;
    }
}
bool Automata::check() {
    if (state == states::CHECK) {
        if (product.price > cash) {
            Print("insufficient funds, replenish the account");
            return false;
        } else {
           return true;
        }
    } else {
        throw std::logic_error("what you want to check?");
    }
}
void Automata::cancel() {
    if (state == states::ACCEPT || state == states::CHECK) {
        product = {};
        state = states::WAIT;
    }
}
void Automata::cook() {
    if (state == states::CHECK) {
        if (check()) {
            cash -= product.price;
            Print("Please wait");
            state = states::COOK;
        }
    }
}
void Automata::finish() {
    if (state == states::COOK) {
        Print("Ready");
        state = states::WAIT;
    }
}
void Automata::getMenu() {
    for (const auto& [key, item] : menu)
        std::cout << key << ". "
        << item.name << " - "
        << item.price << std::endl;
}
int Automata::getState() {
    return state;
}
void Automata::Print(const std::string message) {
    std::cout << message << std::endl;
}
