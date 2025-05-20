//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define round_count 10

unsigned char* cryptohash(unsigned char *str, size_t len) {
  unsigned int i, j, round;
  unsigned char *hash = malloc(16);
  unsigned char *buffer = malloc(len+64);
  unsigned int *m = (unsigned int*)buffer;
  unsigned int a[4] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476};
  unsigned int b[4];

  memcpy(buffer, str, len);

  buffer[len] = 0x80;
  memset(buffer+len+1, 0, 64-len-1);

  m[len/4] = len*8;

  for (i = 0; i < len/64+1; i++) {
    memcpy(b, a, sizeof(a));

    for (j = 0; j < 64; j++) {
      if (j < 16)
        m[j] = buffer[i*64+j];
      else
        m[j] = m[j-16] + (((m[j-15]>>7)|(m[j-15]<<(32-7))) ^ ((m[j-15]>>18)|(m[j-15]<<(32-18))) ^ (m[j-15]>>3)) + m[j-7] + (((m[j-2]>>17)|(m[j-2]<<(32-17))) ^ ((m[j-2]>>19)|(m[j-2]<<(32-19))) ^ (m[j-2]>>10));
      round = (j/16)%round_count;
      a[(4-round)%4] = a[(4-round)%4] + (((a[(5-round)%4]>>6)|(a[(5-round)%4]<<(32-6))) ^ ((a[(5-round)%4]>>11)|(a[(5-round)%4]<<(32-11))) ^ ((a[(5-round)%4]>>25)|(a[(5-round)%4]<<(32-25)))) + ((a[(5-round)%4]&a[(6-round)%4])^((~a[(5-round)%4])&a[(7-round)%4])) + m[j] + (j < 48 ? 0x5A827999 : (j < 64 ? 0x6ED9EBA1 : 0x8F1BBCDC));
    }

    for (j = 0; j < 4; j++)
      a[j] += b[j];
  }

  memcpy(hash, a, 16);
  free(buffer);
  return hash;
}

int main(int argc, char **argv) {
  unsigned char *result;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s string\n", argv[0]);
    return 1;
  }

  result = cryptohash(argv[1], strlen(argv[1]));
  printf("Hash value is: %02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X\n",
    result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7],
    result[8], result[9], result[10], result[11], result[12], result[13], result[14], result[15]
  );

  free(result);
  return 0;
}