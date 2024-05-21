#ifndef SORTER_H
#define SORTER_H

#include <stack>
#include <vector>
#include <string>

// ����������� ���� ������
enum class WagonType { TYPE_A, TYPE_B };

// ���������, �������������� �����
struct Wagon {
    WagonType type;
    std::string id;
};

// ����� ��� ���������� �������
class TrainSorter {
public:
    TrainSorter();
    void loadWagonsFromInput(std::istream& input); // �������� ������� �� �����
    void sortWagons(); // ���������� �������
    void printSortedWagons(std::ostream& output); // ����� ��������������� �������

private:
    std::stack<Wagon> wagons; // ���� ���� �������
    std::stack<Wagon> typeAWagons; // ���� ������� ���� A
    std::stack<Wagon> typeBWagons; // ���� ������� ���� B
};

#endif // SORTER_H
