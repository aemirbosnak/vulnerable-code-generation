//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int row;
    int col;
    int value;
} Element;

Element *matrix1, *matrix2, *result;

void *matrix_multiplication(void *arg);

int main(int argc, char **argv) {
    int i, j;

    // Initialize matrices
    matrix1 = (Element *) malloc(MAX_ROWS * MAX_COLS * sizeof(Element));
    matrix2 = (Element *) malloc(MAX_ROWS * MAX_COLS * sizeof(Element));
    result = (Element *) malloc(MAX_ROWS * MAX_COLS * sizeof(Element));

    // Fill matrices with random values
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            matrix1[i * MAX_COLS + j].value = rand() % 100;
            matrix2[i * MAX_COLS + j].value = rand() % 100;
        }
    }

    // Create threads for matrix multiplication
    pthread_t threads[MAX_ROWS];
    for (i = 0; i < MAX_ROWS; i++) {
        pthread_create(&threads[i], NULL, matrix_multiplication, (void *) i);
    }

    // Join threads
    for (i = 0; i < MAX_ROWS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print result matrix
    printf("Result:\n");
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", result[i * MAX_COLS + j].value);
        }
        printf("\n");
    }

    return 0;
}

void *matrix_multiplication(void *arg) {
    int row = *(int *) arg;
    int i, j, k;

    for (i = 0; i < MAX_COLS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            result[row * MAX_COLS + i].value += matrix1[row * MAX_COLS + j].value * matrix2[j * MAX_COLS + i].value;
        }
    }

    return NULL;
}