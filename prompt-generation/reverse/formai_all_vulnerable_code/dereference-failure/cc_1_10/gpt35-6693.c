//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROTR(x, n) ((x >> n) | (x << (32 - n))) // Circular Right Shift
#define ch(x, y, z) ((x & y) ^ (~x & z)) // Choose
#define maj(x, y, z) ((x & y) ^ (x & z) ^ (y & z)) // Majority
#define SIGMA0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22)) // Sigma-0
#define SIGMA1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25)) // Sigma-1
#define sigma0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ (x >> 3)) // sigma-0
#define sigma1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ (x >> 10)) // sigma-1

typedef unsigned char BYTE; // 8-bit byte
typedef unsigned int  WORD; // 32-bit word

// Hash values (Constants)
WORD H[8] = {
  0x6a09e667,
  0xbb67ae85,
  0x3c6ef372,
  0xa54ff53a,
  0x510e527f,
  0x9b05688c,
  0x1f83d9ab,
  0x5be0cd19
};

// Round constants
WORD K[] = {
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

// Function to pad input message
void pad_message(BYTE message[], int len, WORD hashed_message[]) {
  int i;
  WORD extra_bits;
  WORD message_bits = len * 8; // Length of message in bits
  WORD total_bits; // Total length of padded message in bits
  int blocks; // Number of 512-bit blocks required for the padded message

  // Calculate number of extra bits required to fill the last 512-bit block
  extra_bits = (message_bits % 512) < 448 ? (448 - (message_bits % 512)) : (960 - (message_bits % 512));

  // Calculate total length of the padded message in bits
  total_bits = message_bits + extra_bits + 64;

  // Calculate number of 512-bit blocks required for the padded message
  blocks = total_bits / 512;

  // Allocate memory for the padded message
  WORD *padded_message = (WORD*) malloc(blocks * 16);

  // Copy input message to padded message
  memcpy(padded_message, message, len);

  // Add 1 bit followed by required number of 0 bits to fill the last 512-bit block
  padded_message[len / 4] |= (0x80 << ((len % 4) * 8));
  for (i = len / 4 + 1; i < 16 * blocks - 2; i++) {
    padded_message[i] = 0;
  }

  // Add the length of the original message in bits to the last 2 words of the padded message
  padded_message[16 * blocks - 2] = message_bits >> 32;
  padded_message[16 * blocks - 1] = message_bits & 0xffffffff;

  // Hash the padded message using SHA-256 algorithm
  for (i = 0; i < blocks; i++) {
    int j;
    WORD w[64];
    WORD a, b, c, d, e, f, g, h;

    // Prepare message schedule
    for (j = 0; j < 16; j++) {
      w[j] = (padded_message[i * 16 + j] & 0xff000000) | 
             (padded_message[i * 16 + j] & 0xff0000) << 8 |
             (padded_message[i * 16 + j] & 0xff00) << 24 |
             (padded_message[i * 16 + j] & 0xff) << 16;
    }
    for (j = 16; j < 64; j++) {
      w[j] = sigma1(w[j - 2]) + w[j - 7] + sigma0(w[j - 15]) + w[j - 16];
    }

    // Initialize hash values for this block
    a = H[0];
    b = H[1];
    c = H[2];
    d = H[3];
    e = H[4];
    f = H[5];
    g = H[6];
    h = H[7];

    // Perform 64 rounds of hashing
    for (j = 0; j < 64; j++) {
      WORD temp1 = h + SIGMA1(e) + ch(e, f, g) + K[j] + w[j];
      WORD temp2 = SIGMA0(a) + maj(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + temp1;
      d = c;
      c = b;
      b = a;
      a = temp1 + temp2;
    }

    // Update hash values for this block
    H[0] += a;
    H[1] += b;
    H[2] += c;
    H[3] += d;
    H[4] += e;
    H[5] += f;
    H[6] += g;
    H[7] += h;
  }

  // Copy the hashed message to output
  memcpy(hashed_message, H, 8 * sizeof(WORD));
}

int main() {
  BYTE message[] = "Hello, World!";
  int len = strlen(message);

  // Allocate memory for the hashed message
  WORD *hashed_message = (WORD*) malloc(8 * sizeof(WORD));

  // Pad and hash input message
  pad_message(message, len, hashed_message);

  // Print the hashed message in hex form
  printf("Hashed Message: %08x%08x%08x%08x%08x%08x%08x%08x\n",
         hashed_message[0], hashed_message[1], hashed_message[2], hashed_message[3],
         hashed_message[4], hashed_message[5], hashed_message[6], hashed_message[7]);

  // Free the memory allocated for hashed message
  free(hashed_message);

  return 0;
}