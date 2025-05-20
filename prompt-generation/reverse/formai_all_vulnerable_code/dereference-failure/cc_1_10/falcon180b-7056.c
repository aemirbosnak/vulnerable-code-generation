//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 1000

typedef struct {
    int *data;
    int size;
} Array;

void initArray(Array *array) {
    array->data = (int *)malloc(MAX_ARRAY_SIZE * sizeof(int));
    array->size = 0;
}

void addElement(Array *array, int element) {
    if (array->size == MAX_ARRAY_SIZE) {
        printf("Error: Array is full.\n");
        return;
    }
    array->data[array->size++] = element;
}

void bucketSort(Array *array) {
    int max = 0;
    for (int i = 0; i < array->size; i++) {
        if (array->data[i] > max) {
            max = array->data[i];
        }
    }
    int *bucket = (int *)malloc(max * sizeof(int));
    memset(bucket, 0, max * sizeof(int));
    for (int i = 0; i < array->size; i++) {
        bucket[array->data[i]]++;
    }
    int index = 0;
    for (int i = 0; i < max; i++) {
        while (bucket[i] > 0) {
            array->data[index++] = i;
            bucket[i]--;
        }
    }
    free(bucket);
}

void printArray(Array *array) {
    printf("Array: ");
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    Array array;
    initArray(&array);
    int choice;
    while (1) {
        printf("Enter your choice:\n1. Add element\n2. Print array\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int element;
                printf("Enter element: ");
                scanf("%d", &element);
                addElement(&array, element);
                break;
            }
            case 2: {
                printArray(&array);
                break;
            }
            case 3: {
                bucketSort(&array);
                printArray(&array);
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }
    return 0;
}