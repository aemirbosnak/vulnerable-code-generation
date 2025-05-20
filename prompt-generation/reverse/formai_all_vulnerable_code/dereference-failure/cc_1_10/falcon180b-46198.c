//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(void* a, void* b) {
    int* num1 = (int*)a;
    int* num2 = (int*)b;
    if (*num1 > *num2) {
        return 1;
    } else if (*num1 < *num2) {
        return -1;
    } else {
        return 0;
    }
}

// Function to perform bucket sort
void bucket_sort(int* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    int range = max / size;
    int* buckets = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        buckets[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        int index = (array[i] / range) * range;
        buckets[index]++;
    }
    for (int i = 0; i < size; i++) {
        int start = (i * range) + 1;
        for (int j = 0; j < buckets[i]; j++) {
            array[start + j] = i * range + j;
        }
    }
    free(buckets);
}

// Main function
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int* array = (int*)malloc(size * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    bucket_sort(array, size);
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}