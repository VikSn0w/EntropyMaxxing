#include "BozoSort.h"
void swap_2_elements_randomly(int a[], int length) {
    swap_2_elements(a, rand() % length, rand() % length);
}

void bozo_sort(int a[], int length) {
    while (!is_sorted(a, length)) {
        swap_2_elements_randomly(a, length);
    }
}