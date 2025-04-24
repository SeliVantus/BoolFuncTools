#include "Transformations.h"
#include <cmath>
#include <algorithm>

// Преобразование Уолша-Адамара
std::vector<int> Transformations::walshHadamardTransform(const std::vector<int>& f) const {
    int n = f.size();
    std::vector<int> w(n);
    for (int i = 0; i < n; ++i) {
            w[i] = f[i] ? -1 : 1;
    }
    // Преобразование Уолша-Адамара (быстрое)
    for (int len = 1; len < n; len *= 2) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; ++j) {
                int u = w[i + j];
                int v = w[i + j + len];
                w[i + j] = u + v;
                w[i + j + len] = u - v;
            }
        }
    }
    return w;
}

// Нелинейность
int Transformations::nonlinearity(const std::vector<int>& f) const {
    auto w = walshHadamardTransform(f);
    int maxVal = *std::max_element(w.begin(), w.end(), [](int a, int b) { return std::abs(a) < std::abs(b); });
    return (f.size() / 2) - (std::abs(maxVal) / 2);
}

// DDT
std::vector<std::vector<int>> Transformations::ddt(const std::vector<int>& f) const {
    int n = f.size();
    std::vector<std::vector<int>> ddt(n, std::vector<int>(n, 0));
    for (int delta = 0; delta < n; ++delta) {
        for (int x = 0; x < n; ++x) {
            ddt[delta][f[x] ^ f[(x ^ delta)]]++;
        }
    }
    return ddt;
}

// LAT
std::vector<std::vector<int>> Transformations::lat(const std::vector<int>& f) const {
    int n = f.size();
    std::vector<std::vector<int>> lat(n, std::vector<int>(n, 0));
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            int count = 0;
            for (int x = 0; x < n; ++x) {
                count += (scalarProduct(a, x) == b) ? 1 : 0;
            }
            lat[a][b] = count;
        }
    }
    return lat;
}

// Скалярное произведение
int Transformations::scalarProduct(int a, int b) const {
    int res = 0;
    while (a > 0 || b > 0) {
        res ^= (a % 2) * (b % 2);
        a >>= 1;
        b >>= 1;
    }
    return res;
}

int Transformations::correlation(const std::vector<int>& f1, const std::vector<int>& f2) const {
    int result = 0;
    for (size_t i = 0; i < f1.size(); ++i) {
        result += std::pow(-1, f1[i] ^ f2[i]);
    }
    return result;
}
