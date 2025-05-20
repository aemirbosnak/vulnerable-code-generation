//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of given length
char* generateRandomString(int length) {
    char* result = (char*)malloc(length * sizeof(char));
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        result[i] = rand() % 26 + 'a';
    }
    result[length] = '\0';
    return result;
}

// Function to print a QR code pattern
void printQRCode(char* data, int version) {
    int size = (version - 1) * 4 + 17;
    int qrCode[size][size];

    // Initialize the QR code matrix with zeros
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            qrCode[i][j] = 0;
        }
    }

    // Add data to the QR code matrix
    for (int i = 0; i < strlen(data); i++) {
        int bit = data[i] - '0';
        int x = i % size;
        int y = i / size;
        for (int k = 0; k < 8; k++) {
            qrCode[y + k][x + k] = (qrCode[y + k][x + k] | (bit << k)) & 0x3;
        }
    }

    // Print the QR code matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (qrCode[i][j] == 0) {
                printf("  ");
            }
            else {
                printf("##");
            }
        }
        printf("\n");
    }
}

int main() {
    int version;
    printf("Enter the version of the QR code (1-40): ");
    scanf("%d", &version);

    char* data = generateRandomString(10);
    printf("Random data to encode: %s\n", data);

    printQRCode(data, version);

    return 0;
}