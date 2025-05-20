//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: detailed
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define CHECKSUM_SIZE 2

void swap_bytes(uint8_t *data, uint32_t index, uint32_t length) {
    uint8_t temp;

    for (uint32_t i = 0; i < length / 2; i++) {
        temp = data[index + i];
        data[index + i] = data[index + length - i - 1];
        data[index + length - i - 1] = temp;
    }
}

uint16_t calculate_checksum(uint8_t *data, uint32_t length) {
    uint16_t checksum = 0xFFFF;

    for (uint32_t i = 0; i < length; i += 2) {
        checksum += data[i] << 8;
        checksum += data[i + 1];
    }

    if (length % 2 != 0) {
        checksum += data[length - 1] << 8;
    }

    checksum = (checksum & 0xFFFF) + (checksum >> 16);

    checksum = ~checksum;

    return checksum;
}

bool validate_checksum(uint8_t *data, uint32_t length) {
    uint16_t calculated_checksum = calculate_checksum(data, length);
    uint16_t stored_checksum[CHECKSUM_SIZE];

    memcpy(stored_checksum, data + length, CHECKSUM_SIZE);

    return calculated_checksum == (stored_checksum[0] << 8 | stored_checksum[1]);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    uint32_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    uint8_t *buffer = (uint8_t *)malloc(file_size);

    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    size_t read_bytes = fread(buffer, 1, file_size, file);

    if (read_bytes != file_size) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return 1;
    }

    fclose(file);

    // Swap byte order for little-endian systems
    if (*(uint16_t *) &file_size == 0x0000) {
        swap_bytes(buffer, 0, file_size + CHECKSUM_SIZE);
    }

    printf("Data:\n");
    for (uint32_t i = 0; i < file_size + CHECKSUM_SIZE; i++) {
        printf("%.2X ", buffer[i]);
    }
    printf("\n");

    if (validate_checksum(buffer, file_size)) {
        printf("Checksum is valid\n");
    } else {
        printf("Checksum is invalid\n");
    }

    free(buffer);

    return 0;
}