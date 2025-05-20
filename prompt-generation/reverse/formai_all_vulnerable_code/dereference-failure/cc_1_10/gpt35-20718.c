//FormAI DATASET v1.0 Category: QR code reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define NUM_PIXELS 25 // Size of QR code matrix
#define WHITE 0 // Value of white pixel in QR code
#define BLACK 1 // Value of black pixel in QR code

typedef struct {
    uint8_t data[NUM_PIXELS][NUM_PIXELS]; // QR code matrix
    int width; // Width of QR code matrix
    int height; // Height of QR code matrix
} QRCode;

QRCode *createQRCode(int width, int height) {
    QRCode *qrcode = calloc(1, sizeof(QRCode));
    qrcode->width = width;
    qrcode->height = height;
    return qrcode;
}

void destroyQRCode(QRCode *qrcode) {
    free(qrcode);
}

QRCode *decodeQRCode(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return NULL;
    }

    QRCode *qrcode = createQRCode(NUM_PIXELS, NUM_PIXELS);
    char line[NUM_PIXELS + 1];

    for (int row = 0; row < NUM_PIXELS; row++) {
        if (!fgets(line, NUM_PIXELS + 1, file)) {
            printf("Error reading file.\n");
            destroyQRCode(qrcode);
            fclose(file);
            return NULL;
        }

        for (int col = 0; col < NUM_PIXELS; col++) {
            if (line[col] == '0') {
                qrcode->data[row][col] = WHITE;
            } else {
                qrcode->data[row][col] = BLACK;
            }
        }
    }

    fclose(file);
    return qrcode;
}

void printQRCode(QRCode *qrcode) {
    printf("QR Code: %d x %d\n", qrcode->width, qrcode->height);
    for (int row = 0; row < NUM_PIXELS; row++) {
        for (int col = 0; col < NUM_PIXELS; col++) {
            printf("%c", qrcode->data[row][col] == WHITE ? ' ' : '*');
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    QRCode *qrcode = decodeQRCode(argv[1]);
    if (!qrcode) {
        return 1;
    }

    printQRCode(qrcode);

    destroyQRCode(qrcode);
    return 0;
}