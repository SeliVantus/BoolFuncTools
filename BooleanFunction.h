#pragma once
#ifndef BOOLEANFUNCTION_H
#define BOOLEANFUNCTION_H

#include <vector>
#include <string>

class BooleanFunction {
private:
    std::vector<int> values; // ������ �������� �������
    int nextHammingNumber(int a) const;

public:
    BooleanFunction(const std::vector<int>& values);

    // �������������� � ����
    std::vector<std::vector<std::string>> toPDNF() const;

    // �������������� � ���
    std::vector<std::vector<std::string>> toANF() const;

    // ��� ��������
    int hammingWeight() const;

    // ��������������
    std::vector<int> autocorrelation() const;

    // �������� ����������
    bool isAffine() const;

    // �������������� ����������
    int correlativeImmunityK2() const;
};

#endif