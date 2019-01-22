#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

template <typename T, size_t n>
T* createArr(T (*gen)()){       //pointer on the function
    T* mas = new T[n+1];
    for (size_t i = 0; i < n; i++) {
        mas[i] = gen();
    }
    return mas;
}
