//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define VERSION 1
#define SIZE 21 // Size of the QR code for version 1
#define MODULE_SIZE 4 // Number of pixels for each QR module

// Function declarations
void generateQR(char *data);
void drawModule(int x, int y, int value);
void createQRMatrix(char *data, int qr[SIZE][SIZE]);
void printQR(int qr[SIZE][SIZE]);

// QR code's error correction level
const char *ERROR_CORRECTION = "L";

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *data = argv[1];
    generateQR(data);
    return EXIT_SUCCESS;
}

// Generate a simple QR Code. First, we create a matrix for it.
void generateQR(char *data) {
    int qr[SIZE][SIZE] = {0}; // QR matrix initialized to 0
    createQRMatrix(data, qr);
    printQR(qr);
}

// Draws a module of the QR code at the specified (x, y) coordinate
void drawModule(int x, int y, int value) {
    printf("\033[%d;%dH%c", y * MODULE_SIZE, x * MODULE_SIZE, value ? '#' : ' ');
}

// Fill the QR matrix with data and format
void createQRMatrix(char *data, int qr[SIZE][SIZE]) {
    int i, j;

    // Add finder patterns (top-left, top-right, bottom-left)
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            if (i == 0 || i == 6 || j == 0 || j == 6 || (i >= 2 && i <= 4 && j >= 2 && j <= 4)) {
                qr[i][j] = 1; // Black module
            }
        }
    }
    for (i = 0; i < 7; i++) {
        for (j = SIZE - 7; j < SIZE; j++) {
            if (i == 0 || i == 6 || j == SIZE - 1 || j == SIZE - 7 || (i >= 2 && i <= 4 && j <= SIZE - 4)) {
                qr[i][j] = 1; // Black module
            }
        }
    }
    for (i = SIZE - 7; i < SIZE; i++) {
        for (j = 0; j < 7; j++) {
            if (i == SIZE - 1 || i == SIZE - 7 || j == 0 || j == 6 || (i <= SIZE - 4 && j >= 2 && j <= 4)) {
                qr[i][j] = 1; // Black module
            }
        }
    }

    // Just for demonstration purposes, add data in a simple way
    size_t len = strlen(data);
    for (i = 0; i < len && i < SIZE - 8; i++) { // Leave space for the finder patterns
        qr[i + 2][2] = (data[i] % 2); // Simple encoding
    }
}

// Print the QR code in a readable format
void printQR(int qr[SIZE][SIZE]) {
    int x, y;

    for (y = 0; y < SIZE; y++) {
        for (x = 0; x < SIZE; x++) {
            drawModule(x, y, qr[x][y]);
        }
    }
    printf("\033[0m"); // Reset terminal color
    printf("\n");
}