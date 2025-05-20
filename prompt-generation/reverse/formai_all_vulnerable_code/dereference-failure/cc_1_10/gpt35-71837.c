//FormAI DATASET v1.0 Category: QR code reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct containing the QR code data
typedef struct {
    char type; // QR code type (e.g. alphanumeric, binary)
    int size; // Size of QR code in bytes
    char* data; // QR code data
} QRCode;

// Function to read QR code from file
QRCode readQRCode(char* file) {
    FILE* fp;
    int size;
    QRCode qrcode;

    // Open file for reading binary data
    fp = fopen(file, "rb");

    // Determine size of file
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    // Allocate memory for QR code data
    qrcode.data = (char*) malloc(size);

    // Read QR code data from file
    fread(qrcode.data, 1, size, fp);

    // Determine QR code type based on file extension
    char* ext = strrchr(file, '.') + 1;
    if (strcmp(ext, "txt") == 0) {
        qrcode.type = 'A';
    } else if (strcmp(ext, "bin") == 0) {
        qrcode.type = 'B';
    } else {
        qrcode.type = 'U';
    }

    // Assign size of QR code
    qrcode.size = size;

    // Close file
    fclose(fp);

    return qrcode;
}

// Function to print QR code data
void printQRCode(QRCode qrcode) {
    printf("QR code type: %c\n", qrcode.type);
    printf("QR code size: %d bytes\n", qrcode.size);
    printf("QR code data: %s\n", qrcode.data);
}

int main() {
    char* file = "qrcode.txt";
    QRCode qrcode = readQRCode(file);
    printQRCode(qrcode);
    return 0;
}