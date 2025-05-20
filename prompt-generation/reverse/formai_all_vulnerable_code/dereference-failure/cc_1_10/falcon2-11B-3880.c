//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SQR(x) ((x)*(x))

// Generate QR code for a given string
void generate_qr_code(char* data, int width, int height) {
    int i, j, k, m;
    int n = width*height;
    char *code;

    // Allocate memory for QR code
    code = (char*)malloc((n+1)*sizeof(char));
    memset(code, 0, n+1);

    // Create QR code pattern
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            int x = i*SQR(height);
            int y = j*SQR(width);

            // Check if pixel is black
            if (data[k = x + y * width] == '1') {
                // Set pixel to 1
                code[k] = '1';
            }
            else {
                // Set pixel to 0
                code[k] = '0';
            }
        }
    }

    // Print QR code
    printf("QR Code for %s:\n", data);
    for (i = 0; i < n; i++) {
        if (code[i] == '1') {
            printf("X");
        }
        else {
            printf(" ");
        }
    }
    printf("\n");

    // Free memory
    free(code);
}

int main() {
    char data[] = "Hello, world!";
    int width = 10;
    int height = 10;

    generate_qr_code(data, width, height);

    return 0;
}