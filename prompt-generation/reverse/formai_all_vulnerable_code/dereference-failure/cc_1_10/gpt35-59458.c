//FormAI DATASET v1.0 Category: QR code generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <qrencode.h>

#define MAX_CAPACITY 1000
#define MAX_QR_SIZE 40

void generateQR(char *data) {
    int i, j;
    QRcode *code = QRcode_encodeString(data, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if (code == NULL) {
        printf("Error generating QR code.\n");
        exit(EXIT_FAILURE);
    }

    printf("\n");

    for (i = 0; i < code->width + 4; i++) {
        printf("\033[47m  \033[0m");
    }

    printf("\n");

    for (i = 0; i < code->width; i++) {
        printf("\033[47m  \033[0m");
        for (j = 0; j < code->width; j++) {
            if (code->data[i * code->width + j] & 1) {
                printf("\033[40m  \033[0m");
            } else {
                printf("\033[47m  \033[0m");
            }
        }
        printf("\033[47m  \033[0m\n");
    }

    for (i = 0; i < code->width + 4; i++) {
        printf("\033[47m  \033[0m");
    }

    printf("\n");

    QRcode_free(code);
}

void validateCapacity(int capacity) {
    if (capacity < 1 || capacity > MAX_CAPACITY) {
        printf("Invalid capacity. Maximum allowed capacity is %d.\n", MAX_CAPACITY);
        exit(EXIT_FAILURE);
    }
}

void validateQRSize(int qr_size) {
    if (qr_size < 1 || qr_size > MAX_QR_SIZE) {
        printf("Invalid QR code size. Maximum allowed QR code size is %d.\n", MAX_QR_SIZE);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: qr_generator <data> <capacity> <qr_size>\n");
        exit(EXIT_FAILURE);
    }

    char *data = argv[1];
    int capacity = atoi(argv[2]);
    int qr_size = atoi(argv[3]);

    validateCapacity(capacity);
    validateQRSize(qr_size);

    int i;

    printf("Generating QR codes...\n");

    for (i = 0; i < capacity; i++) {
        printf("(QR Code %d/%d) ", i + 1, capacity);
        generateQR(data);
    }

    printf("QR codes generated successfully.\n");

    return 0;
}