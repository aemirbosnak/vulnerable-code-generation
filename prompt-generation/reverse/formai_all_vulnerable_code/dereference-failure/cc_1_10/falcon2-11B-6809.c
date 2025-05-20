//Falcon2-11B DATASET v1.0 Category: Cryptographic hash function ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/err.h>

#define CHUNK_SIZE 16

void get_chunk(char* input, char* output) {
  char* end = NULL;
  char* current_chunk = NULL;

  for (char* p = strtok(input, ""); p!= NULL; p = strtok(NULL, "")) {
    current_chunk = malloc(strlen(p) + 1);
    strcpy(current_chunk, p);
    if (end!= NULL) {
      free(end);
    }
    end = current_chunk;
  }

  if (end!= NULL) {
    free(end);
  }
}

void hash(char* input) {
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, input, strlen(input));
  SHA256_Final(hash, &ctx);
}

int main() {
  char* input = "Hello, world!";
  char* chunk[CHUNK_SIZE];

  get_chunk(input, chunk);
  for (int i = 0; i < CHUNK_SIZE; i++) {
    hash(chunk[i]);
  }

  char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, " ", 1);
  SHA256_Update(&ctx, chunk[0], strlen(chunk[0]));
  for (int i = 1; i < CHUNK_SIZE; i++) {
    SHA256_Update(&ctx, " ", 1);
    SHA256_Update(&ctx, chunk[i], strlen(chunk[i]));
  }
  SHA256_Final(hash, &ctx);

  printf("Chunk hashes: ");
  for (int i = 0; i < CHUNK_SIZE; i++) {
    printf("%s ", hash);
  }
  printf("\nFinal hash: ");
  printf("%s", hash);

  return 0;
}