//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "SuperSecretKey123"

// Declare the encryption function
char* encrypt(char* plaintext);

// Declare the main function
int main(int argc, char* argv[])
{
    // Check if the user has provided a plaintext file
    if (argc != 2)
    {
        printf("Usage: %s <plaintext_file>\n", argv[0]);
        return 1;
    }

    // Read the plaintext file
    FILE* plaintext_file = fopen(argv[1], "r");
    if (plaintext_file == NULL)
    {
        printf("Error opening plaintext file: %s\n", argv[1]);
        return 1;
    }

    // Get the size of the plaintext file
    fseek(plaintext_file, 0, SEEK_END);
    long plaintext_size = ftell(plaintext_file);
    rewind(plaintext_file);

    // Allocate memory for the plaintext
    char* plaintext = (char*)malloc(plaintext_size + 1);
    if (plaintext == NULL)
    {
        printf("Error allocating memory for plaintext\n");
        return 1;
    }

    // Read the plaintext from the file
    fread(plaintext, 1, plaintext_size, plaintext_file);
    fclose(plaintext_file);

    // Encrypt the plaintext
    char* ciphertext = encrypt(plaintext);

    // Print the ciphertext to the screen
    printf("Ciphertext: %s\n", ciphertext);

    // Free the memory allocated for the plaintext and ciphertext
    free(plaintext);
    free(ciphertext);

    return 0;
}

// Define the encryption function
char* encrypt(char* plaintext)
{
    // Get the length of the plaintext
    int plaintext_length = strlen(plaintext);

    // Allocate memory for the ciphertext
    char* ciphertext = (char*)malloc(plaintext_length + 1);
    if (ciphertext == NULL)
    {
        printf("Error allocating memory for ciphertext\n");
        return NULL;
    }

    // Encrypt the plaintext using the XOR operator
    for (int i = 0; i < plaintext_length; i++)
    {
        ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
    }

    // Add the null terminator to the ciphertext
    ciphertext[plaintext_length] = '\0';

    // Return the ciphertext
    return ciphertext;
}