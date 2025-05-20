//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(char *inputFile, char *outputFile, char *key)
{
    // Open the input file
    FILE *in = fopen(inputFile, "rb");
    if (in == NULL)
    {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file
    FILE *out = fopen(outputFile, "wb");
    if (out == NULL)
    {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Get the file size
    fseek(in, 0, SEEK_END);
    long fileSize = ftell(in);
    rewind(in);

    // Allocate memory for the input buffer
    char *inputBuffer = malloc(fileSize);
    if (inputBuffer == NULL)
    {
        perror("Error allocating memory for input buffer");
        exit(EXIT_FAILURE);
    }

    // Read the input file into the buffer
    fread(inputBuffer, fileSize, 1, in);

    // Allocate memory for the output buffer
    char *outputBuffer = malloc(fileSize);
    if (outputBuffer == NULL)
    {
        perror("Error allocating memory for output buffer");
        exit(EXIT_FAILURE);
    }

    // Encrypt the input buffer
    for (int i = 0; i < fileSize; i++)
    {
        outputBuffer[i] = inputBuffer[i] ^ key[i % strlen(key)];
    }

    // Write the encrypted buffer to the output file
    fwrite(outputBuffer, fileSize, 1, out);

    // Free the memory
    free(inputBuffer);
    free(outputBuffer);

    // Close the files
    fclose(in);
    fclose(out);
}

// Function to decrypt a file
void decryptFile(char *inputFile, char *outputFile, char *key)
{
    // Open the input file
    FILE *in = fopen(inputFile, "rb");
    if (in == NULL)
    {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file
    FILE *out = fopen(outputFile, "wb");
    if (out == NULL)
    {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Get the file size
    fseek(in, 0, SEEK_END);
    long fileSize = ftell(in);
    rewind(in);

    // Allocate memory for the input buffer
    char *inputBuffer = malloc(fileSize);
    if (inputBuffer == NULL)
    {
        perror("Error allocating memory for input buffer");
        exit(EXIT_FAILURE);
    }

    // Read the input file into the buffer
    fread(inputBuffer, fileSize, 1, in);

    // Allocate memory for the output buffer
    char *outputBuffer = malloc(fileSize);
    if (outputBuffer == NULL)
    {
        perror("Error allocating memory for output buffer");
        exit(EXIT_FAILURE);
    }

    // Decrypt the input buffer
    for (int i = 0; i < fileSize; i++)
    {
        outputBuffer[i] = inputBuffer[i] ^ key[i % strlen(key)];
    }

    // Write the decrypted buffer to the output file
    fwrite(outputBuffer, fileSize, 1, out);

    // Free the memory
    free(inputBuffer);
    free(outputBuffer);

    // Close the files
    fclose(in);
    fclose(out);
}

// Main function
int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Usage: %s <encrypt/decrypt> <input file> <output file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "encrypt") == 0)
    {
        encryptFile(argv[2], argv[3], argv[4]);
    }
    else if (strcmp(argv[1], "decrypt") == 0)
    {
        decryptFile(argv[2], argv[3], argv[4]);
    }
    else
    {
        printf("Invalid operation. Valid operations are 'encrypt' and 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}