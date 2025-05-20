//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QR_MAX_SIZE 256

// QR code structure
typedef struct {
    int size;
    int **matrix;
} QRCode;

// Create QR code matrix
QRCode *qrcode_create(int size) {
    QRCode *qrcode = (QRCode *)malloc(sizeof(QRCode));
    qrcode->size = size;
    qrcode->matrix = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        qrcode->matrix[i] = (int *)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            qrcode->matrix[i][j] = 0;
        }
    }
    return qrcode;
}

// Free QR code matrix
void qrcode_destroy(QRCode *qrcode) {
    for (int i = 0; i < qrcode->size; i++) {
        free(qrcode->matrix[i]);
    }
    free(qrcode->matrix);
    free(qrcode);
}

// Set QR code matrix value
void qrcode_set(QRCode *qrcode, int x, int y, int value) {
    qrcode->matrix[x][y] = value;
}

// Get QR code matrix value
int qrcode_get(QRCode *qrcode, int x, int y) {
    return qrcode->matrix[x][y];
}

// Calculate QR code mask
int qrcode_mask(int size) {
    int mask = 0;
    for (int i = 0; i < size; i++) {
        mask |= 1 << (size - 1 - i);
    }
    return mask;
}

// Encode QR code data
QRCode *qrcode_encode(char *data, int size) {
    QRCode *qrcode = qrcode_create(size);
    int mask = qrcode_mask(size);
    int pos = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                qrcode_set(qrcode, i, j, 1);
            } else if (data[pos] == '1') {
                qrcode_set(qrcode, i, j, 1);
            } else {
                qrcode_set(qrcode, i, j, 0);
            }
            pos++;
        }
    }
    return qrcode;
}

// Save QR code image
void qrcode_save(QRCode *qrcode, char *filename) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Error: Failed to save QR code image.\n");
        exit(1);
    }
    fwrite(qrcode->matrix[0], sizeof(int), qrcode->size * qrcode->size, f);
    fclose(f);
}

// Main function
int main() {
    char *data = "Hello, world!";
    int size = 10;
    QRCode *qrcode = qrcode_encode(data, size);
    qrcode_save(qrcode, "qrcode.png");
    qrcode_destroy(qrcode);
    return 0;
}