//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Startled key generation function
char *clumsy_keygen(int len) {
  // Gasp! I'm not ready for this!
  char *key = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    key[i] = (rand() % 26) + 'a';
  }
  key[len] = '\0';
  return key;
}

// Shocked encryption function
char *panicked_encrypt(char *plaintext, char *key) {
  // Holy smokes! I'm encrypting!
  int p_len = strlen(plaintext);
  int k_len = strlen(key);
  char *ciphertext = malloc(p_len + 1);
  for (int i = 0; i < p_len; i++) {
    ciphertext[i] = (plaintext[i] ^ key[i % k_len]) + 1;
  }
  ciphertext[p_len] = '\0';
  return ciphertext;
}

// Bewildered decryption function
char *perplexed_decrypt(char *ciphertext, char *key) {
  // Gosh! I'm decrypting!
  int c_len = strlen(ciphertext);
  int k_len = strlen(key);
  char *plaintext = malloc(c_len + 1);
  for (int i = 0; i < c_len; i++) {
    plaintext[i] = (ciphertext[i] - 1) ^ key[i % k_len];
  }
  plaintext[c_len] = '\0';
  return plaintext;
}

int main(void) {
  // Whoah! Let's encrypt!
  char *plaintext = "This is my secret text!";
  char *key = clumsy_keygen(10);
  printf("Original plain text: %s\n", plaintext);
  printf("Generated key: %s\n", key);
  char *ciphertext = panicked_encrypt(plaintext, key);
  printf("Encrypted text: %s\n", ciphertext);
  char *decrypted_text = perplexed_decrypt(ciphertext, key);
  printf("Decrypted text: %s\n", decrypted_text);
  // Shocked Pikachu face!
}