#define CATCH_CONFIG_RUNNER

#include <QCoreApplication>
#include "catch.hpp"

int main(int argc, char **argv) {
        QCoreApplication app(argc, argv);

        int result = Catch::Session().run(argc, argv);

        return result < 0xff ? result : 0xff;
}
