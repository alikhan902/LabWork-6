#include "sorter.h"
#include <iostream>
#include <sstream>

TrainSorter::TrainSorter() {}

void TrainSorter::loadWagonsFromInput(std::istream& input) {
    int n;
    std::string line;

    // ������ ���������� �������
    std::cout << "������� ���������� �������: ";
    while (true) {
        std::getline(input, line);
        std::istringstream iss(line);
        if (iss >> n && n > 0) {
            break;
        }
        else {
            std::cout << "������ �����. ������� ������������� ����� �����: ";
        }
    }

    // ������ ������ � �������
    for (int i = 0; i < n; ++i) {
        std::string id;
        char type;

        std::cout << "������� ������������� � ��� ������ (A/B) ����� ������: ";
        while (true) {
            std::getline(input, line);
            std::istringstream iss(line);
            if (iss >> id >> type && (type == 'A' || type == 'B')) {
                WagonType wagonType = (type == 'A') ? WagonType::TYPE_A : WagonType::TYPE_B;
                wagons.push({ wagonType, id });
                break;
            }
            else {
                std::cout << "������ �����. ��������� ���� �������������� � ���� ������ (A/B): ";
            }
        }
    }
}

void TrainSorter::sortWagons() {
    // ���������� ������� �� �����
    while (!wagons.empty()) {
        Wagon wagon = wagons.top();
        wagons.pop();
        if (wagon.type == WagonType::TYPE_A) {
            typeAWagons.push(wagon);
        }
        else {
            typeBWagons.push(wagon);
        }
    }
}

void TrainSorter::printSortedWagons(std::ostream& output) {
    output << "������ ���� A:" << std::endl;
    while (!typeAWagons.empty()) {
        output << typeAWagons.top().id << std::endl;
        typeAWagons.pop();
    }
    output << "������ ���� B:" << std::endl;
    while (!typeBWagons.empty()) {
        output << typeBWagons.top().id << std::endl;
        typeBWagons.pop();
    }
}
