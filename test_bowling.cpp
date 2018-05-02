#include "catch.hpp"
#include "Game.h"

class BowlingTester {
protected:
    void setup() {
        g = new Game();
    }

    void rollMany(int n, int pins) {
        for (int i = 0; i < n; i++) {
            g->roll(pins);
        }
    }

    void rollSpare() {
        g->roll(5);
        g->roll(5);
    }

    void rollStrike() {
        g->roll(10);
    }

    Game *g = nullptr;
};

SCENARIO_METHOD(BowlingTester, "Types of games", "") {
    GIVEN("an empty game") {
        setup();

        WHEN("gutter game") {
            rollMany(20, 0);

            THEN("the result is 0") {
                REQUIRE(g->score() == 0);

            }
        }

        WHEN("all ones game") {
            rollMany(20, 1);

            THEN("the result is 20") {
                REQUIRE(g->score() == 20);
            }
        }

        WHEN("one spare") {
            rollSpare();
            g->roll(3);

            rollMany(17, 0);

            THEN("the result is 16") {
                REQUIRE(g->score() == 16);
            }
        }

        WHEN("one strike") {
            rollStrike();
            g->roll(3);
            g->roll(4);
            rollMany(16, 0);

            THEN("the result is 24") {
                REQUIRE(g->score() == 24);
            }
        }

        WHEN("perfect game") {
            rollMany(12, 10);

            THEN("300") {
                REQUIRE(g->score() == 300);
            }
        }
    }
}
