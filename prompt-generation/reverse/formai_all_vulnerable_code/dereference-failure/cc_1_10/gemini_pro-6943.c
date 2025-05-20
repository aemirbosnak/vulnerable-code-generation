//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "SECRET"

// Define the encryption function
char *encrypt(char *plaintext) {
  // Allocate memory for the ciphertext
  char *ciphertext = malloc(strlen(plaintext) + 1);

  // Loop through each character in the plaintext
  for (int i = 0; i < strlen(plaintext); i++) {
    // XOR the character with the key
    ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
  }

  // Null-terminate the ciphertext
  ciphertext[strlen(plaintext)] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Define the decryption function
char *decrypt(char *ciphertext) {
  // Allocate memory for the plaintext
  char *plaintext = malloc(strlen(ciphertext) + 1);

  // Loop through each character in the ciphertext
  for (int i = 0; i < strlen(ciphertext); i++) {
    // XOR the character with the key
    plaintext[i] = ciphertext[i] ^ KEY[i % strlen(KEY)];
  }

  // Null-terminate the plaintext
  plaintext[strlen(ciphertext)] = '\0';

  // Return the plaintext
  return plaintext;
}

// Get the plaintext from the user
char *get_plaintext() {
  // Allocate memory for the plaintext
  char *plaintext = malloc(1024);

  // Read the plaintext from the user
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);

  // Return the plaintext
  return plaintext;
}

// Print the ciphertext
void print_ciphertext(char *ciphertext) {
  // Print the ciphertext to the console
  printf("The ciphertext is: %s\n", ciphertext);
}

// Print the plaintext
void print_plaintext(char *plaintext) {
  // Print the plaintext to the console
  printf("The plaintext is: %s\n", plaintext);
}

// Main function
int main() {
  // Get the plaintext from the user
  char *plaintext = get_plaintext();

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext
  print_ciphertext(ciphertext);

  // Decrypt the ciphertext
  char *decrypted_plaintext = decrypt(ciphertext);

  // Print the plaintext
  print_plaintext(decrypted_plaintext);

  // Free the allocated memory
  free(plaintext);
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}