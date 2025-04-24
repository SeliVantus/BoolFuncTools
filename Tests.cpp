#include "Tests.h"
#include "BooleanFunction.h"
#include "Transformations.h"

void Tests::runAllTests() {
    std::cout << "Running all tests...\n";

    hammingWeightTest();
    walshTransformTest();
    ddtTest();
    latTest();

    std::cout << "All tests completed.\n";
}

void Tests::hammingWeightTest() {
    std::cout << "\n--- Hamming Weight Test ---\n";
    BooleanFunction bf({ 0, 1, 1, 1});
    std::cout << "Hamming weight: " << bf.hammingWeight() << "\n";
}

void Tests::walshTransformTest() {
    std::cout << "\n--- Walsh Transform Test ---\n";
    Transformations transform;
    std::vector<int> f = { 0, 1, 1, 1};
    auto w = transform.walshHadamardTransform(f);

    std::cout << "Walsh coefficients: ";
    for (int val : w) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

void Tests::ddtTest() {
    std::cout << "\n--- DDT Test ---\n";
    Transformations transform;
    std::vector<int> f = { 0, 1, 1, 1};
    auto ddt = transform.ddt(f);

    std::cout << "DDT:\n";
    for (const auto& row : ddt) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

void Tests::latTest() {
    std::cout << "\n--- LAT Test ---\n";
    Transformations transform;
    std::vector<int> f = { 0, 1, 1, 1};
    auto lat = transform.lat(f);

    std::cout << "LAT:\n";
    for (const auto& row : lat) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}