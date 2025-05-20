//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void bucket_sort(int arr[], int n);
void print_array(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // generate random numbers
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // sort using bucket sort
    bucket_sort(arr, n);

    // print sorted array
    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}

void bucket_sort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucket_size = range / n;

    int *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] >= (min + j * bucket_size) && arr[i] < (min + (j + 1) * bucket_size)) {
                int k = 0;
                while (k < bucket_size && buckets[j][k]!= -1) {
                    k++;
                }
                buckets[j][k] = arr[i];
            }
        }
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

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}