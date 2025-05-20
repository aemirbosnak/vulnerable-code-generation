//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The key to unlock the secret
#define KEY "SURPRISE!"

// Encrypt a message using the xor cipher
char* encrypt(char* message) {
  size_t len = strlen(message);

  // Allocate memory for the encrypted message
  char* encrypted = malloc(len + 1);
  if (!encrypted) {
    perror("Memory allocation failed");
    return NULL;
  }

  // Encrypt the message byte by byte
  for (int i = 0; i < len; i++) {
    encrypted[i] = message[i] ^ KEY[i % strlen(KEY)];
  }

  // Null-terminate the encrypted message
  encrypted[len] = '\0';

  // Return the encrypted message
  return encrypted;
}

// Decrypt an encrypted message using the xor cipher
char* decrypt(char* encrypted) {
  size_t len = strlen(encrypted);

  // Allocate memory for the decrypted message
  char* decrypted = malloc(len + 1);
  if (!decrypted) {
    perror("Memory allocation failed");
    return NULL;
  }

  // Decrypt the message byte by byte
  for (int i = 0; i < len; i++) {
    decrypted[i] = encrypted[i] ^ KEY[i % strlen(KEY)];
  }

  // Null-terminate the decrypted message
  decrypted[len] = '\0';

  // Return the decrypted message
  return decrypted;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <message>\n", argv[0]);
    return 1;
  }

  // Get the message to be encrypted
  char* message = argv[1];

  // Encrypt the message
  char* encrypted = encrypt(message);
  if (!encrypted) {
    return 2;
  }

  // Decrypt the encrypted message
  char* decrypted = decrypt(encrypted);
  if (!decrypted) {
    return 3;
  }

  // Print the decrypted message
  printf("Original Message: %s\n", message);
  printf("Encrypted Message: %s\n", encrypted);
  printf("Decrypted Message: %s\n", decrypted);

  // Free the allocated memory
  free(encrypted);
  free(decrypted);

  return 0;
}