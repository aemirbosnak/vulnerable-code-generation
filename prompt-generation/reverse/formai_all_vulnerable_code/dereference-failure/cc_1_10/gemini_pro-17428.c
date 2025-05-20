//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 10
#define NUM_MATS 10

// Initialize matrices with random values
void init_matrices(double* m1, double* m2, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            m1[i * size + j] = (double)rand() / RAND_MAX;
            m2[i * size + j] = (double)rand() / RAND_MAX;
        }
    }
}

// Allocate memory for matrices and store them in an array
double** alloc_matrices(int num_mats, int size)
{
    double** matrices = malloc(num_mats * sizeof(double*));
    for (int i = 0; i < num_mats; i++)
    {
        matrices[i] = malloc(size * size * sizeof(double));
    }
    return matrices;
}

// Free the memory allocated for the matrices
void free_matrices(double** matrices, int num_mats, int size)
{
    for (int i = 0; i < num_mats; i++)
    {
        free(matrices[i]);
    }
    free(matrices);
}

// Compute the product of two matrices
void matrix_product(double* m1, double* m2, double* result, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i * size + j] = 0;
            for (int k = 0; k < size; k++)
            {
                result[i * size + j] += m1[i * size + k] * m2[k * size + j];
            }
        }
    }
}

// Compute the mean of the matrix values
double matrix_mean(double* m, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum += m[i * size + j];
        }
    }
    return sum / (size * size);
}

// Compute the determinant of a matrix
double matrix_determinant(double* m, int size)
{
    if (size == 2)
    {
        return m[0] * m[3] - m[1] * m[2];
    }

    double det = 0;
    for (int i = 0; i < size; i++)
    {
        double* submatrix = malloc((size - 1) * (size - 1) * sizeof(double));
        for (int j = 1; j < size; j++)
        {
            int submatrix_index = (j - 1) * (size - 1);
            for (int k = 0; k < size; k++)
            {
                if (k == i)
                {
                    continue;
                }
                submatrix[submatrix_index++] = m[j * size + k];
            }
        }
        det += (i % 2 == 0 ? 1 : -1) * m[i] * matrix_determinant(submatrix, size - 1);
    }
    return det;
}

// Compute the inverse of a matrix
void matrix_inverse(double* m, double* inv, int size)
{
    double det = matrix_determinant(m, size);
    if (det == 0)
    {
        printf("Singular matrix. Cannot compute the inverse.\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            double* submatrix = malloc((size - 1) * (size - 1) * sizeof(double));
            int submatrix_index = 0;
            for (int k = 0; k < size; k++)
            {
                for (int l = 0; l < size; l++)
                {
                    if (k == i || l == j)
                    {
                        continue;
                    }
                    submatrix[submatrix_index++] = m[k * size + l];
                }
            }
            inv[i * size + j] = ((i + j) % 2 == 0 ? 1 : -1) * matrix_determinant(submatrix, size - 1) / det;
        }
    }
}

// Print a matrix
void print_matrix(double* m, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%.2f ", m[i * size + j]);
        }
        printf("\n");
    }
}

int main()
{
    int size = ROWS * COLS;
    int num_mats = NUM_MATS;

    // Allocate memory for the matrices
    double** matrices = alloc_matrices(num_mats, size);

    // Initialize the matrices with random values
    for (int i = 0; i < num_mats; i++)
    {
        init_matrices(matrices[i], matrices[i], size);
    }

    // Compute the mean of each matrix
    double* means = malloc(num_mats * sizeof(double));
    for (int i = 0; i < num_mats; i++)
    {
        means[i] = matrix_mean(matrices[i], size);
    }

    // Print the mean of each matrix
    printf("Mean of each matrix:\n");
    for (int i = 0; i < num_mats; i++)
    {
        printf("Matrix %d: %.2f\n", i + 1, means[i]);
    }

    // Compute the determinants of the matrices
    double* dets = malloc(num_mats * sizeof(double));
    for (int i = 0; i < num_mats; i++)
    {
        dets[i] = matrix_determinant(matrices[i], size);
    }

    // Print the determinants of the matrices
    printf("\nDeterminants of the matrices:\n");
    for (int i = 0; i < num_mats; i++)
    {
        printf("Matrix %d: %.2f\n", i + 1, dets[i]);
    }

    // Compute the inverse of each matrix
    double** inverses = alloc_matrices(num_mats, size);
    for (int i = 0; i < num_mats; i++)
    {
        matrix_inverse(matrices[i], inverses[i], size);
    }

    // Print the inverses of the matrices
    printf("\nInverses of the matrices:\n");
    for (int i = 0; i < num_mats; i++)
    {
        printf("Matrix %d:\n", i + 1);
        print_matrix(inverses[i], size);
    }

    // Free the memory allocated for the matrices
    free_matrices(matrices, num_mats, size);
    free_matrices(inverses, num_mats, size);
    free(means);
    free(dets);
    return 0;
}