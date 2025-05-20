//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Linus Torvalds
// Linux Torvalds style C File Encyptor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the encryption key
#define KEY "abcdefghijklmnopqrstuvwxyz"

// Encrypt the file
void encrypt(FILE *input, FILE *output)
{
    int keylen = strlen(KEY);
    int c;

    while ((c = fgetc(input)) != EOF)
    {
        // Get the corresponding character from the key
        int keychar = c % keylen;

        // Encrypt the character by XORing it with the key character
        c ^= KEY[keychar];

        // Write the encrypted character to the output file
        fputc(c, output);
    }
}

// Decrypt the file
void decrypt(FILE *input, FILE *output)
{
    int keylen = strlen(KEY);
    int c;

    while ((c = fgetc(input)) != EOF)
    {
        // Get the corresponding character from the key
        int keychar = c % keylen;

        // Decrypt the character by XORing it with the key character
        c ^= KEY[keychar];

        // Write the decrypted character to the output file
        fputc(c, output);
    }
}

// Usage: ./encryptor [-e|-d] inputfile outputfile
int main(int argc, char *argv[])
{
    // Check for the correct number of arguments
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./encryptor [-e|-d] inputfile outputfile\n");
        exit(EXIT_FAILURE);
    }

    // Get the input and output file names
    char *inputfile = argv[2];
    char *outputfile = argv[3];

    // Get the encryption/decryption flag
    char *flag = argv[1];

    // Open the input and output files
    FILE *input = fopen(inputfile, "r");
    FILE *output = fopen(outputfile, "w");

    // Check if the files were opened successfully
    if (input == NULL || output == NULL)
    {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    // Encrypt or decrypt the file
    if (strcmp(flag, "-e") == 0)
    {
        encrypt(input, output);
    }
    else if (strcmp(flag, "-d") == 0)
    {
        decrypt(input, output);
    }
    else
    {
        fprintf(stderr, "Invalid flag. Use either -e or -d.\n");
        exit(EXIT_FAILURE);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}