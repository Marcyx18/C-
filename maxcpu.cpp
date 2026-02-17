#include <iostream>
#include <thread>
#include <vector>
#include <cmath>

void f() {
    double x = 1.5;
    while (true) {
        x = std::sin(x) * std::sqrt(x + 1.0);
        if (x > 100.0) x = 1.5;
    }
}

int main() {
    unsigned int n = std::thread::hardware_concurrency();
    std::vector<std::thread> v;

    for (unsigned int i = 0; i < n; ++i) {
        v.emplace_back(f);
    }

    for (auto& t : v) {
        t.join();
    }

    return 0;
}