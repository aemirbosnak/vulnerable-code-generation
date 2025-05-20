//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Function to generate a random matrix
void generate_matrix(int rows, int cols, double matrix[][cols]) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

//Function to print a matrix
void print_matrix(int rows, int cols, double matrix[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

//Function to calculate the determinant of a matrix
double determinant(int n, double matrix[][n]) {
    double det = 1;
    for (int i = 0; i < n; i++) {
        int sign = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            sign *= -1;
            double temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
            det += sign * matrix[i][j] * determinant(n - 1, matrix);
        }
    }
    return det;
}

int main() {
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    double matrix[n][n];
    generate_matrix(n, n, matrix);

    printf("The matrix is:\n");
    print_matrix(n, n, matrix);

    double det = determinant(n, matrix);

    printf("The determinant of the matrix is: %lf\n", det);

    return 0;
}