//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define QR_VERSION 25
#define QR_SIZE (QR_VERSION * 4 + 17)
#define QR_DATA_SIZE ((QR_SIZE - 17) / 4)

typedef struct {
    int x;
    int y;
} QRPoint;

typedef struct {
    int version;
    int size;
    int dataSize;
    char data[QR_DATA_SIZE];
    int matrix[QR_SIZE][QR_SIZE];
} QRCode;

QRCode *qrcode_new() {
    QRCode *qrcode = malloc(sizeof(QRCode));
    qrcode->version = QR_VERSION;
    qrcode->size = QR_SIZE;
    qrcode->dataSize = QR_DATA_SIZE;
    memset(qrcode->data, 0, QR_DATA_SIZE);
    memset(qrcode->matrix, 0, sizeof(qrcode->matrix));
    return qrcode;
}

void qrcode_free(QRCode *qrcode) {
    free(qrcode);
}

int qrcode_set_data(QRCode *qrcode, char *data) {
    if (strlen(data) > QR_DATA_SIZE) {
        return -1;
    }
    strcpy(qrcode->data, data);
    return 0;
}

int qrcode_generate(QRCode *qrcode) {
    int x, y, i, j;
    QRPoint *finderPatterns[3];
    int **codewords;
    int mask;

    // Find the finder patterns
    finderPatterns[0] = malloc(sizeof(QRPoint));
    finderPatterns[0]->x = 0;
    finderPatterns[0]->y = 0;
    finderPatterns[1] = malloc(sizeof(QRPoint));
    finderPatterns[1]->x = QR_SIZE - 7;
    finderPatterns[1]->y = 0;
    finderPatterns[2] = malloc(sizeof(QRPoint));
    finderPatterns[2]->x = 0;
    finderPatterns[2]->y = QR_SIZE - 7;

    // Generate the codewords
    codewords = malloc(sizeof(int *) * QR_DATA_SIZE);
    for (i = 0; i < QR_DATA_SIZE; i++) {
        codewords[i] = malloc(sizeof(int) * 8);
        for (j = 0; j < 8; j++) {
            codewords[i][j] = rand() % 2;
        }
    }

    // Mask the codewords
    mask = 0;
    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            if ((i + j) % 2 == mask) {
                qrcode->matrix[i][j] = !qrcode->matrix[i][j];
            }
        }
    }

    // Add the finder patterns
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
            qrcode->matrix[finderPatterns[i]->x + j][finderPatterns[i]->y] = 1;
            qrcode->matrix[finderPatterns[i]->x][finderPatterns[i]->y + j] = 1;
            qrcode->matrix[finderPatterns[i]->x + j][finderPatterns[i]->y + 6] = 1;
            qrcode->matrix[finderPatterns[i]->x + 6][finderPatterns[i]->y + j] = 1;
        }
    }

    // Add the alignment patterns
    for (i = 0; i < QR_SIZE; i += 10) {
        for (j = 0; j < QR_SIZE; j += 10) {
            if (i == 0 || i == QR_SIZE - 1 || j == 0 || j == QR_SIZE - 1) {
                continue;
            }
            qrcode->matrix[i - 2][j - 2] = 1;
            qrcode->matrix[i - 2][j + 2] = 1;
            qrcode->matrix[i + 2][j - 2] = 1;
            qrcode->matrix[i + 2][j + 2] = 1;
        }
    }

    // Add the timing pattern
    for (i = 6; i < QR_SIZE; i++) {
        qrcode->matrix[i][8] = 1;
    }
    for (i = 8; i < QR_SIZE; i++) {
        qrcode->matrix[8][i] = 1;
    }

    // Add the data
    i = QR_SIZE - 1;
    j = QR_SIZE - 1;
    for (int k = 0; k < QR_DATA_SIZE; k++) {
        for (int l = 7; l >= 0; l--) {
            if (codewords[k][l] == 1) {
                qrcode->matrix[i][j] = 1;
            }
            if (i == 0) {
                i = QR_SIZE - 1;
            } else {
                i--;
            }
        }
        if (j == 0) {
            j = QR_SIZE - 1;
        } else {
            j--;
        }
    }

    return 0;
}

void qrcode_print(QRCode *qrcode) {
    int i, j;
    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            printf("%d", qrcode->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    QRCode *qrcode = qrcode_new();
    qrcode_set_data(qrcode, "Hello, world!");
    qrcode_generate(qrcode);
    qrcode_print(qrcode);
    qrcode_free(qrcode);
    return 0;
}