//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Declare the function to encrypt the file
void encryptFile(char *fileName, char *key);

// Declare the main function
int main() {
    // Declare the variables
    char fileName[100];
    char key[100];

    // Get the file name from the user
    printf("Enter the file name to encrypt: ");
    scanf("%s", fileName);

    // Get the key from the user
    printf("Enter the key to encrypt the file: ");
    scanf("%s", key);

    // Encrypt the file
    encryptFile(fileName, key);

    // Print a success message
    printf("File encrypted successfully!\n");

    return 0;
}

// Define the function to encrypt the file
void encryptFile(char *fileName, char *key) {
    // Open the file to be encrypted
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening the file!\n");
        exit(1);
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Create a buffer to store the encrypted data
    char *encryptedData = (char *)malloc(fileSize);
    if (encryptedData == NULL) {
        printf("Error allocating memory for the encrypted data!\n");
        exit(1);
    }

    // Encrypt the file
    for (long i = 0; i < fileSize; i++) {
        // Get the current byte from the file
        char byte = fgetc(file);

        // Encrypt the byte using the key
        byte ^= key[i % strlen(key)];

        // Store the encrypted byte in the buffer
        encryptedData[i] = byte;
    }

    // Close the file
    fclose(file);

    // Open a new file to store the encrypted data
    file = fopen("encrypted.txt", "wb");
    if (file == NULL) {
        printf("Error opening the file to store the encrypted data!\n");
        exit(1);
    }

    // Write the encrypted data to the file
    fwrite(encryptedData, 1, fileSize, file);

    // Close the file
    fclose(file);

    // Free the memory allocated for the encrypted data
    free(encryptedData);
}