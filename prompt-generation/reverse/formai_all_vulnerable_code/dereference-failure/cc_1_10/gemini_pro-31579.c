//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the encryption and decryption functions
char *encrypt(char *plaintext, int key);
char *decrypt(char *ciphertext, int key);

// Main function
int main() {
  // Declare the plaintext and ciphertext
  char plaintext[] = "Hello, world!";
  char ciphertext[strlen(plaintext)];

  // Encrypt the plaintext
  int key = 3;
  char *encryptedText = encrypt(plaintext, key);

  // Print the ciphertext
  printf("Ciphertext: %s\n", encryptedText);

  // Decrypt the ciphertext
  char *decryptedText = decrypt(encryptedText, key);

  // Print the decrypted text
  printf("Decrypted text: %s\n", decryptedText);

  return 0;
}

// Encryption function
char *encrypt(char *plaintext, int key) {
  // Allocate memory for the ciphertext
  char *ciphertext = malloc(strlen(plaintext) + 1);

  // Encrypt each character in the plaintext
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] + key;
  }

  // Terminate the ciphertext with a null character
  ciphertext[strlen(plaintext)] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Decryption function
char *decrypt(char *ciphertext, int key) {
  // Allocate memory for the plaintext
  char *plaintext = malloc(strlen(ciphertext) + 1);

  // Decrypt each character in the ciphertext
  for (int i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] - key;
  }

  // Terminate the plaintext with a null character
  plaintext[strlen(ciphertext)] = '\0';

  // Return the plaintext
  return plaintext;
}