//
// Created by Vittorio on 27/03/2026.
//

#include "StoogeSort.h"
void stooge_sort(int arr[], int length) {
    _stooge_sort(arr, 0, length - 1);
}
void _stooge_sort(int arr[], int i, int j) {
    if (arr[i] > arr[j]) {
        swap_2_elements(arr, i, j);
    }
    if ((j - i + 1) > 2) {
        int temp = floor((j - i + 1) / 3);
        _stooge_sort(arr, i, j-temp);
        _stooge_sort(arr, i+temp, j);
        _stooge_sort(arr, i, j-temp);
    }
}