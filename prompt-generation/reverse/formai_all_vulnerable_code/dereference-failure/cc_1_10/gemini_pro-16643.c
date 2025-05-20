//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define QR_VERSION_MIN 1
#define QR_VERSION_MAX 40

typedef unsigned char byte;

typedef struct {
    int version;
    int size;
    int data_codewords;
    int ecc_codewords;
    byte *data_codewords_buffer;
    byte *ecc_codewords_buffer;
} qr_code_t;

qr_code_t *qr_code_new(int version) {
    if (version < QR_VERSION_MIN || version > QR_VERSION_MAX) {
        return NULL;
    }

    qr_code_t *qr_code = malloc(sizeof(qr_code_t));
    if (qr_code == NULL) {
        return NULL;
    }

    qr_code->version = version;
    qr_code->size = (version * 4) + 17;
    qr_code->data_codewords = (version * 4) + 10;
    qr_code->ecc_codewords = (version * 4) + 16;
    qr_code->data_codewords_buffer = malloc(qr_code->data_codewords);
    if (qr_code->data_codewords_buffer == NULL) {
        free(qr_code);
        return NULL;
    }
    qr_code->ecc_codewords_buffer = malloc(qr_code->ecc_codewords);
    if (qr_code->ecc_codewords_buffer == NULL) {
        free(qr_code->data_codewords_buffer);
        free(qr_code);
        return NULL;
    }

    return qr_code;
}

void qr_code_free(qr_code_t *qr_code) {
    free(qr_code->data_codewords_buffer);
    free(qr_code->ecc_codewords_buffer);
    free(qr_code);
}

int qr_code_get_version(qr_code_t *qr_code) {
    return qr_code->version;
}

int qr_code_get_size(qr_code_t *qr_code) {
    return qr_code->size;
}

int qr_code_get_data_codewords(qr_code_t *qr_code) {
    return qr_code->data_codewords;
}

int qr_code_get_ecc_codewords(qr_code_t *qr_code) {
    return qr_code->ecc_codewords;
}

byte *qr_code_get_data_codewords_buffer(qr_code_t *qr_code) {
    return qr_code->data_codewords_buffer;
}

byte *qr_code_get_ecc_codewords_buffer(qr_code_t *qr_code) {
    return qr_code->ecc_codewords_buffer;
}

bool qr_code_set_data_codewords(qr_code_t *qr_code, byte *data_codewords, int data_codewords_length) {
    if (data_codewords_length != qr_code->data_codewords) {
        return false;
    }

    memcpy(qr_code->data_codewords_buffer, data_codewords, data_codewords_length);
    return true;
}

bool qr_code_set_ecc_codewords(qr_code_t *qr_code, byte *ecc_codewords, int ecc_codewords_length) {
    if (ecc_codewords_length != qr_code->ecc_codewords) {
        return false;
    }

    memcpy(qr_code->ecc_codewords_buffer, ecc_codewords, ecc_codewords_length);
    return true;
}

bool qr_code_generate(qr_code_t *qr_code) {
    // Calculate the Reed-Solomon ECC codewords.
    int ecc_codewords_length = qr_code->ecc_codewords;
    byte *ecc_codewords = malloc(ecc_codewords_length);
    if (ecc_codewords == NULL) {
        return false;
    }

    int data_codewords_length = qr_code->data_codewords;
    byte *data_codewords = qr_code->data_codewords_buffer;

    int i;
    for (i = 0; i < ecc_codewords_length; i++) {
        int j;
        ecc_codewords[i] = 0;
        for (j = 0; j < data_codewords_length; j++) {
            ecc_codewords[i] ^= data_codewords[j] << (ecc_codewords_length - i - 1);
        }
    }

    // Interleave the data and ECC codewords.
    int codewords_length = data_codewords_length + ecc_codewords_length;
    byte *codewords = malloc(codewords_length);
    if (codewords == NULL) {
        free(ecc_codewords);
        return false;
    }

    int codewords_index = 0;
    int data_codewords_index = 0;
    int ecc_codewords_index = 0;

    for (i = 0; i < codewords_length; i++) {
        if ((i & 1) == 0) {
            codewords[i] = data_codewords[data_codewords_index++];
        } else {
            codewords[i] = ecc_codewords[ecc_codewords_index++];
        }
    }

    free(data_codewords);
    free(ecc_codewords);

    // Append the Reed-Solomon ECC codewords to the data codewords.
    qr_code->ecc_codewords_buffer = codewords;
    qr_code->ecc_codewords = codewords_length;

    return true;
}

void qr_code_print(qr_code_t *qr_code) {
    int size = qr_code->size;
    int i;
    int j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if ((i + j) % 2 == 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <data>\n", argv[0]);
        return 1;
    }

    char *data = argv[1];
    int data_length = strlen(data);

    // Create a new QR code.
    qr_code_t *qr_code = qr_code_new(5);
    if (qr_code == NULL) {
        printf("Error: Could not create QR code.\n");
        return 1;
    }

    // Set the data codewords.
    if (!qr_code_set_data_codewords(qr_code, (byte *)data, data_length)) {
        printf("Error: Could not set data codewords.\n");
        qr_code_free(qr_code);
        return 1;
    }

    // Generate the QR code.
    if (!qr_code_generate(qr_code)) {
        printf("Error: Could not generate QR code.\n");
        qr_code_free(qr_code);
        return 1;
    }

    // Print the QR code.
    qr_code_print(qr_code);

    // Free the QR code.
    qr_code_free(qr_code);

    return 0;
}