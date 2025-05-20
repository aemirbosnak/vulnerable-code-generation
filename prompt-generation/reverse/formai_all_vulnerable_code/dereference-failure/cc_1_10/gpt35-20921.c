//FormAI DATASET v1.0 Category: QR code generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define QR_CODE_LENGTH 21
#define BLOCK_SIZE 3

static uint8_t qrCode[QR_CODE_LENGTH + 1]; // Add space for NULL terminator

// Function prototypes
bool validateInput(char *input);
uint8_t calculateChecksum(uint8_t *data, size_t len);
void generateQrCode(char *input);
void printQrCode(uint8_t *qrCode);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <input string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if(validateInput(argv[1])) {
        generateQrCode(argv[1]);
        printQrCode(qrCode);
    }
    else {
        printf("Invalid input\n");
    }

    return EXIT_SUCCESS;
}

// Validate input string
bool validateInput(char *input) {
    // Ensure input length is within bounds
    if(strlen(input) > 15 || strlen(input) < 1) {
        return false;
    }

    // Ensure input consists only of uppercase/lowercase alphabets or digits
    for(int i = 0; i < strlen(input); i++) {
        if(!isalnum(input[i])) {
            return false;
        }
    }

    return true;
}

// Calculate QR code checksum
uint8_t calculateChecksum(uint8_t *data, size_t len) {
    uint8_t checksum = 0;

    for(int i = 0; i < len; i++) {
        checksum ^= *(data+i);
    }

    return checksum;
}

// Generate QR code from input string
void generateQrCode(char *input) {
    // Initialize QR code array to all zeros
    memset(qrCode, 0, sizeof(qrCode));

    // Append input string to QR code array
    strcat(qrCode, input);

    // Calculate and append checksum to QR code array
    uint8_t checksum = calculateChecksum(qrCode, strlen(qrCode));
    sprintf(&qrCode[strlen(qrCode)], "%02X", checksum);
}

// Print QR code to console
void printQrCode(uint8_t *qrCode) {
    uint8_t blocks = QR_CODE_LENGTH / BLOCK_SIZE;

    for(int i = 0; i < blocks; i++) {
        printf("%.*s ", BLOCK_SIZE, qrCode + (i * BLOCK_SIZE));
    }

    // Print remaining characters
    uint8_t remaining = QR_CODE_LENGTH % BLOCK_SIZE;
    if(remaining != 0) {
        printf("%.*s", remaining, qrCode + (blocks * BLOCK_SIZE));
    }

    printf("\n");
}