#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

template<typename T>
class Quick {
public:
    static void sort(std::vector<T>& a) {
        shuffle(a);
        sort(a, 0, static_cast<int>(a.size()) - 1);
    }

private:
    static void sort(std::vector<T>& a, int lo, int hi) {
        if (hi <= lo) return;

        T pivot = a[lo];
        int lt = lo, gt = hi;
        int i = lo + 1;

        while (i <= gt) {
            if (a[i] < pivot) {
                std::swap(a[lt], a[i]);
                ++lt;
                ++i;
            } else if (a[i] > pivot) {
                std::swap(a[i], a[gt]);
                --gt;
            } else {
                ++i;
            }
        }

        sort(a, lo, lt - 1);
        sort(a, gt + 1, hi);
    }

    static void shuffle(std::vector<T>& a) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(a.begin(), a.end(), g);
    }
};

// ---------- Main para probar con int y string ----------
int main() {
    std::vector<std::string> words = {"dark", "apple", "banana", "cherry", "apple", "cold"};
    std::vector<int> numbers = {3, 5, 3, 2, 1, 3, 4, 2};

    // Estos son para probar el caso especifico de que todos los elems son iguales
    //std::vector<std::string> words = {"banana", "banana", "banana", "banana", "banana", "banana"};
    //std::vector<int> numbers = {5, 5, 5, 5, 5, 5, 5, 5};

    std::cout << "Strings antes de ordenar:\n";
    for (const auto& w : words) std::cout << w << " ";
    std::cout << "\n";

    Quick<std::string>::sort(words);

    std::cout << "Strings después de ordenar:\n";
    for (const auto& w : words) std::cout << w << " ";
    std::cout << "\n\n";

    std::cout << "Números antes de ordenar:\n";
    for (const auto& n : numbers) std::cout << n << " ";
    std::cout << "\n";

    Quick<int>::sort(numbers);

    std::cout << "Números después de ordenar:\n";
    for (const auto& n : numbers) std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
