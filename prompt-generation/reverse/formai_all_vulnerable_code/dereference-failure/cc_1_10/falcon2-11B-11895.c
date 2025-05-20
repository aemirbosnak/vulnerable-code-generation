//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int n = 10;
    int i;
    int num1, num2;
    int* arr = (int*)malloc(n * sizeof(int));
    int* arr2 = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 10;
        arr2[i] = rand() % 10;
    }

    printf("Initial array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        num1 = rand() % n;
        num2 = rand() % n;
        while (num1 == i || num2 == i) {
            num1 = rand() % n;
            num2 = rand() % n;
        }

        int temp = arr2[num1];
        arr2[num1] = arr2[num2];
        arr2[num2] = temp;
    }

    printf("Revealed array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        if (arr[i] == arr2[i]) {
            printf("c");
        } else {
            printf("c");
        }
    }

    free(arr);
    free(arr2);

    return 0;
}