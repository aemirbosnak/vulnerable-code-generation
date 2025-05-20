//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate QR code
void generateQRCode(char* input, int size) {
    int len = strlen(input);
    int qrSize = size * size;
    int qrWidth = qrSize + 4;
    int qrHeight = qrSize + 4;
    int qrData = 0;
    int qrBit = 1;
    int i, j, x, y;

    // Initialize QR code
    for (i = 0; i < qrSize; i++) {
        for (j = 0; j < qrSize; j++) {
            qrData += (i & 1) * (j & 1);
        }
    }

    // Add data
    for (i = 0; i < len; i++) {
        qrData += input[i] - 48;
    }

    // Add error correction
    for (i = 0; i < qrData; i++) {
        qrData += 4;
    }

    // Add format information
    qrData += 8;

    // Add mask
    int mask = 0;
    for (i = 0; i < qrSize; i++) {
        for (j = 0; j < qrSize; j++) {
            if ((i + j) % 2 == 0) {
                mask ^= 1 << ((i / 2) * qrSize + j / 2);
            }
        }
    }
    qrData += mask;

    // Add terminator
    qrData += 1;

    // Convert QR code to ASCII
    char* qrAscii = malloc((qrWidth * qrHeight + 1) * sizeof(char));
    for (i = 0; i < qrWidth * qrHeight; i++) {
        x = i % qrWidth;
        y = i / qrWidth;
        if (qrAscii[i] = (qrData & 1)) {
            printf("X");
        } else {
            printf(" ");
        }
        qrData >>= 1;
    }
    printf("\n");

    // Print QR code
    for (i = 0; i < qrHeight; i++) {
        for (j = 0; j < qrWidth; j++) {
            if (qrAscii[i * qrWidth + j] == 'X') {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    char input[100];
    int size;

    // Get input and size from user
    printf("Enter input: ");
    scanf("%s", input);
    printf("Enter size: ");
    scanf("%d", &size);

    // Generate QR code
    generateQRCode(input, size);

    return 0;
}