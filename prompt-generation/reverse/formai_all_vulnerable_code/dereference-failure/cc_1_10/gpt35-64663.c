//FormAI DATASET v1.0 Category: QR code reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1024

typedef struct qr_code {
    char data[MAX_SIZE];
    int size;
} qr_code;

qr_code* read_qr_code(char* filename);
bool is_qr_code(char* filename);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <path/to/qr_code>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];

    if (!is_qr_code(filename)) {
        printf("%s is not a valid QR code.\n", filename);
        exit(1);
    }

    qr_code* code = read_qr_code(filename);

    printf("Data: %s\n", code->data);
    printf("Size: %d\n", code->size);

    free(code);

    return 0;
}

qr_code* read_qr_code(char* filename) {
    qr_code* code = (qr_code*)malloc(sizeof(qr_code));
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file: %s\n", filename);
        exit(1);
    }

    char line[MAX_SIZE];
    int count = 0;
    while (fgets(line, MAX_SIZE, fp) != NULL) {
        if (count == 0) {
            int size = strlen(line) - 1; // do not include newline character
            strncpy(code->data, line, size);
            code->data[size] = '\0';
            code->size = size;
        }

        count++;
    }

    fclose(fp);
    return code;
}

bool is_qr_code(char* filename) {
    char* extension = strrchr(filename, '.');

    if (extension == NULL || strcmp(extension, ".qr") != 0) {
        return false;
    }

    return true;
}