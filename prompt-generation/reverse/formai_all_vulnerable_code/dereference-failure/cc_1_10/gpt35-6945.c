//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: unmistakable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

// This function rotates input x, k number of times
uint32_t R(uint32_t x, uint32_t k) {
  return (x << k) | (x >> (32 - k));
}

// This function implements the SHA-256 hash algorithm
void sha256(uint8_t* data, uint32_t len, uint32_t* hash) {

  uint32_t k[] = {
    0x428a2f98,
    0x71374491,
    0xb5c0fbcf,
    0xe9b5dba5,
    0x3956c25b,
    0x59f111f1,
    0x923f82a4,
    0xab1c5ed5,
    0xd807aa98,
    0x12835b01,
    0x243185be,
    0x550c7dc3,
    0x72be5d74,
    0x80deb1fe,
    0x9bdc06a7,
    0xc19bf174,
    0xe49b69c1,
    0xefbe4786,
    0x0fc19dc6,
    0x240ca1cc,
    0x2de92c6f,
    0x4a7484aa,
    0x5cb0a9dc,
    0x76f988da,
    0x983e5152,
    0xa831c66d,
    0xb00327c8,
    0xbf597fc7,
    0xc6e00bf3,
    0xd5a79147,
    0x06ca6351,
    0x14292967,
    0x27b70a85,
    0x2e1b2138,
    0x4d2c6dfc,
    0x53380d13,
    0x650a7354,
    0x766a0abb,
    0x81c2c92e,
    0x92722c85,
    0xa2bfe8a1,
    0xa81a664b,
    0xc24b8b70,
    0xc76c51a3,
    0xd192e819,
    0xd6990624,
    0xf40e3585,
    0x106aa070,
    0x19a4c116,
    0x1e376c08,
    0x2748774c,
    0x34b0bcb5,
    0x391c0cb3,
    0x4ed8aa4a,
    0x5b9cca4f,
    0x682e6ff3,
    0x748f82ee,
    0x78a5636f,
    0x84c87814,
    0x8cc70208,
    0x90befffa,
    0xa4506ceb,
    0xbef9a3f7,
    0xc67178f2
  };

  uint32_t H[] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
  };

  // Pre-processing
  uint32_t new_len = ((((len + 8) / 64) + 1) * 64) - 8;
  uint8_t* msg = (uint8_t*) malloc(new_len + 64);
  memcpy(msg, data, len);
  msg[len] = 0x80;
  for (uint32_t i = len + 1; i < new_len; i++)
    msg[i] = 0;
  uint32_t bits_len = len * 8;
  memcpy(msg + new_len, &bits_len, 4);

  // Process the message in successive 512-bit chunks
  for (uint32_t i = 0; i < new_len; i += 64) {

    uint32_t* w = (uint32_t*) &msg[i];

    // Initialize the working variables
    uint32_t a = H[0], b = H[1], c = H[2], d = H[3], e = H[4], f = H[5], g = H[6], h = H[7];

    // Calculate the hash values for the entire block
    for (uint32_t j = 0; j < 64; j++) {
      uint32_t t1 = h + (R(e, 6) ^ R(e, 11) ^ R(e, 25)) + ((e & f) ^ ((~e) & g)) + k[j] + w[j];
      uint32_t t2 = (R(a, 2) ^ R(a, 13) ^ R(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }

    // Update the hash values
    H[0] += a;
    H[1] += b;
    H[2] += c;
    H[3] += d;
    H[4] += e;
    H[5] += f;
    H[6] += g;
    H[7] += h;

  }

  // Convert the hash to a string of hexadecimal digits
  for (int i = 0; i < 8; i++) {
    uint32_t h = H[i];
    hash[i] = (h >> 24) | ((h >> 8) & 0xff00) | ((h << 8) & 0xff0000) | (h << 24);
  }

  free(msg);

}

int main() {

  uint8_t message[] = "Hello, world!";
  uint32_t hash[8];

  sha256(message, strlen((char*)message), hash);

  printf("Hash of \"%s\" is:\n", message);
  for (int i = 0; i < 8; i++) {
    printf("%08x ", hash[i]);
  }
  printf("\n");

  return 0;
}