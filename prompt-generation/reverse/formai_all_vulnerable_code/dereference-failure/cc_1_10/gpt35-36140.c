//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/aes.h>

// Define the key and initialization vector
#define KEY "0123456789abcdef"
#define IV "abcdef0123456789"

int main(void) {
  AES_KEY enc_key, dec_key;
  uint8_t key[AES_BLOCK_SIZE];
  uint8_t iv[AES_BLOCK_SIZE];
  char *plaintext = "Hello, world!";
  size_t plaintext_len = strlen(plaintext);
  size_t encrypted_len = 0;
  size_t decrypted_len = 0;
  uint8_t *encrypted = NULL;
  uint8_t *decrypted = NULL;
  
  // Copy the key and IV into uint8_t arrays
  memcpy(key, KEY, sizeof(key));
  memcpy(iv, IV, sizeof(iv));
  
  // Initialize the encryption and decryption keys
  AES_set_encrypt_key(key, 128, &enc_key);
  AES_set_decrypt_key(key, 128, &dec_key);
  
  // Allocate memory for encrypted and decrypted buffers
  encrypted = calloc(plaintext_len + AES_BLOCK_SIZE, sizeof(char));
  decrypted = calloc(plaintext_len + AES_BLOCK_SIZE, sizeof(char));
  
  // Encrypt the plaintext
  AES_cbc_encrypt(plaintext, encrypted, plaintext_len, &enc_key, iv, AES_ENCRYPT);
  encrypted_len = strlen((char *)encrypted);
  
  // Decrypt the ciphertext
  AES_cbc_encrypt(encrypted, decrypted, encrypted_len, &dec_key, iv, AES_DECRYPT);
  decrypted_len = strlen((char *)decrypted);
  
  // Print the original plaintext, encrypted ciphertext, and decrypted plaintext
  printf("Original Plaintext: %s\n", plaintext);
  printf("Encrypted Ciphertext: ");
  for (size_t i = 0; i < encrypted_len; i++) {
    printf("%02x", encrypted[i]);
  }
  printf("\n");
  printf("Decrypted Plaintext: %s\n", decrypted);
  
  // Free the memory
  free(encrypted);
  free(decrypted);
  
  return 0;
}