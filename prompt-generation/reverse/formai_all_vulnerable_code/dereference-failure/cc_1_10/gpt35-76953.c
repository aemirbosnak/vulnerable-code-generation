//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))
#define F1(x, y, z) ((x) ^ (y) ^ (z))
#define F2(x, y, z) (((x) & (y)) | (~(x) & (z)))
#define F3(x, y, z) (((x) | ~(y)) ^ (z))
#define F4(x, y, z) (((x) & (z)) | ((y) & ~(z)))
#define F5(x, y, z) ((x) ^ ((y) | ~(z)))

uint32_t h[5] = {
 0x67452301,
 0xEFCDAB89,
 0x98BADCFE,
 0x10325476,
 0xC3D2E1F0
};

void sha1_hash(uint8_t *msg, uint32_t len) {
  uint32_t i, j;
  uint32_t w[80], a, b, c, d, e, f, k;

  for (i = 0; i < len / 64; i++) {
    for (j = 0; j < 16; j++) {
      w[j] = (msg[i * 64 + j * 4 + 0] << 24) |
             (msg[i * 64 + j * 4 + 1] << 16) |
             (msg[i * 64 + j * 4 + 2] << 8) |
             (msg[i * 64 + j * 4 + 3] << 0);
    }

    for (j = 16; j < 80; j++) {
      w[j] = ROTL(w[j - 3] ^ w[j - 8] ^ w[j - 14] ^ w[j - 16], 1);
    }

    a = h[0];
    b = h[1];
    c = h[2];
    d = h[3];
    e = h[4];

    for (j = 0; j < 80; j++) {
      if (j <= 19) {
        f = F1(b, c, d);
        k = 0x5A827999;
      } else if (j <= 39) {
        f = F2(b, c, d);
        k = 0x6ED9EBA1;
      } else if (j <= 59) {
        f = F3(b, c, d);
        k = 0x8F1BBCDC;
      } else {
        f = F4(b, c, d);
        k = 0xCA62C1D6;
      }

      uint32_t tmp = ROTL(a, 5) + f + e + k + w[j];
      e = d;
      d = c;
      c = ROTL(b, 30);
      b = a;
      a = tmp;
    }

    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
  }
}

void sha1(uint8_t *msg, uint32_t len, uint8_t *hash) {
  uint8_t *msg2 = NULL;
  uint32_t i, remainder;
  uint64_t bit_len;

  // Append padding bits and length
  bit_len = len * 8;
  remainder = len % 64;
  if (remainder < 56) {
    remainder = 56 - remainder;
  } else {
    remainder = 120 - remainder;
  }
  msg2 = (uint8_t *) malloc(len + remainder + 8);
  memcpy(msg2, msg, len);
  msg2[len] = 0x80;
  for (i = 1; i < remainder; i++) {
    msg2[len + i] = 0;
  }
  msg2[len + remainder + 0] = (bit_len >> 56) & 0xFF;
  msg2[len + remainder + 1] = (bit_len >> 48) & 0xFF;
  msg2[len + remainder + 2] = (bit_len >> 40) & 0xFF;
  msg2[len + remainder + 3] = (bit_len >> 32) & 0xFF;
  msg2[len + remainder + 4] = (bit_len >> 24) & 0xFF;
  msg2[len + remainder + 5] = (bit_len >> 16) & 0xFF;
  msg2[len + remainder + 6] = (bit_len >>  8) & 0xFF;
  msg2[len + remainder + 7] = (bit_len >>  0) & 0xFF;

  // Hash the padded message
  sha1_hash(msg2, len + remainder + 8);

  // Copy the hash to the output buffer
  for (i = 0; i < 20; i++) {
    hash[i] = (h[i / 4] >> (8 * (3 - i % 4))) & 0xFF;
  }

  // Free memory
  free(msg2);
}

int main() {
  char *msg = "Hello, world!";
  uint8_t hash[20];

  sha1((uint8_t *) msg, strlen(msg), hash);

  printf("Message: %s\n", msg);
  printf("Hash: ");
  for (int i = 0; i < 20; i++) {
    printf("%02x", hash[i]);
  }

  return 0;
}