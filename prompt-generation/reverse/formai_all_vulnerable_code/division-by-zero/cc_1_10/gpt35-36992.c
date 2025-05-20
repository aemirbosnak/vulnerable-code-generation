//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// Function to generate a random number using the given seed
int generate_random_number(int seed) {
  srand(seed);
  return rand() % 100;
}

// Function to generate the public key
int generate_public_key(int p, int q) {
  int n = p * q;
  int phi_n = (p - 1) * (q - 1);
  int e = 2;
  while (e < phi_n) {
    if (gcd(e, phi_n) == 1) {
      break;
    } else {
      e++;
    }
  }
  return e;
}

// Function to generate the private key
int generate_private_key(int p, int q, int e) {
  int n = p * q;
  int phi_n = (p - 1) * (q - 1);
  int k = 1;
  while (1) {
    k = k + phi_n;
    if (k % e == 0) {
      int d = k / e;
      return d;
    }
  }
}

// Function to encrypt a message using the public key
void encrypt(char *plaintext, int n, int e, char *ciphertext) {
  int i = 0;
  while (plaintext[i] != '\0') {
    int m = plaintext[i];
    int c = 1;
    for (int j = 0; j < e; j++) {
      c = (c * m) % n;
    }
    sprintf(ciphertext + strlen(ciphertext), "%d", c);
    i++;
  }
}

// Function to decrypt a message using the private key
void decrypt(char *ciphertext, int n, int d, char *decryptedtext) {
  int i = 0;
  while (ciphertext[i] != '\0') {
    int c = 0;
    char buf[BUF_SIZE] = {0};
    int j = 0;
    while (isdigit(ciphertext[i])) {
      buf[j] = ciphertext[i];
      i++;
      j++;
    }
    c = atoi(buf);
    int m = 1;
    for (int j = 0; j < d; j++) {
      m = (m * c) % n;
    }
    decryptedtext[strlen(decryptedtext)] = m;
    i++;
  }
}

int main() {
  int p = generate_random_number(1);
  int q = generate_random_number(2);
  int public_key = generate_public_key(p, q);
  int private_key = generate_private_key(p, q, public_key);

  printf("p = %d\n", p);
  printf("q = %d\n", q);
  printf("Public key = %d\n", public_key);
  printf("Private key = %d\n", private_key);

  char plaintext[] = "Hello, World!";
  char ciphertext[BUF_SIZE] = {0};
  char decryptedtext[BUF_SIZE] = {0};

  encrypt(plaintext, p * q, public_key, ciphertext);
  printf("Encrypted text: %s\n", ciphertext);

  decrypt(ciphertext, p * q, private_key, decryptedtext);
  printf("Decrypted text: %s\n", decryptedtext);

  return 0;
}