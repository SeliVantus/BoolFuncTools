#include <iostream>
#include "BooleanFunction.h"
#include "Transformations.h"
#include "Tests.h"

int main() {
    // Пример использования
    std::vector<int> f = { 0, 1, 1, 1}; // Булева функция
    BooleanFunction bf(f);

    // Преобразование в СДНФ
    std::cout << "PDNF: ";
    for (const auto& term : bf.toPDNF()) {
        for (const auto& var : term) {
            std::cout << var << " ";
        }
        std::cout << "| ";
    }
    std::cout << std::endl;

    // Преобразование в АНФ
    std::cout << "ANF: ";
    for (const auto& term : bf.toANF()) {
        for (const auto& var : term) {
            std::cout << var << " ";
        }
        std::cout << "| ";
    }
    std::cout << std::endl;

    // Вес Хэмминга
    std::cout << "Hamming weight: " << bf.hammingWeight() << std::endl;

    // Нелинейность
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

    // Запуск тестов
    Tests tests;
    tests.runAllTests();

    return 0;
}