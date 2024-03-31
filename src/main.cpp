// Copyright 2024 EltIsma

#include "../include/Automata.h"

int main() {
    Automata coffee;
    coffee.on();
    coffee.coin(30);
    coffee.choice(1);
    coffee.cancel();
    coffee.coin(50);
    coffee.choice(1);
    coffee.check();
    coffee.cook();
    coffee.finish();
    coffee.off();
}
