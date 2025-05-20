//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// function to create an array of size n and fill it with unique elements
void create_array(int *array, int n) {
    // create an array of size n
    array = (int*)malloc(n * sizeof(int));

    // fill the array with unique elements
    int i, j, k;
    for (i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }

    // shuffle the array
    for (j = 0; j < n - 1; j++) {
        int temp = array[j];
        for (k = j + 1; k < n; k++) {
            if (array[k] < temp) {
                temp = array[k];
            }
        }
        array[j] = temp;
    }
}

// function to print an array
void print_array(int *array, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// function to perform bucket sort
void bucket_sort(int *array, int n) {
    int *buckets, i, j, k, num_buckets, max_bucket, count;

    // create an array of size n
    buckets = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        buckets[i] = array[i];
    }

    // find the maximum element in the array
    max_bucket = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] > max_bucket) {
            max_bucket = array[i];
        }
    }

    // create num_buckets buckets based on the maximum element
    num_buckets = (max_bucket + 1);

    // allocate memory for buckets
    buckets = (int*)malloc(num_buckets * sizeof(int));

    // sort each bucket
    for (i = 0; i < num_buckets; i++) {
        buckets[i] = array[0];
        count = 1;
        for (j = 1; j < n; j++) {
            if (array[j] <= i * (max_bucket / num_buckets) + 1) {
                buckets[i]++;
                count++;
            } else {
                buckets[i] += array[j] - i * (max_bucket / num_buckets) - 1;
                count++;
                i++;
            }
        }
    }

    // merge the buckets back into the original array
    for (i = 0; i < n; i++) {
        array[i] = buckets[i];
    }

    // free the memory allocated for buckets
    free(buckets);
}

// main function
int main() {
    int n, i;
    srand(time(NULL));

    // create an array of size n
    n = 10;
    int *array = (int*)malloc(n * sizeof(int));
    create_array(array, n);

    // print the array
    print_array(array, n);

    // sort the array using bucket sort
    bucket_sort(array, n);

    // print the sorted array
    print_array(array, n);

    // free the memory allocated for array
    free(array);

    return 0;
}