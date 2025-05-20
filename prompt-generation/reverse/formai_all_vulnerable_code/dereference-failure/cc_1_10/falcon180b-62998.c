//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_STR_LEN 1000

int main() {
    int i, j;
    char *str;
    int *arr;
    clock_t start, end;

    srand(time(NULL));

    printf("Testing string operations...\n");
    str = malloc(MAX_STR_LEN * sizeof(char));
    for (i = 0; i < MAX_STR_LEN; i++) {
        str[i] = rand() % 26 + 'a';
    }
    printf("Random string generated: %s\n", str);

    start = clock();
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_STR_LEN; j++) {
            str[j] = rand() % 26 + 'a';
        }
    }
    end = clock();
    printf("Time taken for string operations: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(str);

    printf("Testing array operations...\n");
    arr = malloc(MAX_SIZE * sizeof(int));
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
    printf("Random array generated: ");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    start = clock();
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
    end = clock();
    printf("Time taken for array operations: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);

    return 0;
}