#ifndef TESTS_H
#define TESTS_H

#include <vector>
#include <iostream>

class Tests {
public:
    // Запуск всех тестов
    void runAllTests();

private:
    // Тест веса Хэмминга
    void hammingWeightTest();

    // Тест преобразования Уолша-Адамара
    void walshTransformTest();

    // Тест DDT
    void ddtTest();

    // Тест LAT
    void latTest();
};

#endif#pragma once
