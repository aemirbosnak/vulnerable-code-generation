//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

typedef struct {
    int value;
    int index;
} element;

void generate_array(element arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i].value = rand() % MAX_VALUE;
        arr[i].index = i;
    }
}

void bucket_sort(element arr[], int size) {
    int n = size;
    element temp[n];
    int i, j;
    int max = arr[0].value;
    int min = arr[0].value;

    for (i = 1; i < n; i++) {
        if (arr[i].value > max)
            max = arr[i].value;
        if (arr[i].value < min)
            min = arr[i].value;
    }

    int range = max - min + 1;
    int bucket_size = (range / n) + 1;

    for (i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    for (i = 0; i < n; i++) {
        int bucket = (temp[i].value - min) / bucket_size;
        arr[i] = temp[bucket];
    }
}

void print_array(element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].value);
    }
    printf("\n");
}

int main() {
    element arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Error: Array size too large.\n");
        return 1;
    }

    generate_array(arr, size);
    printf("Original array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);
    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}