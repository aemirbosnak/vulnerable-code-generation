//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_SIZE 25

int main(void) {
    char *data = "Hello, world!";
    int data_len = strlen(data);

    // Create a QR code matrix
    int **matrix = (int **)malloc(QR_SIZE * sizeof(int *));
    for (int i = 0; i < QR_SIZE; i++) {
        matrix[i] = (int *)malloc(QR_SIZE * sizeof(int));
    }

    // Initialize the matrix to 0
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            matrix[i][j] = 0;
        }
    }

    // Set the data bits in the matrix
    int bit_index = 0;
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            if (bit_index < data_len) {
                matrix[i][j] = (data[bit_index] >> (7 - j)) & 1;
                bit_index++;
            }
        }
    }

    // Print the QR code matrix
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the QR code matrix
    for (int i = 0; i < QR_SIZE; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}