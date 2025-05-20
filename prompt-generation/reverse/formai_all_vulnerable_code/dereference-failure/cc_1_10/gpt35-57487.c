//FormAI DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt(char *input, char *output, int key);

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Prompt the user for the name of the file to encrypt
    printf("Enter the name of the file to encrypt: ");
    char filename[256];
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove trailing newline if present
    
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // Get the size of the file
    fseek(fp, 0L, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);
    
    // Allocate memory for the file contents
    char *filecontents = malloc(filesize + 1);
    fread(filecontents, 1, filesize, fp);
    
    // Close the file
    fclose(fp);
    
    // Generate a random encryption key
    int key = rand() % 100;
    printf("Using key: %d\n", key);
    
    // Encrypt the file contents using the key
    char *encrypted = malloc(filesize + 1);
    encrypt(filecontents, encrypted, key);
    
    // Create a new file to write the encrypted contents to
    char encryptedfilename[256];
    strncpy(encryptedfilename, filename, sizeof(encryptedfilename) - 2);
    strncat(encryptedfilename, ".enc", sizeof(encryptedfilename) - strlen(encryptedfilename) - 1);
    fp = fopen(encryptedfilename, "wb");
    if (fp == NULL) {
        printf("Error creating encrypted file.\n");
        return 1;
    }
    
    // Write the encrypted contents to the file
    fwrite(encrypted, 1, filesize, fp);
    
    // Close the file
    fclose(fp);
    
    // Free memory
    free(filecontents);
    free(encrypted);
    
    printf("Encryption complete. Output written to %s\n", encryptedfilename);
    
    return 0;
}

void encrypt(char *input, char *output, int key)
{
    // Iterate through each character in the input string
    while (*input != '\0') {
        // Apply the key to the character
        *output++ = (*input++) ^ key;
    }
    // Terminate the output string
    *output = '\0';
}