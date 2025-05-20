//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file using XOR encryption
int encrypt_file(char *input_file, char *output_file, char *key)
{
    // Open the input file in read mode
    FILE *input = fopen(input_file, "rb");
    if (input == NULL)
    {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return -1;
    }

    // Open the output file in write mode
    FILE *output = fopen(output_file, "wb");
    if (output == NULL)
    {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        return -1;
    }

    // Get the file size
    fseek(input, 0L, SEEK_END);
    long file_size = ftell(input);
    rewind(input);

    // Allocate a buffer to store the file contents
    unsigned char *file_buffer = malloc(file_size);
    if (file_buffer == NULL)
    {
        fprintf(stderr, "Error allocating memory for file buffer\n");
        return -1;
    }

    // Read the file contents into the buffer
    fread(file_buffer, 1, file_size, input);

    // Encrypt the file contents using XOR encryption
    for (long i = 0; i < file_size; i++)
    {
        file_buffer[i] ^= key[i % strlen(key)];
    }

    // Write the encrypted contents to the output file
    fwrite(file_buffer, 1, file_size, output);

    // Free the allocated memory
    free(file_buffer);

    // Close the files
    fclose(input);
    fclose(output);

    return 0;
}

// Function to decrypt a file using XOR encryption
int decrypt_file(char *input_file, char *output_file, char *key)
{
    // Open the input file in read mode
    FILE *input = fopen(input_file, "rb");
    if (input == NULL)
    {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return -1;
    }

    // Open the output file in write mode
    FILE *output = fopen(output_file, "wb");
    if (output == NULL)
    {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        return -1;
    }

    // Get the file size
    fseek(input, 0L, SEEK_END);
    long file_size = ftell(input);
    rewind(input);

    // Allocate a buffer to store the file contents
    unsigned char *file_buffer = malloc(file_size);
    if (file_buffer == NULL)
    {
        fprintf(stderr, "Error allocating memory for file buffer\n");
        return -1;
    }

    // Read the file contents into the buffer
    fread(file_buffer, 1, file_size, input);

    // Decrypt the file contents using XOR encryption
    for (long i = 0; i < file_size; i++)
    {
        file_buffer[i] ^= key[i % strlen(key)];
    }

    // Write the decrypted contents to the output file
    fwrite(file_buffer, 1, file_size, output);

    // Free the allocated memory
    free(file_buffer);

    // Close the files
    fclose(input);
    fclose(output);

    return 0;
}

// Main function
int main(int argc, char **argv)
{
    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key> <mode>\n", argv[0]);
        fprintf(stderr, "Mode can be either 'encrypt' or 'decrypt'\n");
        return -1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *key = argv[3];
    char *mode = argv[4];

    if (strcmp(mode, "encrypt") == 0)
    {
        if (encrypt_file(input_file, output_file, key) != 0)
        {
            fprintf(stderr, "Error encrypting file\n");
            return -1;
        }
    }
    else if (strcmp(mode, "decrypt") == 0)
    {
        if (decrypt_file(input_file, output_file, key) != 0)
        {
            fprintf(stderr, "Error decrypting file\n");
            return -1;
        }
    }
    else
    {
        fprintf(stderr, "Invalid mode: %s\n", mode);
        return -1;
    }

    return 0;
}