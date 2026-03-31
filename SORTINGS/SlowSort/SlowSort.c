//
// Created by Vittorio on 27/03/2026.
//

#include "SlowSort.h"
void slow_sort(int arr[], int length) {
    _slow_sort(arr, 0, length - 1);
};

void _slow_sort(int arr[], int i, int j) {
    if (i >= j) return;

    int mid = floor((i + j) / 2);

    _slow_sort(arr, i, mid);
    _slow_sort(arr, mid + 1, j);

    if (arr[j] < arr[mid]) {
        int k = arr[mid];
        arr[mid] = arr[j];
        arr[j] = k;
    }

    _slow_sort(arr, i, j - 1);
}