//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY 0x1234

// Function to encrypt a file
void encrypt(char *filename) {
  // Open the file in read mode
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  // Allocate memory for the encrypted file
  char *encrypted_file = malloc(file_size);
  if (encrypted_file == NULL) {
    perror("Error allocating memory");
    exit(1);
  }

  // Read the file and encrypt it
  size_t bytes_read = fread(encrypted_file, 1, file_size, file);
  if (bytes_read != file_size) {
    perror("Error reading file");
    exit(1);
  }
  fclose(file);

  for (long i = 0; i < file_size; i++) {
    // XOR the byte with the encryption key
    encrypted_file[i] ^= KEY;
  }

  // Open the encrypted file in write mode
  file = fopen("encrypted.txt", "wb");
  if (file == NULL) {
    perror("Error opening encrypted file");
    exit(1);
  }

  // Write the encrypted file to disk
  fwrite(encrypted_file, 1, file_size, file);
  fclose(file);

  // Free the memory allocated for the encrypted file
  free(encrypted_file);

  printf("File encrypted successfully\n");
}

// Function to decrypt a file
void decrypt(char *filename) {
  // Open the file in read mode
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  // Allocate memory for the decrypted file
  char *decrypted_file = malloc(file_size);
  if (decrypted_file == NULL) {
    perror("Error allocating memory");
    exit(1);
  }

  // Read the file and decrypt it
  size_t bytes_read = fread(decrypted_file, 1, file_size, file);
  if (bytes_read != file_size) {
    perror("Error reading file");
    exit(1);
  }
  fclose(file);

  for (long i = 0; i < file_size; i++) {
    // XOR the byte with the encryption key
    decrypted_file[i] ^= KEY;
  }

  // Open the decrypted file in write mode
  file = fopen("decrypted.txt", "wb");
  if (file == NULL) {
    perror("Error opening decrypted file");
    exit(1);
  }

  // Write the decrypted file to disk
  fwrite(decrypted_file, 1, file_size, file);
  fclose(file);

  // Free the memory allocated for the decrypted file
  free(decrypted_file);

  printf("File decrypted successfully\n");
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s [encrypt|decrypt] filename\n", argv[0]);
    exit(1);
  }

  if (strcmp(argv[1], "encrypt") == 0) {
    encrypt(argv[2]);
  } else if (strcmp(argv[1], "decrypt") == 0) {
    decrypt(argv[2]);
  } else {
    printf("Invalid operation: %s", argv[1]);
    exit(1);
  }

  return 0;
}