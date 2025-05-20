//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(int **arr, int n) {
    int i, j, count = 0, prev = -1, curr = -1;
    for (i = 0; i < n; i++) {
        if (prev != arr[i]) {
            curr = arr[i];
            prev = arr[i];
            count++;
        } else {
            curr = arr[i];
            prev = arr[i];
            count++;
        }
    }

    int comp_size = count + 1;
    int **comp_arr = (int **)malloc(comp_size * sizeof(int));
    comp_arr[0] = comp_size;

    i = 0;
    for (j = 0; j < n; j++) {
        if (prev != arr[j]) {
            comp_arr[i++] = arr[j];
            prev = arr[j];
        }
    }

    *arr = comp_arr;
    free(comp_arr);
}

int main() {
    int n = 10;
    int **arr = (int **)malloc(n * sizeof(int));
    arr[0] = n;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 2;
    arr[4] = 3;
    arr[5] = 3;
    arr[6] = 4;
    arr[7] = 5;
    arr[8] = 5;
    arr[9] = 6;

    compress(arr, n);

    printf("Compressed array:\n");
    for (int i = 0; i < arr[0]; i++) {
        printf("%d ", arr[i + 1]);
    }

    return 0;
}