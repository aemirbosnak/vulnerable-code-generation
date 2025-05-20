//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

void print_ascii(int **matrix, int rows, int cols) {
    int i, j;
    char symbol;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            symbol = ' ';
            switch (matrix[i][j]) {
                case 0:
                    symbol = 'O';
                    break;
                case 1:
                    symbol = 'X';
                    break;
                default:
                    break;
            }
            printf("%c", symbol);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int **matrix, rows, cols, i, j;
    char str[MAX];

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    cols = strlen(argv[1]);
    rows = cols / 2 + cols % 2;
    matrix = (int **)calloc(rows, sizeof(int *));

    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)calloc(cols, sizeof(int));
        for (j = 0; j < cols; j++) {
            if (i < rows / 2) {
                matrix[i][j] = argv[1][j] == 'X' ? 1 : 0;
            } else {
                matrix[i][j] = argv[1][cols - j - 1] == 'X' ? 1 : 0;
            }
        }
    }

    print_ascii(matrix, rows, cols);

    for (i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}