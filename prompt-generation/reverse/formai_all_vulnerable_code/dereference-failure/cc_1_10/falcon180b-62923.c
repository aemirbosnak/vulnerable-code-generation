//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_NUM_OPS 10

int main() {
    int size = rand() % MAX_SIZE + 1;
    int num_ops = rand() % MAX_NUM_OPS + 1;

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    printf("Size of array: %d\n", size);
    printf("Number of operations: %d\n", num_ops);

    srand(time(NULL));
    int *ops = (int *)malloc(num_ops * sizeof(int));
    if (ops == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < num_ops; i++) {
        ops[i] = rand() % 5;
    }

    int result = 0;
    for (int i = 0; i < num_ops; i++) {
        switch (ops[i]) {
            case 0:
                result = result | arr[i];
                break;
            case 1:
                result = result & arr[i];
                break;
            case 2:
                result = result ^ arr[i];
                break;
            case 3:
                result = result << arr[i];
                break;
            case 4:
                result = result >> arr[i];
                break;
            default:
                printf("Error: Invalid operation!\n");
                exit(1);
        }
    }

    printf("Result: %d\n", result);

    free(arr);
    free(ops);

    return 0;
}