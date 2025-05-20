//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The key for the encryption
#define KEY "Cyberpunk"

// Function to encrypt a string
char *encrypt(char *text) {
  int len = strlen(text);
  char *encryptedText = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    encryptedText[i] = text[i] ^ KEY[i % strlen(KEY)];
  }
  encryptedText[len] = '\0';
  return encryptedText;
}

// Function to decrypt a string
char *decrypt(char *text) {
  int len = strlen(text);
  char *decryptedText = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    decryptedText[i] = text[i] ^ KEY[i % strlen(KEY)];
  }
  decryptedText[len] = '\0';
  return decryptedText;
}

// Main function
int main() {
  // Get the text to be encrypted
  char text[100];
  printf("Enter the text to be encrypted: ");
  scanf("%s", text);

  // Encrypt the text
  char *encryptedText = encrypt(text);

  // Print the encrypted text
  printf("Encrypted text: %s\n", encryptedText);

  // Decrypt the encrypted text
  char *decryptedText = decrypt(encryptedText);

  // Print the decrypted text
  printf("Decrypted text: %s\n", decryptedText);

  // Free the allocated memory
  free(encryptedText);
  free(decryptedText);

  return 0;
}