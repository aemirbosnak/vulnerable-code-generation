//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
} Vector;

Vector createVector(int size) {
    Vector v;
    v.data = (int *)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void destroyVector(Vector v) {
    free(v.data);
}

void printVector(Vector v) {
    int i;
    for (i = 0; i < v.size; i++) {
        printf("%d ", v.data[i]);
    }
    printf("\n");
}

void addVectors(Vector v1, Vector v2, Vector result) {
    int i;
    for (i = 0; i < v1.size; i++) {
        result.data[i] = v1.data[i] + v2.data[i];
    }
}

void multiplyVector(Vector v, int scalar, Vector result) {
    int i;
    for (i = 0; i < v.size; i++) {
        result.data[i] = v.data[i] * scalar;
    }
}

int main() {
    int i;
    Vector v1, v2, result;

    // Create vectors
    v1 = createVector(MAX_SIZE);
    v2 = createVector(MAX_SIZE);

    // Fill vectors with random data
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        v1.data[i] = rand() % 100;
        v2.data[i] = rand() % 100;
    }

    // Print vectors
    printf("Vector 1:\n");
    printVector(v1);
    printf("Vector 2:\n");
    printVector(v2);

    // Add vectors
    addVectors(v1, v2, result);
    printf("Result of addition:\n");
    printVector(result);

    // Multiply vector by scalar
    multiplyVector(v1, 2, result);
    printf("Result of multiplication:\n");
    printVector(result);

    // Destroy vectors
    destroyVector(v1);
    destroyVector(v2);
    destroyVector(result);

    return 0;
}