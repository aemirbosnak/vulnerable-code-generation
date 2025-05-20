//FormAI DATASET v1.0 Category: QR code generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define QR_SIZE 21 // QR code size
#define BLACK_SQUARE "\u25A0" // Unicode for black square
#define WHITE_SQUARE "\u25A1" // Unicode for white square

// Function to print the QR code
void printQR(char qr_code[QR_SIZE][QR_SIZE]) {
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            printf("%s", qr_code[i][j]); // Print black or white square
        }
        printf("\n"); // Move to next line
    }
}

// Function to generate the QR code
void generateQR(char message[]) {
    // Convert message to upper case
    char upper_message[strlen(message)];
    for (int i = 0; i < strlen(message); i++) {
        upper_message[i] = toupper(message[i]);
    }
    
    // Calculate number of blocks required
    int num_blocks = (QR_SIZE*QR_SIZE)/(strlen(upper_message)*8);
    if ((QR_SIZE*QR_SIZE)%(strlen(upper_message)*8) > 0) {
        num_blocks++;
    }
    
    // Allocate memory for block data
    char **blocks = malloc(num_blocks * sizeof(char *));
    for (int i = 0; i < num_blocks; i++) {
        blocks[i] = malloc(9 * sizeof(char)); // Each block is 8 bits plus null terminator
    }
    
    // Generate block data
    int bit_count = 0;
    int block_index = 0;
    for (int i = 0; i < strlen(upper_message); i++) {
        for (int j = 7; j >= 0; j--) {
            int bit = (upper_message[i] >> j) & 1;
            blocks[block_index][bit_count] = bit + '0';
            bit_count++;
            if (bit_count == 8) {
                blocks[block_index][bit_count] = '\0'; // Add null terminator
                bit_count = 0;
                block_index++;
            }
        }
    }
    if (bit_count > 0) {
        for (int i = bit_count; i < 8; i++) {
            blocks[block_index][i] = '0'; // Pad with zeros
        }
        blocks[block_index][8] = '\0'; // Add null terminator
    }
    
    // Initialize QR code to all white squares
    char qr_code[QR_SIZE][QR_SIZE][2];
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            strcpy(qr_code[i][j], WHITE_SQUARE);
        }
    }
    
    // Add blocks to QR code
    int x = 0;
    int y = 0;
    for (int i = 0; i < num_blocks; i++) {
        // Place block
        if (i % 2 == 0) {
            for (int j = 0; j < 8; j++) {
                if (blocks[i][j] == '1') {
                    strcpy(qr_code[x][y], BLACK_SQUARE);
                }
                y++;
                if (y == QR_SIZE) {
                    x++;
                    y--;
                    break;
                }
            }
        } else {
            for (int j = 7; j >= 0; j--) {
                if (blocks[i][j] == '1') {
                    strcpy(qr_code[x][y], BLACK_SQUARE);
                }
                y--;
                if (y < 0) {
                    x++;
                    y++;
                    break;
                }
            }
        }
    }
    
    // Print QR code
    printQR(qr_code);
    
    // Free memory
    for (int i = 0; i < num_blocks; i++) {
        free(blocks[i]);
    }
    free(blocks);
}

int main() {
    char message[100];
    printf("Enter message: ");
    scanf("%[^\n]", message);
    generateQR(message);
    return 0;
}