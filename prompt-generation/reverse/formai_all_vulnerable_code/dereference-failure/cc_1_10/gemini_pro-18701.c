//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encrypts a file using the XOR cipher
int encrypt_file(char *filename, char *key) {
  // Open the file
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return -1;
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory for the encrypted file
  char *encrypted_file = malloc(file_size);
  if (encrypted_file == NULL) {
    printf("Error allocating memory for encrypted file\n");
    fclose(file);
    return -1;
  }

  // Read the file into the buffer
  fread(encrypted_file, 1, file_size, file);
  fclose(file);

  // Encrypt the file using the XOR cipher
  for (long i = 0; i < file_size; i++) {
    encrypted_file[i] ^= key[i % strlen(key)];
  }

  // Open the output file
  FILE *output_file = fopen("encrypted.txt", "wb");
  if (output_file == NULL) {
    printf("Error opening output file\n");
    free(encrypted_file);
    return -1;
  }

  // Write the encrypted file to the output file
  fwrite(encrypted_file, 1, file_size, output_file);
  fclose(output_file);

  // Free the memory allocated for the encrypted file
  free(encrypted_file);

  return 0;
}

// Decrypts a file using the XOR cipher
int decrypt_file(char *filename, char *key) {
  // Open the file
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return -1;
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory for the decrypted file
  char *decrypted_file = malloc(file_size);
  if (decrypted_file == NULL) {
    printf("Error allocating memory for decrypted file\n");
    fclose(file);
    return -1;
  }

  // Read the file into the buffer
  fread(decrypted_file, 1, file_size, file);
  fclose(file);

  // Decrypt the file using the XOR cipher
  for (long i = 0; i < file_size; i++) {
    decrypted_file[i] ^= key[i % strlen(key)];
  }

  // Open the output file
  FILE *output_file = fopen("decrypted.txt", "wb");
  if (output_file == NULL) {
    printf("Error opening output file\n");
    free(decrypted_file);
    return -1;
  }

  // Write the decrypted file to the output file
  fwrite(decrypted_file, 1, file_size, output_file);
  fclose(output_file);

  // Free the memory allocated for the decrypted file
  free(decrypted_file);

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <filename> <key> <encrypt/decrypt>\n", argv[0]);
    return -1;
  }

  char *filename = argv[1];
  char *key = argv[2];
  char *mode = argv[3];

  if (strcmp(mode, "encrypt") == 0) {
    encrypt_file(filename, key);
  } else if (strcmp(mode, "decrypt") == 0) {
    decrypt_file(filename, key);
  } else {
    printf("Invalid mode\n");
    return -1;
  }

  return 0;
}