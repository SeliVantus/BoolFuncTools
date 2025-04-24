#pragma once
#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include <vector>

class Transformations {
public:
    // �������������� �����-�������
    std::vector<int> walshHadamardTransform(const std::vector<int>& f) const;

    // ������������
    int nonlinearity(const std::vector<int>& f) const;

    // DDT
    std::vector<std::vector<int>> ddt(const std::vector<int>& f) const;

    // LAT
    std::vector<std::vector<int>> lat(const std::vector<int>& f) const;

private:
    // ��������� ������������
    int scalarProduct(int a, int b) const;
};

#endif