// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
TEST(BASE, not_work) {
    Automata coffee;

    EXPECT_EQ(0, coffee.getState());
}

TEST(BASE, turn_on) {
    Automata coffee;
    coffee.on();

    EXPECT_EQ(1, coffee.getState());
}

TEST(BASE, accept_money) {
    Automata coffee;
    coffee.on();
    coffee.coin(90);

    EXPECT_EQ(2, coffee.getState());
}

TEST(BASE, choice) {
    Automata coffee;
    coffee.on();
    coffee.coin(90);
    coffee.choice(1);

    EXPECT_EQ(3, coffee.getState());
}

TEST(BASE, check) {
    Automata coffee;
    coffee.on();
    coffee.coin(90);
    coffee.choice(1);
    coffee.check();

    EXPECT_EQ(3, coffee.getState());
}

TEST(BASE, not_enough_money) {
    Automata coffee;
    coffee.on();
    coffee.coin(30);
    coffee.choice(1);
    coffee.check();

    EXPECT_EQ(false, coffee.check());
}

TEST(BASE, cook) {
    Automata coffee;
    coffee.on();
    coffee.coin(90);
    coffee.choice(1);
    coffee.check();
    coffee.cook();

    EXPECT_EQ(4, coffee.getState());
}

TEST(BASE, finish) {
    Automata coffee;
    coffee.on();
    coffee.coin(90);
    coffee.choice(1);
    coffee.check();
    coffee.cook();
    coffee.finish();

    EXPECT_EQ(1, coffee.getState());
}

TEST(ERROR, incorr_choice) {
    Automata coffee;
    coffee.on();
    coffee.coin(90);
    try {
        coffee.choice(10);
    } catch(const std::out_of_range err) {
        ASSERT_STREQ("uncorrect data", err.what());
    }
}

TEST(ERROR, unexp_check) {
    Automata coffee;
    try {
        coffee.check();
    } catch(const std::logic_error err) {
        ASSERT_STREQ("what you want to check?", err.what());
    }
}
