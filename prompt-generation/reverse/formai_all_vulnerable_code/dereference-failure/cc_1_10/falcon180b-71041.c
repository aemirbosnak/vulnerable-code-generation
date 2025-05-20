//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int *array = (int *) malloc(MAX_SIZE * sizeof(int));
    int size = 0;
    int num;

    srand(time(NULL));

    printf("Enter integers (0 to stop): ");

    while (scanf("%d", &num) == 1) {
        if (size >= MAX_SIZE) {
            printf("Array is full.\n");
            break;
        }
        array[size++] = num;
    }

    printf("Enter a number to search for: ");
    scanf("%d", &num);

    int index = binary_search(array, size, num);

    if (index == -1) {
        printf("Number not found.\n");
    } else {
        printf("Number found at index %d.\n", index);
    }

    free(array);
    return 0;
}

int binary_search(int *array, int size, int num) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (array[mid] == num) {
            return mid;
        } else if (array[mid] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}