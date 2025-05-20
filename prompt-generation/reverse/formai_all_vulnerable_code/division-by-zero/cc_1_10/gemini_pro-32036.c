//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int a, b, c, d, e, f, g, h, i, j;
  float k, l, m, n, o, p, q, r, s, t;
  double u, v, w, x, y, z;
  char aa, bb, cc, dd, ee, ff, gg, hh, ii, jj;

  // Arithmetic operators
  a = b + c;
  a = b - c;
  a = b * c;
  a = b / c;
  a = b % c;

  // Increment and decrement operators
  a++;
  a--;

  // Assignment operators
  a = b;
  a += b;
  a -= b;
  a *= b;
  a /= b;
  a %= b;

  // Conditional operators
  a = (b > c) ? b : c;

  // Bitwise operators
  a = b & c;
  a = b | c;
  a = b ^ c;
  a = ~b;
  a = b << c;
  a = b >> c;

  // Logical operators
  a = (b && c);
  a = (b || c);
  a = (!b);

  // Mathematical functions
  a = abs(b);
  a = acos(b);
  a = asin(b);
  a = atan(b);
  a = atan2(b, c);
  a = ceil(b);
  a = cos(b);
  a = cosh(b);
  a = exp(b);
  a = fabs(b);
  a = floor(b);
  a = fmod(b, c);
  a = frexp(b, &c);
  a = ldexp(b, c);
  a = log(b);
  a = log10(b);
  a = modf(b, &c);
  a = pow(b, c);
  a = sin(b);
  a = sinh(b);
  a = sqrt(b);
  a = tan(b);
  a = tanh(b);

  // Input and output
  scanf("%d", &a);
  printf("%d\n", a);

  return 0;
}