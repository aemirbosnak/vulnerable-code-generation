//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MIN_VALUE 0
#define MAX_VALUE 100

int main() {
    int arr[MAX_SIZE];
    int size;
    int i;
    int sum = 0;
    int count = 0;
    int max_value = MIN_VALUE;
    int min_value = MAX_VALUE;
    int avg_value = 0;

    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the values of the array:\n");
    for (i = 0; i < size; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        printf("%d ", arr[i]);
    }

    printf("\n");

    for (i = 0; i < size; i++) {
        sum += arr[i];
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }

    avg_value = sum / size;

    printf("Sum of the array: %d\n", sum);
    printf("Average of the array: %d\n", avg_value);
    printf("Minimum value in the array: %d\n", min_value);
    printf("Maximum value in the array: %d\n", max_value);

    return 0;
}