//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 1024   // Define the size for the matrices
#define THREAD_COUNT 8 // Number of threads for multiplication

typedef struct {
    int id; 
    int (*a)[SIZE]; 
    int (*b)[SIZE]; 
    int (*c)[SIZE]; 
} MatrixData;

void *multiply(void *arg) {
    MatrixData *data = (MatrixData *) arg;
    int id = data->id;
    int (*a)[SIZE] = data->a;
    int (*b)[SIZE] = data->b;
    int (*c)[SIZE] = data->c;

    for (int i = id; i < SIZE; i += THREAD_COUNT) {
        for (int j = 0; j < SIZE; j++) {
            c[i][j] = 0; // Ensure to reset the matrix cell
            for (int k = 0; k < SIZE; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return NULL;
}

void initialize_matrix(int (*matrix)[SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = rand() % 10; // Fill matrix with random numbers
}

void print_matrix(int (*matrix)[SIZE]) {
    for (int i = 0; i < 10; i++) { // just print the first 10 rows for brevity
        for (int j = 0; j < 10; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int (*a)[SIZE] = malloc(SIZE * SIZE * sizeof(int));
    int (*b)[SIZE] = malloc(SIZE * SIZE * sizeof(int));
    int (*c)[SIZE] = malloc(SIZE * SIZE * sizeof(int));

    if (a == NULL || b == NULL || c == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    initialize_matrix(a);
    initialize_matrix(b);

    pthread_t threads[THREAD_COUNT];
    MatrixData thread_data[THREAD_COUNT];

    clock_t start = clock();

    // Create threads for matrix multiplication
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_data[i].id = i;
        thread_data[i].a = a;
        thread_data[i].b = b;
        thread_data[i].c = c;
        pthread_create(&threads[i], NULL, multiply, &thread_data[i]);
    }

    // Join threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_t end = clock();

    printf("Matrix A:\n");
    print_matrix(a);
    printf("Matrix B:\n");
    print_matrix(b);
    printf("Matrix C (Result of A * B):\n");
    print_matrix(c);
    
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication: %f seconds\n", time_spent);

    // Cleanup
    free(a);
    free(b);
    free(c);

    return 0;
}