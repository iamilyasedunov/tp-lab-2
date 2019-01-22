#include <iostream>
using namespace std;

template <typename T,  size_t n>
void map(T (&arr)[n],T (* change)(T)){  //link on the mas which consists from n elements and pointer on the function with parameter 
    for(size_t i = 0; i < n; i++){
        arr[i] = change(arr[i]);
    }
}
