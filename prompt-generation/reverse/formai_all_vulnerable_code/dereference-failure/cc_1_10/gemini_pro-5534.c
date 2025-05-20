//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define QR_VERSION_MIN 1
#define QR_VERSION_MAX 40
#define QR_SIZE_MIN 21
#define QR_SIZE_MAX 177

typedef unsigned char byte;

typedef struct {
    int version;
    int size;
    byte *data;
    int data_len;
} qr_code;

qr_code *qr_code_new(int version) {
    if (version < QR_VERSION_MIN || version > QR_VERSION_MAX) {
        return NULL;
    }

    qr_code *code = malloc(sizeof(qr_code));
    code->version = version;
    code->size = QR_SIZE_MIN + (version - 1) * 4;
    code->data = malloc(code->size * code->size);
    code->data_len = 0;

    return code;
}

void qr_code_free(qr_code *code) {
    free(code->data);
    free(code);
}

bool qr_code_add_data(qr_code *code, byte *data, int data_len) {
    if (code->data_len + data_len > code->size * code->size) {
        return false;
    }

    memcpy(code->data + code->data_len, data, data_len);
    code->data_len += data_len;

    return true;
}

void qr_code_print(qr_code *code) {
    for (int y = 0; y < code->size; y++) {
        for (int x = 0; x < code->size; x++) {
            printf("%c", code->data[y * code->size + x] ? '#' : ' ');
        }
        printf("\n");
    }
}

int main() {
    qr_code *code = qr_code_new(1);

    qr_code_add_data(code, "Hello, world!", 13);

    qr_code_print(code);

    qr_code_free(code);

    return 0;
}