//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 256

void xor_encrypt_decrypt(char *input, char *output, char *key)
{
    size_t key_len = strlen(key);
    for (size_t i = 0; i < strlen(input); i++)
    {
        output[i] = input[i] ^ key[i % key_len];
    }
}

void usage(char *program_name)
{
    fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", program_name);
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *input_file_name = argv[2];
    char *output_file_name = argv[3];
    char *key = argv[4];

    if (strlen(key) > KEY_SIZE)
    {
        fprintf(stderr, "Key size exceeds %d characters.\n", KEY_SIZE);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(input_file_name, "rb");
    if (!input_file)
    {
        perror("Could not open input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(output_file_name, "wb");
    if (!output_file)
    {
        perror("Could not open output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    size_t read_size;

    if (strcmp(mode, "encrypt") == 0)
    {
        while ((read_size = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0)
        {
            char output[BUFFER_SIZE];
            xor_encrypt_decrypt(buffer, output, key);
            fwrite(output, 1, read_size, output_file);
        }
        printf("Encryption completed successfully!\n");
    }
    else if (strcmp(mode, "decrypt") == 0)
    {
        while ((read_size = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0)
        {
            char output[BUFFER_SIZE];
            xor_encrypt_decrypt(buffer, output, key);
            fwrite(output, 1, read_size, output_file);
        }
        printf("Decryption completed successfully!\n");
    }
    else
    {
        usage(argv[0]);
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}