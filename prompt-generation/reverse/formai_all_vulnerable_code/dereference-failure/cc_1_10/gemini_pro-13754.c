//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The key to unlock the encrypted file
#define KEY "abracadabra"

// The function to encrypt the file
void encrypt(char *filename) {
  // Open the file in read mode
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Get the size of the file
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind(file);

  // Allocate memory for the encrypted file
  char *encrypted = malloc(size);
  if (encrypted == NULL) {
    perror("Error allocating memory");
    exit(1);
  }

  // Read the file into the buffer
  fread(encrypted, 1, size, file);
  fclose(file);

  // Encrypt the file
  for (int i = 0; i < size; i++) {
    encrypted[i] ^= KEY[i % strlen(KEY)];
  }

  // Open the file in write mode
  file = fopen(filename, "w");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Write the encrypted file to disk
  fwrite(encrypted, 1, size, file);
  fclose(file);

  // Free the memory allocated for the encrypted file
  free(encrypted);

  printf("File encrypted successfully\n");
}

// The function to decrypt the file
void decrypt(char *filename) {
  // Open the file in read mode
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Get the size of the file
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind(file);

  // Allocate memory for the decrypted file
  char *decrypted = malloc(size);
  if (decrypted == NULL) {
    perror("Error allocating memory");
    exit(1);
  }

  // Read the file into the buffer
  fread(decrypted, 1, size, file);
  fclose(file);

  // Decrypt the file
  for (int i = 0; i < size; i++) {
    decrypted[i] ^= KEY[i % strlen(KEY)];
  }

  // Open the file in write mode
  file = fopen(filename, "w");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Write the decrypted file to disk
  fwrite(decrypted, 1, size, file);
  fclose(file);

  // Free the memory allocated for the decrypted file
  free(decrypted);

  printf("File decrypted successfully\n");
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <encrypt|decrypt> <filename>\n", argv[0]);
    return 1;
  }

  char *filename = argv[2];
  if (strcmp(argv[1], "encrypt") == 0) {
    encrypt(filename);
  } else if (strcmp(argv[1], "decrypt") == 0) {
    decrypt(filename);
  } else {
    printf("Invalid command\n");
    return 1;
  }

  return 0;
}