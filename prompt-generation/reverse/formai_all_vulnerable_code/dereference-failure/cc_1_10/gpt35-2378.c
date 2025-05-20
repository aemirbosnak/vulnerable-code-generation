//FormAI DATASET v1.0 Category: Image Classification system ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the size of input image and number of classes
#define ROWS 28
#define COLS 28
#define NUM_CLASSES 10

// Define the structure for a matrix
typedef struct {
    int rows;
    int cols;
    double **data;
} matrix;

// Function to allocate memory for the matrix
matrix make_matrix(int rows, int cols) {
    int i;
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double **) malloc(rows * sizeof(double *));
    for (i = 0; i < rows; ++i) {
        m.data[i] = (double *) malloc(cols * sizeof(double));
    }
    return m;
}

// Function to free the memory allocated for the matrix
void free_matrix(matrix m) {
    int i;
    for (i = 0; i < m.rows; ++i) {
        free(m.data[i]);
    }
    free(m.data);
}

// Function to initialize the matrix with random values
void randomize_matrix(matrix m) {
    int i, j;
    for (i = 0; i < m.rows; ++i) {
        for (j = 0; j < m.cols; ++j) {
            m.data[i][j] = (double) rand() / RAND_MAX;
        }
    }
}

// Function to print the matrix
void print_matrix(matrix m) {
    int i, j;
    for (i = 0; i < m.rows; ++i) {
        for (j = 0; j < m.cols; ++j) {
            printf("%f ", m.data[i][j]);
        }
        printf("\n");
    }
}

// Function to create a matrix of all ones
matrix ones_matrix(int rows, int cols) {
    matrix m = make_matrix(rows, cols);
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            m.data[i][j] = 1;
        }
    }
    return m;
}

// Function to multiply two matrices
matrix matmul(matrix a, matrix b) {
    if (a.cols != b.rows) {
        printf("Matrix multiplication error: incompatible dimensions\n");
        exit(1);
    }
    matrix c = make_matrix(a.rows, b.cols);
    int i, j, k;
    for (i = 0; i < a.rows; ++i) {
        for (j = 0; j < b.cols; ++j) {
            for (k = 0; k < a.cols; ++k) {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return c;
}

// Function to add two matrices
matrix add(matrix a, matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Matrix addition error: incompatible dimensions\n");
        exit(1);
    }
    matrix c = make_matrix(a.rows, a.cols);
    int i, j;
    for (i = 0; i < a.rows; ++i) {
        for (j = 0; j < a.cols; ++j) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}

// Function to multiply a matrix with a scalar
matrix scalar_mul(matrix a, double x) {
    matrix c = make_matrix(a.rows, a.cols);
    int i, j;
    for (i = 0; i < a.rows; ++i) {
        for (j = 0; j < a.cols; ++j) {
            c.data[i][j] = x * a.data[i][j];
        }
    }
    return c;
}

// Function to apply the ReLU activation function to a matrix
matrix relu(matrix a) {
    matrix c = make_matrix(a.rows, a.cols);
    int i, j;
    for (i = 0; i < a.rows; ++i) {
        for (j = 0; j < a.cols; ++j) {
            c.data[i][j] = fmax(0, a.data[i][j]);
        }
    }
    return c;
}

// Function to calculate the softmax values of a matrix
matrix softmax(matrix a) {
    matrix c = make_matrix(a.rows, a.cols);
    int i, j;
    for (i = 0; i < a.rows; ++i) {
        double sum = 0;
        for (j = 0; j < a.cols; ++j) {
            sum += exp(a.data[i][j]);
        }
        for (j = 0; j < a.cols; ++j) {
            c.data[i][j] = exp(a.data[i][j]) / sum;
        }
    }
    return c;
}

int main() {
    // Load the input image
    matrix x = make_matrix(ROWS, COLS);
    FILE *img_file = fopen("input_image", "r");
    if (!img_file) {
        printf("Error: could not open input image file\n");
        exit(1);
    }
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            fscanf(img_file, "%lf", &x.data[i][j]);
        }
    }
    fclose(img_file);

    // Define the network architecture
    matrix w1 = make_matrix(100, ROWS * COLS);
    matrix b1 = ones_matrix(100, 1);
    matrix w2 = make_matrix(NUM_CLASSES, 100);
    matrix b2 = ones_matrix(NUM_CLASSES, 1);

    // Initialize the network weights and biases
    randomize_matrix(w1);
    randomize_matrix(w2);

    // Forward pass of the network
    matrix z1 = matmul(w1, x);
    matrix a1 = relu(add(z1, b1));
    matrix z2 = matmul(w2, a1);
    matrix a2 = softmax(add(z2, b2));

    // Print the output probabilities
    print_matrix(a2);

    // Free the memory allocated for the matrices
    free_matrix(x);
    free_matrix(w1);
    free_matrix(b1);
    free_matrix(z1);
    free_matrix(a1);
    free_matrix(w2);
    free_matrix(b2);
    free_matrix(z2);
    free_matrix(a2);

    return 0;
}