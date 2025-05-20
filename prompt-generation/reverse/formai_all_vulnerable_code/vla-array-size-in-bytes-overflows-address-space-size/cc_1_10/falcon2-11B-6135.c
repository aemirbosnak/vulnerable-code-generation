//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define constants for QR code version and error correction level
#define VERSION 1
#define ERROR_CORRECTION_LEVEL 3

// Define a function to generate a QR code
void generate_qr_code(int width, int height) {
    // Generate QR code grid
    int grid[height][width];
    
    // Initialize QR code grid with zeros
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = 0;
        }
    }
    
    // Generate QR code pattern
    int r, c;
    for (r = 0; r < height; r++) {
        for (c = 0; c < width; c++) {
            // Determine pattern based on QR code version and error correction level
            int pattern = (VERSION * (c % 4) + (r % 4)) % 4;
            if (pattern == 0) {
                grid[r][c] = 1;
            } else if (pattern == 1) {
                grid[r][c] = 1 - (grid[r - 1][c] * 2);
            } else if (pattern == 2) {
                grid[r][c] = 1 - (grid[r][c - 1] * 2);
            } else {
                grid[r][c] = 1 - (grid[r - 1][c - 1] * 4);
            }
        }
    }
    
    // Display QR code grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Get user input for QR code dimensions
    int width, height;
    printf("Enter QR code width: ");
    scanf("%d", &width);
    printf("Enter QR code height: ");
    scanf("%d", &height);
    
    // Generate QR code
    generate_qr_code(width, height);
    
    return 0;
}