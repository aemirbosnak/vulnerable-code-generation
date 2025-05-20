//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <time.h>

#define QR_VERSION 1
#define QR_ERROR_CORRECTION_LEVEL 0
#define QR_SIZE 21

#define QR_DATA_BITS 152
#define QR_ERROR_CORRECTION_BITS 32

#define QR_FORMAT_BITS 4
#define QR_TYPE_BITS 4
#define QR_VERSION_BITS 3

#define QR_MODE_NUMERIC 1
#define QR_MODE_ALPHANUMERIC 2
#define QR_MODE_BYTE 4
#define QR_MODE_KANJI 8

#define QR_TERMINATOR_BITS 4

typedef struct {
    int version;
    int error_correction_level;
    int mode;
    int data_bits;
    int error_correction_bits;
    int size;
    int data_codewords;
    int error_correction_codewords;
    int total_codewords;
    int format_bits;
    int type_bits;
    int version_bits;
    int terminator_bits;
    int total_bits;
    char *data;
    int *codewords;
    int *mask_pattern;
} qr_code;

qr_code *qr_code_new() {
    qr_code *code = malloc(sizeof(qr_code));
    code->version = QR_VERSION;
    code->error_correction_level = QR_ERROR_CORRECTION_LEVEL;
    code->mode = QR_MODE_BYTE;
    code->data_bits = QR_DATA_BITS;
    code->error_correction_bits = QR_ERROR_CORRECTION_BITS;
    code->size = QR_SIZE;
    code->data_codewords = (code->data_bits + 7) / 8;
    code->error_correction_codewords = (code->error_correction_bits + 7) / 8;
    code->total_codewords = code->data_codewords + code->error_correction_codewords;
    code->format_bits = QR_FORMAT_BITS;
    code->type_bits = QR_TYPE_BITS;
    code->version_bits = QR_VERSION_BITS;
    code->terminator_bits = QR_TERMINATOR_BITS;
    code->total_bits = code->format_bits + code->type_bits + code->version_bits + code->data_bits + code->error_correction_bits + code->terminator_bits;
    code->data = NULL;
    code->codewords = NULL;
    code->mask_pattern = NULL;
    return code;
}

void qr_code_free(qr_code *code) {
    if (code->data != NULL) {
        free(code->data);
    }
    if (code->codewords != NULL) {
        free(code->codewords);
    }
    if (code->mask_pattern != NULL) {
        free(code->mask_pattern);
    }
    free(code);
}

int qr_code_generate(qr_code *code) {
    int i, j, k, l, m, n;

    // Generate data codewords
    code->data = malloc(code->data_bits / 8 + 1);
    memset(code->data, 0, code->data_bits / 8 + 1);
    strcpy(code->data, "Hello, world!");

    // Generate error correction codewords
    code->codewords = malloc(code->total_codewords * sizeof(int));
    memset(code->codewords, 0, code->total_codewords * sizeof(int));
    for (i = 0; i < code->data_codewords; i++) {
        code->codewords[i] = (code->data[i] >> 4) & 0x0f;
        code->codewords[i + code->data_codewords] = code->data[i] & 0x0f;
    }
    for (i = code->data_codewords; i < code->total_codewords; i++) {
        code->codewords[i] = 0;
    }

    // Generate mask pattern
    code->mask_pattern = malloc(code->size * code->size * sizeof(int));
    memset(code->mask_pattern, 0, code->size * code->size * sizeof(int));
    for (i = 0; i < code->size; i++) {
        for (j = 0; j < code->size; j++) {
            if ((i + j) % 2 == 0) {
                code->mask_pattern[i * code->size + j] = 1;
            }
        }
    }

    // Apply mask pattern
    for (i = 0; i < code->size; i++) {
        for (j = 0; j < code->size; j++) {
            if (code->mask_pattern[i * code->size + j] == 1) {
                for (k = 0; k < 8; k++) {
                    code->codewords[i * code->size + j] ^= (1 << k);
                }
            }
        }
    }

    // Generate QR code image
    for (i = 0; i < code->size; i++) {
        for (j = 0; j < code->size; j++) {
            if (code->codewords[i * code->size + j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}

int main() {
    qr_code *code = qr_code_new();
    qr_code_generate(code);
    qr_code_free(code);
    return 0;
}