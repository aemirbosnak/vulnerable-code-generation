//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 256
#define MAX_BLOCK_SIZE 64

// Cipher Initialization Vector (IV)
unsigned char iv[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

// Key Expansion Function
unsigned int *key_expansion(unsigned char *key, int key_size) {
  unsigned int *w = malloc(44 * sizeof(unsigned int));
  unsigned int *rc = malloc(11 * sizeof(unsigned int));

  rc[0] = 0x01000000;
  for (int i = 1; i < 11; i++) {
    rc[i] = (rc[i - 1] << 8) | (rc[i - 1] >> 24);
  }

  memcpy(w, key, key_size);

  for (int i = key_size / 4; i < 44; i++) {
    unsigned int temp = w[i - 1];
    if (i % 8 == 0) {
      temp = (temp << 8) | (temp >> 24);
      temp = (temp << 11) | (temp >> 21);
      temp ^= rc[i / 8];
    } else if (i % 8 == 4) {
      temp = (temp << 1) | (temp >> 31);
    }
    w[i] = w[i - 8] ^ temp;
  }

  free(rc);
  return w;
}

// AES-128 Round Function
unsigned int aes_round(unsigned int state[4], unsigned int *key) {
  unsigned int t0 = state[0] ^ key[0];
  unsigned int t1 = state[1] ^ key[1];
  unsigned int t2 = state[2] ^ key[2];
  unsigned int t3 = state[3] ^ key[3];

  t0 ^= (t1 ^ t2 ^ t3) & t2;
  t1 ^= (t0 ^ t2 ^ t3) & t3;
  t2 ^= (t0 ^ t1 ^ t3) & t0;
  t3 ^= (t0 ^ t1 ^ t2) & t1;

  t0 ^= (t1 ^ t2 ^ t3) & t2;
  t1 ^= (t0 ^ t2 ^ t3) & t3;
  t2 ^= (t0 ^ t1 ^ t3) & t0;
  t3 ^= (t0 ^ t1 ^ t2) & t1;

  t0 ^= (t1 ^ t2 ^ t3) & t2;
  t1 ^= (t0 ^ t2 ^ t3) & t3;
  t2 ^= (t0 ^ t1 ^ t3) & t0;
  t3 ^= (t0 ^ t1 ^ t2) & t1;

  state[0] = (t0 ^ key[4]) & 0xFFFFFFFF;
  state[1] = (t1 ^ key[5]) & 0xFFFFFFFF;
  state[2] = (t2 ^ key[6]) & 0xFFFFFFFF;
  state[3] = (t3 ^ key[7]) & 0xFFFFFFFF;
}

// AES-128 Encryption Function
void aes_encrypt(unsigned char *plaintext, unsigned char *ciphertext, int block_size, unsigned int *key) {
  unsigned int state[4];
  memcpy(state, plaintext, block_size);
  state[0] ^= key[0] ^ ((unsigned int)iv[0] << 24) ^ ((unsigned int)iv[1] << 16) ^ ((unsigned int)iv[2] << 8) ^ ((unsigned int)iv[3]);
  state[1] ^= key[1] ^ ((unsigned int)iv[4] << 24) ^ ((unsigned int)iv[5] << 16) ^ ((unsigned int)iv[6] << 8) ^ ((unsigned int)iv[7]);
  state[2] ^= key[2] ^ ((unsigned int)iv[8] << 24) ^ ((unsigned int)iv[9] << 16) ^ ((unsigned int)iv[10] << 8) ^ ((unsigned int)iv[11]);
  state[3] ^= key[3] ^ ((unsigned int)iv[12] << 24) ^ ((unsigned int)iv[13] << 16) ^ ((unsigned int)iv[14] << 8) ^ ((unsigned int)iv[15]);

  for (int round = 0; round < 9; round++) {
    aes_round(state, key + 8 * round);
  }

  aes_round(state, key + 72);

  memcpy(ciphertext, state, block_size);
}

// AES-128 Decryption Function
void aes_decrypt(unsigned char *ciphertext, unsigned char *plaintext, int block_size, unsigned int *key) {
  unsigned int state[4];
  memcpy(state, ciphertext, block_size);
  state[0] ^= key[72] ^ ((unsigned int)iv[0] << 24) ^ ((unsigned int)iv[1] << 16) ^ ((unsigned int)iv[2] << 8) ^ ((unsigned int)iv[3]);
  state[1] ^= key[73] ^ ((unsigned int)iv[4] << 24) ^ ((unsigned int)iv[5] << 16) ^ ((unsigned int)iv[6] << 8) ^ ((unsigned int)iv[7]);
  state[2] ^= key[74] ^ ((unsigned int)iv[8] << 24) ^ ((unsigned int)iv[9] << 16) ^ ((unsigned int)iv[10] << 8) ^ ((unsigned int)iv[11]);
  state[3] ^= key[75] ^ ((unsigned int)iv[12] << 24) ^ ((unsigned int)iv[13] << 16) ^ ((unsigned int)iv[14] << 8) ^ ((unsigned int)iv[15]);

  for (int round = 8; round > 0; round--) {
    aes_round(state, key + 8 * round);
  }

  aes_round(state, key);

  memcpy(plaintext, state, block_size);
}

int main() {
  unsigned char key[] = "0123456789ABCDEF0123456789ABCDEF";
  int key_size = strlen(key);
  unsigned int *expanded_key = key_expansion(key, key_size);

  unsigned char plaintext[] = "This is a secret message";
  int block_size = strlen(plaintext);
  unsigned char ciphertext[block_size];

  // Encrypt plaintext
  aes_encrypt(plaintext, ciphertext, block_size, expanded_key);

  printf("Encrypted plaintext: ");
  for (int i = 0; i < block_size; i++) {
    printf("%02X", ciphertext[i]);
  }
  printf("\n");

  // Decrypt ciphertext
  unsigned char decrypted_plaintext[block_size];
  aes_decrypt(ciphertext, decrypted_plaintext, block_size, expanded_key);

  printf("Decrypted ciphertext: %s\n", decrypted_plaintext);

  free(expanded_key);
  return 0;
}