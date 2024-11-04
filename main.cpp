#include "func.hpp"
#include <iostream>

int main() {
    const std::string filename = "record.txt"; //Переменная с названием файла(в виде строки)

    regist::logLaunch(filename); //Регистрируем ноывый запуск программы 

    std::cout << "Successfully!" << std::endl;

    return 0;
}
