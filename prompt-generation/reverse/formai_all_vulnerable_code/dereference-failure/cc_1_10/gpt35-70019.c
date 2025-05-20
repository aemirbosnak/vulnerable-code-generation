//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PRIME_SIZE 512 // the size of the prime numbers used in the algorithm
#define BUFF_SIZE (PRIME_SIZE / 8) // the size of the buffer for storing keys

// data structure for storing public and private keys
typedef struct rsa_key_pair {
  unsigned char public_key[BUFF_SIZE];
  unsigned char private_key[BUFF_SIZE];
} rsa_key_pair_t;

// generate a random prime number between 2^(size-1) and 2^size-1
void generate_prime(unsigned char *p, int size) {
  int i;
  for (i = 0; i < size; i++) {
    p[i] = rand() % 256;
  }
  p[0] |= 0x80; // set the most significant bit to ensure number is > 2^(size-1)
  p[size-1] |= 0x01; // set the least significant bit to ensure number is odd
}

// calculate the modular inverse of a number using the Extended Euclidean algorithm
int modular_inverse(int a, int b) {
  int q, r, x1 = 1, y1 = 0, x2 = 0, y2 = 1, x, y, gcd = b;

  while (b) {
    q = a / b;
    r = a % b;
    x = x1 - q * x2;
    y = y1 - q * y2;

    a = b;
    b = r;
    x1 = x2;
    y1 = y2;
    x2 = x;
    y2 = y;
  }

  if (x1 < 0) {
    x1 += gcd;
  }

  return x1;
}

// generate a key pair for the RSA encryption algorithm
void rsa_keygen(rsa_key_pair_t *key_pair) {
  unsigned char p[BUFF_SIZE], q[BUFF_SIZE], n[BUFF_SIZE], e[BUFF_SIZE], d[BUFF_SIZE], phi[BUFF_SIZE];
  
  // generate two random prime numbers
  generate_prime(p, PRIME_SIZE);
  generate_prime(q, PRIME_SIZE);

  // calculate n = p*q
  memset(n, 0, sizeof(n));
  memcpy(n + (BUFF_SIZE - PRIME_SIZE/8), p, PRIME_SIZE/8);
  memcpy(n + (BUFF_SIZE - 2*PRIME_SIZE/8), q, PRIME_SIZE/8);

  // calculate phi(n) = (p-1)(q-1)
  memset(phi, 0, sizeof(phi));
  memcpy(phi + (BUFF_SIZE - PRIME_SIZE/8), p, PRIME_SIZE/8);
  phi[BUFF_SIZE - PRIME_SIZE/8 - 1] -= 1;
  memcpy(phi + (BUFF_SIZE - 2*PRIME_SIZE/8), q, PRIME_SIZE/8);
  phi[BUFF_SIZE - 2*PRIME_SIZE/8 - 1] -= 1;

  // choose an encoding exponent e
  e[0] = 0x01;
  e[1] = 0x00;
  e[2] = 0x01;

  // calculate the decoding exponent d = e^-1 mod phi(n)
  memcpy(d, e, sizeof(e));
  int inv = modular_inverse(d[0] << 16 | d[1] << 8 | d[2], phi[0] << 16 | phi[1] << 8 | phi[2]);
  d[0] = inv >> 16;
  d[1] = (inv >> 8) & 0xff;
  d[2] = inv & 0xff;

  // store the public and private keys in the key pair
  memcpy(key_pair->public_key, n, sizeof(n));
  memcpy(key_pair->private_key, d, sizeof(d));
}

// encrypt a message using the RSA encryption algorithm
void rsa_encrypt(unsigned char *msg, size_t len, unsigned char *out, rsa_key_pair_t key_pair) {
  unsigned char n[BUFF_SIZE], e[BUFF_SIZE];
  memcpy(n, key_pair.public_key, sizeof(n));
  memcpy(e, "\x00\x01\x00\x01", 4); // fixed encoding exponent

  int i, j, k, num_blocks = len / (PRIME_SIZE/8);
  unsigned char block[PRIME_SIZE/8], block_enc[PRIME_SIZE/8];

  for (i = 0; i < num_blocks; i++) {
    // copy a block of data into the buffer
    memset(block, 0, sizeof(block));
    memcpy(block + (PRIME_SIZE/8 - (len - i*(PRIME_SIZE/8))), msg + i*(PRIME_SIZE/8), PRIME_SIZE/8);

    // perform modular exponentiation to encrypt the block
    int x = block[0] << 16 | block[1] << 8 | block[2];
    int t = e[0] << 16 | e[1] << 8 | e[2];
    for (j = 0; j < 7; j++) {
      x = (int)((unsigned long long)(x * x) % (n[0] << 16 | n[1] << 8 | n[2]));
    }
    x = (int)((unsigned long long)x * t % (n[0] << 16 | n[1] << 8 | n[2]));
    for (j = 0; j < 5; j++) {
      x = (int)((unsigned long long)(x * x) % (n[0] << 16 | n[1] << 8 | n[2]));
    }
    x = (int)((unsigned long long)x * t % (n[0] << 16 | n[1] << 8 | n[2]));
    for (j = 0; j < 3; j++) {
      x = (int)((unsigned long long)(x * x) % (n[0] << 16 | n[1] << 8 | n[2]));
    }

    // copy the encrypted block into the output buffer
    for (k = 0; k < PRIME_SIZE/8; k++) {
      out[i*(PRIME_SIZE/8) + k] = x >> (8*(PRIME_SIZE/8-1-k));
    }
  }
}

// decrypt a message using the RSA encryption algorithm
void rsa_decrypt(unsigned char *msg, size_t len, unsigned char *out, rsa_key_pair_t key_pair) {
  unsigned char n[BUFF_SIZE], d[BUFF_SIZE];
  memcpy(n, key_pair.public_key, sizeof(n));
  memcpy(d, key_pair.private_key, sizeof(d));

  int i, j, k, num_blocks = len / (PRIME_SIZE/8);
  unsigned char block_enc[PRIME_SIZE/8], block_dec[PRIME_SIZE/8];

  for (i = 0; i < num_blocks; i++) {
    // copy a block of data into the buffer
    memset(block_enc, 0, sizeof(block_enc));
    memcpy(block_enc, msg + i*(PRIME_SIZE/8), PRIME_SIZE/8);

    // perform modular exponentiation to decrypt the block
    int x = block_enc[0] << 16 | block_enc[1] << 8 | block_enc[2];
    int t = d[0] << 16 | d[1] << 8 | d[2];
    for (j = 0; j < 7; j++) {
      x = (int)((unsigned long long)(x * x) % (n[0] << 16 | n[1] << 8 | n[2]));
    }
    x = (int)((unsigned long long)x * t % (n[0] << 16 | n[1] << 8 | n[2]));
    for (j = 0; j < 5; j++) {
      x = (int)((unsigned long long)(x * x) % (n[0] << 16 | n[1] << 8 | n[2]));
    }
    x = (int)((unsigned long long)x * t % (n[0] << 16 | n[1] << 8 | n[2]));
    for (j = 0; j < 3; j++) {
      x = (int)((unsigned long long)(x * x) % (n[0] << 16 | n[1] << 8 | n[2]));
    }

    // copy the decrypted block into the output buffer
    for (k = 0; k < PRIME_SIZE/8; k++) {
      out[i*(PRIME_SIZE/8) + k] = x >> (8*(PRIME_SIZE/8-1-k));
    }
  }
}

int main(int argc, char *argv[]) {
  // generate a key pair
  rsa_key_pair_t key_pair;
  rsa_keygen(&key_pair);

  // encrypt a message
  unsigned char plaintext[] = "Hello, world!";
  size_t plaintext_len = strlen((char *)plaintext);
  unsigned char ciphertext[1024];
  rsa_encrypt(plaintext, plaintext_len, ciphertext, key_pair);

  // decrypt the ciphertext
  unsigned char decrypted[1024];
  rsa_decrypt(ciphertext, plaintext_len, decrypted, key_pair);

  // print the results
  printf("Original message: %s\n", plaintext);
  printf("Encrypted message: ");
  int i;
  for (i = 0; i < plaintext_len; i++) {
    printf("%02x", ciphertext[i]);
  }
  printf("\n");
  printf("Decrypted message: %s\n", decrypted);

  return 0;
}