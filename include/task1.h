#include <iostream>
#include <algorithm>
#include <cstring>
#include <iterator>

using namespace std;

template <typename T>
bool cmp(T &x, T &y){   //function of comparing for numbers
    return x<y;
}

bool cmp(char* &x, char* &y){
    return strlen(x)<strlen(y);     //function of comparing for strings
}

template <typename T>
void merge(T mas[], size_t left_s, size_t right_s) {
    size_t left_pos = 0, right_pos = left_s, new_pos = 0;   

    T* temp = new T[right_s + left_s];      //temp wil sorted

    while (left_pos < left_s || right_pos < right_s + left_s) {

        if (cmp(mas[left_pos], mas[right_pos])) {
            temp[new_pos++] = mas[left_pos++];
        }
        else {
            temp[new_pos++] = mas[right_pos++];
        }
        if (left_pos == left_s) {
            //copy from [&mas[right_pos], &mas[right_s + left_s] ] to [&temp[new_pos], &temp[left_s + right_s] ];
            for (size_t i = right_pos; i < right_s + left_s; i++) {
                temp[new_pos] = mas[i];
                new_pos++;
            }
            break;
        }
        if (right_pos == left_s + right_s) {
            //copy from [ &mas[left_pos], &mas[left_s] ] to [&temp[new_pos], &temp[left_s + right_s]];
            for (size_t i = left_pos; i < left_s; i++) {
                temp[new_pos] = mas[i];
                new_pos++;
            }
            break;
        }
    }
    //copy from [&temp[0], &temp[right_s + left_s] ] to mas);
    for (size_t i = 0; i < left_s + right_s; i++) {
        mas[i] = temp[i];
        new_pos++;
    }
    delete[] temp;
}


template <typename T>
void msort(T mas[], size_t s){

        if (s <= 1){
            return;
        }
        size_t const left_s = s / 2;
        size_t const right_s = s - left_s;

        msort(&mas[0], left_s); //sorting of the left half
        msort(&mas[left_s], right_s); //sorting of the right half
        merge(&mas[0], left_s, right_s); //merging
}
