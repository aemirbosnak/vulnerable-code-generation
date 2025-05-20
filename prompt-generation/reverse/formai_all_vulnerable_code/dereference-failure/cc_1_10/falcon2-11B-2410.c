//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int n;
    int m;
    int* matrix;
    Point* points;
} PercolationMatrix;

PercolationMatrix* create_percolation_matrix(int n, int m) {
    PercolationMatrix* matrix = malloc(sizeof(PercolationMatrix));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    matrix->n = n;
    matrix->m = m;
    matrix->matrix = malloc(n * m * sizeof(int));
    if (matrix->matrix == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    matrix->points = malloc(n * m * sizeof(Point));
    if (matrix->points == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix->matrix[i * matrix->m + j] = rand() % 2;
            matrix->points[i * matrix->m + j].x = i;
            matrix->points[i * matrix->m + j].y = j;
        }
    }
    return matrix;
}

void print_percolation_matrix(PercolationMatrix* matrix) {
    for (int i = 0; i < matrix->n; i++) {
        for (int j = 0; j < matrix->m; j++) {
            printf("%d ", matrix->matrix[i * matrix->m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void percolate_point(PercolationMatrix* matrix, Point* point) {
    int n = matrix->n;
    int m = matrix->m;
    int x = point->x;
    int y = point->y;
    int connected = 0;
    int new_point;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            new_point = i * m + j;
            if (new_point >= n * m || new_point < 0 || matrix->matrix[new_point] == 0) {
                continue;
            }
            if (i == x && j == y) {
                connected++;
            } else {
                if (matrix->matrix[new_point] == 1) {
                    connected++;
                } else if (matrix->matrix[new_point] == 0) {
                    percolate_point(matrix, matrix->points + new_point);
                    if (matrix->points[new_point].x == x && matrix->points[new_point].y == y) {
                        connected++;
                    }
                }
            }
        }
    }
    if (connected == matrix->n * matrix->m) {
        printf("Percolated point (%d, %d)\n", x, y);
    } else {
        printf("Not percolated point (%d, %d)\n", x, y);
    }
}

int main() {
    srand(time(NULL));
    int n = 10;
    int m = 10;
    PercolationMatrix* matrix = create_percolation_matrix(n, m);
    print_percolation_matrix(matrix);
    Point point1 = { 0, 0 };
    Point point2 = { 3, 3 };
    percolate_point(matrix, &point1);
    percolate_point(matrix, &point2);
    free(matrix->matrix);
    free(matrix->points);
    free(matrix);
    return 0;
}