//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
  char *password;
  char *salt;
  int iterations;
} Password;

Password *create_password(char *password, char *salt, int iterations) {
  Password *p = malloc(sizeof(Password));
  p->password = strdup(password);
  p->salt = strdup(salt);
  p->iterations = iterations;
  return p;
}

void destroy_password(Password *p) {
  free(p->password);
  free(p->salt);
  free(p);
}

char *hash_password(Password *p) {
  unsigned char *hash = malloc(SHA256_DIGEST_LENGTH);
  char *hashed = malloc(SHA256_DIGEST_LENGTH * 2 + 1);
  int i;

  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, p->password, strlen(p->password));
  SHA256_Update(&ctx, p->salt, strlen(p->salt));
  SHA256_Final(hash, &ctx);

  for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    sprintf(hashed + i * 2, "%02x", hash[i]);
  }

  free(hash);
  return hashed;
}

int compare_passwords(Password *p1, Password *p2) {
  char *hash1 = hash_password(p1);
  char *hash2 = hash_password(p2);
  int result = strcmp(hash1, hash2);
  free(hash1);
  free(hash2);
  return result;
}

int main() {
  Password *p1 = create_password("secret", "salt", 1000);
  Password *p2 = create_password("secret", "salt", 1000);

  if (compare_passwords(p1, p2) == 0) {
    printf("The passwords match.\n");
  } else {
    printf("The passwords do not match.\n");
  }

  destroy_password(p1);
  destroy_password(p2);

  return 0;
}