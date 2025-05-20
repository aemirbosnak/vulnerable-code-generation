//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 1000000

int get_minimum(int* arr, int size) {
    int minimum = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

int get_maximum(int* arr, int size) {
    int maximum = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}

int* sort_and_merge(int* arr, int size) {
    int* sorted_arr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        sorted_arr[i] = arr[i];
    }
    int left_index = 0;
    int right_index = size - 1;
    int mid_index = 0;
    int i = 0;
    while (left_index <= right_index) {
        if (sorted_arr[left_index] == sorted_arr[right_index]) {
            left_index++;
            right_index--;
        } else if (sorted_arr[left_index] < sorted_arr[right_index]) {
            sorted_arr[mid_index] = sorted_arr[left_index];
            left_index++;
            mid_index++;
        } else {
            sorted_arr[mid_index] = sorted_arr[right_index];
            right_index--;
            mid_index++;
        }
    }
    return sorted_arr;
}

int main() {
    int* arr = (int*)malloc(sizeof(int) * MAX_SIZE);
    int size = 0;
    int* sorted_arr;
    int minimum = 1000000;
    int maximum = -1000000;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    printf("Minimum: %d\n", minimum);
    printf("Maximum: %d\n", maximum);
    sorted_arr = sort_and_merge(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");
    free(arr);
    free(sorted_arr);
    return 0;
}