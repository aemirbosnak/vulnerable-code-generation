//FormAI DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the QR code data
typedef struct {
    char version;
    char charset;
    int size;
    char data[100];
} QRCode;

// Function to generate the QR code
QRCode* generateQRCode(char* data, int size) {
    // Create a new QR code with version 1, charset ASCII, and provided data and size
    QRCode* qrCode = malloc(sizeof(QRCode));
    qrCode->version = 1;
    qrCode->charset = 'A';
    qrCode->size = size;
    strcpy(qrCode->data, data);
    
    printf("QR code generated successfully!\n");
    
    return qrCode;
}

int main() {
    // Get user input
    char data[100];
    printf("Enter data to encode: ");
    fgets(data, sizeof(data), stdin);
    
    // Remove newline character from user input
    data[strcspn(data, "\n")] = 0;
    
    // Generate QR code
    QRCode* qrCode = generateQRCode(data, strlen(data));
    
    // Display QR code
    printf("\n\nQR Code:\n");
    printf("Version: %d\n", qrCode->version);
    printf("Charset: %c\n", qrCode->charset);
    printf("Size: %d\n", qrCode->size);
    printf("Data: %s\n", qrCode->data);
    
    // Free memory allocated for QR code
    free(qrCode);
    
    return 0;
}