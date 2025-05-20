//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_STRING_LENGTH 256

typedef struct HashFunctionState {
  unsigned char digest[SHA_DIGEST_LENGTH];
  int digestLength;
  unsigned char key[MAX_STRING_LENGTH];
  int keyLength;
} HashFunctionState;

HashFunctionState hashFunction(const unsigned char *message, int messageLength, const unsigned char *key, int keyLength)
{
  HashFunctionState state;

  state.digestLength = SHA_DIGEST_LENGTH;
  state.keyLength = keyLength;

  if (keyLength > MAX_STRING_LENGTH) {
    return state;
  }

  memcpy(state.key, key, keyLength);
  memcpy(state.digest, SHA256(message, messageLength, state.key), state.digestLength);

  return state;
}

int main()
{
  const unsigned char *message = "Hello, world!";
  const unsigned char *key = "Secret key";
  int messageLength = strlen(message);
  int keyLength = strlen(key);

  HashFunctionState state = hashFunction(message, messageLength, key, keyLength);

  printf("Digest: ");
  for (int i = 0; i < state.digestLength; i++) {
    printf("%02x ", state.digest[i]);
  }

  printf("\nKey: ");
  for (int i = 0; i < state.keyLength; i++) {
    printf("%02x ", state.key[i]);
  }

  return 0;
}