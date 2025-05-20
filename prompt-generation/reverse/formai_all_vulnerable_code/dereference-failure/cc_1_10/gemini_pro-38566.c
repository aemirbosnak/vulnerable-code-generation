//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption key
#define KEY "mysecretkey"

// Encrypt a string using XOR encryption
char* encrypt(const char* plaintext) {
  size_t len = strlen(plaintext);
  char* ciphertext = malloc(len + 1);
  for (size_t i = 0; i < len; i++) {
    ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
  }
  ciphertext[len] = '\0';
  return ciphertext;
}

// Decrypt a string using XOR encryption
char* decrypt(const char* ciphertext) {
  size_t len = strlen(ciphertext);
  char* plaintext = malloc(len + 1);
  for (size_t i = 0; i < len; i++) {
    plaintext[i] = ciphertext[i] ^ KEY[i % strlen(KEY)];
  }
  plaintext[len] = '\0';
  return plaintext;
}

// Print usage information
void usage() {
  printf("Usage: %s [encrypt|decrypt] <filename>\n", "file-encryptor");
  exit(EXIT_FAILURE);
}

// Main function
int main(int argc, char* argv[]) {
  if (argc < 3) {
    usage();
  }

  // Get the operation and filename
  char* operation = argv[1];
  char* filename = argv[2];

  // Open the file
  FILE* file = fopen(filename, "r+");
  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  // Read the contents of the file
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fseek(file, 0, SEEK_SET);
  char* contents = malloc(size + 1);
  fread(contents, 1, size, file);

  // Perform the encryption or decryption
  char* result;
  if (strcmp(operation, "encrypt") == 0) {
    result = encrypt(contents);
  } else if (strcmp(operation, "decrypt") == 0) {
    result = decrypt(contents);
  } else {
    usage();
  }

  // Write the result back to the file
  fseek(file, 0, SEEK_SET);
  fwrite(result, 1, strlen(result), file);

  // Close the file
  fclose(file);

  // Free the allocated memory
  free(contents);
  free(result);

  return EXIT_SUCCESS;
}