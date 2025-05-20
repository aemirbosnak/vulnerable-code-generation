//FormAI DATASET v1.0 Category: QR code generator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

// Define the QR Code payload type
typedef struct {
    uint8_t type;
    uint16_t code;
    char data[255];
} qr_payload_t;

// A function to calculate the QR Code checksum
uint8_t qr_checksum(uint8_t *data, uint16_t len) {
    uint8_t crc = 0;
    for (uint16_t i = 0; i < len; i++) {
        crc ^= data[i];
    }
    return crc;
}

// A function to generate a QR Code as an array of bytes
void generate_qr_code(qr_payload_t *payload, uint8_t *out, uint16_t *out_len) {
    // Define the QR Code header
    uint8_t header[] = {0x51, 0x52, 0x44, 0x00};

    // Calculate the payload length
    uint16_t payload_len = strlen(payload->data) + 3;

    // Allocate memory for the QR Code data
    uint16_t data_len = payload_len + 2;
    uint8_t *data = (uint8_t *)malloc(data_len);

    // Write the payload type, code, and data to the QR Code data buffer
    data[0] = payload->type;
    data[1] = payload->code >> 8;
    data[2] = payload->code & 0xFF;
    memcpy(data + 3, payload->data, strlen(payload->data));

    // Calculate the QR Code checksum
    uint8_t checksum = qr_checksum(data, payload_len);

    // Allocate memory for the final QR Code data, including header, payload, and checksum
    *out_len = data_len + sizeof(header) + 1;
    uint8_t *final_data = (uint8_t *)malloc(*out_len);

    // Copy the header, payload, and checksum to the final QR Code data buffer
    memcpy(final_data, header, sizeof(header));
    memcpy(final_data + sizeof(header), data, data_len);
    final_data[data_len + sizeof(header)] = checksum;

    // Free the temporary data buffer
    free(data);

    // Copy the final QR Code data to the output buffer
    memcpy(out, final_data, *out_len);

    // Free the final QR Code data buffer
    free(final_data);
}

int main() {
    // Define a sample QR Code payload
    qr_payload_t payload;
    payload.type = 0x01;
    payload.code = 0x1234;
    strcpy(payload.data, "Hello, World!");

    // Generate the QR Code
    uint16_t qr_code_len;
    uint8_t qr_code[512];
    generate_qr_code(&payload, qr_code, &qr_code_len);

    // Print the QR Code as hexadecimal values
    printf("QR Code: ");
    for (int i = 0; i < qr_code_len; i++) {
        printf("%02X ", qr_code[i]);
    }

    return 0;
}