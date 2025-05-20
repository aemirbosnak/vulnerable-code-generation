//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

void love(int x, int y) {
    int i, j;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int gx, gy, i, j, n, m, p, q, t, k, u, v;
    char ch;

    printf("Enter number of rows: ");
    scanf("%d", &n);
    printf("Enter number of columns: ");
    scanf("%d", &m);

    int arr[n][m];

    printf("\nEnter the elements of the matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nEnter the row and column of the submatrix:\n");
    scanf("%d%d", &gx, &gy);

    if (gx > n || gy > m) {
        printf("Invalid submatrix dimensions.\n");
        exit(0);
    }

    int submatrix[gx][gy];

    for (i = 0; i < gx; i++) {
        for (j = 0; j < gy; j++) {
            submatrix[i][j] = arr[i][j];
        }
    }

    int det = 0;

    if (gx == 1) {
        det = submatrix[0][0];
    } else if (gx == 2) {
        det = submatrix[0][0] * submatrix[1][1] - submatrix[0][1] * submatrix[1][0];
    } else if (gx == 3) {
        det = submatrix[0][0] * (submatrix[1][1] * submatrix[2][2] + submatrix[1][2] * submatrix[2][1]) -
               submatrix[0][1] * (submatrix[1][0] * submatrix[2][2] + submatrix[1][2] * submatrix[2][0]) +
               submatrix[0][2] * (submatrix[1][0] * submatrix[2][1] - submatrix[1][1] * submatrix[2][0]);
    }

    printf("\nThe determinant of the submatrix is: %d\n", det);

    return 0;
}