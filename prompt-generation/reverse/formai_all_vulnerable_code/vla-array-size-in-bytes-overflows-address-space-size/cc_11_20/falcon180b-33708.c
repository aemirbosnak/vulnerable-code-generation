//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a pattern
void print_pattern(int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n, m;

    // Get pattern dimensions from user
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    // Generate a random pattern
    srand(time(NULL));
    int pattern[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pattern[i][j] = rand() % 2;
        }
    }

    // Print the pattern
    printf("Random pattern:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pattern[i][j] == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print the pattern with a border
    printf("\nPattern with border:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("*");
            } else if (pattern[i][j] == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print the pattern with a border and spacing
    printf("\nPattern with border and spacing:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("*");
            } else if (pattern[i][j] == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}