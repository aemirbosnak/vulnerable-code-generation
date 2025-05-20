//Gemma-7B DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 64

void encrypt(unsigned char *msg, unsigned char *key) {
  unsigned char *enc_msg = malloc(BLOCK_SIZE);
  unsigned int i, j, block_num = 0;

  for (i = 0; msg[i] != '\0'; i++) {
    block_num++;
  }

  for (i = 0; i < block_num; i++) {
    for (j = 0; j < BLOCK_SIZE; j++) {
      enc_msg[j] = msg[j] ^ key[j];
    }
    msg += BLOCK_SIZE;
  }

  free(enc_msg);
}

void decrypt(unsigned char *msg, unsigned char *key) {
  unsigned char *dec_msg = malloc(BLOCK_SIZE);
  unsigned int i, j, block_num = 0;

  for (i = 0; msg[i] != '\0'; i++) {
    block_num++;
  }

  for (i = 0; i < block_num; i++) {
    for (j = 0; j < BLOCK_SIZE; j++) {
      dec_msg[j] = msg[j] ^ key[j];
    }
    msg += BLOCK_SIZE;
  }

  free(dec_msg);
}

int main() {
  unsigned char msg[] = "Hello, world!";
  unsigned char key[] = "Secret key";

  encrypt(msg, key);
  decrypt(msg, key);

  printf("%s\n", msg);

  return 0;
}