//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_FILE_SIZE 1024 * 1024
#define MAX_PATTERN_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <file> <pattern>\n", argv[0]);
        return 1;
    }

    // Read the file into memory
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    uint8_t *file_data = malloc(file_size);
    if (file_data == NULL)
    {
        printf("Error: could not allocate memory for file data\n");
        fclose(file);
        return 1;
    }
    fread(file_data, 1, file_size, file);
    fclose(file);

    // Read the pattern into memory
    FILE *pattern_file = fopen(argv[2], "rb");
    if (pattern_file == NULL)
    {
        printf("Error: could not open pattern file %s\n", argv[2]);
        free(file_data);
        return 1;
    }
    fseek(pattern_file, 0, SEEK_END);
    long pattern_size = ftell(pattern_file);
    fseek(pattern_file, 0, SEEK_SET);
    uint8_t *pattern_data = malloc(pattern_size);
    if (pattern_data == NULL)
    {
        printf("Error: could not allocate memory for pattern data\n");
        fclose(pattern_file);
        free(file_data);
        return 1;
    }
    fread(pattern_data, 1, pattern_size, pattern_file);
    fclose(pattern_file);

    // Scan the file for the pattern
    int found = 0;
    for (int i = 0; i < file_size - pattern_size; i++)
    {
        if (memcmp(file_data + i, pattern_data, pattern_size) == 0)
        {
            found = 1;
            printf("Pattern found at offset %d\n", i);
        }
    }

    // Free the memory
    free(file_data);
    free(pattern_data);

    return found;
}