//FormAI DATASET v1.0 Category: QR code generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qrencode.h"

// Function to print the QR code in the terminal
void print_qr_terminal(QRcode *qr) {
    // Get the QR code size
    int size = qr->width;

    // Loop through the QR code matrix and print the appropriate character
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (qr->data[i * size + j] & 1) {
                printf("\033[37;40m  \033[m"); // Black pixel
            } else {
                printf("\033[30;47m  \033[m"); // White pixel
            }
        }
        printf("\n");
    }
}

// Function to generate the QR code and return the data
unsigned char* generate_qr_data(char* input, int size) {
    // Set the error correction level to M
    QRecLevel level = QR_ECLEVEL_M;

    // Set the QR version to 6 (29x29 matrix size)
    int version = 6;

    // Create the QR code
    QRcode* qr = QRcode_encodeString(input, 0, level, QR_MODE_8, 1);

    // Get the QR code size
    int qr_size = qr->width;

    // Allocate memory for the QR data
    unsigned char* qr_data = (unsigned char*) malloc(qr_size * qr_size * sizeof(unsigned char));

    // Copy the QR code data into the allocated memory
    memcpy(qr_data, qr->data, qr_size * qr_size * sizeof(unsigned char));

    // Free the QR code
    QRcode_free(qr);

    // Return the QR data
    return qr_data;
}

int main() {
    // Get the input string from the user
    char input[256];
    printf("Enter the input string: ");
    scanf("%s", input);

    // Generate the QR code data
    unsigned char* qr_data = generate_qr_data(input, strlen(input));

    // Print the QR code in the terminal
    QRcode* qr = QRcode_encodeData(strlen(input), qr_data, 0, QR_ECLEVEL_M);
    print_qr_terminal(qr);

    // Free the QR data and QR code objects
    free(qr_data);
    QRcode_free(qr);

    return 0;
}