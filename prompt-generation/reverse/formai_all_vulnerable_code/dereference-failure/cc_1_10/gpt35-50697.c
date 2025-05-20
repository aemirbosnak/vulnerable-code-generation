//FormAI DATASET v1.0 Category: QR code reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// This function takes a QR code as input and returns the decoded data
char* decode_qr_code(const char *qr_code) {
    int len = strlen(qr_code);
    char *data = malloc(len);

    // Extract the data from the QR code
    for (int i = 0; i < len; i++) {
        if (qr_code[i] == '0' || qr_code[i] == '1') {
            data[i] = qr_code[i];
        }
    }

    // Convert the binary string to ASCII characters
    len = strlen(data);
    char *decoded = malloc(len / 8 + 1);
    for (int i = 0; i < len; i+=8) {
        char byte[9];
        strncpy(byte, data+i, 8);
        byte[8] = '\0';
        decoded[i/8] = strtol(byte, NULL, 2);
    }
    decoded[len/8] = '\0';

    free(data);
    return decoded;
}

int main() {
    char qr_code[MAX_LENGTH];
    printf("Please scan QR code: ");
    fgets(qr_code, MAX_LENGTH, stdin);

    // Remove new line character from input
    qr_code[strcspn(qr_code, "\n")] = 0;

    // Decode the QR code
    char *data = decode_qr_code(qr_code);
    printf("Decoded data: %s", data);

    // Free the memory allocated for decoded data
    free(data);

    return 0;
}