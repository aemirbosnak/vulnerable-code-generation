//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define BLACK 0
#define WHITE 1

typedef struct {
    int x, y;
} Point;

void printQRCode(int **qrCode, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (qrCode[i][j] == BLACK) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generateQRCode(char *input, int **qrCode, int size, int pos) {
    int value, mask = 1;
    for (int i = 0; i < strlen(input); i++) {
        value = input[i] - 48;
        for (int j = 0; j < 8; j++) {
            if (value & mask) {
                qrCode[pos][i * 8 + j] = BLACK;
            } else {
                qrCode[pos][i * 8 + j] = WHITE;
            }
            mask <<= 1;
        }
    }
}

int main() {
    char input[MAX_SIZE];
    printf("Enter the text to generate QR code: ");
    scanf("%s", input);

    int size = strlen(input) * 8 + 16;
    int **qrCode = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        qrCode[i] = (int *)malloc(sizeof(int) * size);
    }

    int pos = (size - 1) / 2;
    generateQRCode(input, qrCode, size, pos);

    printQRCode(qrCode, size);

    for (int i = 0; i < size; i++) {
        free(qrCode[i]);
    }
    free(qrCode);

    return 0;
}