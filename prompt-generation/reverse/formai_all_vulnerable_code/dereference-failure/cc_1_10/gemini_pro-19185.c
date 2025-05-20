//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1024

int main(int argc, char *argv[]) {
  // Check the command line arguments.
  if (argc != 4) {
    fprintf(stderr, "Usage: %s key message encrypt|decrypt\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Read the key from the command line.
  char *key = argv[1];
  if (strlen(key) > MAX_KEY_LENGTH) {
    fprintf(stderr, "Error: Key is too long.\n");
    return EXIT_FAILURE;
  }

  // Read the message from the command line.
  char *message = argv[2];
  if (strlen(message) > MAX_MESSAGE_LENGTH) {
    fprintf(stderr, "Error: Message is too long.\n");
    return EXIT_FAILURE;
  }

  // Get the encryption/decryption mode from the command line.
  char *mode = argv[3];
  if (strcmp(mode, "encrypt") != 0 && strcmp(mode, "decrypt") != 0) {
    fprintf(stderr, "Error: Invalid mode.\n");
    return EXIT_FAILURE;
  }

  // Generate a random seed for the random number generator.
  srand(time(NULL));

  // Create a buffer for the encrypted/decrypted message.
  char *result = malloc(MAX_MESSAGE_LENGTH);
  if (result == NULL) {
    fprintf(stderr, "Error: Could not allocate memory for the result.\n");
    return EXIT_FAILURE;
  }

  // Encrypt or decrypt the message.
  if (strcmp(mode, "encrypt") == 0) {
    for (int i = 0; i < strlen(message); i++) {
      result[i] = message[i] ^ key[i % strlen(key)];
    }
  } else {
    for (int i = 0; i < strlen(message); i++) {
      result[i] = message[i] ^ key[i % strlen(key)];
    }
  }

  // Print the encrypted/decrypted message to the stdout.
  printf("%s\n", result);

  // Free the memory allocated for the result.
  free(result);

  return EXIT_SUCCESS;
}