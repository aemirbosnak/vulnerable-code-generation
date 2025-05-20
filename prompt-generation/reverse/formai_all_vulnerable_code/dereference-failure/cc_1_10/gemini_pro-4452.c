//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// This function takes a string and encrypts it using the Romeo and Juliet cipher.
char *encrypt(char *plaintext) {
  int i, len;
  char *ciphertext;

  // Calculate the length of the plaintext string.
  len = strlen(plaintext);

  // Allocate memory for the ciphertext string.
  ciphertext = malloc(len + 1);

  // Encrypt the plaintext string.
  for (i = 0; i < len; i++) {
    if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
      ciphertext[i] = 'z' - (plaintext[i] - 'a');
    } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
      ciphertext[i] = 'Z' - (plaintext[i] - 'A');
    } else {
      ciphertext[i] = plaintext[i];
    }
  }

  // Null-terminate the ciphertext string.
  ciphertext[len] = '\0';

  // Return the ciphertext string.
  return ciphertext;
}

// This function takes a string and decrypts it using the Romeo and Juliet cipher.
char *decrypt(char *ciphertext) {
  int i, len;
  char *plaintext;

  // Calculate the length of the ciphertext string.
  len = strlen(ciphertext);

  // Allocate memory for the plaintext string.
  plaintext = malloc(len + 1);

  // Decrypt the ciphertext string.
  for (i = 0; i < len; i++) {
    if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
      plaintext[i] = 'z' - (ciphertext[i] - 'a');
    } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
      plaintext[i] = 'Z' - (ciphertext[i] - 'A');
    } else {
      plaintext[i] = ciphertext[i];
    }
  }

  // Null-terminate the plaintext string.
  plaintext[len] = '\0';

  // Return the plaintext string.
  return plaintext;
}

// This function takes a string and prints it to the console.
void print_string(char *string) {
  printf("%s\n", string);
}

// This function takes a string and frees the memory allocated to it.
void free_string(char *string) {
  free(string);
}

// This is the main function.
int main() {
  // The plaintext string.
  char *plaintext = "Romeo, Romeo! wherefore art thou Romeo?";

  // Encrypt the plaintext string.
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext string to the console.
  print_string(ciphertext);

  // Decrypt the ciphertext string.
  char *decrypted_plaintext = decrypt(ciphertext);

  // Print the decrypted plaintext string to the console.
  print_string(decrypted_plaintext);

  // Free the memory allocated to the ciphertext string.
  free_string(ciphertext);

  // Free the memory allocated to the decrypted plaintext string.
  free_string(decrypted_plaintext);

  return 0;
}