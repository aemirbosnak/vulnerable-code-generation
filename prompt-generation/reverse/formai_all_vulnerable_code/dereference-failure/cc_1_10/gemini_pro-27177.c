//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned char *plaintext;
  unsigned char *ciphertext;
  unsigned char *key;
  int keylen;
  int ptlen;
  int ctlen;
} ShannonCipher;

ShannonCipher *shannon_init(const unsigned char *key, int keylen)
{
  ShannonCipher *cipher = malloc(sizeof(ShannonCipher));
  cipher->key = malloc(keylen);
  memcpy(cipher->key, key, keylen);
  cipher->keylen = keylen;
  return cipher;
}

void shannon_encrypt(ShannonCipher *cipher, const unsigned char *plaintext, int ptlen)
{
  cipher->plaintext = malloc(ptlen);
  memcpy(cipher->plaintext, plaintext, ptlen);
  cipher->ptlen = ptlen;
  cipher->ciphertext = malloc(ptlen);
  cipher->ctlen = ptlen;
  for (int i = 0; i < ptlen; i++) {
    cipher->ciphertext[i] = cipher->plaintext[i] ^ cipher->key[i % cipher->keylen];
  }
}

void shannon_decrypt(ShannonCipher *cipher)
{
  for (int i = 0; i < cipher->ctlen; i++) {
    cipher->plaintext[i] = cipher->ciphertext[i] ^ cipher->key[i % cipher->keylen];
  }
}

void shannon_free(ShannonCipher *cipher)
{
  free(cipher->plaintext);
  free(cipher->ciphertext);
  free(cipher->key);
  free(cipher);
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    fprintf(stderr, "Usage: %s key plaintext\n", argv[0]);
    return EXIT_FAILURE;
  }

  ShannonCipher *cipher = shannon_init((unsigned char *)argv[1], strlen(argv[1]));
  shannon_encrypt(cipher, (unsigned char *)argv[2], strlen(argv[2]));
  printf("Ciphertext: %s\n", cipher->ciphertext);
  shannon_decrypt(cipher);
  printf("Plaintext: %s\n", cipher->plaintext);
  shannon_free(cipher);

  return EXIT_SUCCESS;
}