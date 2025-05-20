//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MIN_VALUE INT_MIN
#define MAX_VALUE INT_MAX

typedef struct {
    int arr[MAX_SIZE];
    int size;
} array;

void print_array(const array *a) {
    printf("Printing array contents:\n");
    for (int i = 0; i < a->size; i++) {
        printf("%d ", a->arr[i]);
    }
    printf("\n");
}

void initialize_array(array *a) {
    printf("Initializing array with random values:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        a->arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
    a->size = MAX_SIZE;
}

void find_min_max(const array *a, int *min, int *max) {
    *min = *max = a->arr[0];

    printf("Finding minimum and maximum values:\n");
    for (int i = 0; i < a->size; i++) {
        if (a->arr[i] < *min) {
            *min = a->arr[i];
        }

        if (a->arr[i] > *max) {
            *max = a->arr[i];
        }
    }
}

int main() {
    array my_array;
    int min, max;

    printf("Initializing and printing the array:\n");
    initialize_array(&my_array);
    print_array(&my_array);

    printf("Finding minimum and maximum values:\n");
    find_min_max(&my_array, &min, &max);
    printf("Minimum: %d, Maximum: %d\n", min, max);

    return 0;
}