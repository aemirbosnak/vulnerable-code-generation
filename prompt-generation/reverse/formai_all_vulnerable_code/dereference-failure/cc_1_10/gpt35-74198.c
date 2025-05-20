//FormAI DATASET v1.0 Category: QR code reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_SIZE 100 // Maximum size of QR code

// Structure to store QR code data
typedef struct {
    int size;   // Size of QR code
    int *data;  // Data in QR code
} QRCode;

// Function to read QR code from file
QRCode readQR(char *filename) {
    QRCode qr;

    FILE *fp = fopen(filename, "r");    // Open file
    if (fp == NULL) {   // Check if file opened successfully
        printf("Unable to open file %s.\n", filename);
        qr.size = -1;
        qr.data = NULL;
        return qr;
    }

    char buffer[MAX_QR_SIZE];   // Buffer to read QR code data
    int i = 0;  // Index for buffer
    while (fgets(buffer, MAX_QR_SIZE, fp) != NULL) {   // Read QR code data line by line
        if (i == 0) {   // First line contains size of QR code
            qr.size = atoi(buffer);
            qr.data = (int*) malloc(qr.size * qr.size * sizeof(int)); // Allocate memory for QR code data
        } else {    // Remaining lines contain QR code data
            for (int j = 0; j < qr.size; j++) {
                qr.data[(i - 1) * qr.size + j] = (buffer[j] == '1') ? 1 : 0;   // Convert from ASCII to binary
            }
        }
        i++;
    }

    fclose(fp); // Close file
    return qr;
}

// Function to print QR code data
void printQR(QRCode qr) {
    for (int i = 0; i < qr.size; i++) {
        for (int j = 0; j < qr.size; j++) {
            printf("%d ", qr.data[i * qr.size + j]);
        }
        printf("\n");
    }
}

// Function to decode QR code
char* decodeQR(QRCode qr) {
    char *message = (char*) malloc((qr.size * qr.size / 8 + 1) * sizeof(char)); // Allocate memory for message
    int index = 0;  // Index for message

    // Loop through QR code data, 8 bits at a time
    for (int i = 0; i < qr.size; i += 2) {
        for (int j = 0; j < qr.size; j += 8) {
            char byte = 0;
            for (int k = 0; k < 8; k++) {
                byte = (byte << 1) + qr.data[(i + k/2) * qr.size + j + k%2];
            }
            message[index++] = byte;
        }
    }

    // Terminate message
    message[index] = '\0';
    return message;
}

int main() {
    char *filename = "qrcode.txt";  // File containing QR code data
    char *message = NULL;   // Decoded message

    // Read QR code from file
    QRCode qr = readQR(filename);
    if (qr.size == -1) {
        return 1;
    }

    // Decode QR code
    message = decodeQR(qr);

    // Print decoded message
    printf("Decoded message:\n%s\n", message);

    // Free memory
    free(qr.data);
    free(message);

    return 0;
}