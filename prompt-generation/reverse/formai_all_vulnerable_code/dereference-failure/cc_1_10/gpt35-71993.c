//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define POLYNOMIAL 0x04C11DB7
#define INITIAL_VALUE 0xFFFFFFFF
#define FINAL_XOR_VALUE 0xFFFFFFFF

uint32_t calculate_checksum(uint8_t *data, uint32_t len)
{
    uint32_t crc = INITIAL_VALUE;

    for (uint32_t i = 0; i < len; i++)
    {
        crc ^= (uint32_t)data[i] << 24;
        for (uint8_t j = 0; j < 8; j++)
        {
            if (crc & 0x80000000)
            {
                crc = (crc << 1) ^ POLYNOMIAL;
            }
            else
            {
                crc <<= 1;
            }
        }
    }

    return crc ^ FINAL_XOR_VALUE;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp)
    {
        fprintf(stderr, "Failed to open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    uint32_t file_size = ftell(fp);
    rewind(fp);

    uint8_t *data = (uint8_t *)malloc(file_size);
    if (!data)
    {
        fprintf(stderr, "Failed to allocate memory for file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (fread(data, file_size, 1, fp) != 1)
    {
        fprintf(stderr, "Failed to read file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    uint32_t checksum = calculate_checksum(data, file_size);

    printf("Checksum of file %s: %08X\n", argv[1], checksum);

    free(data);
    fclose(fp);

    return 0;
}