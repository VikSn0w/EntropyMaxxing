#include <stdio.h>
#include "addons.h"
#include "SORTINGS/BeadSort/BeadSort.h"
#include "SORTINGS/BogoSort/BogoSort.h"
#include "SORTINGS/JingleSort/JingleSort.h"

int main(void) {
    int unsorted_arr[] = {1, 3, 2, 4, 5, 4, 5, 6 ,7};
    int unsorted_size = sizeof(unsorted_arr) / sizeof(unsorted_arr[0]);
    print_array(unsorted_arr, unsorted_size);
    jingle_sort(unsorted_arr, unsorted_size);
    printf("\n");
    print_array(unsorted_arr, unsorted_size);
    return 0;
}
