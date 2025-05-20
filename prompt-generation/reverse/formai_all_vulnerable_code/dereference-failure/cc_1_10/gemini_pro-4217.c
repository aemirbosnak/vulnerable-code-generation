//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// A mind-bending cryptographic hash function
unsigned char* hash_it(const char* input, int length) {
  // Allocate memory for the hash
  unsigned char* hash = malloc(SHA256_DIGEST_LENGTH);

  // Create a SHA256 context
  SHA256_CTX ctx;
  SHA256_Init(&ctx);

  // Update the context with the input
  SHA256_Update(&ctx, input, length);

  // Finalize the context and compute the hash
  SHA256_Final(hash, &ctx);

  // Return the hash
  return hash;
}

// A truly mind-bending example
int main() {
  // A series of random and seemingly meaningless strings
  const char* strings[] = {
    "Aardvarks are aardwolves, but not aardvarks.",
    "Beets by Bears: Battlestar Galactica.",
    "Celery stalks are like celery stalks.",
    "Dogs eat dog food, but cats don't."
  };

  // Hash each string and print the result
  for (int i = 0; i < 4; i++) {
    unsigned char* hash = hash_it(strings[i], strlen(strings[i]));

    // Print the hash as a hexadecimal string
    for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
      printf("%02x", hash[j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the hashes
  for (int i = 0; i < 4; i++) {
    free(hash_it(strings[i], strlen(strings[i])));
  }

  // Return 0, because why not
  return 0;
}