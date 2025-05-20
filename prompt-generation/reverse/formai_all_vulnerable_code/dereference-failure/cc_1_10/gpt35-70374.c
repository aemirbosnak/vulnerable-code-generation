//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* 
  This is a custom hash function that uses the SHA-256 algorithm 
  to generate a cryptographic hash of a given input string. 
  The hash is 256 bits (32 bytes) long and is represented as a 
  hexadecimal string of length 64 characters.
*/

// SHA-256 constants
#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define Ch(x, y, z) (((x) & (y)) ^ ((~(x)) & (z)))
#define Maj(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define Sigma0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define Sigma1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define sigma0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ ((x) >> 3))
#define sigma1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ ((x) >> 10))

// Initial hash values (first 32 bits of the fractional parts of the square roots of the first 8 primes)
const uint32_t H[] = {
  0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 
  0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// Constants for SHA-256 (first 32 bits of the fractional parts of the cube roots of the first 64 primes)
const uint32_t K[] = {
  0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
  0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
  0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
  0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
  0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
  0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
  0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
  0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
  0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
  0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
  0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
  0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
  0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
  0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
  0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
  0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// SHA-256 processing function
void sha256_process(const uint8_t *data, uint32_t len, uint32_t *hash) {
  uint32_t H[8], W[64], a, b, c, d, e, f, g, h, i, j, t1, t2;

  // Initialize hash values
  memcpy(H, hash, 32);

  // Pre-processing
  uint8_t *padded_data = calloc((len + 72) / 64, 64);
  memcpy(padded_data, data, len);
  padded_data[len] = 0x80;
  uint32_t bitlen = len * 8;
  memcpy(padded_data + (len >= 56 ? 120 : 56), &bitlen, 4);

  // Process message in 512-bit chunks
  for (i = 0; i < len / 64 + 1; i++) {
    // Prepare message schedule
    if (i < 16) {
      for (j = 0; j < 16; j++) {
        W[j] = (padded_data[i * 64 + j * 4] << 24) | (padded_data[i * 64 + j * 4 + 1] << 16) | (padded_data[i * 64 + j * 4 + 2] << 8) | (padded_data[i * 64 + j * 4 + 3]);
      }
    } else {
      for (j = 0; j < 16; j++) {
        W[j] = sigma1(W[j - 2]) + W[j - 7] + sigma0(W[j - 15]) + W[j - 16];
      }
    }

    // Initialize working variables
    a = H[0]; b = H[1]; c = H[2]; d = H[3]; e = H[4]; f = H[5]; g = H[6]; h = H[7];

    // Compression function
    for (j = 0; j < 64; j++) {
      t1 = h + Sigma1(e) + Ch(e, f, g) + K[j] + W[j];
      t2 = Sigma0(a) + Maj(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }

    // Update hash values
    H[0] += a; H[1] += b; H[2] += c; H[3] += d; 
    H[4] += e; H[5] += f; H[6] += g; H[7] += h;
  }

  // Post-processing
  for (i = 0; i < 8; i++) {
    hash[i] = H[i];
  }

  free(padded_data);
}

// SHA-256 hash function
void sha256(const uint8_t *data, uint32_t len, char *hash_string) {
  uint32_t hash_bytes[8];
  sha256_process(data, len, hash_bytes);

  for (int i = 0; i < 8; i++) {
    sprintf(hash_string + i * 8, "%08x", hash_bytes[i]);
  }

  hash_string[64] = '\0';
}


/*** Example usage ***/

int main() {
  char input_string[] = "The quick brown fox jumps over the lazy dog";
  char hash_string[65];

  sha256(input_string, strlen(input_string), hash_string);

  printf("Input string: %s\n", input_string);
  printf("Hash: %s\n", hash_string);

  return 0;
}