#include "BooleanFunction.h"
#include <cmath>
#include <algorithm>
#include "Transformations.h"

BooleanFunction::BooleanFunction(const std::vector<int>& values) : values(values) {}

// Преобразование в СДНФ
std::vector<std::vector<std::string>> BooleanFunction::toPDNF() const {
    std::vector<std::vector<std::string>> pdnf;
    int n = std::log2(values.size());
    for (size_t i = 0; i < values.size(); ++i) {
        if (values[i] == 1) {
            std::vector<std::string> term;
            for (int j = n - 1; j >= 0; --j) {
                if ((i & (1 << j)) != 0) {
                    term.push_back("x_" + std::to_string(n - j));
                }
                else {
                    term.push_back("-x_" + std::to_string(n - j));
                }
            }
            pdnf.push_back(term);
        }
    }
    return pdnf;
}

// Преобразование в АНФ
std::vector<std::vector<std::string>> BooleanFunction::toANF() const {
    std::vector<int> anfCoeffs = values;
    int n = std::log2(values.size());

    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if ((mask & (1 << i)) != 0) {
                anfCoeffs[mask] ^= anfCoeffs[mask ^ (1 << i)];
            }
        }
    }

    std::vector<std::vector<std::string>> anf;
    for (int i = 0; i < (1 << n); ++i) {
        if (anfCoeffs[i] == 1) {
            std::vector<std::string> term;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    term.push_back("x_" + std::to_string(j + 1));
                }
            }
            if (term.empty()) term.push_back("1");
            anf.push_back(term);
        }
    }
    return anf;
}

// Вес Хэмминга
int BooleanFunction::hammingWeight() const {
    return std::count(values.begin(), values.end(), 1);
}

// Автокорреляция
std::vector<int> BooleanFunction::autocorrelation() const {
    std::vector<int> result(values.size(), 0);
    for (size_t e = 0; e < values.size(); ++e) {
        for (size_t b = 0; b < values.size(); ++b) {
            result[e] += std::pow(-1, values[b] ^ values[(b ^ e)]);
        }
    }
    return result;
}

// Проверка аффинности
bool BooleanFunction::isAffine() const {
    return toANF().size() <= 1; // Если АНФ содержит только константу или линейные члены
}

// Корреляционная иммунность
int BooleanFunction::correlativeImmunityK2() const {
    Transformations transform;
    auto wf = transform.walshHadamardTransform(values);
    if (wf[0] != 0) return -1;
    for (int m = 1; m < static_cast<int>(std::log2(values.size())); ++m) {
        int a = (1 << m) - 1;
        while (a < static_cast<int>(values.size())) {
            if (wf[a] != 0) return m - 1;
            a = nextHammingNumber(a);
        }
    }
    return static_cast<int>(std::log2(values.size()));
}

// Следующее число с тем же весом Хэмминга
int BooleanFunction::nextHammingNumber(int a) const {
    int c = a & -a;
    int r = a + c;
    return (((r ^ a) >> 2) / c) | r;
}