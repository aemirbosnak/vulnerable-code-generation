//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main() {
  // The message we wish to shroud in secrecy
  const char *plaintext = "Whispers in the wind, secrets kept within";

  // The key to our enigmatic lockbox
  const char *key = "Aetherial enigma";

  // Choose an algorithm fit for our encryption quest
  EVP_CIPHER *cipher = EVP_aes_256_cbc();

  // Create a context for our encryption rituals
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

  // Prepare the context for encrypting our message
  EVP_EncryptInit_ex(ctx, cipher, NULL, (unsigned char *)key, NULL);

  // Allocate a buffer to hold our encrypted message
  unsigned char ciphertext[strlen(plaintext) + 1];

  // Perform the sacred act of encryption
  int ciphertext_len;
  EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char *)plaintext, strlen(plaintext));
  EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len);

  // Bask in the glow of our encrypted treasure
  printf("Encrypted message: %s\n", ciphertext);

  // Now, let us unveil the secrets concealed within
  EVP_DecryptInit_ex(ctx, cipher, NULL, (unsigned char *)key, NULL);

  // Allocate a buffer to hold our decrypted message
  unsigned char decryptedtext[strlen(ciphertext) + 1];

  // Perform the inverse of encryption, restoring our message to its original form
  int decryptedtext_len;
  EVP_DecryptUpdate(ctx, decryptedtext, &decryptedtext_len, ciphertext, strlen((char *)ciphertext));
  EVP_DecryptFinal_ex(ctx, decryptedtext + decryptedtext_len, &decryptedtext_len);

  // Witness the resurrection of our plaintext message
  printf("Decrypted message: %s\n", decryptedtext);

  // Clean up the remnants of our encryption rituals
  EVP_CIPHER_CTX_free(ctx);

  return 0;
}