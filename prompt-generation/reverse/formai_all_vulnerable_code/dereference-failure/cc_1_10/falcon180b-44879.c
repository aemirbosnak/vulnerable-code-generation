//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void generate_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucket_size = max / n;
    int *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (int *) malloc(bucket_size * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        int j = arr[i] / bucket_size;
        int k = 0;
        while (buckets[j][k]!= -1) {
            k++;
        }
        buckets[j][k] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_size; j++) {
            if (buckets[i][j]!= -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    generate_array(arr, n);
    printf("Original array:\n");
    print_array(arr, n);

    bucket_sort(arr, n);
    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}