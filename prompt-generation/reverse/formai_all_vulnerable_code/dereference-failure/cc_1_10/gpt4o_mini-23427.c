//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <math.h>

#define QR_VERSION 1
#define MODULE_SIZE 10
#define BUFFER_SIZE 1024

typedef struct {
    int size;
    int **matrix;
} QRCode;

QRCode* createQRCode(int version) {
    QRCode *qr = (QRCode *)malloc(sizeof(QRCode));
    if (!qr) {
        perror("Failed to allocate memory for QR Code");
        exit(EXIT_FAILURE);
    }
    qr->size = version * 4 + 17; // Basic formula for size
    qr->matrix = (int **)malloc(qr->size * sizeof(int *));
    for (int i = 0; i < qr->size; i++) {
        qr->matrix[i] = (int *)calloc(qr->size, sizeof(int));
    }
    return qr;
}

void generateFinderPatterns(QRCode *qr) {
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            if ((x == 0 || x == 6 || y == 0 || y == 6) || 
               (x >= 2 && x <= 4 && y >= 2 && y <= 4)) {
                qr->matrix[y][x] = 1; // Dark Module
            } else {
                qr->matrix[y][x] = 0; // Light Module
            }
        }
    }
}

void placeFinderPatterns(QRCode *qr) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x = (qr->size - 7) * (i == 1 ? 1 : 0) + 7 * i;
            int y = (qr->size - 7) * (j == 1 ? 1 : 0) + 7 * j;
            for (int m = 0; m < 7; m++) {
                for (int n = 0; n < 7; n++) {
                    qr->matrix[y + m][x + n] = (m == 0 || m == 6 || n == 0 || n == 6) || 
                                                (m >= 2 && m <= 4 && n >= 2 && n <= 4) ? 1 : 0;
                }
            }
        }
    }
}

void printQRCode(QRCode *qr) {
    for (int y = 0; y < qr->size; y++) {
        for (int x = 0; x < qr->size; x++) {
            printf("%s", qr->matrix[y][x] ? "██" : "  ");
        }
        printf("\n");
    }
}

void generateDataPattern(QRCode *qr, const char *data) {
    // Simulated data pattern for the example
    int index = 0;
    while (data[index] != '\0' && index < BUFFER_SIZE) {
        qr->matrix[index % qr->size][(index / qr->size) % qr->size] = data[index] % 2;
        index++;
    }
}

void freeQRCode(QRCode *qr) {
    for (int i = 0; i < qr->size; i++) {
        free(qr->matrix[i]);
    }
    free(qr->matrix);
    free(qr);
}

int main() {
    char input[BUFFER_SIZE];
    printf("Enter data to encode in QR code: ");
    fgets(input, BUFFER_SIZE, stdin);

    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    QRCode *qrCode = createQRCode(QR_VERSION);
    generateFinderPatterns(qrCode);
    placeFinderPatterns(qrCode);
    generateDataPattern(qrCode, input);
    printQRCode(qrCode);
    
    freeQRCode(qrCode);
    return 0;
}