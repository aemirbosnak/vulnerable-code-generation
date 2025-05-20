//FormAI DATASET v1.0 Category: QR code generator ; Style: secure
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define QRCODE_VERSION 0x1
#define MAX_QRCODE_SIZE 177

typedef struct qr_code_t {
    uint8_t version;
    uint8_t data[MAX_QRCODE_SIZE];
    uint16_t size;
    uint8_t ecc[MAX_QRCODE_SIZE];
} qr_code_t;

// Helper function to calculate the polynomial coefficient
uint8_t gf_mul(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    while (b) {
        if (b & 1)
            p ^= a;
        if (a & 0x80)
            a = (a << 1) ^ 0x11d;
        else
            a <<= 1;
        b >>= 1;
    }
    return p;
}

// Helper function to calculate the Reed-Solomon error correction code
void rs_encode(uint8_t *data, uint16_t size, uint8_t *ecc, uint8_t ecc_size) {
    uint8_t *dividend = malloc(sizeof(uint8_t) * (size + ecc_size));
    memset(dividend, 0, size + ecc_size);
    memcpy(dividend, data, size);

    uint8_t *divisor = malloc(sizeof(uint8_t) * (ecc_size + 1));
    memset(divisor, 0, ecc_size + 1);
    divisor[0] = 1;

    for (uint16_t i = 0; i < size; i++) {
        uint8_t factor = dividend[i] ^ ecc[0];
        for (uint8_t j = 0; j < ecc_size; j++) {
            dividend[i + j] ^= gf_mul(divisor[j], factor);
        }
    }

    memcpy(ecc, dividend + size, ecc_size);
    free(dividend);
    free(divisor);
}

// Helper function to print out the QR code
void print_qr_code(qr_code_t qr_code) {
    printf("Version: %d\n", qr_code.version);
    printf("Size: %d\n", qr_code.size);
    printf("Data: ");
    for (uint16_t i = 0; i < qr_code.size; i++) {
        printf("%02X ", qr_code.data[i]);
    }
    printf("\nECC: ");
    for (uint16_t i = 0; i < qr_code.version == 1 ? 9 : 17; i++) {
        printf("%02X ", qr_code.ecc[i]);
    }
    printf("\n");
}

int main() {
    char input_str[256];
    printf("Enter data: ");
    fgets(input_str, sizeof(input_str), stdin);

    // Calculate the required QR code size
    uint16_t input_str_size = strlen(input_str) - 1;
    uint16_t qr_code_size = 17 * (QRCODE_VERSION + 1) * (QRCODE_VERSION + 1);
    if (input_str_size > qr_code_size - 26) {
        printf("Data too long for QR code.\n");
        return 1;
    }

    // Construct the bit stream for the QR code
    uint8_t bit_stream[qr_code_size];
    memset(bit_stream, 0, qr_code_size);

    // Add mode indicator (8-bit, binary)
    bit_stream[0] = 0b0010;
    // Add character count indicator (depends on version and mode)
    if (QRCODE_VERSION <= 9) {
        bit_stream[1] = input_str_size << 1;
    } else if (QRCODE_VERSION <= 26) {
        bit_stream[1] = (input_str_size << 1) + 1;
        bit_stream[2] = (input_str_size >> 7) & 0b111;
    } else {
        bit_stream[1] = (input_str_size << 1) + 2;
        bit_stream[2] = (input_str_size >> 14) & 0b111;
        bit_stream[3] = (input_str_size >> 7) & 0b1111111;
    }

    // Add data payload (8-bit, binary)
    for (uint16_t i = 0; i < input_str_size; i++) {
        bit_stream[13 + i] = input_str[i];
    }

    // Calculate the Reed-Solomon error correction code
    uint8_t ecc_size = QRCODE_VERSION == 1 ? 9 : 17;
    uint16_t data_size = 13 + input_str_size;
    uint16_t ecc_start = qr_code_size - ecc_size;
    rs_encode(bit_stream, data_size, bit_stream + ecc_start, ecc_size);

    // Construct the final QR code struct
    qr_code_t qr_code;
    qr_code.version = QRCODE_VERSION;
    qr_code.size = qr_code_size / 8;
    memcpy(qr_code.data, bit_stream, qr_code.size);
    memcpy(qr_code.ecc, bit_stream + ecc_start, ecc_size);

    // Print out the result
    print_qr_code(qr_code);

    return 0;
}