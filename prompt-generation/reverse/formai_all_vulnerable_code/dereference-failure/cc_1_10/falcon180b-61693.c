//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to generate QR code
void generate_qr_code(int size, char *data, char *filename) {
    int i, j, k, x, y, bit, value, mask = 1;
    FILE *fp;
    char *buffer = (char *)malloc(size * size * 3); // Allocate memory for QR code image

    // Initialize QR code with white color
    memset(buffer, 0xff, size * size * 3);

    // Add data to QR code
    for (i = 0; i < strlen(data); i++) {
        value = data[i] - 48; // Convert ASCII code to integer value
        for (j = 0; j < 8; j++) {
            bit = (value >> (7 - j)) & 1; // Get bit value from integer value
            for (k = 0; k < 8; k++) {
                x = i * 8 + j - 3; // Calculate position of bit in QR code
                y = k * 8 - 7;
                if (bit == 1) {
                    buffer[(y * size + x) * 3] = 0; // Set pixel color to black
                }
            }
        }
    }

    // Save QR code image to file
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not save QR code image.\n");
        exit(1);
    }
    fwrite(buffer, size * size * 3, 1, fp);
    fclose(fp);

    // Free memory
    free(buffer);
}

int main() {
    int size;
    char data[100], filename[100];

    // Get QR code size from user
    printf("Enter QR code size (1-40): ");
    scanf("%d", &size);

    // Get data to encode in QR code
    printf("Enter data to encode in QR code: ");
    scanf("%s", data);

    // Generate QR code image
    sprintf(filename, "qrcode_%d.bmp", size);
    generate_qr_code(size, data, filename);

    // Display success message
    printf("QR code generated successfully!\n");

    return 0;
}