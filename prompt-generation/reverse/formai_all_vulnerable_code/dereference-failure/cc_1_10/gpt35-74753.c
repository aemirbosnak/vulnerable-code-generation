//FormAI DATASET v1.0 Category: File Encyptor ; Style: statistical
/* A Statistical C File Encryptor Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Encryption Key
#define ENCRYPTION_KEY 0xFF

// Define the maximum file size to be encrypted
#define MAX_FILE_SIZE 1024

// File Encryptor Function
void fileEncryptor(char *path, unsigned char key)
{
    // Open the File in Read-Write Mode
    FILE *file = fopen(path, "r+b");

    // Check if the File was Opened Successfully
    if (file == NULL)
    {
        printf("File cannot be opened for encryption!");
        exit(1);
    }

    // Read the File into Buffer
    unsigned char buffer[MAX_FILE_SIZE];
    size_t bytesRead = fread(buffer, sizeof(unsigned char), MAX_FILE_SIZE, file);

    // Check if the File was Read Successfully
    if (bytesRead == 0)
    {
        printf("File cannot be read for encryption!");
        exit(1);
    }

    // Encrypt the File
    for (int i = 0; i < bytesRead; i++)
    {
        buffer[i] ^= key;
    }

    // Write the Encrypted File back to Disk
    fseek(file, 0, SEEK_SET);
    fwrite(buffer, sizeof(unsigned char), bytesRead, file);

    // Close the File
    fclose(file);
}

int main(int argc, char *argv[])
{
    // Check if the Command-Line Arguments are Correct
    if (argc != 2)
    {
        printf("Usage: encrypt <filename>");
        return 1;
    }

    // Get the Path of the File to be Encrypted
    char *filePath = argv[1];

    // Get the File Extension
    char *fileExtension = strrchr(filePath, '.');

    // Check if the File Extension is Valid
    if (fileExtension == NULL || strcmp(fileExtension, ".txt") != 0)
    {
        printf("Invalid file extension!");
        return 1;
    }

    // Encrypt the File
    fileEncryptor(filePath, ENCRYPTION_KEY);

    // Print Success Message
    printf("File encrypted successfully!");

    // Exit Program
    return 0;
}