#ifndef SORTER_H
#define SORTER_H

#include <stack>
#include <vector>
#include <string>

// Определение типа вагона
enum class WagonType { TYPE_A, TYPE_B };

// Структура, представляющая вагон
struct Wagon {
    WagonType type;
    std::string id;
};

// Класс для сортировки вагонов
class TrainSorter {
public:
    TrainSorter();
    void loadWagonsFromInput(std::istream& input); // Загрузка вагонов из ввода
    void sortWagons(); // Сортировка вагонов
    void printSortedWagons(std::ostream& output); // Вывод отсортированных вагонов

private:
    std::stack<Wagon> wagons; // Стек всех вагонов
    std::stack<Wagon> typeAWagons; // Стек вагонов типа A
    std::stack<Wagon> typeBWagons; // Стек вагонов типа B
};

#endif // SORTER_H
