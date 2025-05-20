//GEMINI-pro DATASET v1.0 Category: QR code reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_QR_CODE_SIZE 100

// Structure to represent a QR code
typedef struct QRCode {
    int size;
    char data[MAX_QR_CODE_SIZE];
} QRCode;

// Function to read a line from standard input
char *readline(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    nread = getline(&line, &len, stdin);
    if (nread == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }

    return line;
}

// Function to parse a QR code from a string
QRCode *parse_qr_code(char *string) {
    QRCode *qr_code = malloc(sizeof(QRCode));
    if (qr_code == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Check if the string is a valid QR code
    if (strlen(string) != MAX_QR_CODE_SIZE) {
        fprintf(stderr, "Invalid QR code size: %d\n", strlen(string));
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_QR_CODE_SIZE; i++) {
        if (!isprint(string[i])) {
            fprintf(stderr, "Invalid QR code character: %c\n", string[i]);
            exit(EXIT_FAILURE);
        }
    }

    // Parse the QR code data
    qr_code->size = MAX_QR_CODE_SIZE;
    strcpy(qr_code->data, string);

    return qr_code;
}

// Function to print a QR code
void print_qr_code(QRCode *qr_code) {
    for (int i = 0; i < qr_code->size; i++) {
        printf("%c", qr_code->data[i]);
    }
    printf("\n");
}

// Main function
int main(void) {
    // Read a line from standard input
    char *line = readline();

    // Parse the QR code from the line
    QRCode *qr_code = parse_qr_code(line);

    // Print the QR code
    print_qr_code(qr_code);

    // Free the QR code
    free(qr_code);

    // Free the line
    free(line);

    return EXIT_SUCCESS;
}