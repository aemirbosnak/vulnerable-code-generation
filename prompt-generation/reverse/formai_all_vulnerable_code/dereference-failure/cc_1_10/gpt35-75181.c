//FormAI DATASET v1.0 Category: File Encyptor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 17 // Key for encryption

void encrypt(char* filename);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: file_encryptor <filename>\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        encrypt(argv[i]);
        printf("File %s encrypted successfully!\n", argv[i]);
    }

    return 0;
}

void encrypt(char* filename)
{
    FILE* input_file = fopen(filename, "rb");

    if (input_file == NULL)
    {
        printf("Error opening file %s!\n", filename);
        exit(1);
    }

    // Get file size
    fseek(input_file, 0, SEEK_END);
    int file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    // Allocate memory for file contents
    char* buffer = malloc(file_size);

    if (buffer == NULL)
    {
        printf("Error allocating memory!\n");
        exit(1);
    }

    // Read file contents into buffer
    fread(buffer, file_size, 1, input_file);
    fclose(input_file);

    // Encrypt file contents
    for (int i = 0; i < file_size; i++)
    {
        buffer[i] ^= KEY;
    }

    // Write encrypted file contents back to file
    FILE* output_file = fopen(filename, "wb");

    if (output_file == NULL)
    {
        printf("Error opening file %s!\n", filename);
        exit(1);
    }

    fwrite(buffer, file_size, 1, output_file);
    fclose(output_file);

    // Free memory
    free(buffer);
}