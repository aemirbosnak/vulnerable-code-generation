//FormAI DATASET v1.0 Category: QR code reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint8_t version;
    uint8_t ecc_level;
    uint8_t module_size;
    uint8_t* data;
    uint32_t data_size;
} qr_code_t;

const char* get_error_string(uint32_t error_code)
{
    switch (error_code)
    {
        case 1: return "Invalid QR code version";
        case 2: return "Invalid ECC level";
        case 3: return "Invalid module size";
        case 4: return "Invalid QR code data";
        default: return "Unknown error";
    }
}

uint32_t read_qr_code(const uint8_t* buffer, size_t buffer_size, qr_code_t* qr_code)
{
    // Check QR code header
    if (buffer_size < 21 || buffer[0] != 0x51 || buffer[1] != 0x52 || buffer[2] != 0x53)
    {
        return 4; // Invalid QR code data
    }

    // Get version number
    qr_code->version = buffer[3];
    if (qr_code->version < 1 || qr_code->version > 40)
    {
        return 1; // Invalid QR code version
    }

    // Get ECC level
    qr_code->ecc_level = buffer[4];
    if (qr_code->ecc_level < 1 || qr_code->ecc_level > 4)
    {
        return 2; // Invalid ECC level
    }

    // Get module size
    qr_code->module_size = buffer[5];
    if (qr_code->module_size < 1 || qr_code->module_size > 10)
    {
        return 3; // Invalid module size
    }

    // Get data size
    qr_code->data_size = (uint32_t)(buffer[16] << 24) | (uint32_t)(buffer[17] << 16) | (uint32_t)(buffer[18] << 8) | (uint32_t)(buffer[19]);
    if (buffer_size < 21 + qr_code->data_size)
    {
        return 4; // Invalid QR code data
    }

    // Allocate data buffer
    qr_code->data = (uint8_t*)malloc(qr_code->data_size);
    if (!qr_code->data)
    {
        return 5; // Out of memory
    }

    // Copy data buffer
    memcpy(qr_code->data, &buffer[21], qr_code->data_size);

    return 0; // Success
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <qr_code.bin>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "rb");
    if (!fp)
    {
        fprintf(stderr, "Unable to open file '%s' for reading\n", argv[1]);
        return 2;
    }

    fseek(fp, 0, SEEK_END);
    size_t buffer_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    uint8_t* buffer = (uint8_t*)malloc(buffer_size);
    if (!buffer)
    {
        fprintf(stderr, "Unable to allocate memory for buffer\n");
        fclose(fp);
        return 3;
    }

    if (fread(buffer, buffer_size, 1, fp) != 1)
    {
        fprintf(stderr, "Unable to read file '%s'\n", argv[1]);
        free(buffer);
        fclose(fp);
        return 4;
    }

    fclose(fp);

    qr_code_t qr_code;
    uint32_t error_code = read_qr_code(buffer, buffer_size, &qr_code);
    if (error_code)
    {
        fprintf(stderr, "Error: %s\n", get_error_string(error_code));
        free(buffer);
        if (qr_code.data)
        {
            free(qr_code.data);
        }
        return 5;
    }

    printf("QR code version: %u\n", qr_code.version);
    printf("QR code ECC level: %u\n", qr_code.ecc_level);
    printf("QR code module size: %u\n", qr_code.module_size);
    printf("QR code data size: %u\n", qr_code.data_size);
    printf("QR code data:\n");
    fwrite(qr_code.data, qr_code.data_size, 1, stdout);

    free(buffer);
    free(qr_code.data);

    return 0;
}