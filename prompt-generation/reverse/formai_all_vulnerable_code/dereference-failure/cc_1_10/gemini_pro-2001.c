//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-style ASCII art for the program banner
const char *banner =
    "███████╗███████╗██╗████████╗███████╗██╗   ██╗███████╗    \n"
    "██╔════╝██╔════╝██║╚══██╔══╝██╔════╝██║   ██║██╔════╝    \n"
    "███████╗█████╗  ██║   ██║   ███████╗██║   ██║███████╗    \n"
    "╚════██║██╔══╝  ██║   ██║   ╚════██║██║   ██║╚════██║    \n"
    "███████║███████╗██║   ██║   ███████║╚██████╔╝███████║    \n"
    "╚══════╝╚══════╝╚═╝   ╚═╝   ╚══════╝ ╚═════╝ ╚══════╝    \n";

// Function to encrypt a string using the Caesar cipher
char *caesar_encrypt(char *plaintext, int key) {
  char *ciphertext = malloc(strlen(plaintext) + 1);
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = (plaintext[i] + key - 'a') % 26 + 'a';
  }
  ciphertext[strlen(plaintext)] = '\0';
  return ciphertext;
}

// Function to decrypt a string using the Caesar cipher
char *caesar_decrypt(char *ciphertext, int key) {
  char *plaintext = malloc(strlen(ciphertext) + 1);
  for (int i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = (ciphertext[i] - key - 'a') % 26 + 'a';
  }
  plaintext[strlen(ciphertext)] = '\0';
  return plaintext;
}

int main() {
  // Print the program banner
  printf("%s\n", banner);

  // Get the plaintext from the user
  char plaintext[1024];
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);

  // Get the encryption key from the user
  int key;
  printf("Enter the encryption key: ");
  scanf("%d", &key);

  // Encrypt the plaintext
  char *ciphertext = caesar_encrypt(plaintext, key);

  // Print the ciphertext
  printf("Encrypted ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  char *decrypted_plaintext = caesar_decrypt(ciphertext, key);

  // Print the decrypted plaintext
  printf("Decrypted plaintext: %s\n", decrypted_plaintext);

  return 0;
}