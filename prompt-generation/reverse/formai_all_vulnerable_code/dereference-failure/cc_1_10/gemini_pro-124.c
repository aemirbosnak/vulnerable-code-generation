//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

char *swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
  return a;
}

char *rc4(char *key, int keylen, char *text, int textlen, int mode) {
  int i, j, k, t;
  char *sbox, *keystream;

  sbox = malloc(256);
  keystream = malloc(textlen);

  for (i = 0; i < 256; i++) { sbox[i] = i; }

  j = k = 0;
  for (i = 0; i < 256; i++) {
    j += sbox[i] + key[k];
    swap(&sbox[i], &sbox[j]);
    k = (k + 1) % keylen;
  }

  for (i = 0, j = 0, k = 0; i < textlen; i++) {
    j += 1;
    k += sbox[j];
    swap(&sbox[j], &sbox[k]);
    t = sbox[(sbox[j] + sbox[k]) % 256];
    if (mode == ENCRYPT) {
      keystream[i] = text[i] ^ t;
    } else if (mode == DECRYPT) {
      keystream[i] = text[i] ^ t;
    }
  }

  return keystream;
}

int main(int argc, char *argv[]) {
  char *key, *text;
  int keylen, textlen, mode;

  if (argc < 5) {
    fprintf(stderr, "Usage: %s [key] [text] [keylen] [textlen] [mode]\n", argv[0]);
    return 1;
  }

  key = argv[1];
  text = argv[2];
  keylen = atoi(argv[3]);
  textlen = atoi(argv[4]);
  mode = atoi(argv[5]);

  char *encrypted;
  char *decrypted;

  if (mode == ENCRYPT) {
    encrypted = rc4(key, keylen, text, textlen, mode);
    printf("Encrypted: %s\n", encrypted);
  } else if (mode == DECRYPT) {
    decrypted = rc4(key, keylen, text, textlen, mode);
    printf("Decrypted: %s\n", decrypted);
  }

  return 0;
}