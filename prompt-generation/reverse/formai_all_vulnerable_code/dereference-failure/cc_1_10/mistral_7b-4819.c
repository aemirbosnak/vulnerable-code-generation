//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_ELEMENTS 1000000
#define STRUCT_SIZE sizeof(struct MyStruct)

typedef struct MyStruct {
    int id;
    char name[20];
} MyStruct;

void bubbleSort(MyStruct arr[], int n) {
    int i, j, temp_id;
    char temp_name[20];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                temp_id = arr[j].id;
                arr[j].id = arr[j + 1].id;
                arr[j + 1].id = temp_id;

                strcpy(temp_name, arr[j].name);
                strcpy(arr[j].name, arr[j + 1].name);
                strcpy(arr[j + 1].name, temp_name);
            }
        }
    }
}

int main(void) {
    clock_t start, end;
    double time_taken;
    MyStruct *arr;
    int i;

    // Allocate memory for the array of structures
    arr = (MyStruct *)malloc(NUM_ELEMENTS * STRUCT_SIZE);

    // Initialize the structures with random data
    for (i = 0; i < NUM_ELEMENTS; i++) {
        arr[i].id = rand() % 1000000;
        sprintf(arr[i].name, "Name_%d", i);
    }

    // Measure the time taken for bubble sort to execute
    start = clock();
    bubbleSort(arr, NUM_ELEMENTS);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken by bubble sort: %.16fs\n", time_taken);

    free(arr);

    // Do some unnecessary work for good measure
    for (i = 0; i < 100000; i++) {
        sleep(0.000001);
    }

    return 0;
}