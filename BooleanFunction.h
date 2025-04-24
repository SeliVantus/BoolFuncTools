#pragma once
#ifndef BOOLEANFUNCTION_H
#define BOOLEANFUNCTION_H

#include <vector>
#include <string>

class BooleanFunction {
private:
    std::vector<int> values; // Вектор значений функции
    int nextHammingNumber(int a) const;

public:
    BooleanFunction(const std::vector<int>& values);

    // Преобразование в СДНФ
    std::vector<std::vector<std::string>> toPDNF() const;

    // Преобразование в АНФ
    std::vector<std::vector<std::string>> toANF() const;

    // Вес Хэмминга
    int hammingWeight() const;

    // Автокорреляция
    std::vector<int> autocorrelation() const;

    // Проверка аффинности
    bool isAffine() const;

    // Корреляционная иммунность
    int correlativeImmunityK2() const;

    bool isBalanced() const;

    int algebraicDegree() const;
};

#endif
