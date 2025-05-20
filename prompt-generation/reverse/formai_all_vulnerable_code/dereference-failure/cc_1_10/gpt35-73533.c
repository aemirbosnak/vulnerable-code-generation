//FormAI DATASET v1.0 Category: QR code reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// QR code structure
typedef struct {
    int size;
    char** data;
} QRCode;

// function to initialize a QR code
void initQRCode(QRCode* code, int size) {
    code->size = size;
    code->data = malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        code->data[i] = malloc(size * sizeof(char));
    }
}

// function to free memory allocated for a QR code
void freeQRCode(QRCode* code) {
    for (int i = 0; i < code->size; i++) {
        free(code->data[i]);
    }
    free(code->data);
}

// function to read a QR code from a file
bool readQRCode(QRCode* code, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }
    char buffer[512];
    int line = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // remove newline character
        if (strlen(buffer) != code->size) {
            // invalid line length
            fclose(file);
            return false;
        }
        strcpy(code->data[line], buffer);
        line++;
        if (line == code->size) {
            break;
        }
    }
    fclose(file);
    return (line == code->size);
}

// function to print a QR code
void printQRCode(QRCode* code) {
    for (int i = 0; i < code->size; i++) {
        printf("%s\n", code->data[i]);
    }
}

// main function
int main() {
    int size = 5;
    QRCode code;
    initQRCode(&code, size);
    if (!readQRCode(&code, "qrcode.txt")) {
        printf("Error: Failed to read QR code from file.\n");
        freeQRCode(&code);
        return 1;
    }
    printf("QR code read successfully.\n");
    printQRCode(&code);
    freeQRCode(&code);
    return 0;
}