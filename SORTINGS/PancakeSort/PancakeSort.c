#include "PancakeSort.h"
void flip(int arr[], int k) {
    int left = 0;
    while (left < k) {
        int temp_left = arr[left];
        arr[left] = arr[k];
        arr[k] = temp_left;
        k--;
        left++;
    }
}

void pancakeSort(int arr[], int length) {
    int t_length = length;
    while (t_length > 1) {
        int maxIndex = max_index(arr, t_length);
        if (arr[maxIndex] != t_length - 1) {
            if (arr[maxIndex] != 0) {
                flip(arr, maxIndex);
            }
            flip(arr, t_length - 1);
        }
        t_length--;
    }
}