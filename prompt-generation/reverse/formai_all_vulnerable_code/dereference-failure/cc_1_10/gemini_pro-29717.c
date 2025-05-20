//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: post-apocalyptic
// In the desolate wasteland, where shadows dance amid ruin, a cryptic message whispers through the ether.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The key to unlock the secrets of the wasteland lies within this ancient algorithm.
unsigned char S[256], T[256];

// In a realm where chaos reigns, initialize the encryption key.
void initKey(unsigned char *key, int len)
{
  int j = 0, k = 0, i;
  for (i = 0; i < 256; i++)
  {
    S[i] = i;
    T[i] = key[i % len];
  }
  for (i = 0; i < 256; i++)
  {
    j = (j + S[i] + T[i]) % 256;
    S[i] ^= S[j];
    S[j] ^= S[i];
    S[i] ^= S[j];
  }
}

// The arcane art of encryption, weaving threads of confusion.
void encrypt(unsigned char *msg, int len)
{
  int j = 0, k = 0, i;
  for (i = 0; i < len; i++)
  {
    j = (j + 1) % 256;
    k = (k + S[j]) % 256;
    S[j] ^= S[k];
    S[k] ^= S[j];
    S[j] ^= S[k];
    msg[i] ^= S[(S[j] + S[k]) % 256];
  }
}

// The shattered remnants of a desolate world, now encoded in shadows.
void printEncoded(unsigned char *msg, int len)
{
  int i;
  printf("[Encoded from the wasteland]: ");
  for (i = 0; i < len; i++)
  {
    printf("%02X", msg[i]);
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  // Gather the relics of the past to decipher the forgotten.
  if (argc < 2)
  {
    printf("Usage: %s <encryption key>\n", argv[0]);
    return 1;
  }
  int keyLen = strlen(argv[1]);
  unsigned char *key = (unsigned char *)malloc(keyLen);
  strcpy((char *)key, argv[1]);

  // Prepare to plunge into the depths of the unknown.
  initKey(key, keyLen);

  // A message emerges from the ruins, a ghost from a forgotten time.
  char msg[] = "The ruins whisper secrets, echoes of a world long lost.";
  int len = strlen(msg);

  // The ritual of encryption, a dance with the shadows.
  encrypt((unsigned char *)msg, len);

  // Transmit the encoded message into the unforgiving void.
  printEncoded((unsigned char *)msg, len);

  return 0;
}