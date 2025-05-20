//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define QR_BOX_SIZE 4
#define QR_PIXEL_SIZE 8

#define QR_CORNERS (4 * QR_BOX_SIZE + 1)
#define QR_PIXEL_MASK (QR_PIXEL_SIZE - 1)

typedef struct {
    unsigned char data[QR_CORNERS];
} qr_code_t;

static void qr_code_init(qr_code_t* code) {
    memset(code->data, 0, QR_CORNERS);
}

static void qr_code_print(const qr_code_t* code) {
    for (int i = 0; i < QR_CORNERS; i++) {
        printf("%02X ", code->data[i]);
    }
    printf("\n");
}

static void qr_code_add_data(qr_code_t* code, const unsigned char* data, int data_length) {
    for (int i = 0; i < data_length; i++) {
        int bit = data[i] & QR_PIXEL_MASK;
        for (int j = 0; j < QR_BOX_SIZE; j++) {
            int pos = QR_BOX_SIZE * (QR_CORNERS - 1) + j;
            if (bit & 1) {
                code->data[pos] = 1;
            } else {
                code->data[pos] = 0;
            }
        }
    }
}

static void qr_code_print_matrix(const qr_code_t* code) {
    int i, j;
    printf("QR Code Matrix\n");
    for (i = 0; i < QR_CORNERS; i++) {
        for (j = 0; j < QR_CORNERS; j++) {
            if (code->data[j * QR_BOX_SIZE + i]) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

static void qr_code_print_error_correcting_level(const qr_code_t* code) {
    int i;
    for (i = 0; i < QR_CORNERS; i++) {
        printf("%02X ", code->data[i]);
    }
    printf("\n");
}

static void qr_code_add_error_correcting_level(qr_code_t* code) {
    int i;
    for (i = 0; i < QR_CORNERS; i++) {
        int bit = 0;
        for (int j = 0; j < QR_BOX_SIZE; j++) {
            int pos = QR_BOX_SIZE * (QR_CORNERS - 1) + j;
            if (code->data[pos] == 1) {
                bit |= 1;
            }
        }
        code->data[i] = bit;
    }
}

int main() {
    qr_code_t code;
    qr_code_init(&code);

    // Add data to the QR code
    unsigned char data[] = {
        0x00, 0x01, 0x02, 0x03,
        0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B,
        0x0C, 0x0D, 0x0E, 0x0F
    };
    qr_code_add_data(&code, data, sizeof(data) / sizeof(data[0]));

    // Print the QR code matrix
    qr_code_print_matrix(&code);

    // Print the error correcting level
    qr_code_print_error_correcting_level(&code);

    // Add error correcting level to the QR code
    qr_code_add_error_correcting_level(&code);

    // Print the updated QR code matrix
    qr_code_print_matrix(&code);

    return 0;
}