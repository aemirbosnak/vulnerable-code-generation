//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the size of the QR code
#define QR_SIZE 21

// Function to initialize the QR code matrix
void initializeQRCode(int qr[QR_SIZE][QR_SIZE]) {
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            qr[i][j] = 0; // Set default value to 0 (white)
        }
    }
}

// Function to draw modules in the QR code matrix
void drawModule(int qr[QR_SIZE][QR_SIZE], int x, int y, int value) {
    if (x >= 0 && x < QR_SIZE && y >= 0 && y < QR_SIZE) {
        qr[x][y] = value;
    }
}

// Function to create a simple pattern (finder pattern) in the QR code
void drawFinderPatterns(int qr[QR_SIZE][QR_SIZE]) {
    int pattern[7][7] = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}
    };
    
    // Place patterns at corners
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            drawModule(qr, i, j, pattern[i][j]);
            drawModule(qr, i, QR_SIZE - 1 - j, pattern[i][j]);
            drawModule(qr, QR_SIZE - 1 - i, j, pattern[i][j]);
        }
    }
}

// Function to show the QR Code visually
void displayQRCode(int qr[QR_SIZE][QR_SIZE]) {
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            printf("%s ", qr[i][j] == 1 ? "##" : "  ");
        }
        printf("\n");
    }
}

// Function to input a message and create the QR code
void createQRCode(const char *message) {
    int qr[QR_SIZE][QR_SIZE];
    initializeQRCode(qr);
    drawFinderPatterns(qr);
    
    // Basic processing for demonstration
    for (int i = 0; i < strlen(message); i++) {
        int posX = (i / 3) + 8; // Simple pattern logic
        int posY = (i % 3) + 8; 
        drawModule(qr, posX, posY, 1);
    }
    
    printf("Generated QR Code for message: \"%s\"\n", message);
    displayQRCode(qr);
}

// The main program starts here
int main(int argc, char *argv[]) {
    // Ensure that the user has provided a message to encode
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    createQRCode(argv[1]);
    
    return EXIT_SUCCESS;
}