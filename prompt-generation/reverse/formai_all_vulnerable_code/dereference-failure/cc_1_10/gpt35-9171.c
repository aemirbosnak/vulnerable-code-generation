//FormAI DATASET v1.0 Category: Game of Life ; Style: multi-threaded
// C Game of Life example program in a multi-threaded style
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variables
int ROWS, COLUMNS, GENERATIONS, THREADS;
int **matrix, **tempMatrix;
pthread_barrier_t barrier;

// Function to allocate memory for matrix
void allocateMatrix() {
    int i;
    matrix = (int **)malloc(sizeof(int *) * ROWS);
    tempMatrix = (int **)malloc(sizeof(int *) * ROWS);
    for (i = 0; i < ROWS; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * COLUMNS);
        tempMatrix[i] = (int *)malloc(sizeof(int) * COLUMNS);
    }
}

// Function to print matrix
void printMatrix() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count live neighbors
int countNeighbours(int i, int j) {
    int neighbours = 0;
    if (matrix[(i - 1 + ROWS) % ROWS][j]) neighbours++;
    if (matrix[(i - 1 + ROWS) % ROWS][(j - 1 + COLUMNS) % COLUMNS]) neighbours++;
    if (matrix[(i - 1 + ROWS) % ROWS][(j + 1) % COLUMNS]) neighbours++;
    if (matrix[(i + 1) % ROWS][j]) neighbours++;
    if (matrix[(i + 1) % ROWS][(j - 1 + COLUMNS) % COLUMNS]) neighbours++;
    if (matrix[(i + 1) % ROWS][(j + 1) % COLUMNS]) neighbours++;
    if (matrix[i][(j - 1 + COLUMNS) % COLUMNS]) neighbours++;
    if (matrix[i][(j + 1) % COLUMNS]) neighbours++;
    return neighbours;
}

// Function to update the matrix values
void *updateMatrix(void *rank) {
    long myRank = (long) rank;
    int i, j, k, start, end, neighbours;
    start = (int) (myRank * ROWS/THREADS);
    end = (int) ((myRank + 1) * ROWS/THREADS);
    for (k = 0; k < GENERATIONS; k++) {
        for (i = start; i < end; i++) {
            for (j = 0; j < COLUMNS; j++) {
                neighbours = countNeighbours(i, j);
                if (matrix[i][j] == 1) {
                    if (neighbours < 2 || neighbours > 3) tempMatrix[i][j] = 0;
                    else tempMatrix[i][j] = 1;
                } else {
                    if (neighbours == 3) tempMatrix[i][j] = 1;
                    else tempMatrix[i][j] = 0;
                }
            }
        }
        // Synchronize threads before updating matrix values
        pthread_barrier_wait(&barrier);
        for (i = start; i < end; i++) {
            for (j = 0; j < COLUMNS; j++) {
                matrix[i][j] = tempMatrix[i][j];
            }
        }
        // Synchronize threads before moving to next generation
        pthread_barrier_wait(&barrier);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: ./game_of_life <rows> <columns> <generations> <threads>\n");
        exit(1);
    }
    ROWS = atoi(argv[1]);
    COLUMNS = atoi(argv[2]);
    GENERATIONS = atoi(argv[3]);
    THREADS = atoi(argv[4]);
    allocateMatrix();
    pthread_barrier_init(&barrier, NULL, THREADS);
    pthread_t threads[THREADS];
    long i;
    for (i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, updateMatrix, (void *) i);
    }
    for (i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printMatrix();
    return 0;
}