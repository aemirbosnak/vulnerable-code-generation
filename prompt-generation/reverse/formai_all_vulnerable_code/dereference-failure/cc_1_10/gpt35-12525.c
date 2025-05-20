//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

const char *hex = "0123456789abcdef";
const int BLOCK_SIZE = 64; // 512 bits
const int OUTPUT_SIZE = 32; // 256 bits

// Rotate left function to shift bits to the left
uint32_t left_rotate(uint32_t x, uint32_t n) {
  return (x << n) | (x >> (32 - n));
}

// The main hashing function of SHA-256
void sha256_hash(const char *message, uint8_t hash[OUTPUT_SIZE]) {

  // Initial hash values
  uint32_t h[] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
  };

  // Message schedule
  uint32_t w[64];

  int len = strlen(message);

  // Pre-processing: padding message
  int new_len = ((((len + 8) / BLOCK_SIZE) + 1) * BLOCK_SIZE) - 8;
  uint8_t *msg = calloc(new_len + 64, 1);
  memcpy(msg, message, len);
  msg[len] = 0x80;
  *((uint64_t *)(msg + new_len)) = len * 8;

  // Process each 512-bit block
  for (int i = 0; i < new_len; i += BLOCK_SIZE) {

    // Initialize message schedule
    for (int j = 0; j < 16; j++) {
      w[j] = *((uint32_t *)(msg + i + j * 4));
    }
    for (int j = 16; j < 64; j++) {
      uint32_t s0 = left_rotate(w[j - 15], 7) ^ left_rotate(w[j - 15], 18) ^ (w[j - 15] >> 3);
      uint32_t s1 = left_rotate(w[j - 2], 17) ^ left_rotate(w[j - 2], 19) ^ (w[j - 2] >> 10);
      w[j] = w[j - 16] + s0 + w[j - 7] + s1;
    }

    // Initialize variables
    uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], h2 = h[7];

    // Main compression loop
    for (int j = 0; j < 64; j++) {
      uint32_t s0 = left_rotate(a, 2) ^ left_rotate(a, 13) ^ left_rotate(a, 22);
      uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
      uint32_t t2 = s0 + maj;
      uint32_t s1 = left_rotate(e, 6) ^ left_rotate(e, 11) ^ left_rotate(e, 25);
      uint32_t ch = (e & f) ^ (~e & g);
      uint32_t t1 = h2 + s1 + ch + w[j] + ((uint32_t[]){0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2})[j];

      h2 = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }

    // Add compressed block to hash value
    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
    h[5] += f;
    h[6] += g;
    h[7] += h2;
  }

  // Convert hash values to bytes
  for (int i = 0; i < OUTPUT_SIZE; i++) {
    hash[i] = (uint8_t)(h[i / 4] >> (24 - 8 * (i % 4)));
  }

  free(msg);
}

// Convert byte array to hex string
char *bytes_to_str(const uint8_t *bytes, size_t len) {
  char *str = calloc(2 * len + 1, 1);
  size_t j = 0;
  for (size_t i = 0; i < len; i++) {
    str[j++] = hex[bytes[i] >> 4];
    str[j++] = hex[bytes[i] & 0xf];
  }
  str[j] = '\0';
  return str;
}

int main() {

  char message[] = "Hello, world!";
  uint8_t hash[OUTPUT_SIZE];

  sha256_hash(message, hash);

  char *hash_str = bytes_to_str(hash, OUTPUT_SIZE);

  printf("%s\n", hash_str);

  free(hash_str);

  return 0;
}