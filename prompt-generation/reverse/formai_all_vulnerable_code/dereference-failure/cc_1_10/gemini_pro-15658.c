//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Key generation function
char *generateKey(int length) {
  srand(time(NULL));  // Initialize random number generator
  char *key = malloc(length + 1);  // Allocate memory for the key
  int i;
  for (i = 0; i < length; i++) {
    key[i] = (rand() % 26) + 'a';  // Generate a random lowercase character
  }
  key[length] = '\0';  // Terminate the string
  return key;
}

// Encryption function
char *encrypt(char *plaintext, char *key) {
  int plaintextLength = strlen(plaintext);
  int keyLength = strlen(key);
  char *ciphertext = malloc(plaintextLength + 1);  // Allocate memory for the ciphertext
  int i;
  for (i = 0; i < plaintextLength; i++) {
    char plaintextChar = plaintext[i];
    char keyChar = key[i % keyLength];
    int ciphertextChar = (plaintextChar - 'a' + keyChar - 'a') % 26 + 'a';  // Encrypt the character
    ciphertext[i] = ciphertextChar;
  }
  ciphertext[plaintextLength] = '\0';  // Terminate the string
  return ciphertext;
}

// Decryption function
char *decrypt(char *ciphertext, char *key) {
  int ciphertextLength = strlen(ciphertext);
  int keyLength = strlen(key);
  char *plaintext = malloc(ciphertextLength + 1);  // Allocate memory for the plaintext
  int i;
  for (i = 0; i < ciphertextLength; i++) {
    char ciphertextChar = ciphertext[i];
    char keyChar = key[i % keyLength];
    int plaintextChar = (ciphertextChar - 'a' - keyChar + 'a' + 26) % 26 + 'a';  // Decrypt the character
    plaintext[i] = plaintextChar;
  }
  plaintext[ciphertextLength] = '\0';  // Terminate the string
  return plaintext;
}

int main() {
  int keyLength;
  printf("Enter the length of the key: ");
  scanf("%d", &keyLength);

  char *key = generateKey(keyLength);  // Generate the key
  printf("Key: %s\n", key);

  char plaintext[100];
  printf("Enter the plaintext: ");
  scanf(" %[^\n]%*c", plaintext);  // Read the plaintext from the user

  char *ciphertext = encrypt(plaintext, key);  // Encrypt the plaintext
  printf("Ciphertext: %s\n", ciphertext);

  char *decryptedPlaintext = decrypt(ciphertext, key);  // Decrypt the ciphertext
  printf("Decrypted plaintext: %s\n", decryptedPlaintext);

  free(key);  // Free the memory allocated for the key
  free(ciphertext);  // Free the memory allocated for the ciphertext
  free(decryptedPlaintext);  // Free the memory allocated for the decrypted plaintext
  return 0;
}