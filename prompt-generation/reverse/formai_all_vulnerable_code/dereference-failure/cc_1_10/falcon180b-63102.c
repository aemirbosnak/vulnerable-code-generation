//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

#define HASH_SIZE 32
#define SALT_SIZE 16
#define ITERATIONS 1000

int main() {
    unsigned char salt[SALT_SIZE];
    unsigned char password[64];
    unsigned char hash[HASH_SIZE];
    int i;

    // generate random salt
    srand(time(NULL));
    for (i = 0; i < SALT_SIZE; i++) {
        salt[i] = rand() % 256;
    }

    // get password from user
    printf("Enter password: ");
    scanf("%s", password);

    // concatenate salt and password
    unsigned char input[SALT_SIZE + strlen(password) + 1];
    strcpy(input, salt);
    strcat(input, password);

    // hash input using SHA-256
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input, strlen(input));
    SHA256_Final(hash, &ctx);

    // apply iterations to hash
    for (i = 0; i < ITERATIONS; i++) {
        SHA256_Init(&ctx);
        SHA256_Update(&ctx, hash, HASH_SIZE);
        SHA256_Final(hash, &ctx);
    }

    // print hash
    printf("Hash: ");
    for (i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}