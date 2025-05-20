//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROT_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))


void sha256_hash(const uint8_t *data, uint32_t len, uint8_t *hash) {
  uint32_t w[64];
  uint32_t h[8] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
  };
  uint32_t a, b, c, d, e, f, g, h0, t1, t2;
  uint32_t i, j;

  len += ((len % 64 < 56) ? (64 - len % 64) : (128 - len % 64)) - 8;
  uint8_t *data_padded = malloc(len + 8);
  memcpy(data_padded, data, len);
  data_padded[len] = 0x80;
  for (i = len + 1; i <= len + 8; i++) {
    data_padded[i] = 0;
  }
  uint32_t bit_len = len * 8;
  memcpy(data_padded + len + 8, &bit_len, 4);

  for (i = 0; i < len; i += 64) {
    for (j = 0; j < 16; j++) {
      w[j] = ntohl(*((uint32_t *) (data_padded + i + j * 4)));
    }
    for (j = 16; j < 64; j++) {
      w[j] = w[j - 16] + ROT_LEFT(w[j - 15], 7) + w[j - 7] + ROT_LEFT(w[j - 2], 15);
    }
    a = h[0];
    b = h[1];
    c = h[2];
    d = h[3];
    e = h[4];
    f = h[5];
    g = h[6];
    h0 = h[7];

    for (j = 0; j < 64; j++) {
      t1 = h0 + ROT_LEFT(e, 6) + ((e & f) ^ (~e & g)) + 0x428a2f98UL + w[j];
      t2 = ROT_LEFT(a, 2) + ((a & b) ^ (a & c) ^ (b & c));
      h0 = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
    h[5] += f;
    h[6] += g;
    h[7] += h0;
  }
  for (i = 0; i < 8; i++) {
    *((uint32_t *) hash + i) = htonl(h[i]);
  }
  free(data_padded);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <string-to-hash>\n", argv[0]);
    return 0;
  }
  uint8_t hash[32];
  sha256_hash((uint8_t *) argv[1], strlen(argv[1]), hash);
  for (int i = 0; i < 32; i++) {
    printf("%02x", hash[i]);
  }
  printf("\n");
  return 0;
}