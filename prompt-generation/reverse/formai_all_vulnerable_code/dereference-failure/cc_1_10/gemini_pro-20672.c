//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_DATA_SIZE 255

typedef struct {
    int size;
    char *data;
} QRCode;

QRCode *create_qrcode(char *data) {
    // Calculate the size of the QR code
    int size = (int)ceil(sqrt(strlen(data) * 8 + 17)) + 1;

    // Allocate memory for the QR code
    QRCode *qrcode = malloc(sizeof(QRCode));
    qrcode->size = size;
    qrcode->data = malloc(size * size);

    // Initialize the QR code with white spaces
    for (int i = 0; i < size * size; i++) {
        qrcode->data[i] = ' ';
    }

    // Generate the QR code
    int x = 0, y = 0, dx = 1, dy = 0;
    int counter = 0;
    while (counter < strlen(data) * 8) {
        // Write the next bit of data
        qrcode->data[y * size + x] = data[counter / 8] & (1 << (7 - counter % 8)) ? 'X' : ' ';

        // Update the position
        x += dx;
        y += dy;

        // Check if we need to change direction
        if (x == size || x == -1) {
            dx *= -1;
            dy ^= 1;
            y += dy;
        }

        // Check if we need to skip two positions
        if (x == 0 && y == size - 1) {
            x += 2;
        }

        // Increment the counter
        counter++;
    }

    // Add the finder patterns
    for (int i = 0; i < 7; i++) {
        qrcode->data[i * size] = 'X';
        qrcode->data[i * size + 6] = 'X';
        qrcode->data[6 * size + i] = 'X';
        qrcode->data[6 * size + i + 7] = 'X';
    }

    // Add the alignment patterns
    for (int i = 0; i < 3; i++) {
        qrcode->data[i * size + 5] = 'X';
        qrcode->data[i * size + 11] = 'X';
        qrcode->data[11 * size + i] = 'X';
        qrcode->data[11 * size + 5 + i] = 'X';
        qrcode->data[11 * size + 11 + i] = 'X';
    }

    // Return the QR code
    return qrcode;
}

void print_qrcode(QRCode *qrcode) {
    for (int i = 0; i < qrcode->size; i++) {
        for (int j = 0; j < qrcode->size; j++) {
            printf("%c", qrcode->data[i * qrcode->size + j]);
        }
        printf("\n");
    }
}

int main() {
    // Get the data to encode
    char data[MAX_DATA_SIZE];
    printf("Enter the data to encode: ");
    scanf("%s", data);

    // Create the QR code
    QRCode *qrcode = create_qrcode(data);

    // Print the QR code
    printf("The QR code is:\n");
    print_qrcode(qrcode);

    // Free the memory allocated for the QR code
    free(qrcode->data);
    free(qrcode);

    return 0;
}