//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

void encrypt(char **matrix, int size, int key)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            if (matrix[r][c] != 0)
            {
                int offset = (key * matrix[r][c]) % MAX_SIZE;
                matrix[r][c] = (matrix[r][c] - offset) % MAX_SIZE + 1;
            }
        }
    }
}

void decrypt(char **matrix, int size, int key)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            if (matrix[r][c] != 0)
            {
                int offset = (key * matrix[r][c]) % MAX_SIZE;
                matrix[r][c] = (matrix[r][c] + offset) % MAX_SIZE + 1;
            }
        }
    }
}

int main()
{
    int size = 3;
    char **matrix = (char **)malloc(size * sizeof(char *));
    for (int r = 0; r < size; r++)
    {
        matrix[r] = (char *)malloc(size * sizeof(char));
    }

    matrix[0][0] = 10;
    matrix[0][1] = 20;
    matrix[0][2] = 30;
    matrix[1][0] = 40;
    matrix[1][1] = 50;
    matrix[1][2] = 60;
    matrix[2][0] = 70;
    matrix[2][1] = 80;
    matrix[2][2] = 90;

    int key = 13;
    encrypt(matrix, size, key);

    key = 13;
    decrypt(matrix, size, key);

    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }

    free(matrix);
    return 0;
}