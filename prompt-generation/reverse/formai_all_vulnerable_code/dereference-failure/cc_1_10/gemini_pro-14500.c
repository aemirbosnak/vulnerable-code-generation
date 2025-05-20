//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static uint32_t f(uint32_t x) {
  return (x >> 1) ^ (-(x & 1) & 0x80808080);
}

static uint32_t g(uint32_t x) {
  return (x >> 2) ^ (-(x & 3) & 0x03030303);
}

static uint32_t h(uint32_t x) {
  return (x >> 4) ^ (-(x & 15) & 0x0f0f0f0f);
}

static uint32_t mix(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
  return f(a) + g(b) + h(c) + d;
}

static void mush(uint32_t *x, uint32_t *y, uint32_t *z, uint32_t *w, uint32_t t) {
  *x += mix(*y, *z, *w, t);
  *y += mix(*z, *w, *x, t + 1);
  *z += mix(*w, *x, *y, t + 2);
  *w += mix(*x, *y, *z, t + 3);
}

static void enigma(uint32_t *key, uint8_t *data, size_t len) {
  uint32_t x = key[0], y = key[1], z = key[2], w = key[3];
  for (size_t i = 0; i < len; i += 4) {
    mush(&x, &y, &z, &w, i);
    *(uint32_t *)(data + i) ^= x;
  }
  key[0] = x;
  key[1] = y;
  key[2] = z;
  key[3] = w;
}

int main() {
  uint8_t key[] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef };
  uint8_t data[] = "Hello, world!";
  size_t len = strlen((char *)data);

  printf("Original data: %s\n", data);

  enigma((uint32_t *)key, data, len);

  printf("Encrypted data: %s\n", data);

  enigma((uint32_t *)key, data, len);

  printf("Decrypted data: %s\n", data);

  return 0;
}