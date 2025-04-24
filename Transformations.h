#pragma once
#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include <vector>

class Transformations {
public:
    // Преобразование Уолша-Адамара
    std::vector<int> walshHadamardTransform(const std::vector<int>& f) const;

    // Нелинейность
    int nonlinearity(const std::vector<int>& f) const;

    // DDT
    std::vector<std::vector<int>> ddt(const std::vector<int>& f) const;

    // LAT
    std::vector<std::vector<int>> lat(const std::vector<int>& f) const;

    int correlation(const std::vector<int>& f1, const std::vector<int>& f2) const;

private:
    // Скалярное произведение
    int scalarProduct(int a, int b) const;
};

#endif
