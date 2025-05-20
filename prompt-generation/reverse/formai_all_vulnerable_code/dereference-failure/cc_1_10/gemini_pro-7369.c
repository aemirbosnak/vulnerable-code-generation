//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Define the encryption key
#define KEY "my_super_secret_key"

// Encrypt a string using XOR encryption
char *encrypt(char *plaintext) {
  char *ciphertext = malloc(strlen(plaintext) + 1);

  // Get the length of the key
  int key_len = strlen(KEY);

  // Iterate over the plaintext and encrypt each character
  for (int i = 0; i < strlen(plaintext); i++) {
    char key_char = KEY[i % key_len];
    ciphertext[i] = plaintext[i] ^ key_char;
  }

  // Add the null-terminator
  ciphertext[strlen(plaintext)] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Decrypt a string using XOR encryption
char *decrypt(char *ciphertext) {
  char *plaintext = malloc(strlen(ciphertext) + 1);

  // Get the length of the key
  int key_len = strlen(KEY);

  // Iterate over the ciphertext and decrypt each character
  for (int i = 0; i < strlen(ciphertext); i++) {
    char key_char = KEY[i % key_len];
    plaintext[i] = ciphertext[i] ^ key_char;
  }

  // Add the null-terminator
  plaintext[strlen(ciphertext)] = '\0';

  // Return the plaintext
  return plaintext;
}

// Get input from the user
char *get_input(char *prompt) {
  char *input = malloc(1024);
  printf("%s", prompt);
  fgets(input, 1024, stdin);
  return input;
}

// Main function
int main() {
  // Get the plaintext from the user
  char *plaintext = get_input("Enter the plaintext: ");

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext
  printf("Encrypted text: %s\n", ciphertext);

  // Decrypt the ciphertext
  char *decrypted_plaintext = decrypt(ciphertext);

  // Print the decrypted plaintext
  printf("Decrypted text: %s\n", decrypted_plaintext);

  // Free the allocated memory
  free(plaintext);
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}