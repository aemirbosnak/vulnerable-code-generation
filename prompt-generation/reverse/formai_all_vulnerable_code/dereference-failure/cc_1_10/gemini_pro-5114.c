//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define the SHA256 hash function
uint32_t sha256(const char *message, size_t length) {
  // Initialize the hash state
  uint32_t h0 = 0x6a09e667;
  uint32_t h1 = 0xbb67ae85;
  uint32_t h2 = 0x3c6ef372;
  uint32_t h3 = 0xa54ff53a;
  uint32_t h4 = 0x510e527f;
  uint32_t h5 = 0x9b05688c;
  uint32_t h6 = 0x1f83d9ab;
  uint32_t h7 = 0x5be0cd19;

  // Process the message in 512-bit blocks
  for (size_t i = 0; i < length; i += 64) {
    // Create a 64-bit block
    uint64_t block;
    memcpy(&block, message + i, 64);

    // Process the block
    uint32_t w[64];
    for (size_t j = 0; j < 16; j++) {
      w[j] = block >> (32 * (15 - j));
    }
    for (size_t j = 16; j < 64; j++) {
      w[j] = (w[j - 16] + w[j - 7] + (w[j - 15] << 25) + (w[j - 2] << 30)) & 0xffffffff;
    }

    uint32_t a = h0;
    uint32_t b = h1;
    uint32_t c = h2;
    uint32_t d = h3;
    uint32_t e = h4;
    uint32_t f = h5;
    uint32_t g = h6;
    uint32_t h = h7;

    for (size_t j = 0; j < 64; j++) {
      uint32_t s0 = (a >> 2 | a << 30) ^ (a >> 13 | a << 19) ^ (a >> 22 | a << 10);
      uint32_t s1 = (e >> 6 | e << 26) ^ (e >> 11 | e << 21) ^ (e >> 25 | e << 7);
      uint32_t ch = (e & f) ^ (~e & g);
      uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
      uint32_t temp1 = h + s1 + ch + w[j] + 0x428a2f98;
      uint32_t temp2 = s0 + maj;
      h = g;
      g = f;
      f = e;
      e = d + temp1;
      d = c;
      c = b;
      b = a;
      a = temp1 + temp2;
    }

    h0 += a;
    h1 += b;
    h2 += c;
    h3 += d;
    h4 += e;
    h5 += f;
    h6 += g;
    h7 += h;
  }

  // Return the hash value
  uint32_t hash = h0 + (h1 << 1) + (h2 << 2) + (h3 << 3) + (h4 << 4) + (h5 << 5) + (h6 << 6) + (h7 << 7);
  return hash;
}

// Main function
int main(int argc, char **argv) {
  // Check if a message was provided
  if (argc < 2) {
    printf("Usage: %s <message>\n", argv[0]);
    return 1;
  }

  // Get the message
  const char *message = argv[1];

  // Calculate the SHA256 hash of the message
  uint32_t hash = sha256(message, strlen(message));

  // Print the hash value
  printf("SHA256 hash: %08x\n", hash);

  return 0;
}