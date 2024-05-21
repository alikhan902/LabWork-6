#include <iostream>
#include <fstream>
#include "sorter.h"

void printUsage() {
    std::cout << "Использование: \n"
        << "1. Из файла: ./program filename\n"
        << "2. С клавиатуры: ./program\n";
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");

    TrainSorter sorter;

    if (argc == 2) {
        // Считывание из файла
        std::ifstream inputFile(argv[1]);
        if (!inputFile) {
            std::cerr << "Ошибка при открытии файла " << argv[1] << std::endl;
            return 1;
        }
        sorter.loadWagonsFromInput(inputFile);
    }
    else if (argc == 1) {
        // Считывание с клавиатуры
        std::cout << "Введите количество вагонов, затем их идентификаторы и типы (A/B):\n";
        sorter.loadWagonsFromInput(std::cin);
    }
    else {
        printUsage();
        return 1;
    }

    sorter.sortWagons();
    sorter.printSortedWagons(std::cout);

    return 0;
}
