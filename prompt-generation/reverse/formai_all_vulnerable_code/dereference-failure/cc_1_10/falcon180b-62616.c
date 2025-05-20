//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

#define HASH_LENGTH 64
#define SALT_LENGTH 16
#define ITERATIONS 10000

void generate_salt(unsigned char salt[SALT_LENGTH]) {
    unsigned char bytes[SALT_LENGTH];
    FILE *dev_urandom = fopen("/dev/urandom", "rb");
    if (dev_urandom == NULL) {
        printf("Error: Unable to open /dev/urandom\n");
        exit(1);
    }
    if (fread(bytes, 1, SALT_LENGTH, dev_urandom)!= SALT_LENGTH) {
        printf("Error: Unable to read from /dev/urandom\n");
        exit(1);
    }
    fclose(dev_urandom);
    for (int i = 0; i < SALT_LENGTH; i++) {
        salt[i] = bytes[i];
    }
}

void hash_password(const char *password, const unsigned char salt[SALT_LENGTH],
                   unsigned char hash[HASH_LENGTH]) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, salt, SALT_LENGTH);
    SHA256_Update(&ctx, password, strlen(password));
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_Final(digest, &ctx);
    for (int i = 0; i < HASH_LENGTH; i++) {
        hash[i] = digest[i];
    }
}

int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    unsigned char salt[SALT_LENGTH];
    generate_salt(salt);
    unsigned char hash[HASH_LENGTH];
    hash_password(password, salt, hash);
    printf("Salt: ");
    for (int i = 0; i < SALT_LENGTH; i++) {
        printf("%02x", salt[i]);
    }
    printf("\n");
    printf("Hash: ");
    for (int i = 0; i < HASH_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}