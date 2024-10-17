#include <string>

namespace regist {

    // Получаем текущее веремя
    std::string getCurrentTime();

    // Записываем время запуска в файл
    void logLaunch(const std::string& filename);

}

