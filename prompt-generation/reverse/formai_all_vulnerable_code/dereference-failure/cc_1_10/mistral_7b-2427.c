//MISTRAL-7B DATASET v1.0 Category: Cryptographic hash function ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/md5.h>

#define HASH_SIZE 32
#define MAX_MESSAGE_LENGTH 1024

void my_hash_function(unsigned char *message, unsigned char *hash) {
    unsigned char sha256_hash[SHA256_DIGEST_LENGTH];
    unsigned char md5_hash[MD5_DIGEST_LENGTH];
    unsigned char combined_hash[SHA256_DIGEST_LENGTH + MD5_DIGEST_LENGTH];

    SHA256_CTX sha256_context;
    MD5_CTX md5_context;

    SHA256_Init(&sha256_context);
    SHA256_Update(&sha256_context, message, strlen((const char *)message));
    SHA256_Final(sha256_hash, &sha256_context);

    MD5_Init(&md5_context);
    MD5_Update(&md5_context, message, strlen((const char *)message));
    MD5_Final(md5_hash, &md5_context);

    memmove(combined_hash, sha256_hash, SHA256_DIGEST_LENGTH);
    memmove(combined_hash + SHA256_DIGEST_LENGTH, md5_hash, MD5_DIGEST_LENGTH);

    memcpy(hash, combined_hash, HASH_SIZE);
}

int main(int argc, char *argv[]) {
    unsigned char message[MAX_MESSAGE_LENGTH] = "This is a secret message.";
    unsigned char hash[HASH_SIZE];

    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    memcpy(message, argv[1], strlen((const char *)argv[1]) + 1);

    my_hash_function(message, hash);

    printf("Hash:");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf(" %02x", hash[i]);
    }
    printf("\n");

    return 0;
}