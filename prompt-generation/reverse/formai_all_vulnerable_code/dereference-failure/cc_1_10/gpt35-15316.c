//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void generate_key(int size, char* key) {
  // generate random key of given size
  srand(time(0));
  for(int i=0; i<size; i++) {
    key[i] = 'A' + (rand() % 26);
  }
  key[size] = '\0';
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
  // perform XOR operation between plaintext and key
  int len = strlen(plaintext);
  for(int i=0; i<len; i++) {
    int j = i % strlen(key);
    ciphertext[i] = plaintext[i] ^ key[j];
  }
  ciphertext[len] = '\0';
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
  // perform XOR operation between ciphertext and key
  int len = strlen(ciphertext);
  for(int i=0; i<len; i++) {
    int j = i % strlen(key);
    plaintext[i] = ciphertext[i] ^ key[j];
  }
  plaintext[len] = '\0';
}

int main() {
  char plaintext[100], key[100], ciphertext[100];

  printf("Enter the plaintext message: ");
  fgets(plaintext, 100, stdin);
  printf("Plain text: %s", plaintext);

  generate_key(strlen(plaintext)-1, key);
  printf("Generated key: %s\n", key);

  encrypt(plaintext, key, ciphertext);
  printf("Encrypted message: %s\n", ciphertext);

  decrypt(ciphertext, key, plaintext);
  printf("Decrypted message: %s\n", plaintext);

  return 0;
}