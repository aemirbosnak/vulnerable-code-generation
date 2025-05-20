//FormAI DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>

int main() {

    // Matrix creation and initialization

    int shape = 1; // initialize shape to square

    int rows, cols;

    printf("Enter the number of rows: ");

    scanf("%d", &rows);

    printf("Enter the number of columns: ");

    scanf("%d", &cols);

    int a[rows][cols], b[rows][cols], result[rows][cols];

    printf("Enter values for matrix A:\n");

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            printf("Enter value for A[%d][%d]: ", i, j);

            scanf("%d", &a[i][j]);

        }

    }

    printf("Enter values for matrix B:\n");

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            printf("Enter value for B[%d][%d]: ", i, j);

            scanf("%d", &b[i][j]);

        }

    }

    // Matrix operations

    char choice;

    printf("Select an operation to perform (+, -, x): ");

    scanf("%c", &choice);

    if(choice == '\n') {
        scanf("%c", &choice);
    }

    switch (choice) {

        case '+':

            if (shape == 0) { // if matrix is row vector

                for (int i = 0; i < cols; i++) {

                    result[0][i] = a[0][i] + b[0][i];

                }

            } else if (shape == 1) { // if matrix is square

                for (int i = 0; i < rows; i++) {

                    for (int j = 0; j < cols; j++) {

                        result[i][j] = a[i][j] + b[i][j];

                    }

                }

            } else { // if matrix is column vector

                for (int i = 0; i < rows; i++) {

                    result[i][0] = a[i][0] + b[i][0];

                }

            }

            printf("Result of matrix addition:\n");

            for (int i = 0; i < rows; i++) {

                for (int j = 0; j < cols; j++) {

                    printf("%d ", result[i][j]);

                }

                printf("\n");

            }

            break;

        case '-':

            if (shape == 0) { // if matrix is row vector

                for (int i = 0; i < cols; i++) {

                    result[0][i] = a[0][i] - b[0][i];

                }

            } else if (shape == 1) { // if matrix is square

                for (int i = 0; i < rows; i++) {

                    for (int j = 0; j < cols; j++) {

                        result[i][j] = a[i][j] - b[i][j];

                    }

                }

            } else { // if matrix is column vector

                for (int i = 0; i < rows; i++) {

                    result[i][0] = a[i][0] - b[i][0];

                }

            }

            printf("Result of matrix subtraction:\n");

            for (int i = 0; i < rows; i++) {

                for (int j = 0; j < cols; j++) {

                    printf("%d ", result[i][j]);

                }

                printf("\n");

            }

            break;

        case 'x':

            if (shape == 0) { // if matrix is row vector

                int dot_product = 0;

                for (int i = 0; i < cols; i++) {

                    dot_product += a[0][i] * b[0][i];

                }

                printf("Result of dot product: %d\n", dot_product);

            } else if (shape == 1) { // if matrix is square

                for (int i = 0; i < rows; i++) {

                    for (int j = 0; j < cols; j++) {

                        int element_sum = 0;

                        for (int k = 0; k < rows; k++) {

                            element_sum += a[i][k] * b[k][j];

                        }

                        result[i][j] = element_sum;

                    }

                }

                printf("Result of matrix multiplication:\n");

                for (int i = 0; i < rows; i++) {

                    for (int j = 0; j < cols; j++) {

                        printf("%d ", result[i][j]);

                    }

                    printf("\n");

                }

            } else { // if matrix is column vector

                printf("Error: Cannot multiply column vectors\n");

            }

            break;

        default:

            printf("Error: Invalid operation selected\n");

            break;

    }

    return 0;

}