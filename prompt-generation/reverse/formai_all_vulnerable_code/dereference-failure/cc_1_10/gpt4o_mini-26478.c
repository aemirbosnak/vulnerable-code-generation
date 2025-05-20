//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a Matrix
typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

// Function prototypes
Matrix* createMatrix(int rows, int cols);
void freeMatrix(Matrix *matrix);
Matrix* addMatrices(const Matrix *a, const Matrix *b);
Matrix* subtractMatrices(const Matrix *a, const Matrix *b);
Matrix* multiplyMatrices(const Matrix *a, const Matrix *b);
void printMatrix(const Matrix *matrix);
void fillMatrix(Matrix *matrix);
void transposeMatrix(const Matrix *matrix, Matrix *result);
double determinant(const Matrix *matrix);
Matrix* inverseMatrix(const Matrix *matrix);

int main() {
    // Creating two 3x3 matrices
    Matrix *A = createMatrix(3, 3);
    Matrix *B = createMatrix(3, 3);

    printf("Fill Matrix A:\n");
    fillMatrix(A);
    printf("Fill Matrix B:\n");
    fillMatrix(B);

    // Matrix addition
    Matrix *C = addMatrices(A, B);
    printf("Matrix C (A + B):\n");
    printMatrix(C);

    // Matrix subtraction
    Matrix *D = subtractMatrices(A, B);
    printf("Matrix D (A - B):\n");
    printMatrix(D);

    // Matrix multiplication
    Matrix *E = multiplyMatrices(A, B);
    printf("Matrix E (A * B):\n");
    printMatrix(E);

    // Transpose of Matrix A
    Matrix *transposeA = createMatrix(A->cols, A->rows);
    transposeMatrix(A, transposeA);
    printf("Transpose of Matrix A:\n");
    printMatrix(transposeA);

    // Determinant of Matrix A
    double detA = determinant(A);
    printf("Determinant of Matrix A: %.2lf\n", detA);

    // Inverse of Matrix A
    Matrix *inverseA = inverseMatrix(A);
    if (inverseA != NULL) {
        printf("Inverse of Matrix A:\n");
        printMatrix(inverseA);
    } else {
        printf("Matrix A is singular and cannot be inverted.\n");
    }

    // Free allocated memory
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);
    freeMatrix(D);
    freeMatrix(E);
    freeMatrix(transposeA);
    freeMatrix(inverseA);

    return 0;
}

// Function to create a matrix and allocate memory
Matrix* createMatrix(int rows, int cols) {
    Matrix *matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

// Function to free allocated memory of matrix
void freeMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

// Fill matrix with user input
void fillMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%lf", &matrix->data[i][j]);
        }
    }
}

// Print a matrix
void printMatrix(const Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%8.2lf ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Matrix addition
Matrix* addMatrices(const Matrix *a, const Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        return NULL; // Incompatible dimensions
    }
    Matrix *result = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

// Matrix subtraction
Matrix* subtractMatrices(const Matrix *a, const Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        return NULL; // Incompatible dimensions
    }
    Matrix *result = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return result;
}

// Matrix multiplication
Matrix* multiplyMatrices(const Matrix *a, const Matrix *b) {
    if (a->cols != b->rows) {
        return NULL; // Incompatible dimensions
    }
    Matrix *result = createMatrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

// Transpose of a matrix
void transposeMatrix(const Matrix *matrix, Matrix *result) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[j][i] = matrix->data[i][j];
        }
    }
}

// Determinant calculation using recursive method
double determinant(const Matrix *matrix) {
    if (matrix->rows != matrix->cols) {
        return 0; // Not a square matrix
    }
    if (matrix->rows == 1) {
        return matrix->data[0][0];
    }
    double det = 0;
    for (int i = 0; i < matrix->cols; i++) {
        Matrix *subMatrix = createMatrix(matrix->rows - 1, matrix->cols - 1);
        for (int j = 1; j < matrix->rows; j++) {
            int colIndex = 0;
            for (int k = 0; k < matrix->cols; k++) {
                if (k != i) {
                    subMatrix->data[j - 1][colIndex++] = matrix->data[j][k];
                }
            }
        }
        det += (i % 2 == 0 ? 1 : -1) * matrix->data[0][i] * determinant(subMatrix);
        freeMatrix(subMatrix);
    }
    return det;
}

// Inverse of a matrix
Matrix* inverseMatrix(const Matrix *matrix) {
    double det = determinant(matrix);
    if (det == 0) {
        return NULL; // Singular matrix
    }
    // Adjugate method
    Matrix *inv = createMatrix(matrix->rows, matrix->cols);
    Matrix *cofactor = createMatrix(matrix->rows, matrix->cols);
    
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            Matrix *temp = createMatrix(matrix->rows - 1, matrix->cols - 1);
            int rowIndex = 0, colIndex;
            for (int x = 0; x < matrix->rows; x++) {
                for (int y = 0; y < matrix->cols; y++) {
                    if (x != i && y != j) {
                        colIndex = (y < j) ? y : y - 1;
                        temp->data[rowIndex][colIndex] = matrix->data[x][y];
                    }
                }
                if (x != i) rowIndex++;
            }
            cofactor->data[i][j] = (i + j) % 2 == 0 ? determinant(temp) : -determinant(temp);
            freeMatrix(temp);
        }
    }
    
    // Transpose of the cofactor matrix
    transposeMatrix(cofactor, inv);
    
    // Divide each element by the determinant
    for (int i = 0; i < inv->rows; i++) {
        for (int j = 0; j < inv->cols; j++) {
            inv->data[i][j] /= det;
        }
    }
    
    freeMatrix(cofactor);
    return inv;
}