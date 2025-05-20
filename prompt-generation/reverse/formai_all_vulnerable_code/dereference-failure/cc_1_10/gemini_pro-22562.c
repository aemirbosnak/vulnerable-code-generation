//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void ye_olde_hash(byte *msg, int len, byte *hash)
{
  int i, j;
  byte a, b, c, d, e, f, g, h;

  a = 0x67;
  b = 0x45;
  c = 0x23;
  d = 0x01;
  e = 0xEF;
  f = 0xCD;
  g = 0xAB;
  h = 0x89;

  for (i = 0; i < len; i++)
  {
    a = (a + msg[i]) % 256;
    b = (b + a) % 256;
    c = (c + b) % 256;
    d = (d + c) % 256;
    e = (e + d) % 256;
    f = (f + e) % 256;
    g = (g + f) % 256;
    h = (h + g) % 256;
  }

  hash[0] = a;
  hash[1] = b;
  hash[2] = c;
  hash[3] = d;
  hash[4] = e;
  hash[5] = f;
  hash[6] = g;
  hash[7] = h;
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s <message>\n", argv[0]);
    return 1;
  }

  byte msg[strlen(argv[1])];
  strcpy(msg, argv[1]);

  byte hash[8];

  ye_olde_hash(msg, strlen(msg), hash);

  printf("Message: %s\n", argv[1]);
  printf("Hash: ");
  for (int i = 0; i < 8; i++)
  {
    printf("%02x", hash[i]);
  }
  printf("\n");

  return 0;
}