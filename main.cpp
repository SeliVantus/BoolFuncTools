#include <iostream>
#include "BooleanFunction.h"
#include "Transformations.h"
#include "Tests.h"

int main() {
    // ������ �������������
    std::vector<int> f = { 0, 1, 1, 1}; // ������ �������
    BooleanFunction bf(f);

    // �������������� � ����
    std::cout << "PDNF: ";
    for (const auto& term : bf.toPDNF()) {
        for (const auto& var : term) {
            std::cout << var << " ";
        }
        std::cout << "| ";
    }
    std::cout << std::endl;

    // �������������� � ���
    std::cout << "ANF: ";
    for (const auto& term : bf.toANF()) {
        for (const auto& var : term) {
            std::cout << var << " ";
        }
        std::cout << "| ";
    }
    std::cout << std::endl;

    // ��� ��������
    std::cout << "Hamming weight: " << bf.hammingWeight() << std::endl;

    // ������������
    Transformations transform;
    std::cout << "Nonlinearity: " << transform.nonlinearity(f) << std::endl;

    // DDT
    std::cout << "DDT:" << std::endl;
    auto ddt = transform.ddt(f);
    for (const auto& row : ddt) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // ������ ������
    Tests tests;
    tests.runAllTests();

    return 0;
}