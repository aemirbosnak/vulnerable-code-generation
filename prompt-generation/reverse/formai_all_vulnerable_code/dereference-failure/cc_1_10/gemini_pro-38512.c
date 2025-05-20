//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: relaxed
// Benchmarking the blazing speed of our C code

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Our blazing-fast function
void turboBoost(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

// The main event, benchmarking in all its glory
int main() {
    clock_t start, end;
    double cpu_time_used;

    // Let's create a humongous array to give our code a good workout
    int size = 10000000;
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Time to let the turbocharged function do its magic
    start = clock();
    turboBoost(arr, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Let's announce the results with a fanfare
    printf("TurboBoost completed in %.6f seconds.\n", cpu_time_used);

    // Now, let's check if our array has indeed doubled in size
    int doubled = 1;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            doubled = 0;
            break;
        }
    }

    if (doubled) {
        printf("Success! The array has been doubled.\n");
    } else {
        printf("Oops, something went wrong. The array is not doubled.\n");
    }

    free(arr);

    return 0;
}