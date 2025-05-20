//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 40

void print_header(int width) {
    printf("---------------------------------------------\n");
    printf("| ");
    for (int i = 0; i < width; i++) {
        printf(" %d |", i);
    }
    printf("\n");
}

void print_row(int arr[], int width) {
    for (int i = 0; i < width; i++) {
        printf(" %d |", arr[i]);
    }
    printf("\n");
}

void print_table(int arr[], int rows, int cols) {
    int width = cols / rows;
    printf("---------------------------------------------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j % width == 0) {
                printf("| ");
            }
            printf(" %d ", arr[i * width + j]);
        }
        printf("\n");
    }
    printf("---------------------------------------------\n");
}

int main() {
    srand(time(NULL));
    int rows = rand() % MAX_ROWS + 1;
    int cols = rand() % MAX_COLS + 1;
    int arr[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        arr[i] = rand() % 100;
    }
    printf("Post-Apocalyptic Data:\n");
    printf("-----------------------\n");
    print_header(cols);
    print_table(arr, rows, cols);
    return 0;
}