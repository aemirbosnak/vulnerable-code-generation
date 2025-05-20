//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matrix
{
    int **data;
    int rows;
    int cols;
} matrix;

matrix *create_matrix(int r, int c)
{
    matrix *m = malloc(sizeof(matrix));
    m->rows = r;
    m->cols = c;
    m->data = malloc(r * c * sizeof(int));
    return m;
}

void print_matrix(matrix *m)
{
    for (int r = 0; r < m->rows; r++)
    {
        for (int c = 0; c < m->cols; c++)
        {
            printf("%d ", m->data[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    matrix *a = create_matrix(3, 3);
    a->data[0][0] = 1;
    a->data[0][1] = 2;
    a->data[0][2] = 3;
    a->data[1][0] = 4;
    a->data[1][1] = 5;
    a->data[1][2] = 6;
    a->data[2][0] = 7;
    a->data[2][1] = 8;
    a->data[2][2] = 9;

    print_matrix(a);

    free(a->data);
    free(a);

    return 0;
}