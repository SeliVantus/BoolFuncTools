#include <iostream>
#include "BooleanFunction.h"
#include "Transformations.h"
#include "Tests.h"

void analyzeFunction(const BooleanFunction& f, const std::string& label, const std::vector<int>& raw) {
    std::cout << "\n--- Analysis of " << label << " ---\n";

    std::cout << "PDNF: ";
    for (const auto& term : f.toPDNF()) {
        for (const auto& var : term) std::cout << var << " ";
        std::cout << "| ";
    }
    std::cout << "\n";

    std::cout << "ANF: ";
    for (const auto& term : f.toANF()) {
        for (const auto& var : term) std::cout << var << " ";
        std::cout << "| ";
    }
    std::cout << "\n";

    std::cout << "Hamming weight: " << f.hammingWeight() << "\n";
    std::cout << "Algebraic degree: " << f.algebraicDegree() << "\n";
    std::cout << "Balanced: " << (f.isBalanced() ? "Yes" : "No") << "\n";
    std::cout << "Affine: " << (f.isAffine() ? "Yes" : "No") << "\n";

    std::cout << "Autocorrelation: ";
    auto autocorr = f.autocorrelation();
    for (int val : autocorr) std::cout << val << " ";
    std::cout << "\n";

    Transformations transform;
    std::cout << "Nonlinearity: " << transform.nonlinearity(raw) << "\n";

    std::cout << "DDT:\n";
    auto ddt = transform.ddt(raw);
    for (const auto& row : ddt) {
        for (int val : row) std::cout << val << " ";
        std::cout << "\n";
    }

    std::cout << "LAT:\n";
    auto lat = transform.lat(raw);
    for (const auto& row : lat) {
        for (int val : row) std::cout << val << " ";
        std::cout << "\n";
    }
}

int main() {
    // Пример булевых функций
    std::vector<int> f1 = { 0, 1, 1, 0, 0, 1, 0, 1 };
    std::vector<int> f2 = { 1, 0, 0, 1, 1, 0, 1, 0 };

    BooleanFunction bf1(f1);
    BooleanFunction bf2(f2);
    Transformations transform;

    // Анализ первой функции
    analyzeFunction(bf1, "Function 1", f1);

    // Анализ второй функции
    analyzeFunction(bf2, "Function 2", f2);

    // Корреляция между функциями
    std::cout << "\n--- Correlation between Function 1 and Function 2 ---\n";
    std::cout << "Correlation: " << transform.correlation(f1, f2) << "\n";

    // Запуск встроенных тестов
    Tests tests;
    tests.runAllTests();

    return 0;
}
