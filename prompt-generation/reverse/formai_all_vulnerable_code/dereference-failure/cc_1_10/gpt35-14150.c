//FormAI DATASET v1.0 Category: QR code reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()
#include <string.h> // Required for memset()
#include <stdbool.h> // Required for bool datatype

#define QR_CODE_SIZE 21 // 21 x 21 QR code size

// Function to allocate dynamic memory for QR code matrix
bool** createQRCodeMatrix() {
    bool** qrCodeMatrix = (bool**) malloc(sizeof(bool*) * QR_CODE_SIZE);
    for(int i = 0; i < QR_CODE_SIZE; i++) {
        qrCodeMatrix[i] = (bool*) malloc(sizeof(bool) * QR_CODE_SIZE);
        memset(qrCodeMatrix[i], false, sizeof(bool) * QR_CODE_SIZE); // Initializing to false
    }
    return qrCodeMatrix;
}

// Function to free dynamic memory of QR code matrix
void destroyQRCodeMatrix(bool** qrCodeMatrix) {
    for(int i = 0; i < QR_CODE_SIZE; i++) {
        free(qrCodeMatrix[i]);
    }
    free(qrCodeMatrix);
}

// Function to read QR code from input file and store it in matrix
bool readQRCodeFromFile(bool** qrCodeMatrix, const char* fileName) {
    FILE* filePointer = fopen(fileName, "r");
    if(filePointer == NULL) {
        printf("Error opening file!\n");
        return false;
    }
    char* line = (char*) malloc(sizeof(char) * (QR_CODE_SIZE + 1)); // Buffer to store each line
    for(int i = 0; i < QR_CODE_SIZE; i++) {
        fgets(line, QR_CODE_SIZE + 1, filePointer);
        for(int j = 0; j < QR_CODE_SIZE; j++) {
            if(line[j] == '1') {
                qrCodeMatrix[i][j] = true;
            }
        }
    }
    free(line);
    fclose(filePointer);
    return true;
}

// Function to print QR code matrix to console
void printQRCode(bool** qrCodeMatrix) {
    for(int i = 0; i < QR_CODE_SIZE; i++) {
        for(int j = 0; j < QR_CODE_SIZE; j++) {
            printf("%c", qrCodeMatrix[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

// Entry point of program
int main() {
    bool** qrCodeMatrix = createQRCodeMatrix(); // Allocate memory for QR code matrix
    if(readQRCodeFromFile(qrCodeMatrix, "qr_code.txt")) { // Read QR code from file
        printQRCode(qrCodeMatrix); // Print QR code to console
    }
    destroyQRCodeMatrix(qrCodeMatrix); // Free memory used by QR code matrix
    return 0;
}