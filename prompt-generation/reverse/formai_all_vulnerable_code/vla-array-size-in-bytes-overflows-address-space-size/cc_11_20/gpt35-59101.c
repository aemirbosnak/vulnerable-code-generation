//FormAI DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>

int main() {

    printf("Welcome to this Matrix Operations program!\n");

    int m, n, i, j;
    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter the elements of the matrix:\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The matrix you entered is:\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int choice, k;
    printf("\nWhat operation do you want to perform on the matrix?\n");
    printf("1. Transpose\n2. Row Sum\n3. Column Sum\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("The transpose of the matrix is:\n");
            for(i=0; i<n; i++) {
                for(j=0; j<m; j++) {
                    printf("%d ", matrix[j][i]);
                }
                printf("\n");
            }
            break;

        case 2:
            for(i=0; i<m; i++) {
                int sum = 0;
                for(j=0; j<n; j++) {
                    sum += matrix[i][j];
                }
                printf("The sum of row %d is %d \n", i+1, sum);
            }
            break;

        case 3:
            for(i=0; i<n; i++) {
                int sum = 0;
                for(j=0; j<m; j++) {
                    sum += matrix[j][i];
                }
                printf("The sum of column %d is %d \n", i+1, sum);
            }
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }

    return 0;
}