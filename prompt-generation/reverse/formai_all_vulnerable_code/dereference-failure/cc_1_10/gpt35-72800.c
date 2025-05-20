//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Declare SHA-256 constants
uint32_t sha256_constants[] = {
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

// Declare SHA-256 functions
uint32_t sha256_ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t sha256_maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t sha256_rotr(uint32_t x, uint32_t n);
uint32_t sha256_shr(uint32_t x, uint32_t n);
uint32_t sha256_sigma0(uint32_t x);
uint32_t sha256_sigma1(uint32_t x);
uint32_t sha256_Sigma0(uint32_t x);
uint32_t sha256_Sigma1(uint32_t x);
uint32_t *sha256_pad(const uint8_t *message, size_t len, size_t *new_len);
uint32_t *sha256_hash(const uint8_t *message, size_t len);

int main() {
  // Define a message to hash
  char message[] = "This is a test message";
  size_t len = strlen(message);
  
  // Hash the message
  uint32_t *hash = sha256_hash((uint8_t *)message, len);

  // Print the hash
  printf("SHA-256 hash for message \"%s\":\n", message);
  for (int i = 0; i < 8; i++) {
    printf("%08x", hash[i]);
  }
  printf("\n");

  // Free memory used by hash
  free(hash);
  
  return 0;
}

// SHA-256 functions

uint32_t sha256_ch(uint32_t x, uint32_t y, uint32_t z) {
  return (x & y) ^ (~x & z);
}

uint32_t sha256_maj(uint32_t x, uint32_t y, uint32_t z) {
  return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t sha256_rotr(uint32_t x, uint32_t n) {
  return (x >> n) | (x << (32 - n));
}

uint32_t sha256_shr(uint32_t x, uint32_t n) {
  return x >> n;
}

uint32_t sha256_sigma0(uint32_t x) {
  return sha256_rotr(x, 2) ^ sha256_rotr(x, 13) ^ sha256_rotr(x, 22);
}

uint32_t sha256_sigma1(uint32_t x) {
  return sha256_rotr(x, 6) ^ sha256_rotr(x, 11) ^ sha256_rotr(x, 25);
}

uint32_t sha256_Sigma0(uint32_t x) {
  return sha256_rotr(x, 7) ^ sha256_rotr(x, 18) ^ sha256_shr(x, 3);
}

uint32_t sha256_Sigma1(uint32_t x) {
  return sha256_rotr(x, 17) ^ sha256_rotr(x, 19) ^ sha256_shr(x, 10);
}

uint32_t *sha256_pad(const uint8_t *message, size_t len, size_t *new_len) {
  // Calculate message length in bits
  size_t bits_len = len * 8;
  
  // Calculate padding length in bytes
  size_t padding_len = 64 - ((len + 8) % 64);
  if (padding_len == 64) {
    padding_len = 0;
  }
  
  // Calculate new length for padded message
  *new_len = len + padding_len + 8;
  
  // Allocate memory for padded message
  uint8_t *padded_message = (uint8_t *)calloc(*new_len, sizeof(uint8_t));
  
  // Copy original message
  memcpy(padded_message, message, len);
  
  // Add single '1' bit after message
  padded_message[len] = 0x80;
  
  // Add remaining padding
  for (int i = len + 1; i < *new_len - 8; i++) {
    padded_message[i] = 0x00;
  }
  
  // Add message length (in bits) at end of padded message
  for (int i = 0; i < 8; i++) {
    padded_message[*new_len - 8 + i] = (bits_len >> (56 - 8 * i)) & 0xff;
  }
  
  // Allocate memory for result
  uint32_t *result = (uint32_t *)calloc(*new_len / 4, sizeof(uint32_t));
  
  // Copy padded message into result
  for (int i = 0; i < *new_len; i += 4) {
    result[i / 4] =
      ((uint32_t)padded_message[i] << 24) |
      ((uint32_t)padded_message[i + 1] << 16) |
      ((uint32_t)padded_message[i + 2] << 8) |
      ((uint32_t)padded_message[i + 3]);
  }
  
  // Free memory used by padded message
  free(padded_message);
  
  return result;
}

uint32_t *sha256_hash(const uint8_t *message, size_t len) {
  // Constants
  uint32_t h0 = 0x6a09e667;
  uint32_t h1 = 0xbb67ae85;
  uint32_t h2 = 0x3c6ef372;
  uint32_t h3 = 0xa54ff53a;
  uint32_t h4 = 0x510e527f;
  uint32_t h5 = 0x9b05688c;
  uint32_t h6 = 0x1f83d9ab;
  uint32_t h7 = 0x5be0cd19;
  size_t new_len;
  
  // Pad message
  uint32_t *padded_message = sha256_pad(message, len, &new_len);
  
  // Initialize variables
  uint32_t a, b, c, d, e, f, g, h, t1, t2;
  
  // Process each block
  for (int i = 0; i < new_len / 16; i++) {
    // Initialize hash values for this block
    a = h0;
    b = h1;
    c = h2;
    d = h3;
    e = h4;
    f = h5;
    g = h6;
    h = h7;

    // Compute hash values
    for (int j = 0; j < 64; j++) {
      if (j < 16) {
        t1 = padded_message[i * 16 + j];
      } else {
        t1 = sha256_Sigma1(padded_message[i * 16 + (j + 14) % 16]) +
             padded_message[i * 16 + (j + 9) % 16] +
             sha256_Sigma0(padded_message[i * 16 + (j + 1) % 16]) +
             padded_message[i * 16 + j];
      }
      
      t2 = sha256_sigma1(e) + sha256_ch(e, f, g) + h + sha256_constants[j] + t1;
      
      h = g;
      g = f;
      f = e;
      e = d + t2;
      d = c;
      c = b;
      b = a;
      a = t2 + sha256_maj(a, b, c);
    }

    // Update hash values
    h0 += a;
    h1 += b;
    h2 += c;
    h3 += d;
    h4 += e;
    h5 += f;
    h6 += g;
    h7 += h;
  }
  
  // Free memory used by padded message
  free(padded_message);
  
  // Allocate memory for result
  uint32_t *result = (uint32_t *)calloc(8, sizeof(uint32_t));
  
  // Copy hash values into result
  result[0] = h0;
  result[1] = h1;
  result[2] = h2;
  result[3] = h3;
  result[4] = h4;
  result[5] = h5;
  result[6] = h6;
  result[7] = h7;
  
  return result;
}