//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_SIZE 100

typedef struct QRCode {
    int version;
    int size;
    char **data;
} QRCode;

QRCode *qrcode_new(int version) {
    QRCode *qrcode = malloc(sizeof(QRCode));
    qrcode->version = version;
    qrcode->size = 4 * version + 17;
    qrcode->data = malloc(sizeof(char *) * qrcode->size);
    for (int i = 0; i < qrcode->size; i++) {
        qrcode->data[i] = malloc(sizeof(char) * qrcode->size);
        for (int j = 0; j < qrcode->size; j++) {
            qrcode->data[i][j] = ' ';
        }
    }
    return qrcode;
}

void qrcode_free(QRCode *qrcode) {
    for (int i = 0; i < qrcode->size; i++) {
        free(qrcode->data[i]);
    }
    free(qrcode->data);
    free(qrcode);
}

bool qrcode_set_data(QRCode *qrcode, char *data) {
    int data_len = strlen(data);
    if (data_len > qrcode->size * qrcode->size) {
        return false;
    }
    int i = 0;
    int j = 0;
    for (int k = 0; k < data_len; k++) {
        qrcode->data[i][j] = data[k];
        j++;
        if (j == qrcode->size) {
            j = 0;
            i++;
        }
    }
    return true;
}

void qrcode_print(QRCode *qrcode) {
    for (int i = 0; i < qrcode->size; i++) {
        for (int j = 0; j < qrcode->size; j++) {
            printf("%c", qrcode->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create a QR code with version 1
    QRCode *qrcode = qrcode_new(1);

    // Set the QR code's data
    bool success = qrcode_set_data(qrcode, "Hello, world!");
    if (!success) {
        printf("Error: QR code data too long.\n");
        return 1;
    }

    // Print the QR code
    qrcode_print(qrcode);

    // Free the QR code's memory
    qrcode_free(qrcode);

    return 0;
}