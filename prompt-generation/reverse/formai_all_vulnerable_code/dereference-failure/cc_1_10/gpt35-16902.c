//FormAI DATASET v1.0 Category: File Encyptor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to encrypt the file
void encryptFile(char *fileName, char *key) {
    // Open the original file in read mode
    FILE *fp1 = fopen(fileName, "rb");
    if (fp1 == NULL) {
        printf("Error: Unable to open file %s\n", fileName);
        return;
    }

    // Create a new file with the same name and .enc extension
    char *newFileName = malloc(strlen(fileName) + 5);
    strcpy(newFileName, fileName);
    strcat(newFileName, ".enc");
    FILE *fp2 = fopen(newFileName, "wb");

    // Set seed for random number generation
    srand(time(NULL));

    // Write the encryption key to the beginning of the new file
    fwrite(key, sizeof(char), strlen(key), fp2);

    // Get the file size and store it in a variable
    fseek(fp1, 0L, SEEK_END);
    long size = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET);

    // Loop through the file one byte at a time and encrypt it with the key
    for (long i = 0; i < size; i++) {
        char originalByte;
        fread(&originalByte, sizeof(char), 1, fp1);

        char keyByte = key[i % strlen(key)];
        char encryptedByte = originalByte ^ keyByte;

        fwrite(&encryptedByte, sizeof(char), 1, fp2);
    }

    // Close the files and free dynamically allocated memory
    fclose(fp1);
    fclose(fp2);
    free(newFileName);

    printf("\n%s has been encrypted successfully!\n", fileName);
}

// Function to decrypt the file
void decryptFile(char *fileName, char *key) {
    // Open the encrypted file in read mode
    FILE *fp1 = fopen(fileName, "rb");
    if (fp1 == NULL) {
        printf("Error: Unable to open file %s\n", fileName);
        return;
    }

    // Create a new file with the same name and .dec extension
    char *newFileName = malloc(strlen(fileName) + 5);
    strcpy(newFileName, fileName);
    strcat(newFileName, ".dec");
    FILE *fp2 = fopen(newFileName, "wb");

    // Set the file pointer to the end of the key so we can start reading encrypted bytes
    fseek(fp1, strlen(key), SEEK_SET);

    // Get the file size and store it in a variable
    fseek(fp1, 0L, SEEK_END);
    long size = ftell(fp1);
    fseek(fp1, strlen(key), SEEK_SET);

    // Loop through the file one byte at a time and decrypt it with the key
    for (long i = strlen(key); i < size; i++) {
        char encryptedByte;
        fread(&encryptedByte, sizeof(char), 1, fp1);

        char keyByte = key[(i - strlen(key)) % strlen(key)];
        char decryptedByte = encryptedByte ^ keyByte;

        fwrite(&decryptedByte, sizeof(char), 1, fp2);
    }

    // Close the files and free dynamically allocated memory
    fclose(fp1);
    fclose(fp2);
    free(newFileName);

    printf("\n%s has been decrypted successfully!\n", fileName);
}

int main() {
    // Set the encryption key
    char key[20] = "MedievalCryptoKey";

    // Get the user's choice for which operation they want to perform
    int choice;
    printf("Select an operation:\n1. Encrypt a file\n2. Decrypt a file\n");
    scanf("%d", &choice);

    // Get the filename from the user
    char fileName[50];
    printf("Enter the filename to encrypt/decrypt: ");
    scanf("%s", fileName);

    // Perform the selected operation
    switch (choice) {
        case 1:
            encryptFile(fileName, key);
            break;
        case 2:
            decryptFile(fileName, key);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}