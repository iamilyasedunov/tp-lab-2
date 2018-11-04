#include "task2.h"

template <typename T>

T gen(){
    static int t = -1;
    t--;
    return t - 5.123;
}


int main() {
    const size_t n = 10;
    double* arr;
    arr = createArr<double, n>(gen);
    for (size_t i = 0; i < n; i++)
        cout<<arr[i]<<" ";


    return 0;
}