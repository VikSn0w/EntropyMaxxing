//
// Created by Vittorio on 27/03/2026.
//

#include "BeadSort.h"
void beadSort(int arr[], int length) {
    int max = max_element(arr, length);

    int **beads = (int **)calloc(length, sizeof(int *));
    for (int i = 0; i < length; i++) {
        beads[i] = (int *)calloc(max, sizeof(int));
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < arr[i]; j++) {
            beads[i][j] = 1;
        }
    }

    for (int j = 0; j < max; j++) {
        int sum = 0;
        for (int i = 0; i < length; i++) {
            sum += beads[i][j];
            beads[i][j] = 0; // Clear it to redistribute
        }

        for (int i = length - 1; i >= length - sum; i--) {
            beads[i][j] = 1;
        }
    }

    for (int i = 0; i < length; i++) {
        int row_sum = 0;
        for (int j = 0; j < max; j++) {
            row_sum += beads[i][j];
        }
        arr[i] = row_sum;
    }

    for (int i = 0; i < length; i++) {
        free(beads[i]);
    }
    free(beads);
}