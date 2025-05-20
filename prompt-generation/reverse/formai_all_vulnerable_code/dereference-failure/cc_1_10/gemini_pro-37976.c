//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack operations
typedef struct Stack {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Matrix operations
typedef struct Matrix {
    int rows;
    int columns;
    int** data;
} Matrix;

Matrix* createMatrix(int rows, int columns) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->data = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int*)malloc(sizeof(int) * columns);
    }
    return matrix;
}

void printMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* addMatrices(Matrix* matrix1, Matrix* matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns) {
        printf("Matrices cannot be added: dimensions are not the same\n");
        return NULL;
    }
    Matrix* result = createMatrix(matrix1->rows, matrix1->columns);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->columns; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

Matrix* subtractMatrices(Matrix* matrix1, Matrix* matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns) {
        printf("Matrices cannot be subtracted: dimensions are not the same\n");
        return NULL;
    }
    Matrix* result = createMatrix(matrix1->rows, matrix1->columns);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->columns; j++) {
            result->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }
    return result;
}

Matrix* multiplyMatrices(Matrix* matrix1, Matrix* matrix2) {
    if (matrix1->columns != matrix2->rows) {
        printf("Matrices cannot be multiplied: inner dimensions are not the same\n");
        return NULL;
    }
    Matrix* result = createMatrix(matrix1->rows, matrix2->columns);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->columns; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < matrix1->columns; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
    return result;
}

// A mysterious function that takes a matrix and a stack, and returns a new matrix with a surprising transformation
Matrix* transformMatrix(Matrix* matrix, Stack* stack) {
    if (stack->top < 0) {
        printf("Stack is empty: cannot perform transformation\n");
        return NULL;
    }
    Matrix* result = createMatrix(matrix->rows, matrix->columns);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            int operation = pop(stack);
            switch (operation) {
                case 1:
                    result->data[i][j] = matrix->data[i][j] + 1;
                    break;
                case 2:
                    result->data[i][j] = matrix->data[i][j] - 1;
                    break;
                case 3:
                    result->data[i][j] = matrix->data[i][j] * 2;
                    break;
                case 4:
                    result->data[i][j] = matrix->data[i][j] / 2;
                    break;
                default:
                    printf("Invalid operation: transformation cannot be performed\n");
                    free(result);
                    return NULL;
            }
        }
    }
    return result;
}

int main() {
    // Create a matrix and populate it with some values
    Matrix* matrix1 = createMatrix(3, 3);
    matrix1->data[0][0] = 1;
    matrix1->data[0][1] = 2;
    matrix1->data[0][2] = 3;
    matrix1->data[1][0] = 4;
    matrix1->data[1][1] = 5;
    matrix1->data[1][2] = 6;
    matrix1->data[2][0] = 7;
    matrix1->data[2][1] = 8;
    matrix1->data[2][2] = 9;

    // Create a stack and push some operations onto it
    Stack* stack = createStack(5);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    // Transform the matrix using the stack
    Matrix* transformedMatrix = transformMatrix(matrix1, stack);

    // Print the transformed matrix
    printMatrix(transformedMatrix);

    // Free the allocated memory
    free(matrix1);
    free(transformedMatrix);
    free(stack);

    return 0;
}