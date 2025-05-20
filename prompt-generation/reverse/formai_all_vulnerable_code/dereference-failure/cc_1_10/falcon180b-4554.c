//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_DEPTH 100
#define MAX_STEPS 1000

int width, height, depth, steps;
int **matrix;

void init_matrix() {
    matrix = (int **)malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * width);
    }
}

void free_matrix() {
    for (int i = 0; i < height; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void generate_matrix() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = rand() % depth;
            matrix[y][x] = value;
        }
    }
}

void print_matrix() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", matrix[y][x]);
        }
        printf("\n");
    }
}

void generate_fibonacci_sequence() {
    int a = 0, b = 1;
    for (int i = 0; i < steps; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    srand(time(NULL));

    printf("Enter the width of the matrix: ");
    scanf("%d", &width);

    printf("Enter the height of the matrix: ");
    scanf("%d", &height);

    printf("Enter the depth of the matrix: ");
    scanf("%d", &depth);

    printf("Enter the number of steps for the Fibonacci sequence: ");
    scanf("%d", &steps);

    init_matrix();
    generate_matrix();
    generate_fibonacci_sequence();

    printf("\nMatrix:\n");
    print_matrix();

    free_matrix();

    return 0;
}