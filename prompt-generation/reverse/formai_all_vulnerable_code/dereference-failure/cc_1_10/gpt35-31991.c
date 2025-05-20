//FormAI DATASET v1.0 Category: File Encyptor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *filename);
void decrypt(char *filename);
int load_file(char *filename, char **buffer);

// Main function
int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage: %s [option] [filename]\n", argv[0]);
        printf("Options:\n\t-e: encrypt file\n\t-d: decrypt file\n");
        exit(1);
    }

    char *filename = argv[2];

    // Encrypt or decrypt file based on user input
    if(strcmp(argv[1], "-e") == 0)
        encrypt(filename);
    else if(strcmp(argv[1], "-d") == 0)
        decrypt(filename);
    else
    {
        printf("Invalid option. Please use -e or -d.\n");
        exit(1);
    }

    return 0;
}

// Encrypts a file
void encrypt(char *filename)
{
    char *buffer;
    int file_size, i;

    // Load file into memory
    file_size = load_file(filename, &buffer);

    // XOR each byte in file with 0xFF
    for(i=0; i<file_size; i++)
        buffer[i] = buffer[i] ^ 0xFF;

    // Write encrypted file back to disk
    FILE *out_file = fopen("encrypted_file", "wb");
    fwrite(buffer, sizeof(char), file_size, out_file);
    fclose(out_file);

    printf("Encryption complete! Encrypted file saved as encrypted_file.\n");

    // Free memory
    free(buffer);
}

// Decrypts a file
void decrypt(char *filename)
{
    char *buffer;
    int file_size, i;

    // Load file into memory
    file_size = load_file(filename, &buffer);

    // XOR each byte in file with 0xFF to decrypt
    for(i=0; i<file_size; i++)
        buffer[i] = buffer[i] ^ 0xFF;

    // Write decrypted file back to disk
    FILE *out_file = fopen("decrypted_file", "wb");
    fwrite(buffer, sizeof(char), file_size, out_file);
    fclose(out_file);

    printf("Decryption complete! Decrypted file saved as decrypted_file.\n");

    // Free memory
    free(buffer);
}

// Loads a file into memory
int load_file(char *filename, char **buffer)
{
    FILE *in_file = fopen(filename, "rb");
    fseek(in_file, 0, SEEK_END);
    int file_size = ftell(in_file);
    fseek(in_file, 0, SEEK_SET);
    *buffer = malloc(file_size);
    fread(*buffer, sizeof(char), file_size, in_file);
    fclose(in_file);

    return file_size;
}