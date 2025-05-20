//FormAI DATASET v1.0 Category: QR code generator ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 1000

// Define our QR code struct
typedef struct QRCode {
    int version_number;
    char data[MAX_STRING_LENGTH];
    int size;
} QRCode;

// Function to generate a QR code
QRCode* generate_qr_code(char* input_data) {
    QRCode* qr = (QRCode*)malloc(sizeof(QRCode)); // Allocate memory for the struct
    qr->version_number = 1; // Set the version number to 1
 
    // Randomly generate the size of the QR code (between 10 and 50)
    qr->size = rand() % 41 + 10;

    // Copy the input data into the QR code data field
    strncat(qr->data, input_data, strlen(input_data));

    // Build the QR code
    for (int i = 0; i < qr->size; i++) {
        for (int j = 0; j < qr->size; j++) {
            if (i == 0 || i == qr->size - 1 || j == 0 || j == qr->size - 1) {
                printf("*");
            } else {
                printf("%c", qr->data[(i - 1) * (qr->size - 2) + (j - 1)]);
            }
        }
        printf("\n");
    }

    return qr;
}

// Main function to run the program
int main() {
    char input[MAX_STRING_LENGTH];
    printf("Enter data to be encoded in QR code: ");
    fgets(input, MAX_STRING_LENGTH, stdin);

    QRCode* qr = generate_qr_code(input);

    // Free the memory used by the QR code
    free(qr);

    return 0;
}