//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption algorithm
// XOR encryption
unsigned char encrypt(unsigned char plaintext, unsigned char key) {
  return plaintext ^ key;
}

// Define the decryption algorithm
unsigned char decrypt(unsigned char ciphertext, unsigned char key) {
  return ciphertext ^ key;
}

// Read a file into a buffer
char *read_file(char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  // Allocate a buffer for the file contents
  char *buffer = malloc(file_size + 1);
  if (buffer == NULL) {
    perror("Error allocating memory");
    fclose(file);
    return NULL;
  }

  // Read the file contents into the buffer
  fread(buffer, 1, file_size, file);
  fclose(file);

  // Null-terminate the buffer
  buffer[file_size] = '\0';

  // Return the buffer
  return buffer;
}

// Write a buffer to a file
int write_file(char *filename, char *buffer, size_t buffer_size) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    perror("Error opening file");
    return -1;
  }

  // Write the buffer to the file
  fwrite(buffer, 1, buffer_size, file);
  fclose(file);

  return 0;
}

// Encrypt a file
int encrypt_file(char *filename, char *key) {
  // Read the file into a buffer
  char *buffer = read_file(filename);
  if (buffer == NULL) {
    return -1;
  }

  // Get the file size
  size_t file_size = strlen(buffer);

  // Encrypt the buffer
  for (size_t i = 0; i < file_size; i++) {
    buffer[i] = encrypt(buffer[i], key);
  }

  // Write the encrypted buffer to a new file
  char *encrypted_filename = malloc(strlen(filename) + 5);
  strcpy(encrypted_filename, filename);
  strcat(encrypted_filename, ".enc");

  int status = write_file(encrypted_filename, buffer, file_size);
  free(encrypted_filename);
  free(buffer);

  return status;
}

// Decrypt a file
int decrypt_file(char *filename, char *key) {
  // Read the file into a buffer
  char *buffer = read_file(filename);
  if (buffer == NULL) {
    return -1;
  }

  // Get the file size
  size_t file_size = strlen(buffer);

  // Decrypt the buffer
  for (size_t i = 0; i < file_size; i++) {
    buffer[i] = decrypt(buffer[i], key);
  }

  // Write the decrypted buffer to a new file
  char *decrypted_filename = malloc(strlen(filename) + 5);
  strcpy(decrypted_filename, filename);
  strcat(decrypted_filename, ".dec");

  int status = write_file(decrypted_filename, buffer, file_size);
  free(decrypted_filename);
  free(buffer);

  return status;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <encrypt|decrypt> <filename> <key>\n", argv[0]);
    return 1;
  }

  char *command = argv[1];
  char *filename = argv[2];
  char *key = argv[3];

  if (strcmp(command, "encrypt") == 0) {
    return encrypt_file(filename, key);
  } else if (strcmp(command, "decrypt") == 0) {
    return decrypt_file(filename, key);
  } else {
    printf("Invalid command\n");
    return 1;
  }
}