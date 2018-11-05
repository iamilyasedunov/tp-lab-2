#include "task3.h"

template<typename T>
T change(T val)
{
    return val + 6;
}

int main() {
    const size_t n = 4;
    char arr[n]{'b', 'o', 'b', 'o'};

    map<char, n>(arr, change);
    for(auto i: arr)
        cout<<i<<" ";

    return 0;
}