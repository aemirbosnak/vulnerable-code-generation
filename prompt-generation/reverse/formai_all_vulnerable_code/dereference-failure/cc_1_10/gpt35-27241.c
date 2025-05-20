//FormAI DATASET v1.0 Category: modern Encryption ; Style: expert-level
/* Expert-level C modern encryption program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ENCRYPT 1
#define DECRYPT 0

void encrypt(char* file_path, char* key);
void decrypt(char* file_path, char* key);
void scramble_key(char* key);
void xor_file(char* file_path, char* key, int operation);

int main(int argc, char* argv[])
{
    if(argc < 4)
    {
        printf("Usage: %s [encrypt/decrypt] [file_path] [key]\n", argv[0]);
        return EXIT_FAILURE;
    }

    int operation;
    if(strcmp(argv[1], "encrypt") == 0)
    {
        operation = ENCRYPT;
    }
    else if(strcmp(argv[1], "decrypt") == 0)
    {
        operation = DECRYPT;
    }
    else
    {
        printf("Invalid operation specified. Operation must be either 'encrypt' or 'decrypt'\n");
        return EXIT_FAILURE;
    }

    char* file_path = argv[2];
    char* key = argv[3];

    switch(operation)
    {
        case ENCRYPT:
            encrypt(file_path, key);
            break;
        case DECRYPT:
            decrypt(file_path, key);
            break;
    }

    return EXIT_SUCCESS;
}

void encrypt(char* file_path, char* key)
{
    // Scramble key for extra security
    scramble_key(key);

    // XOR the file with the key
    xor_file(file_path, key, ENCRYPT);

    // Print success message
    printf("Encryption successful\n");
}

void decrypt(char* file_path, char* key)
{
    // Scramble key for extra security
    scramble_key(key);

    // XOR the file with the key
    xor_file(file_path, key, DECRYPT);

    // Print success message
    printf("Decryption successful\n");
}

void scramble_key(char* key)
{
    // Seed random number generator
    srand(time(NULL));

    // Swap characters in the key a random number of times
    int key_len = strlen(key);
    for(int i = 0; i < key_len; i++)
    {
        int j = rand() % key_len;
        char temp = key[i];
        key[i] = key[j];
        key[j] = temp;
    }
}

void xor_file(char* file_path, char* key, int operation)
{
    // Open input file and check for errors
    FILE* input_file = fopen(file_path, "rb+");
    if(input_file == NULL)
    {
        printf("Error opening file: %s\n", file_path);
        return;
    }

    // Get file size
    fseek(input_file, 0, SEEK_END);
    int file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    // Read file content into memory
    char* file_content = (char*) malloc(file_size);
    fread(file_content, 1, file_size, input_file);

    // XOR the file content with the key
    int key_len = strlen(key);
    for(int i = 0; i < file_size; i++)
    {
        file_content[i] ^= key[i % key_len];
    }

    // Write the encrypted/decrypted file content back to the input file
    fseek(input_file, 0, SEEK_SET);
    fwrite(file_content, 1, file_size, input_file);

    // Close input file and free memory
    fclose(input_file);
    free(file_content);
}