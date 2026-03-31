#include "JingleSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    int value;
} Child;

int* global_arr;
atomic_int current_index = 0;

void* child_behavior(void* arg) {
    int gift = *(int*)arg;

    usleep(gift * 100000);

    int my_rank = atomic_fetch_add(&current_index, 1);
    global_arr[my_rank] = gift;

    free(arg);
    return NULL;
}

void jingle_sort(int arr[], int n) {
    global_arr = arr;
    current_index = 0;
    pthread_t kids[n];

    for (int i = 0; i < n; i++) {
        int* val = malloc(sizeof(int));
        *val = arr[i];
        pthread_create(&kids[i], NULL, child_behavior, val);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(kids[i], NULL);
    }
}