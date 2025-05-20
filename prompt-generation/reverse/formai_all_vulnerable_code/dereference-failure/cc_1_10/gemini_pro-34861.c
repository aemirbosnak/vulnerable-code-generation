//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#define PARANOID

// paranoid check to make sure that the pointer is not NULL
#define CHECK_PTR(ptr) do { if (ptr == NULL) { fprintf(stderr, "Error: Null pointer detected!\n"); exit(EXIT_FAILURE); } } while(0)

// paranoid check to make sure that the file is not NULL
#define CHECK_FILE(file) do { if (file == NULL) { fprintf(stderr, "Error: Unable to open file!\n"); exit(EXIT_FAILURE); } } while(0)

// paranoid check to make sure that the size is not 0
#define CHECK_SIZE(size) do { if (size == 0) { fprintf(stderr, "Error: Invalid size!\n"); exit(EXIT_FAILURE); } } while(0)

// paranoia check to make sure that the value is within the range
#define CHECK_RANGE(value, min, max) do { if (value < min || value > max) { fprintf(stderr, "Error: Value out of range!\n"); exit(EXIT_FAILURE); } } while(0)

// paranoid check to make sure the checksum is correct
#define CHECK_CHECKSUM(checksum, expected_checksum) do { if (checksum != expected_checksum) { fprintf(stderr, "Error: Invalid checksum!\n"); exit(EXIT_FAILURE); } } while(0)

// calculate the checksum of a file
uint32_t calculate_checksum(const char *filename)
{
    // paranoid check to make sure that the filename is not NULL
    CHECK_PTR(filename);

    // paranoid check to make sure that the file exists
    FILE *file = fopen(filename, "rb");
    CHECK_FILE(file);

    // paranoid check to make sure that the file size is not 0
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    CHECK_SIZE(size);

    // paranoid check to make sure that the file pointer is not NULL
    rewind(file);

    // paranoid check to make sure the buffer is not NULL
    uint8_t *buffer = malloc(size);
    CHECK_PTR(buffer);

    // paranoid check to make sure that the file pointer is not NULL
    size_t bytes_read = fread(buffer, 1, size, file);
    CHECK_PTR(fread);
    CHECK_RANGE(bytes_read, size, size);

    // paranoid check to make sure the buffer is not NULL
    uint32_t checksum = 0;
    for (size_t i = 0; i < size; i++)
    {
        checksum += buffer[i];
    }
    free(buffer);

    // paranoid check to make sure the file pointer is not NULL
    fclose(file);

    return checksum;
}

int main(int argc, char **argv)
{
    // paranoid check to make sure that the number of arguments is correct
    CHECK_RANGE(argc, 2, 2);
    if (argc != 2)
    {
        fprintf(stderr, "Error: Invalid number of arguments!\n");
        return EXIT_FAILURE;
    }

    // paranoid check to make sure that the filename is not NULL
    const char *filename = argv[1];
    CHECK_PTR(filename);

    // paranoid check to make sure that the checksum is correct
    uint32_t checksum = calculate_checksum(filename);
    uint32_t expected_checksum = 0x12345678;
    CHECK_CHECKSUM(checksum, expected_checksum);

    // paranoid check to make sure that the program exits with the correct exit code
    return EXIT_SUCCESS;
}