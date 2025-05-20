//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEYLEN 16

typedef struct {
  unsigned char key[KEYLEN];
  size_t keylen;
} cipher_key_t;

void encrypt_file(cipher_key_t *key, FILE *in, FILE *out) {
  int ch;
  while ((ch = fgetc(in)) != EOF) {
    fputc(ch ^ key->key[ch % key->keylen], out);
  }
}

void decrypt_file(cipher_key_t *key, FILE *in, FILE *out) {
  int ch;
  while ((ch = fgetc(in)) != EOF) {
    fputc(ch ^ key->key[ch % key->keylen], out);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <key> <action> <input> <output>\n", argv[0]);
    return EXIT_FAILURE;
  }

  cipher_key_t key;
  key.keylen = strlen(argv[1]);
  if (key.keylen > KEYLEN) {
    fprintf(stderr, "Key too long (max %d characters)\n", KEYLEN);
    return EXIT_FAILURE;
  }
  memcpy(key.key, argv[1], key.keylen);

  FILE *in = fopen(argv[3], "rb");
  if (in == NULL) {
    fprintf(stderr, "Failed to open input file '%s'\n", argv[3]);
    return EXIT_FAILURE;
  }

  FILE *out = fopen(argv[4], "wb");
  if (out == NULL) {
    fprintf(stderr, "Failed to open output file '%s'\n", argv[4]);
    fclose(in);
    return EXIT_FAILURE;
  }

  if (strcmp(argv[2], "encrypt") == 0) {
    encrypt_file(&key, in, out);
  } else if (strcmp(argv[2], "decrypt") == 0) {
    decrypt_file(&key, in, out);
  } else {
    fprintf(stderr, "Invalid action '%s'\n", argv[2]);
    fclose(in);
    fclose(out);
    return EXIT_FAILURE;
  }

  fclose(in);
  fclose(out);

  return EXIT_SUCCESS;
}