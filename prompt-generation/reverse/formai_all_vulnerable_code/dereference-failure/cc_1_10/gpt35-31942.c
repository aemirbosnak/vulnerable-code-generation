//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#define ROTATE_LEFT(x, n) ((x << n)| (x >> (32 - n)))
#define Ch(x, y, z) ((x&y) ^ (~x&z))
#define Maj(x, y, z) ((x&y) ^ (x&z) ^ (y&z))
#define SIGMA_0(x) (ROTATE_LEFT(x, 2) ^ ROTATE_LEFT(x, 13) ^ ROTATE_LEFT(x, 22))
#define SIGMA_1(x) (ROTATE_LEFT(x, 6) ^ ROTATE_LEFT(x, 11) ^ ROTATE_LEFT(x, 25))
#define sigma_0(x) (ROTATE_LEFT(x, 7) ^ ROTATE_LEFT(x, 18) ^ (x >> 3))
#define sigma_1(x) (ROTATE_LEFT(x, 17) ^ ROTATE_LEFT(x, 19) ^ (x >> 10))

//Initial hash values
uint32_t H[8] = {
   0x6a09e667,
   0xbb67ae85,
   0x3c6ef372,
   0xa54ff53a,
   0x510e527f,
   0x9b05688c,
   0x1f83d9ab,
   0x5be0cd19
};

//Circular shift function
uint32_t *sha256(char *msg, size_t len) {
   //Calculate total number of blocks
   uint32_t total_blocks = ((len + 64) / 512) + 1;
   //Initialize buffer size
   uint32_t *msg_buffer = (uint32_t *) calloc(total_blocks * 16, sizeof(uint8_t));
   //Copy message to buffer
   memcpy(msg_buffer, msg, len);
   //Padding
   uint32_t *msg_padding = msg_buffer + (len/4);
   *msg_padding++ = 0x80;
   uint32_t msg_length = len * 8;
   *msg_padding = msg_length;
   //Process each block
   for(int i = 0; i < total_blocks; i++) {
      uint32_t *chunk = msg_buffer + (i * 16);
      uint32_t a = H[0], b = H[1], c = H[2], d = H[3], e = H[4], f = H[5],g = H[6], h = H[7], T1, T2;
      for(int j = 0; j < 64; j++) {
         if (j < 16) {
            T1 = Ch(e, f, g) + ((e & f) ^ (~e & h)) + sigma_1(e) + *chunk + 0x428a2f98;
            T2 = SIGMA_0(a) + Maj(a, b, c);
            d += T1;
            h = T1 + T2;
            chunk++;
         } else {
            T1 = sigma_0(e) + Ch(e, f, g) + ((e & f) ^ (~e & h)) + *chunk + 0x71374491;
            T2 = SIGMA_1(a) + Maj(a, b, c);
            d += T1;
            h = T1 + T2;
            chunk++;
         }
         h += g;
         g = f;
         f = e;
         e = d;
         d = c;
         c = b;
         b = a;
         a = h;
      }
      H[0] += a;
      H[1] += b;
      H[2] += c;
      H[3] += d;
      H[4] += e;
      H[5] += f;
      H[6] += g;
      H[7] += h;
   }
   return H;
}
//Driver function
int main() {
   char *stmt = "Hello World";
   uint32_t *result = sha256(stmt, strlen(stmt));
   //Print hash value
   for(int i = 0; i < 8; i++) {
      printf("%02x", result[i]);
   }
   printf("\n");
   return 0;
}