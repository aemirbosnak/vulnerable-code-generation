//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 64
#define HASH_SIZE 32

unsigned char* sha256_hash(const unsigned char* data, size_t data_size);

int main() {
    char input[5000];
    printf("Enter the string to hash: ");
    fgets(input, 5000, stdin);

    unsigned char* hash = sha256_hash((unsigned char*)input, strlen(input));
    printf("Hashed value of input: ");

    for(int i = 0; i < HASH_SIZE; i++) {
      printf("%02x", hash[i]);
    }

    printf("\n");
    free(hash);
    return 0;
}

unsigned char* sha256_hash(const unsigned char* data, size_t data_size) {
  unsigned char* hash = calloc(HASH_SIZE, sizeof(char));

  unsigned char block[BLOCK_SIZE];
  size_t block_size;

  //Initialize hash values
  unsigned int h0 = 0x6a09e667;
  unsigned int h1 = 0xbb67ae85;
  unsigned int h2 = 0x3c6ef372;
  unsigned int h3 = 0xa54ff53a;
  unsigned int h4 = 0x510e527f;
  unsigned int h5 = 0x9b05688c;
  unsigned int h6 = 0x1f83d9ab;
  unsigned int h7 = 0x5be0cd19;

  unsigned int w[64];
  unsigned int a, b, c, d, e, f, g, h, t1, t2;

  for(int i = 0; i < data_size; i += BLOCK_SIZE) {
    block_size = ((i + BLOCK_SIZE) > data_size) ? (data_size - i) : BLOCK_SIZE;
    memcpy(block, &data[i], block_size);

    //Pad the block
    if(block_size < BLOCK_SIZE) {
      block[block_size++] = 0x80;

      while(block_size < BLOCK_SIZE) {
        block[block_size++] = 0x00;
      }
    }

    //Extend the block into the message schedule array
    for(int j = 0; j < 16; j++) {
      w[j] = ((unsigned int)block[j * 4] << 24) | ((unsigned int)block[j * 4 + 1] << 16) | ((unsigned int)block[j * 4 + 2] << 8) | ((unsigned int)block[j * 4 + 3]);
    }

    for(int j = 16; j < 64; j++) {
      w[j] = w[j - 16] + ((w[j - 15] >> 7) | (w[j - 15] << 25)) + w[j - 7] + ((w[j - 2] >> 17) | (w[j - 2] << 15));
    }

    //Initialize working variables
    a = h0;
    b = h1;
    c = h2;
    d = h3;
    e = h4;
    f = h5;
    g = h6;
    h = h7;

    //Compression loop
    for(int j = 0; j < 64; j++) {
      t1 = h + ((e >> 6) | (e << 26)) + ((e & f) ^ (~e & g)) + 0x428a2f98 + w[j];
      t2 = ((a >> 2) | (a << 30)) + ((a & b) ^ (a & c) ^ (b & c));
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }

    //Add compressed chunk to current hash value
    h0 += a;
    h1 += b;
    h2 += c;
    h3 += d;
    h4 += e;
    h5 += f;
    h6 += g;
    h7 += h;
  }

  //Final hash value concatenation
  memcpy(hash, &h0, sizeof(unsigned int));
  memcpy(hash + 4, &h1, sizeof(unsigned int));
  memcpy(hash + 8, &h2, sizeof(unsigned int));
  memcpy(hash + 12, &h3, sizeof(unsigned int));
  memcpy(hash + 16, &h4, sizeof(unsigned int));
  memcpy(hash + 20, &h5, sizeof(unsigned int));
  memcpy(hash + 24, &h6, sizeof(unsigned int));
  memcpy(hash + 28, &h7, sizeof(unsigned int));

  return hash;
}