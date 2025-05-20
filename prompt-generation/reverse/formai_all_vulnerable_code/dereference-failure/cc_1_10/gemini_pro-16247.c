//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the maximum size of the file to be encrypted
#define MAX_FILE_SIZE 1024

// Defining the key for encryption/decryption
#define ENCRYPTION_KEY "my_super_secret_key"

// Function to encrypt the file
void encryptFile(char *fileName) {
  // Opening the file in read mode
  FILE *file = fopen(fileName, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", fileName);
    exit(1);
  }

  // Creating a new file for writing the encrypted data
  char encryptedFileName[strlen(fileName) + 5];
  strcpy(encryptedFileName, fileName);
  strcat(encryptedFileName, ".enc");
  FILE *encryptedFile = fopen(encryptedFileName, "w");
  if (encryptedFile == NULL) {
    printf("Error creating encrypted file %s\n", encryptedFileName);
    exit(1);
  }

  // Reading the file contents
  char buffer[MAX_FILE_SIZE];
  size_t bytesRead;
  while ((bytesRead = fread(buffer, 1, MAX_FILE_SIZE, file)) > 0) {
    // Encrypting the buffer
    for (int i = 0; i < bytesRead; i++) {
      buffer[i] ^= ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
    }

    // Writing the encrypted buffer to the new file
    fwrite(buffer, 1, bytesRead, encryptedFile);
  }

  // Closing the files
  fclose(file);
  fclose(encryptedFile);
}

// Function to decrypt the file
void decryptFile(char *fileName) {
  // Opening the encrypted file in read mode
  FILE *encryptedFile = fopen(fileName, "r");
  if (encryptedFile == NULL) {
    printf("Error opening encrypted file %s\n", fileName);
    exit(1);
  }

  // Creating a new file for writing the decrypted data
  char decryptedFileName[strlen(fileName) - 4];
  strncpy(decryptedFileName, fileName, strlen(fileName) - 4);
  FILE *decryptedFile = fopen(decryptedFileName, "w");
  if (decryptedFile == NULL) {
    printf("Error creating decrypted file %s\n", decryptedFileName);
    exit(1);
  }

  // Reading the encrypted file contents
  char buffer[MAX_FILE_SIZE];
  size_t bytesRead;
  while ((bytesRead = fread(buffer, 1, MAX_FILE_SIZE, encryptedFile)) > 0) {
    // Decrypting the buffer
    for (int i = 0; i < bytesRead; i++) {
      buffer[i] ^= ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
    }

    // Writing the decrypted buffer to the new file
    fwrite(buffer, 1, bytesRead, decryptedFile);
  }

  // Closing the files
  fclose(encryptedFile);
  fclose(decryptedFile);
}

// Main function
int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <encrypt/decrypt> <file_name>\n", argv[0]);
    exit(1);
  }

  if (strcmp(argv[1], "encrypt") == 0) {
    encryptFile(argv[2]);
    printf("File %s encrypted successfully.\n", argv[2]);
  } else if (strcmp(argv[1], "decrypt") == 0) {
    decryptFile(argv[2]);
    printf("File %s decrypted successfully.\n", argv[2]);
  } else {
    printf("Invalid operation. Please specify 'encrypt' or 'decrypt'.\n");
    exit(1);
  }

  return 0;
}