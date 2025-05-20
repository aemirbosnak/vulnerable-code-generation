//Falcon-180B DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate mean
double calc_mean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) sum / size;
}

// Function to calculate median
double calc_median(int arr[], int size) {
    int mid = size / 2;
    if (size % 2 == 0) {
        return (arr[mid - 1] + arr[mid]) / 2.0;
    } else {
        return arr[mid];
    }
}

// Function to calculate mode
int calc_mode(int arr[], int size) {
    int max_count = 0, mode = 0;
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            mode = arr[i];
        }
    }
    return mode;
}

int main() {
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    int min = rand_num(1, 100);
    int max = rand_num(min, 200);

    printf("Random numbers between %d and %d:\n", min, max);
    for (i = 0; i < size; i++) {
        arr[i] = rand_num(min, max);
        printf("%d ", arr[i]);
    }
    printf("\n");

    double mean = calc_mean(arr, size);
    printf("Mean: %.2f\n", mean);

    double median = calc_median(arr, size);
    printf("Median: %.2f\n", median);

    int mode = calc_mode(arr, size);
    printf("Mode: %d\n", mode);

    return 0;
}