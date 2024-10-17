#include "func.hpp"
#include <iostream>

int main() {
    const std::string filename = "record.txt";

    // Логируем запуск программы
    regist::logLaunch(filename);

    std::cout << "Successfully!" << std::endl;

    return 0;
}
