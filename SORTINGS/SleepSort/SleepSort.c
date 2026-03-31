//
// Created by Vittorio on 23/03/2026.
//

#include "SleepSort.h"
typedef struct {
    int* target_array;
    int* index;
    int value;
    pthread_mutex_t* lock;
} thread_data;

void* routine(void* arg) {
    thread_data* data = (thread_data*)arg;

    usleep(data->value * 10000);

    pthread_mutex_lock(data->lock);
    data->target_array[*(data->index)] = data->value;
    (*(data->index))++;
    pthread_mutex_unlock(data->lock);

    free(data);
    return NULL;
}

void sleep_sort(int arr[], int size) {
    pthread_t threads[size];
    pthread_mutex_t lock;
    pthread_mutex_init(&lock, NULL);

    int write_index = 0;

    for (int i = 0; i < size; i++) {
        thread_data* data = malloc(sizeof(thread_data));
        data->target_array = arr;
        data->index = &write_index;
        data->value = arr[i];
        data->lock = &lock;

        if (pthread_create(&threads[i], NULL, &routine, data) != 0) {
            free(data);
        }
    }

    for (int i = 0; i < size; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
}