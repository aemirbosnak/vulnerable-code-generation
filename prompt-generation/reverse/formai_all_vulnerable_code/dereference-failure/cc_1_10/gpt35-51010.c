//FormAI DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define ROWS 3
#define COLUMNS 3

// matrix structures
typedef struct {
    int matrix[ROWS][COLUMNS];
} Matrix;

// function to print a matrix
void printMatrix(Matrix* m) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("%d ", m->matrix[i][j]);
        }
        printf("\n");
    }
}

// function for adding two matrices asynchronously
void* addMatricesAsync(void* m) {
    Matrix* matrixA = (Matrix*)m;
    Matrix* matrixB = (Matrix*)malloc(sizeof(Matrix));
    Matrix* matrixC = (Matrix*)malloc(sizeof(Matrix));
    
    srand(time(NULL));
    
    // delay thread by random amount of time
    int delay = rand() % 3 + 1;
    sleep(delay);
    
    // fill matrix B with random values
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            matrixB->matrix[i][j] = rand() % 10 + 1;
        }
    }
    
    printf("Matrix A:\n");
    printMatrix(matrixA);
    printf("Matrix B:\n");
    printMatrix(matrixB);
    
    // add matrices A and B
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            matrixC->matrix[i][j] = matrixA->matrix[i][j] + matrixB->matrix[i][j];
        }
    }
    
    printf("Result Matrix C:\n");
    printMatrix(matrixC);
    
    free(matrixB);
    free(matrixC);
    
    return NULL;
}

int main() {
    // create matrix A
    Matrix matrixA = {
        { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }
    };
    
    // create 3 threads to add matrices A and B
    pthread_t threads[3];
    for(int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, addMatricesAsync, (void*)&matrixA);
    }
    
    // wait for all threads to finish
    for(int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}