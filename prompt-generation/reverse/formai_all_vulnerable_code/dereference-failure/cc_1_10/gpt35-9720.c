//FormAI DATASET v1.0 Category: QR code reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_CODE_SIZE 256
#define MAX_ERROR_CORRECTION 3

// QR code data structure
typedef struct qr_code {
    int version;
    char error_correction;
    char mask_pattern;
    char mode;
    char *data;
} qr_code;

// Function to check if a given string is a valid QR code
bool is_valid_qr_code(char *str) {
    // Check length of string
    if (strlen(str) > MAX_QR_CODE_SIZE) {
        return false;
    }

    // Check for valid version number, error correction level, mask pattern code, and mode indicator
    if (!(str[0] >= '0' && str[0] <= '9')) {
        return false;
    }
    if (!(str[1] == 'L' || str[1] == 'M' || str[1] == 'Q' || str[1] == 'H')) {
        return false;
    }
    if (!(str[2] >= '0' && str[2] <= '8')) {
        return false;
    }
    if (!(str[3] == '0' || str[3] == '1')) {
        return false;
    }

    // Check if remainder of string is alphanumeric
    int i;
    for (i = 4; i < strlen(str); i++) {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ' '))) {
            return false;
        }
    }

    return true;
}

// Function to decode a QR code
qr_code decode_qr_code(char *str) {
    qr_code code;

    // Parse version number, error correction level, mask pattern code, and mode indicator
    code.version = str[0] - '0';
    code.error_correction = str[1];
    code.mask_pattern = str[2];
    code.mode = str[3];

    // Initialize data string
    code.data = (char*) malloc(MAX_QR_CODE_SIZE * sizeof(char));
    memset(code.data, '\0', sizeof(code.data));

    // Decode remainder of string
    int i;
    int index = 0;
    for (i = 4; i < strlen(str); i += 2) {
        int code_bits = (str[i] - '0') * 10 + (str[i + 1] - '0');
        if (code_bits < 45) {
            code.data[index] = (code_bits / 10) + '0';
            index++;
            code.data[index] = (code_bits % 10) + '0';
            index++;
        } else if (code_bits < 65) {
            code.data[index] = (code_bits - 45) + ' ';
            index++;
        } else if (code_bits < 90) {
            code.data[index] = (code_bits - 65) + 'A';
            index++;
        } else {
            code.data[index] = '?';
            index++;
        }
    }

    return code;
}

// Main function to read QR codes from input
int main() {
    // Initialize variables
    char *input, *str;
    input = (char*) malloc(MAX_QR_CODE_SIZE * sizeof(char));
    memset(input, '\0', sizeof(input));

    // Read input
    printf("Please enter a QR code: ");
    fgets(input, MAX_QR_CODE_SIZE, stdin);

    // Remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Check if input is valid QR code
    if (!is_valid_qr_code(input)) {
        printf("Invalid QR code.\n");
        return 0;
    }

    // Decode QR code
    qr_code code = decode_qr_code(input);

    // Print decoded QR code information
    printf("Version: %d\n", code.version);
    printf("Error Correction: %c\n", code.error_correction);
    printf("Mask Pattern: %c\n", code.mask_pattern);
    printf("Mode: %c\n", code.mode);
    printf("Data: %s\n", code.data);

    // Free allocated memory
    free(input);
    free(code.data);

    return 0;
}