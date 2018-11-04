#include <iostream>
#include <algorithm>
#include <cstring>
#include <iterator>

using namespace std;

template <typename T>
bool cmp(T &x, T &y){
    return x<y;
}

bool cmp(char* &x, char* &y){
    return strlen(x)<strlen(y);
}

template <typename T>
void merge(T mas[], size_t left_s, size_t right_s) {
    size_t left_pos = 0, right_pos = left_s, new_pos = 0;

    T* temp = new T[right_s + left_s];

    while (left_pos < left_s || right_pos < right_s + left_s) {

        if (cmp(mas[left_pos], mas[right_pos])) {
            temp[new_pos++] = mas[left_pos++];
        }
        else {
            temp[new_pos++] = mas[right_pos++];
        }
        if (left_pos == left_s) {
            //copy(&mas[right_pos], &mas[right_s + left_s], &temp[new_pos]);
            for (size_t i = right_pos; i < right_s + left_s; i++) {
                temp[new_pos] = mas[i];
                new_pos++;
            }
            break;
        }
        if (right_pos == left_s + right_s) {
            //copy(&mas[left_pos], &mas[left_s], &temp[new_pos]);
            for (size_t i = left_pos; i < left_s; i++) {
                temp[new_pos] = mas[i];
                new_pos++;
            }
            break;
        }
    }
    //copy(&temp[0], &temp[right_s + left_s], mas);
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

        msort(&mas[0], left_s);
        msort(&mas[left_s], right_s);
        merge(&mas[0], left_s, right_s);
}