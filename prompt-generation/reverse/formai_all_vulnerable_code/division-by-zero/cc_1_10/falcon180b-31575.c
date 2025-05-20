//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size;

    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    printf("\n\nSum of array elements: %d\n", sum);

    int avg = sum / size;
    printf("Average of array elements: %.2f\n", (float)avg / 100);

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("\nMinimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}