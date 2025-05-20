//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ROT_RIGHT(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

uint32_t h0 = 0x67452301;
uint32_t h1 = 0xEFCDAB89;
uint32_t h2 = 0x98BADCFE;
uint32_t h3 = 0x10325476;
uint32_t h4 = 0xC3D2E1F0;

void update_hash(uint32_t *h, uint32_t *w) {
  for (int i = 16; i < 80; i++) {
    w[i] = ROT_RIGHT((w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16]), 1);
  }
  
  uint32_t a = h[0];
  uint32_t b = h[1];
  uint32_t c = h[2];
  uint32_t d = h[3];
  uint32_t e = h[4];
  
  for (int i = 0; i < 80; i++) {
    uint32_t f, k;
    
    if (i < 20) {
      f = (b & c) | ((~b) & d);
      k = 0x5A827999;
    } else if (i < 40) {
      f = b ^ c ^ d;
      k = 0x6ED9EBA1;
    } else if (i < 60) {
      f = (b & c) | (b & d) | (c & d);
      k = 0x8F1BBCDC;
    } else {
      f = b ^ c ^ d;
      k = 0xCA62C1D6;
    }
    
    uint32_t temp = ROT_RIGHT(a, 5) + f + e + k + w[i];
    e = d;
    d = c;
    c = ROT_RIGHT(b, 30);
    b = a;
    a = temp;
  }
  
  h[0] += a;
  h[1] += b;
  h[2] += c;
  h[3] += d;
  h[4] += e;
}

void sha1sum(const char *message, uint32_t *digest) {
  size_t message_length = strlen(message);
  uint8_t *message_padded = malloc((message_length + 9 + 64) & (~63));
  memset(message_padded, 0, (message_length + 9 + 64) & (~63));
  memcpy(message_padded, message, message_length);
  message_padded[message_length] = 0x80;
  uint32_t *message_length_p = (uint32_t *)(message_padded + ((message_length + 9 + 64) & (~63)) - 8);
  *message_length_p = (uint32_t)(((uint64_t)message_length) << 3);
  
  uint32_t *w = (uint32_t *)message_padded;
  
  for (size_t i = 0; i < ((message_length + 9 + 64) & (~63)) / 4; i += 16) {
    update_hash(digest, &w[i]);
  }
  
  free(message_padded);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <message>\n", argv[0]);
    return 1;
  }
  
  char *message = argv[1];
  
  uint32_t digest[5];
  sha1sum(message, digest);
  printf("%08x%08x%08x%08x%08x  %s\n", digest[0], digest[1], digest[2], digest[3], digest[4], message);
  
  return 0;
}