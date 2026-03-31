#include "addons.h"

bool is_sorted(const int arr[], size_t size) {
    if (size <= 1) {
        return true;
    }

    for (size_t i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }

    return true;
}

void pop_at_index(int arr[], int *size, int index) {
    if (index < 0 || index >= *size) {
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d] = %d ", i, arr[i]);
    }
}

int max_index(int arr[], int length) {
    int max = arr[0];
    int max_index = 0;
    for (int i = 0; i < length; i++) {
        if (max < arr[i]) {
            max = arr[i];
            max_index = i;
        }
    }
    return max_index;
}

int max_element(int arr[], int length) {
    return arr[max_index(arr, length)];
}

void swap_2_elements(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}