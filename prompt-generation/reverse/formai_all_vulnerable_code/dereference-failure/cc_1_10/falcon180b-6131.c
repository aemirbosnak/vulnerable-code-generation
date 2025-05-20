//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECKSUM_LENGTH 4
#define MAX_DATA_LENGTH (1024 * 1024) // 1 MB

void generate_checksum(const char* data, size_t length, char* checksum)
{
    const char* magic_data = "The magic data for this program";
    size_t magic_length = strlen(magic_data);
    char magic_checksum[CHECKSUM_LENGTH + 1] = {0};
    char* magic_checksum_ptr = magic_checksum;

    for (size_t i = 0; i < magic_length; i++)
    {
        *magic_checksum_ptr++ = magic_data[i];
    }

    for (size_t i = 0; i < length; i++)
    {
        magic_checksum[0] ^= data[i];
        for (size_t j = 0; j < CHECKSUM_LENGTH; j++)
        {
            magic_checksum[j + 1] ^= magic_checksum[j];
        }
    }

    strncpy(checksum, magic_checksum, CHECKSUM_LENGTH);
}

int main()
{
    char data[MAX_DATA_LENGTH];
    char checksum[CHECKSUM_LENGTH + 1];

    FILE* fp = fopen("data.txt", "rb");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    size_t bytes_read = fread(data, sizeof(char), MAX_DATA_LENGTH, fp);
    if (bytes_read == 0)
    {
        printf("Error reading file.\n");
        return 1;
    }

    fclose(fp);

    generate_checksum(data, bytes_read, checksum);

    printf("Data:\n");
    for (size_t i = 0; i < bytes_read; i++)
    {
        printf("%02X ", data[i]);
    }
    printf("\n");

    printf("Checksum:\n");
    for (size_t i = 0; i < CHECKSUM_LENGTH; i++)
    {
        printf("%02X ", checksum[i]);
    }
    printf("\n");

    return 0;
}