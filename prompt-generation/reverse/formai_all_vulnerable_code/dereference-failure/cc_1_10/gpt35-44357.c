//FormAI DATASET v1.0 Category: QR code reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 500
#define QR_SIZE 21

/**
 * This code reads QR codes and decodes them.
 * Written by Ken Thompson in a unique style.
 */

char *read_input(int max_size);
int read_qr(char *input, char *code);
int decode(char *qr, char *decoded);

int main() {
    char *input = read_input(MAX_SIZE);
    char qr[QR_SIZE];
    int success = read_qr(input, qr);
    if (success == 0) {
        printf("Error: Not a valid QR code.\n");
        return 0;
    }
    char decoded[MAX_SIZE];
    decode(qr, decoded);
    printf("Decoded message: %s\n", decoded);
    return 0;
}

// Reads input from user and returns as a string
char *read_input(int max_size) {
    char *input = malloc(sizeof(char) * max_size);
    printf("Enter QR code: ");
    fgets(input, max_size, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character
    return input;
}

// Reads QR code from input and returns success status
int read_qr(char *input, char *code) {
    if (strlen(input) != QR_SIZE) {
        return 0;
    }
    for (int i = 0; i < QR_SIZE; i++) {
        code[i] = toupper(input[i]);
        if (code[i] != '0' && code[i] != '1') {
            return 0;
        }
    }
    return 1;
}

// Decodes QR string and returns decoded message
int decode(char *qr, char *decoded) {
    char *bin;
    int dec;
    char ch;
    for (int i = 0; i < MAX_SIZE; i++) {
        bin = malloc(sizeof(char) * 8);
        strncpy(bin, qr + (i * 8), 8);
        dec = strtol(bin, NULL, 2);
        if (dec == 0) {
            break;
        }
        ch = (char) dec;
        decoded[i] = ch;
        free(bin);
    }
    return 1;
}