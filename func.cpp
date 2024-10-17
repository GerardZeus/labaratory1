#include "func.hpp"
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>


namespace regist {

    // �������� ������� ����� � ������� "���-�����-����-���-������-�������"
    std::string getCurrentTime() {
        //����� � �������� � ������� 1970 �.
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        //���������� �����
        std::tm local_time;
        localtime_s(&local_time, &now_time); 
        //������������� � ����� ��� ������ ������� � ������ �������
        std::ostringstream timeStream;
        timeStream << std::put_time(&local_time, "%Y-%m-%d-%H-%M-%S");
        return timeStream.str();
    }

    // ���������� ����� ������ � ����
    void logLaunch(const std::string& filename) {
        // ��������� ���� ��� ������, ����� ������ ���������� �����
        std::ifstream file_in(filename);
        int launch_number = 0;
        std::string line;
        while (std::getline(file_in, line)) {
            ++launch_number;  // ����������� ����� �� ������ ������
        }
        file_in.close();

        // �������� ������� �����
        std::string current_time = getCurrentTime();

        // ��������� ���� ��� ������ � �����
        std::ofstream file_out(filename, std::ios::app);
        file_out.is_open();
        file_out << (launch_number + 1) << "-" << current_time << std::endl;
        file_out.close();
        }
        
    }

