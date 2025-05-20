//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k, m, count = 0, flag = 0;
    int arr[100], sum = 0, avg, max, min, range;
    char choice;

    srand(time(NULL));
    printf("Enter the number of integers you want to generate: ");
    scanf("%d", &n);

    printf("Do you want to generate random integers? (y/n) ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        for (i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }
    } else {
        printf("Enter %d integers:\n", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
    }

    printf("\nThe array of %d integers is:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    avg = sum / n;

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }

    range = max - min;

    printf("\nSum: %d\n", sum);
    printf("Average: %.2f\n", avg);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Range: %d\n", range);

    return 0;
}