//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/sha.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define KEY_LEN 32
#define SALT_LEN 16
#define IV_LEN 16
#define OUTPUT_LEN (KEY_LEN + SALT_LEN + IV_LEN)

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
    return 1;
  }

  FILE *input_file = fopen(argv[1], "rb");
  if (input_file == NULL) {
    perror("fopen");
    return 1;
  }

  FILE *output_file = fopen(argv[2], "wb");
  if (output_file == NULL) {
    perror("fopen");
    return 1;
  }

  uint8_t buffer[1024];
  size_t bytes_read;
  uint8_t output[OUTPUT_LEN];

  while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
    uint8_t salt[SALT_LEN];
    uint8_t iv[IV_LEN];

    RAND_bytes(salt, sizeof(salt));
    RAND_bytes(iv, sizeof(iv));

    AES_KEY key;
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, salt, sizeof(salt));
    SHA256_Update(&sha256, buffer, bytes_read);
    SHA256_Final(output, &sha256);

    AES_set_encrypt_key(output, KEY_LEN * 8, &key);
    AES_cbc_encrypt(buffer, output + KEY_LEN, bytes_read, &key, iv, AES_ENCRYPT);

    fwrite(output, 1, OUTPUT_LEN, output_file);
  }

  fclose(input_file);
  fclose(output_file);

  return 0;
}