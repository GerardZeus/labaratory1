#include "func.hpp"
#include <fstream> //Для работы с файлами
#include <iostream>
#include <chrono> //Для работы со временем 
#include <iomanip> //Для изменения формата вывода
#include <sstream> //Для работы со строками(их записи, чтения и т.д)


namespace regist //Создаём пространство имён
{ 

    std::string getTime() // Функция для получения времени в нужном формате
    { 
        auto now = std::chrono::system_clock::now(); //Текущее время в секунадх с момента 1970г.
        std::time_t now_time = std::chrono::system_clock::to_time_t(now); //Преобразование в тип данных time_t(представляет время в секнудах целым числом)

        std::tm local_time; // Переменная для локального времени 
        localtime_s(&local_time, &now_time); //Преобразуем в локальное время 

        std::ostringstream timeStream; //Переменная для записи времени в строку
        timeStream << std::put_time(&local_time, "%Y-%m-%d-%H-%M-%S"); //Преобразуем время в строку нужном формате
        return timeStream.str();
    }

    void logLaunch(const std::string& filename) //Функция для записи в файл
    {
        std::ifstream file_in(filename);//Открывааем файл дял чтения
        int launch_number = 0; //Переменная для счёта количества строк
        std::string line; //Строка для чтения строк в файле 
        while (std::getline(file_in, line))  // Счёт строк из файла 
            ++launch_number;  // Увелиичиваем номер запуска на каждой считанной строке
        
        file_in.close(); // Закрываем файл после чтения

        std::string current_time = getTime(); //Получаем текущее врея в заданом формате

        std::ofstream file_out(filename, std::ios::app); // Открываем файл для записи новой строки (std::ios::app указывает, что строку надо записать в конец)
        file_out << (launch_number + 1) << "-" << current_time << std::endl; //Записываем номер запуска и текущее время уже в нужном формате
        file_out.close(); // Закрываем файл после записи
    }    
}

