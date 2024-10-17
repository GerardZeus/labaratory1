#include "func.hpp"
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>


namespace regist {

    // Получаем текущее время в формате "год-месяц-день-час-минута-секунда"
    std::string getCurrentTime() {
        //Время в секундах с момента 1970 г.
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        //Адекватное время
        std::tm local_time;
        localtime_s(&local_time, &now_time); 
        //Преобрзование в стоку для записи времени в нужном формате
        std::ostringstream timeStream;
        timeStream << std::put_time(&local_time, "%Y-%m-%d-%H-%M-%S");
        return timeStream.str();
    }

    // Записываем новую строку в файл
    void logLaunch(const std::string& filename) {
        // Открываем файл для чтения, чтобы узнать количество строк
        std::ifstream file_in(filename);
        int launch_number = 0;
        std::string line;
        while (std::getline(file_in, line)) {
            ++launch_number;  // Увеличиваем номер на каждой строке
        }
        file_in.close();

        // Получаем текущее время
        std::string current_time = getCurrentTime();

        // Открываем файл для записи в конец
        std::ofstream file_out(filename, std::ios::app);
        file_out.is_open();
        file_out << (launch_number + 1) << "-" << current_time << std::endl;
        file_out.close();
        }
        
    }

