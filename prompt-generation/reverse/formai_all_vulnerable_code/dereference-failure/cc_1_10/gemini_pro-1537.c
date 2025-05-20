//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "The quick brown fox jumps over the lazy dog"

// Encrypt a message using the XOR cipher
char *encrypt(char *message) {
  int key_index = 0;
  int message_length = strlen(message);
  char *encrypted_message = malloc(message_length + 1);
  for (int i = 0; i < message_length; i++) {
    encrypted_message[i] = message[i] ^ KEY[key_index++];
    if (key_index >= strlen(KEY)) {
      key_index = 0;
    }
  }
  encrypted_message[message_length] = '\0';
  return encrypted_message;
}

// Decrypt a message using the XOR cipher
char *decrypt(char *message) {
  int key_index = 0;
  int message_length = strlen(message);
  char *decrypted_message = malloc(message_length + 1);
  for (int i = 0; i < message_length; i++) {
    decrypted_message[i] = message[i] ^ KEY[key_index++];
    if (key_index >= strlen(KEY)) {
      key_index = 0;
    }
  }
  decrypted_message[message_length] = '\0';
  return decrypted_message;
}

// Print the usage information
void print_usage() {
  printf("Usage: encrypt <message>\n");
  printf("       decrypt <encrypted_message>\n");
}

int main(int argc, char **argv) {
  if (argc == 1) {
    print_usage();
    return 1;
  }

  if (strcmp(argv[1], "encrypt") == 0) {
    if (argc != 3) {
      print_usage();
      return 1;
    }
    char *encrypted_message = encrypt(argv[2]);
    printf("Encrypted message: %s\n", encrypted_message);
  } else if (strcmp(argv[1], "decrypt") == 0) {
    if (argc != 3) {
      print_usage();
      return 1;
    }
    char *decrypted_message = decrypt(argv[2]);
    printf("Decrypted message: %s\n", decrypted_message);
  } else {
    print_usage();
    return 1;
  }

  return 0;
}