//Gemma-7B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 23

long prim_fac(long n) {
  long i, p, ctr = 0;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      p = i;
      n /= p;
      ctr++;
    }
  }
  return ctr;
}

long gcd(long a, long b) {
  if (b) {
    return gcd(b, a % b);
  } else {
    return a;
  }
}

long powmod(long a, long e, long n) {
  long r = 1, i;
  for (i = 0; i < e; i++) {
    r = r * a % n;
  }
  return r;
}

int main() {
  long n, e, d, p, g, ph, msg, enc_msg, dec_msg;
  n = prim_fac(MOD);
  e = rand() % n;
  d = gcd(n, e);
  p = rand() % n;
  g = powmod(p, d, n);
  ph = (g * n) % MOD;
  msg = rand() % MOD;
  enc_msg = powmod(g, msg, ph);
  dec_msg = powmod(g, enc_msg, ph);

  printf("Prime factors of MOD: %ld\n", n);
  printf("E: %ld\n", e);
  printf("D: %ld\n", d);
  printf("G: %ld\n", g);
  printf("PH: %ld\n", ph);
  printf("Message: %ld\n", msg);
  printf("Encrypted message: %ld\n", enc_msg);
  printf("Decrypted message: %ld\n", dec_msg);

  return 0;
}