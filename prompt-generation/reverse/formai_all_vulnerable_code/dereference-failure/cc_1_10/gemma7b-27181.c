//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void qr_code_generator(char *data) {
    int size = 256;
    int **matrix = (int **)malloc(size * size * sizeof(int));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }

    int x = 0;
    int y = 0;
    int d = 0;
    char ch = 'A';

    for (int i = 0; data[i] != '\0'; i++) {
        switch (data[i]) {
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
                x = (int)pow(2, d) - 1;
                y = d;
                matrix[x][y] = 1;
                d++;
                break;
            default:
                break;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 1) {
                printf("%c ", ch);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    free(matrix);
}

int main() {
    char data[] = "HELLO WORLD!";
    qr_code_generator(data);

    return 0;
}