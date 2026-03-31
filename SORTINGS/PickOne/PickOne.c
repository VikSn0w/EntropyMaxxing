//
// Created by Vittorio on 23/03/2026.
//

#include "PickOne.h"
void pick_one(int arr[], int *size) {
    arr[0] = arr[rand() % *size];
    *size = 1;
}
