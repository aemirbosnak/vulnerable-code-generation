//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

void print_zigzag(int** arr, int width, int height) {
    int i = 0, j = 0, di = 1, dj = 0, direction = 0;

    while (i < height && j < width) {
        printf("%d ", arr[i][j]);

        if (direction) {
            if (!j || arr[i - 1][j - 1] != arr[i][j]) {
                di = -1;
                dj = 1;
                direction = 0;
            }
        } else {
            if (i == height - 1 || arr[i][j + 1] != arr[i][j]) {
                di = 1;
                dj = 1;
                direction = 1;
            }
        }

        i += di;
        j += dj;
    }

    printf("\n");
}

int main() {
    int** arr;
    int i, j;

    arr = (int**) malloc(HEIGHT * sizeof(int*));
    for (i = 0; i < HEIGHT; i++) {
        arr[i] = (int*) calloc(WIDTH, sizeof(int));
    }

    srand(time(NULL));
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            arr[i][j] = rand() % 10 + 1;
        }
    }

    print_zigzag(arr, WIDTH, HEIGHT);

    for (i = 0; i < HEIGHT; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}