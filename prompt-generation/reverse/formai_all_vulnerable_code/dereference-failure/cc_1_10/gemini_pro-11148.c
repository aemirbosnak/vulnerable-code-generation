//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QR_VERSION 1
#define QR_SIZE 21

// Function to generate the QR code matrix
int** generate_qr_matrix(char *data) {
    // Calculate the number of data bits
    int data_bits = strlen(data) * 8;

    // Calculate the number of error correction bits
    int ecc_bits = data_bits * 0.3;

    // Calculate the total number of bits
    int total_bits = data_bits + ecc_bits;

    // Calculate the number of codewords
    int codewords = total_bits / 8;

    // Allocate memory for the QR code matrix
    int **matrix = malloc(QR_SIZE * sizeof(int *));
    for (int i = 0; i < QR_SIZE; i++) {
        matrix[i] = malloc(QR_SIZE * sizeof(int));
    }

    // Initialize the QR code matrix to 0
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            matrix[i][j] = 0;
        }
    }

    // Place the finder patterns
    for (int i = 0; i < 7; i++) {
        matrix[i][i] = 1;
        matrix[i][QR_SIZE - 1 - i] = 1;
        matrix[QR_SIZE - 1 - i][i] = 1;
    }

    // Place the timing patterns
    for (int i = 8; i < QR_SIZE - 8; i++) {
        if (i % 2 == 0) {
            matrix[i][6] = 1;
            matrix[6][i] = 1;
        }
    }

    // Place the alignment patterns
    for (int i = 10; i < QR_SIZE - 10; i += 4) {
        for (int j = 10; j < QR_SIZE - 10; j += 4) {
            matrix[i][j] = 1;
            matrix[i + 1][j] = 1;
            matrix[i][j + 1] = 1;
        }
    }

    // Place the version information
    for (int i = 0; i < 6; i++) {
        matrix[i][8] = (QR_VERSION >> i) & 1;
        matrix[8][i] = (QR_VERSION >> i) & 1;
    }

    // Place the data bits
    int data_index = 0;
    for (int i = 10; i < QR_SIZE - 10; i++) {
        for (int j = 10; j < QR_SIZE - 10; j++) {
            if (data_index < data_bits) {
                matrix[i][j] = (data[data_index >> 3] >> (7 - (data_index & 7))) & 1;
                data_index++;
            }
        }
    }

    // Place the error correction bits
    int ecc_index = 0;
    for (int i = 10; i < QR_SIZE - 10; i++) {
        for (int j = 10; j < QR_SIZE - 10; j++) {
            if (ecc_index < ecc_bits) {
                matrix[i][j] = (data[ecc_index >> 3] >> (7 - (ecc_index & 7))) & 1;
                ecc_index++;
            }
        }
    }

    return matrix;
}

// Function to print the QR code matrix
void print_qr_matrix(int **matrix) {
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the QR code matrix
void free_qr_matrix(int **matrix) {
    for (int i = 0; i < QR_SIZE; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    // Get the data to be encoded
    char *data = "Hello, world!";

    // Generate the QR code matrix
    int **matrix = generate_qr_matrix(data);

    // Print the QR code matrix
    print_qr_matrix(matrix);

    // Free the QR code matrix
    free_qr_matrix(matrix);

    return 0;
}