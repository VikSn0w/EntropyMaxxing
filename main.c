#include <stdio.h>
#include <time.h>
#include "addons.h"
#include "SORTINGS/BeadSort/BeadSort.h"
#include "SORTINGS/BogoSort/BogoSort.h"
#include "SORTINGS/BozoSort/BozoSort.h"
#include "SORTINGS/IntelligentDesignSort/IntelligentDesignSort.h"
#include "SORTINGS/JingleSort/JingleSort.h"
#include "SORTINGS/MiracleSort/MiracleSort.h"
#include "SORTINGS/NoSort/NoSort.h"
#include "SORTINGS/PancakeSort/PancakeSort.h"
#include "SORTINGS/PickOne/PickOne.h"
#include "SORTINGS/QuantumBogosort/QuantumBogosort.h"
#include "SORTINGS/SleepSort/SleepSort.h"
#include "SORTINGS/SlowSort/SlowSort.h"
#include "SORTINGS/StalinSort/StalinSort.h"
#include "SORTINGS/StoogeSort/StoogeSort.h"
#include "SORTINGS/ThanosSort/ThanosSort.h"

static const char *ALGO_NAMES[] = {
    "BeadSort", "BogoSort", "BozoSort", "IntelligentDesignSort", "JingleSort",
    "MiracleSort", "NoSort", "PancakeSort", "PickOne", "QuantumBogosort",
    "SleepSort", "SlowSort", "StalinSort", "StoogeSort", "ThanosSort"
};
#define ALGO_COUNT 15

static int *build_array_interactive(int *out_size) {
    printf("How many elements do you want to insert? ");
    int n;
    scanf("%d", &n);
    if (n <= 0) { printf("Invalid number.\n"); return NULL; }

    int *arr = malloc(n * sizeof(int));
    if (!arr) return NULL;

    for (int i = 0; i < n; i++) {
        printf("  arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    *out_size = n;
    return arr;
}

static int *build_array_random(int *out_size) {
    printf("How many elements do you want to generate? ");
    int n;
    scanf("%d", &n);
    if (n <= 0) { printf("Invalid number.\n"); return NULL; }

    int *arr = malloc(n * sizeof(int));
    if (!arr) return NULL;

    srand((unsigned int)time(NULL));
    printf("Value range (min max): ");
    int lo, hi;
    scanf("%d %d", &lo, &hi);
    if (lo > hi) { int tmp = lo; lo = hi; hi = tmp; }

    for (int i = 0; i < n; i++)
        arr[i] = lo + rand() % (hi - lo + 1);

    *out_size = n;
    return arr;
}

#define ARRAY_COLS 5
/* Each cell: "| [%3d] = %6d " = 17 chars, separator = 16 dashes per cell */
static void print_array_box(const char *label, int arr[], int size) {
    const char *sep = "+----------------+----------------+----------------+----------------+----------------+";
    printf("%s\n", label);
    if (size == 0) { printf("(empty)\n"); return; }
    printf("%s\n", sep);
    for (int i = 0; i < size; i++) {
        printf("| [%3d] = %6d ", i, arr[i]);
        if ((i + 1) % ARRAY_COLS == 0 || i == size - 1) {
            /* Pad remaining cells in the last incomplete row */
            if (i == size - 1) {
                int filled = (i % ARRAY_COLS) + 1;
                for (int p = filled; p < ARRAY_COLS; p++)
                    printf("|                 ");
            }
            printf("|\n%s\n", sep);
        }
    }
}

static void print_algo_menu(void) {
    printf("+----------------------------+----------------------------+----------------------------+\n");
    printf("|        # Algorithm         |        # Algorithm         |        # Algorithm         |\n");
    printf("+----------------------------+----------------------------+----------------------------+\n");

    for (int row = 0; row < 5; row++) {
        int c0 = row;
        int c1 = row + 5;
        int c2 = row + 10;
        printf("|  %2d) %-22s|  %2d) %-22s|  %2d) %-22s|\n",
               c0 + 1, ALGO_NAMES[c0],
               c1 + 1, ALGO_NAMES[c1],
               c2 + 1, ALGO_NAMES[c2]);
    }
    printf("+----------------------------+----------------------------+----------------------------+\n");
}

static void print_stats(int algo, int input_size, int output_size,
                        int *arr, struct timespec start, struct timespec end) {
    double elapsed = (end.tv_sec - start.tv_sec) * 1000.0
                   + (end.tv_nsec - start.tv_nsec) / 1e6;

    int mn = arr[0], mx = arr[0];
    for (int i = 1; i < output_size; i++) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
    }

    printf("\n+----------------------------------------+\n");
    printf("|              STATISTICS                |\n");
    printf("+----------------------------------------+\n");
    printf("| Algorithm    : %-24s|\n", ALGO_NAMES[algo - 1]);
    printf("| Input size   : %-24d|\n", input_size);
    printf("| Output size  : %-24d|\n", output_size);
    printf("| Min value    : %-24d|\n", mn);
    printf("| Max value    : %-24d|\n", mx);
    printf("| Time elapsed : %-20.3f ms |\n", elapsed);
    printf("+----------------------------------------+\n");
}

int main(void) {
    printf("=== EntropyMaxxing ===\n\n");
    printf("How do you want to provide the array?\n");
    printf("  1) Random generation\n");
    printf("  2) Manual input\n");
    printf("Choice: ");

    int choice;
    scanf("%d", &choice);
    printf("\n");

    int original_size = 0;
    int *original_arr = NULL;

    switch (choice) {
        case 1: original_arr = build_array_random(&original_size);    break;
        case 2: original_arr = build_array_interactive(&original_size); break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }
    if (!original_arr) return 1;

    while (1) {
        int size = original_size;
        int *arr = malloc(size * sizeof(int));
        if (!arr) break;
        for (int i = 0; i < size; i++) arr[i] = original_arr[i];

        print_array_box("\nInput array:", arr, size);

        printf("\n\n\nSelect a sorting algorithm:\n");
        print_algo_menu();
        printf("  0) Exit\n");
        printf("Choice: ");

        int algo;
        scanf("%d", &algo);
        printf("\n");

        if (algo == 0) { free(arr); break; }
        if (algo < 1 || algo > ALGO_COUNT) {
            printf("Invalid choice.\n");
            free(arr);
            continue;
        }

        int input_size = size;
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

        switch (algo) {
            case  1: beadSort(arr, size);                  break;
            case  2: bogo_sort(arr, size);                 break;
            case  3: bozo_sort(arr, size);                 break;
            case  4: intelligent_design_sort(arr, size);   break;
            case  5: jingle_sort(arr, size);               break;
            case  6: miracle_sort(arr, (size_t)size);      break;
            case  7: no_sort(arr, size);                   break;
            case  8: pancakeSort(arr, size);               break;
            case  9: pick_one(arr, &size);                 break;
            case 10: quantum_bogosort(arr, size);          break;
            case 11: sleep_sort(arr, size);                break;
            case 12: slow_sort(arr, size);                 break;
            case 13: stalin_sort(arr, &size);              break;
            case 14: stooge_sort(arr, size);               break;
            case 15: thanos_sort(arr, &size);              break;
        }

        clock_gettime(CLOCK_MONOTONIC, &end);

        print_array_box("Sorted array:", arr, size);

        print_stats(algo, input_size, size, arr, start, end);

        free(arr);

        while (getchar() != '\n');
        printf("\nPress any key to go back to the menu...");
        getchar();
        printf("\n");
    }

    free(original_arr);
    return 0;
}
