//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_KEY_SIZE 256
#define AES_BLOCK_SIZE 128

void encrypt(char *password, char *plaintext, char *ciphertext) {
  unsigned char key[AES_KEY_SIZE/8];
  unsigned char iv[AES_BLOCK_SIZE/8];
  AES_KEY aes_key;

  memset(key, 0, AES_KEY_SIZE/8);
  memset(iv, 0, AES_BLOCK_SIZE/8);

  int password_length = strlen(password);
  int key_length = (password_length > AES_KEY_SIZE/8) ? AES_KEY_SIZE/8 : password_length;
  memcpy(key, password, key_length);

  unsigned char *output = malloc(strlen(plaintext) + AES_BLOCK_SIZE/8);
  
  AES_set_encrypt_key(key, AES_KEY_SIZE, &aes_key);
  AES_cbc_encrypt(plaintext, output, strlen(plaintext), &aes_key, iv, AES_ENCRYPT);

  sprintf(ciphertext, "%s", output);
  free(output);
}

void decrypt(char *password, char *ciphertext, char *plaintext) {
  unsigned char key[AES_KEY_SIZE/8];
  unsigned char iv[AES_BLOCK_SIZE/8];
  AES_KEY aes_key;

  memset(key, 0, AES_KEY_SIZE/8);
  memset(iv, 0, AES_BLOCK_SIZE/8);

  int password_length = strlen(password);
  int key_length = (password_length > AES_KEY_SIZE/8) ? AES_KEY_SIZE/8 : password_length;
  memcpy(key, password, key_length);

  unsigned char *output = malloc(strlen(ciphertext) + AES_BLOCK_SIZE/8);

  AES_set_decrypt_key(key, AES_KEY_SIZE, &aes_key);
  AES_cbc_encrypt(ciphertext, output, strlen(ciphertext), &aes_key, iv, AES_DECRYPT);

  sprintf(plaintext, "%s", output);
  free(output);
}

int main() {
  char password[] = "mypassword";
  char plaintext[] = "hello world";
  char ciphertext[strlen(plaintext)];

  encrypt(password, plaintext, ciphertext);
  
  printf("Plaintext: %s\nCiphertext: %s\n", plaintext, ciphertext);

  char decrypted[strlen(ciphertext)];
  decrypt(password, ciphertext, decrypted);

  printf("Decrypted: %s\n", decrypted);
  
  return 0;
}