//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100000

int rand_num(int lower, int upper) {
    return rand() % (upper - lower + 1) + lower;
}

int main() {
    int num1, num2, n, i, j, temp;
    int *arr1, *arr2;

    printf("Enter the number of elements in the arrays: ");
    scanf("%d", &n);

    arr1 = (int *) malloc(n * sizeof(int));
    arr2 = (int *) malloc(n * sizeof(int));

    printf("Enter the elements of the first array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of the second array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr2[j] > arr2[j + 1]) {
                temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }

    printf("Sorted arrays:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}