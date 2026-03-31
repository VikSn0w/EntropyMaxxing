//
// Created by Vittorio on 23/03/2026.
//

#include "ThanosSort.h"

void thanos_sort(int a[], int* length) {
    int temp_len = *length;
    bool isSorted = is_sorted(a, temp_len);
    while (!isSorted){
        temp_len = temp_len / 2;
        isSorted = is_sorted(a, temp_len);
    }
    *length = temp_len;
}
