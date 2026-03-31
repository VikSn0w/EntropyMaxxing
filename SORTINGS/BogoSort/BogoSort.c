#include "BogoSort.h"
#include "../../addons.h"
void shuffle(int a[], int length) {
    for (int i = 0; i < length; i++) {
        swap_2_elements(a, i, rand() % length);
    }
}

void bogo_sort(int a[], int length) {
    while (!is_sorted(a, length)) {
        shuffle(a, length);
    }
}

int bogo_sort_debug(int a[], int length) {
    int shuffles = 0;
    while (!is_sorted(a, length)) {
        shuffle(a, length);
        shuffles++;
    }
    return shuffles;
}