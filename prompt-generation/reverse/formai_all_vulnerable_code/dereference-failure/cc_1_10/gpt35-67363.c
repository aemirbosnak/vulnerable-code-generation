//FormAI DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(char* filename, char* key) {
  FILE *originalFile;
  FILE *encryptedFile;

  // Open the original file in binary mode
  originalFile = fopen(filename, "rb");

  if (originalFile == NULL) {
    perror("Error opening the file");
    exit(EXIT_FAILURE);
  }

  // Open the encrypted file in binary mode
  encryptedFile = fopen("encrypted.dat", "wb");

  if (encryptedFile == NULL) {
    perror("Error opening the file");
    exit(EXIT_FAILURE);
  }

  // Get the length of the file
  fseek(originalFile, 0, SEEK_END);
  long int fileLength = ftell(originalFile);
  fseek(originalFile, 0, SEEK_SET);

  // Allocate memory to store the contents of the file
  char* buffer = (char*) malloc(sizeof(char) * fileLength);

  if (buffer == NULL) {
    perror("Memory allocation error");
    exit(EXIT_FAILURE);
  }

  // Read the contents of the file into the buffer
  size_t result = fread(buffer, 1, fileLength, originalFile);

  if (result != fileLength) {
    perror("Error reading the file");
    exit(EXIT_FAILURE);
  }

  // Encrypt the file contents using the XOR cipher
  int keyLength = strlen(key);
  int i;

  for (i = 0; i < fileLength; i++) {
    buffer[i] = buffer[i] ^ key[i % keyLength];
  }

  // Write the encrypted contents to the encrypted file
  result = fwrite(buffer, 1, fileLength, encryptedFile);

  if (result != fileLength) {
    perror("Error writing to the file");
    exit(EXIT_FAILURE);
  }

  // Close the files and free the memory
  fclose(originalFile);
  fclose(encryptedFile);
  free(buffer);

  printf("Encryption complete. The encrypted file is 'encrypted.dat'.\n");
}

int main() {
  char* filename = "test.txt";
  char* key = "password";

  encryptFile(filename, key);

  return 0;
}