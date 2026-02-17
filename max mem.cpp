#include <vector>
#include <cstring>

int main() {
    std::vector<void*> v;
    size_t s = 1024 * 1024 * 1024; 

    try {
        while (true) {
            void* p = ::operator new(s);
            std::memset(p, 0, s);
            v.push_back(p);
        }
    } catch (...) {
    }

    while (true); 

    return 0;
}