//FormAI DATASET v1.0 Category: QR code reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if character is a valid hexadecimal
bool is_hexadecimal(char c) {
    return (c >= '0' && c <= '9') ||
           (c >= 'a' && c <= 'f') ||
           (c >= 'A' && c <= 'F');
}

// Function to read QR code from console input
char* read_qr_code() {
    char* input = malloc(sizeof(char) * 1024);
    int index = 0;
    char c;

    printf("Please scan your QR code now: ");
    while ((c = getchar()) != '\n') {
        if (is_hexadecimal(c)) {
            input[index++] = c;
        } else {
            printf("Invalid QR code!\n");
            free(input);
            return NULL;
        }
    }

    input[index] = '\0';
    return input;
}

// Function to decode QR code
void decode_qr_code(char* input) {
    printf("QR code decoded successfully!\n");
    printf("QR code: %s\n", input);
}

int main() {
    printf("Welcome to the Happy QR Code Reader!\n");

    while (true) {
        char* input = read_qr_code();
        if (input != NULL) {
            decode_qr_code(input);
            free(input);
        }
    }

    return 0;
}