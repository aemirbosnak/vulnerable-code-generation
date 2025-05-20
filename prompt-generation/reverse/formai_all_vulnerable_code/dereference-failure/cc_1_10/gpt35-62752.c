//FormAI DATASET v1.0 Category: File Encyptor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_KEY_LENGTH 16

void encryptFile(char* filename, char* key);
void decryptFile(char* filename, char* key);

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter the name of the file to encrypt/decrypt: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);

    // Remove newline character at the end of filename
    filename[strcspn(filename, "\n")] = 0;

    printf("Enter the encryption/decryption key (max 16 chars): ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    // Remove newline character at the end of key
    key[strcspn(key, "\n")] = 0;

    char choice;

    do
    {
        printf("\nChoose an operation:\n");
        printf("1. Encrypt file\n");
        printf("2. Decrypt file\n");
        printf("\nEnter choice: ");
        scanf(" %c", &choice);
    }
    while (choice != '1' && choice != '2');

    if (choice == '1')
    {
        encryptFile(filename, key);
    }
    else
    {
        decryptFile(filename, key);
    }

    return 0;
}

void encryptFile(char* filename, char* key)
{
    FILE* file = fopen(filename, "rb");

    // Check if file exists
    if (file == NULL)
    {
        printf("Error: File not found\n");
        return;
    }

    // Get file size
    fseek(file, 0L, SEEK_END);
    long int fileSize = ftell(file);
    rewind(file);

    // Allocate memory for file data
    char* fileData = malloc(fileSize);

    // Read file data into memory
    fread(fileData, fileSize, 1, file);
    fclose(file);

    // Perform encryption using XOR cipher
    for (int i = 0; i < fileSize; i++)
    {
        fileData[i] ^= key[i % strlen(key)];
    }

    // Write encrypted data back to file
    FILE* encryptedFile = fopen(strcat(filename, ".enc"), "wb");
    fwrite(fileData, fileSize, 1, encryptedFile);
    fclose(encryptedFile);

    printf("File encrypted successfully!\n");
    free(fileData);
}

void decryptFile(char* filename, char* key)
{
    // Check if ".enc" extension exists
    char* extension = strrchr(filename, '.');
    if (extension == NULL || strcmp(extension, ".enc") != 0)
    {
        printf("Error: File is not an encrypted file\n");
        return;
    }

    FILE* file = fopen(filename, "rb");

    // Check if file exists
    if (file == NULL)
    {
        printf("Error: Encrypted file not found\n");
        return;
    }

    // Get file size
    fseek(file, 0L, SEEK_END);
    long int fileSize = ftell(file);
    rewind(file);

    // Allocate memory for file data
    char* fileData = malloc(fileSize);

    // Read file data into memory
    fread(fileData, fileSize, 1, file);
    fclose(file);

    // Perform decryption using XOR cipher
    for (int i = 0; i < fileSize; i++)
    {
        fileData[i] ^= key[i % strlen(key)];
    }

    // Write decrypted data back to file
    char* tempFilename = strdup(filename);
    tempFilename[strlen(tempFilename) - strlen(extension)] = '\0';
    FILE* decryptedFile = fopen(tempFilename, "wb");
    fwrite(fileData, fileSize, 1, decryptedFile);
    fclose(decryptedFile);

    printf("File decrypted successfully!\n");
    free(fileData);
}