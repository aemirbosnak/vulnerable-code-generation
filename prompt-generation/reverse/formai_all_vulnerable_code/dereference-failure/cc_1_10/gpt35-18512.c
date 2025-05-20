//FormAI DATASET v1.0 Category: QR code reader ; Style: Ada Lovelace
// Program to read and decode a QR code
// Written by Ada Lovelace

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_CODE_SIZE 21 // QR code is 21 by 21 cells

// Function to read QR code from user input
void read_qr_code(int **qr_code) {
    printf("Please enter the QR code (0 for white cells, 1 for black cells):\n");
    
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        for (int j = 0; j < QR_CODE_SIZE; j++) {
            scanf("%d", &qr_code[i][j]);
        }
    }
}

// Function to decode QR code and print the message
void decode_qr_code(int **qr_code) {
    char message[41]; // 40 characters + 1 null terminator
    int message_index = 0;
    
    // Scan QR code diagonally
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        for (int j = i % 2 ? QR_CODE_SIZE - 1 : 0; j >= 0 && j < QR_CODE_SIZE; i % 2 ? j-- : j++) {
            message[message_index++] = qr_code[i][j] + '0'; // Convert from int to char
        }
    }
    
    message[message_index] = '\0'; // Add null terminator
    printf("Decoded message: %s\n", message);
}

int main() {
    int **qr_code;
    qr_code = (int **) malloc(QR_CODE_SIZE * sizeof(int *));
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        qr_code[i] = (int *) malloc(QR_CODE_SIZE * sizeof(int));
        memset(qr_code[i], 0, QR_CODE_SIZE * sizeof(int)); // Initialize to all white cells
    }
    
    read_qr_code(qr_code);
    decode_qr_code(qr_code);
    
    // Free memory
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        free(qr_code[i]);
    }
    free(qr_code);
    
    return 0;
}