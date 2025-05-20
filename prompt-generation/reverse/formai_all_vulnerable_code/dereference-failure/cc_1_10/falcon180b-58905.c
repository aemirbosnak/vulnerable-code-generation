//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_RANGE 10000
#define BUCKET_SIZE 10

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(Element* arr, int size) {
    Element* buckets[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i].data / BUCKET_SIZE;
        if (buckets[bucketIndex] == NULL) {
            buckets[bucketIndex] = malloc(BUCKET_SIZE * sizeof(Element));
        }
        Element* bucket = buckets[bucketIndex];
        int j = 0;
        while (j < BUCKET_SIZE && bucket[j].data < arr[i].data) {
            j++;
        }
        for (int k = BUCKET_SIZE - 1; k >= j; k--) {
            bucket[k] = bucket[k - 1];
        }
        bucket[j] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (buckets[i]!= NULL) {
            for (int j = 0; j < BUCKET_SIZE; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

void printArray(Element* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int size = rand() % MAX_SIZE + 1;
    Element* arr = malloc(size * sizeof(Element));

    for (int i = 0; i < size; i++) {
        arr[i].data = rand() % MAX_RANGE;
        arr[i].index = i;
    }

    printf("Before sorting:\n");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("After sorting:\n");
    printArray(arr, size);

    free(arr);
    return 0;
}