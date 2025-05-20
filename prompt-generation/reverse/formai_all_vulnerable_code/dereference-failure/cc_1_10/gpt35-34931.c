//FormAI DATASET v1.0 Category: Image Classification system ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float sigmoid(float x) {
    // Sigmoid function for activation
    return 1 / (1 + exp(-x));
}

typedef struct {
    int width;
    int height;
    float** data;
} Matrix;

Matrix* createMatrix(int width, int height) {
    // Creating a new matrix given width and height
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->width = width;
    matrix->height = height;
    matrix->data = malloc(sizeof(float*) * height);
    for(int i = 0; i < height; i++) {
        matrix->data[i] = malloc(sizeof(float) * width);
    }
    return matrix;
}

void freeMatrix(Matrix* matrix) {
    // Freeing the matrix memory
    for(int i = 0; i < matrix->height; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void randomizeMatrix(Matrix* matrix) {
    // Randomizing the Matrix data with random numbers between -1 to 1
    for(int i = 0; i < matrix->height; i++) {
        for(int j = 0; j < matrix->width; j++) {
            matrix->data[i][j] = ((float) rand() / RAND_MAX) * 2 - 1;
        }
    }
}

Matrix* dotProduct(Matrix* matrix1, Matrix* matrix2) {
    // Performing dotProduct of two matrices
    Matrix* result = createMatrix(matrix2->width, matrix1->height);
    for(int i = 0; i < result->height; i++) {
        for(int j = 0; j < result->width; j++) {
            float sum = 0;
            for(int k = 0; k < matrix1->width; k++) {
                sum += matrix1->data[i][k] * matrix2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

Matrix* addBias(Matrix* matrix, Matrix* bias) {
    // Adding bias Matrix to the given Matrix
    Matrix* result = createMatrix(matrix->width, matrix->height);
    for(int i = 0; i < matrix->height; i++) {
        for(int j = 0; j < matrix->width; j++) {
            result->data[i][j] = matrix->data[i][j] + bias->data[0][j];
        }
    }
    return result;
}

Matrix* applyActivation(Matrix* matrix) {
    // Applying sigmoid activation function to the Matrix
    Matrix* result = createMatrix(matrix->width, matrix->height);
    for(int i = 0; i < matrix->height; i++) {
        for(int j = 0; j < matrix->width; j++) {
            result->data[i][j] = sigmoid(matrix->data[i][j]);
        }
    }
    return result;
}

int main() {
    // Creating the Neural Network
    Matrix* input = createMatrix(3, 1);
    input->data[0][0] = 1;
    input->data[1][0] = 2;
    input->data[2][0] = 3;
    Matrix* weights1 = createMatrix(2, 3);
    randomizeMatrix(weights1);
    Matrix* bias1 = createMatrix(1, 2);
    randomizeMatrix(bias1);
    Matrix* layer1Output = addBias(dotProduct(weights1, input), bias1);
    layer1Output = applyActivation(layer1Output);
    Matrix* weights2 = createMatrix(1, 2);
    randomizeMatrix(weights2);
    Matrix* bias2 = createMatrix(1, 1);
    randomizeMatrix(bias2);
    Matrix* output = addBias(dotProduct(weights2, layer1Output), bias2);
    output = applyActivation(output);

    // Printing the output
    printf("The classification result is: %f\n", output->data[0][0]);

    // Freeing the memory
    freeMatrix(input);
    freeMatrix(weights1);
    freeMatrix(bias1);
    freeMatrix(layer1Output);
    freeMatrix(weights2);
    freeMatrix(bias2);
    freeMatrix(output);

    return 0;
}