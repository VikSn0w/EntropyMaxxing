//
// Created by Vittorio on 27/03/2026.
//

#include "QuantumBogosort.h"
void quantum_bogosort(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        swap_2_elements(arr, i, rand() % length);
    }

    if (!is_sorted(arr, length)) {
        fprintf(stderr, "CRITICAL: Universe inconsistent. Terminating timeline.\n");
        exit(1);
    }
    printf("Success! You are in the one timeline where this worked.\n");
}