#ifndef TESTS_H
#define TESTS_H

#include <vector>
#include <iostream>

class Tests {
public:
    // ������ ���� ������
    void runAllTests();

private:
    // ���� ���� ��������
    void hammingWeightTest();

    // ���� �������������� �����-�������
    void walshTransformTest();

    // ���� DDT
    void ddtTest();

    // ���� LAT
    void latTest();
};

#endif#pragma once
