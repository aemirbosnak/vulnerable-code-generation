//FormAI DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Usage: %s [input_file] [output_file] [key]\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    FILE *output_file = fopen(argv[2], "wb");
    char *key = argv[3];
    int key_len = strlen(key);

    if(input_file == NULL || output_file == NULL)
    {
        printf("Failed to open input or output file\n");
        return 1;
    }

    fseek(input_file, 0L, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0L, SEEK_SET);

    char buffer[BUFFER_SIZE];

    while(fread(buffer, sizeof(char), BUFFER_SIZE, input_file))
    {
        // XOR the buffer with the key
        for(int i = 0; i < BUFFER_SIZE; i++)
        {
            buffer[i] ^= key[i % key_len];
        }

        fwrite(buffer, sizeof(char), BUFFER_SIZE, output_file);
    }

    // Handle the remaining bytes that were smaller than BUFFER_SIZE
    long remaining_bytes = file_size % BUFFER_SIZE;
    fread(buffer, sizeof(char), remaining_bytes, input_file);

    for(int i = 0; i < remaining_bytes; i++)
    {
        buffer[i] ^= key[i % key_len];
    }

    fwrite(buffer, sizeof(char), remaining_bytes, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");
    return 0;
}