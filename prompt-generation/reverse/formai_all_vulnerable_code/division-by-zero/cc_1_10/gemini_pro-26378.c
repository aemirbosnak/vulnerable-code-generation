//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_PRIME_SIZE 1024

typedef struct {
  uint64_t p;
  uint64_t q;
  uint64_t n;
  uint64_t e;
  uint64_t d;
} rsa_key;

static uint64_t gcd(uint64_t a, uint64_t b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

static uint64_t modular_inverse(uint64_t a, uint64_t m) {
  int64_t x = 0, y = 1, lx = 1, ly = 0, q, temp;
  while (m != 0) {
    q = a / m;
    temp = m;
    m = a % m;
    a = temp;
    temp = x;
    x = lx - q * x;
    lx = temp;
    temp = y;
    y = ly - q * y;
    ly = temp;
  }
  return (x + m) % m;
}

static uint64_t generate_prime(int size) {
  int i, j;
  uint64_t p;
  do {
    p = (uint64_t)rand() % ((1ULL << size) - 1) + (1ULL << (size - 1));
    if (p % 2 == 0) {
      p++;
    }
    for (i = 3; i * i <= p; i += 2) {
      if (p % i == 0) {
        break;
      }
    }
  } while (i * i <= p);
  return p;
}

static void generate_keys(rsa_key *key, int size) {
  key->p = generate_prime(size / 2);
  key->q = generate_prime(size / 2);
  key->n = key->p * key->q;
  key->e = 65537;
  key->d = modular_inverse(key->e, (key->p - 1) * (key->q - 1));
}

static void encrypt(rsa_key *key, uint64_t *data, int size) {
  int i;
  for (i = 0; i < size; i++) {
    data[i] = modular_inverse(data[i], key->e);
  }
}

static void decrypt(rsa_key *key, uint64_t *data, int size) {
  int i;
  for (i = 0; i < size; i++) {
    data[i] = modular_inverse(data[i], key->d);
  }
}

int main() {
  rsa_key key;
  uint64_t data[] = {1, 2, 3, 4, 5};
  int size = sizeof(data) / sizeof(data[0]);
  generate_keys(&key, MAX_PRIME_SIZE);
  encrypt(&key, data, size);
  decrypt(&key, data, size);
  for (int i = 0; i < size; i++) {
    printf("%llu ", data[i]);
  }
  printf("\n");
  return 0;
}