//FormAI DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>

// function to display menu
void display_menu() {
    printf("\n1. Add two matrices");
    printf("\n2. Subtract two matrices");
    printf("\n3. Multiply two matrices");
    printf("\n4. Transpose of a matrix");
    printf("\n5. Exit");
}

// function to add two matrices
void add_matrices(int m1, int n1, int a[][n1], int m2, int n2, int b[][n2], int c[][n1]) {
    if (m1 != m2 || n1 != n2) {
        printf("\nError: Matrices must have same dimensions!\n");
        return;
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\nResultant matrix: \n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

// function to subtract two matrices
void sub_matrices(int m1, int n1, int a[][n1], int m2, int n2, int b[][n2], int c[][n1]) {
    if (m1 != m2 || n1 != n2) {
        printf("\nError: Matrices must have same dimensions!\n");
        return;
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("\nResultant matrix: \n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

// function to multiply two matrices
void mult_matrices(int m1, int n1, int a[][n1], int m2, int n2, int b[][n2], int c[][n2]) {
    if (n1 != m2) {
        printf("\nError: Invalid dimensions for matrix multiplication!\n");
        return;
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            int sum = 0;
            for (int k = 0; k < n1; k++) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
    printf("\nResultant matrix: \n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

// function to find transpose of a matrix
void transpose_matrix(int m, int n, int a[][n], int t[][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t[i][j] = a[j][i];
        }
    }
    printf("\nResultant matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice, m1, n1, m2, n2;
    
    printf("Enter dimensions of matrix 1: ");
    scanf("%d %d", &m1, &n1);
    int a[m1][n1];
    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("Enter dimensions of matrix 2: ");
    scanf("%d %d", &m2, &n2);
    int b[m2][n2];
    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    
    int c[m1][n1], t[n1][m1];
    
    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_matrices(m1, n1, a, m2, n2, b, c);
                break;
            case 2:
                sub_matrices(m1, n1, a, m2, n2, b, c);
                break;
            case 3:
                mult_matrices(m1, n1, a, m2, n2, b, c);
                break;
            case 4:
                transpose_matrix(m1, n1, a, t);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 5);
    
    return 0;
}