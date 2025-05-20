//FormAI DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ENCRYPTION_KEY "chatbot"
#define FILE_EXTENSION ".enc"

void encrypt_file(const char* input_filename);
void decrypt_file(const char* input_filename);

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* filename = argv[1];
    char* extension = strrchr(filename, '.');

    if(extension == NULL)
    {
        printf("Invalid file extension\n");
        exit(EXIT_FAILURE);
    }

    if(strcmp(extension, FILE_EXTENSION) == 0)
    {
        decrypt_file(filename);
    }
    else
    {
        encrypt_file(filename);
    }

    return 0;
}

void encrypt_file(const char* input_filename)
{
    // Open input file
    FILE* input_file = fopen(input_filename, "rb");

    if(input_file == NULL)
    {
        printf("Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    // Generate output filename
    char* output_filename = malloc(strlen(input_filename) + strlen(FILE_EXTENSION) + 1);

    if(output_filename == NULL)
    {
        printf("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    strcpy(output_filename, input_filename);
    strcat(output_filename, FILE_EXTENSION);

    // Open output file
    FILE* output_file = fopen(output_filename, "wb");

    if(output_file == NULL)
    {
        printf("Error opening output file\n");
        exit(EXIT_FAILURE);
    }

    // Generate encryption key
    srand(time(NULL));
    char encryption_key[11];

    for(int i = 0; i < 10; i++)
    {
        int rand_num = rand() % 26;
        encryption_key[i] = 'a' + rand_num;
    }

    encryption_key[10] = '\0';

    // Write encryption key to output file
    fwrite(encryption_key, sizeof(char), strlen(encryption_key), output_file);

    // Encrypt file contents
    char* buffer = malloc(1024);
    size_t bytes_read;

    while((bytes_read = fread(buffer, sizeof(char), 1024, input_file)) > 0)
    {
        for(int i = 0; i < bytes_read; i++)
        {
            buffer[i] ^= encryption_key[i % 10];
        }

        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }

    free(buffer);

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully\n");
}

void decrypt_file(const char* input_filename)
{
    // Open input file
    FILE* input_file = fopen(input_filename, "rb");

    if(input_file == NULL)
    {
        printf("Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    // Generate output filename
    size_t input_filename_len = strlen(input_filename);
    char* output_filename = malloc(input_filename_len - strlen(FILE_EXTENSION) + 1);

    if(output_filename == NULL)
    {
        printf("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    strncpy(output_filename, input_filename, input_filename_len - strlen(FILE_EXTENSION));
    output_filename[input_filename_len - strlen(FILE_EXTENSION)] = '\0';

    // Open output file
    FILE* output_file = fopen(output_filename, "wb");

    if(output_file == NULL)
    {
        printf("Error opening output file\n");
        exit(EXIT_FAILURE);
    }

    // Read encryption key from input file
    char encryption_key[11];
    fread(encryption_key, sizeof(char), 10, input_file);
    encryption_key[10] = '\0';

    // Decrypt file contents
    char* buffer = malloc(1024);
    size_t bytes_read;

    while((bytes_read = fread(buffer, sizeof(char), 1024, input_file)) > 0)
    {
        for(int i = 0; i < bytes_read; i++)
        {
            buffer[i] ^= encryption_key[i % 10];
        }

        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }

    free(buffer);

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("File decrypted successfully\n");
}