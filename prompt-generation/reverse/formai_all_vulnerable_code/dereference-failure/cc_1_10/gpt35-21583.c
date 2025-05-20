//FormAI DATASET v1.0 Category: QR code reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

/* QR code constants */
#define QR_CODE_WIDTH 21
#define QR_CODE_VERSION_OFFSET 0
#define QR_CODE_PADDING_OFFSET 1
#define QR_CODE_DATA_OFFSET 2
#define QR_CODE_DATA_SIZE (QR_CODE_WIDTH - QR_CODE_DATA_OFFSET)

/* Single QR code data structure */
typedef struct {
    uint8_t version;
    bool padded;
    char data[QR_CODE_DATA_SIZE];
} QRCode;

/* Read QR code from file */
QRCode* readQRCode(FILE* file) {
    if(file == NULL) {
        printf("ERROR: Invalid file\n");
        return NULL;
    }

    /* Allocate memory for QR code */
    QRCode* code = (QRCode*) malloc(sizeof(QRCode));
    if(code == NULL) {
        printf("ERROR: Memory allocation failed\n");
        return NULL;
    }

    /* Read data from file */
    uint8_t buffer[QR_CODE_WIDTH];
    if(fread(buffer, sizeof(uint8_t), QR_CODE_WIDTH, file) != QR_CODE_WIDTH) {
        if(feof(file)) {
            printf("ERROR: End of file reached\n");
        } else {
            printf("ERROR: File read error: %s\n", strerror(errno));
        }
        free(code);
        return NULL;
    }

    /* Parse QR code fields */
    code->version = buffer[QR_CODE_VERSION_OFFSET];
    code->padded = buffer[QR_CODE_PADDING_OFFSET] > 0;
    strncpy(code->data, (char*)(buffer + QR_CODE_DATA_OFFSET), QR_CODE_DATA_SIZE);

    return code;
}

/* Main program starts here */
int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /* Open file */
    FILE* file = fopen(argv[1], "rb");
    if(file == NULL) {
        printf("ERROR: Can't open file: %s\n", argv[1]);
        return 1;
    }

    /* Read and print QR code contents */
    QRCode* code = readQRCode(file);
    if(code != NULL) {
        printf("QR code version: %d\n", code->version);
        printf("QR code data: %s\n", code->data);
        printf("QR code is %spadded\n", code->padded ? "" : "not ");
        free(code);
    }

    /* Close file and exit */
    fclose(file);
    return 0;
}