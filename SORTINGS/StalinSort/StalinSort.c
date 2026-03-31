//
// Created by Vittorio on 23/03/2026.
//

#include "StalinSort.h"
void stalin_sort(int arr[], int *length) {
    if (*length == 0) return;
    int temp_val = arr[0];
    int i = 1;
    while (i < *length) {
        if (arr[i] < temp_val) {
            pop_at_index(arr, length, i);
        } else {
            temp_val = arr[i];
            i++;
        }
    }
}
