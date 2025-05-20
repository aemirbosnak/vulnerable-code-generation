//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// function to perform circular left shift operation
#define LEFT_ROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

// initial values of constants used in the SHA-256 algorithm
const uint32_t K[] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

// sha256 hash function
void sha256(const char *message, uint32_t hash[]) {
  // message schedule
  uint32_t w[64];

  // hash values
  uint32_t a, b, c, d, e, f, g, h;

  // working variables
  uint32_t t1, t2;

  // temporary variables for loop iterations
  uint32_t i, j;

  // message length in bits
  uint64_t message_len_bits = strlen(message) * 8;

  // message length in bytes
  size_t message_len_bytes = strlen(message);

  // length of the padding (in bytes) to reach a multiple of 512 bits
  size_t padding_len = (message_len_bytes < 56) ? (56 - message_len_bytes) : (64 - message_len_bytes + 56);

  // allocate memory for padded message
  char *padded_message = (char *)malloc(message_len_bytes + padding_len + 8);

  // copy message to padded message
  memcpy(padded_message, message, message_len_bytes);

  // append trailing '1' bit and fill the rest with '0' bits
  padded_message[message_len_bytes] = 0x80;

  // fill up the rest of the padding
  for (i = message_len_bytes + 1; i < message_len_bytes + padding_len; i++) {
    padded_message[i] = 0x00;
  }

  // append the message length in bits in big-endian format
  for (i = 0; i < 8; i++) {
    padded_message[message_len_bytes + padding_len + i] = (message_len_bits >> (56 - i * 8)) & 0xff;
  }

  // initialize hash values
  hash[0] = 0x6a09e667;
  hash[1] = 0xbb67ae85;
  hash[2] = 0x3c6ef372;
  hash[3] = 0xa54ff53a;
  hash[4] = 0x510e527f;
  hash[5] = 0x9b05688c;
  hash[6] = 0x1f83d9ab;
  hash[7] = 0x5be0cd19;

  // main loop
  for (i = 0; i < (message_len_bytes + padding_len + 8) / 64; i++) {
    // break chunk into message schedule
    for (j = 0; j < 16; j++) {
      w[j] = (padded_message[i * 64 + j * 4] << 24) |
             (padded_message[i * 64 + j * 4 + 1] << 16) |
             (padded_message[i * 64 + j * 4 + 2] << 8) |
             (padded_message[i * 64 + j * 4 + 3]);
    }

    for (j = 16; j < 64; j++) {
      uint32_t s0 = LEFT_ROTATE(w[j - 15], 7) ^ LEFT_ROTATE(w[j - 15], 18) ^ (w[j - 15] >> 3);
      uint32_t s1 = LEFT_ROTATE(w[j - 2], 17) ^ LEFT_ROTATE(w[j - 2], 19) ^ (w[j - 2] >> 10);
      w[j] = w[j - 16] + s0 + w[j - 7] + s1;
    }

    // initialize working variables
    a = hash[0];
    b = hash[1];
    c = hash[2];
    d = hash[3];
    e = hash[4];
    f = hash[5];
    g = hash[6];
    h = hash[7];

    // compression function main loop
    for (j = 0; j < 64; j++) {
      uint32_t S1 = LEFT_ROTATE(e, 6) ^ LEFT_ROTATE(e, 11) ^ LEFT_ROTATE(e, 25);
      uint32_t ch = (e & f) ^ (~e & g);
      uint32_t temp1 = h + S1 + ch + K[j] + w[j];
      uint32_t S0 = LEFT_ROTATE(a, 2) ^ LEFT_ROTATE(a, 13) ^ LEFT_ROTATE(a, 22);
      uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
      uint32_t temp2 = S0 + maj;

      h = g;
      g = f;
      f = e;
      e = d + temp1;
      d = c;
      c = b;
      b = a;
      a = temp1 + temp2;
    }

    // add compressed chunk to current hash value
    hash[0] += a;
    hash[1] += b;
    hash[2] += c;
    hash[3] += d;
    hash[4] += e;
    hash[5] += f;
    hash[6] += g;
    hash[7] += h;
  }

  // deallocate memory for padded message
  free(padded_message);
}

int main() {
  // message to hash
  const char *message = "Hello, world!";

  // hash value
  uint32_t hash[8];

  // compute hash
  sha256(message, hash);

  // print hash
  printf("Hash of '%s' is: 0x%08x%08x%08x%08x%08x%08x%08x%08x\n",
         message,
         hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);

  return 0;
}