//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    uint8_t version;
    uint8_t error_correction_level;
    uint32_t data_length;
    uint8_t data[4];
} QRCodeHeader;

typedef struct {
    uint8_t matrix[8][8];
} QRCodeMatrix;

typedef struct {
    QRCodeHeader header;
    QRCodeMatrix matrix;
} QRCode;

int main(void) {
    char* data = "Hello, World!";
    QRCode qr;
    QRCodeHeader* header = &qr.header;
    QRCodeMatrix* matrix = &qr.matrix;

    header->version = 1;
    header->error_correction_level = 0;
    header->data_length = strlen(data);
    memcpy(header->data, data, header->data_length);

    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            matrix->matrix[i][j] = (data[i * 8 + j] - 'A') % 2;
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (matrix->matrix[i][j] == 1) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}