//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 1000

void generate_random_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int *bucket = (int *)malloc(BUCKET_SIZE * sizeof(int));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        bucket[i] = -1;
    }

    for (int i = 0; i < size; i++) {
        int index = arr[i] / BUCKET_SIZE;
        if (bucket[index] == -1) {
            bucket[index] = i;
        } else {
            int j;
            for (j = index; j < size; j += BUCKET_SIZE) {
                if (bucket[j] == -1) {
                    bucket[j] = i;
                    break;
                }
            }
        }
    }

    int sorted_index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (bucket[i]!= -1) {
            int j;
            for (j = i; j < size; j += BUCKET_SIZE) {
                if (bucket[j]!= -1) {
                    int temp = arr[bucket[j]];
                    arr[bucket[j]] = arr[sorted_index];
                    arr[sorted_index] = temp;
                    sorted_index++;
                }
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generate_random_array(arr, size);

    printf("Original array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}