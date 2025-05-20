//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

#define HASH_LENGTH 64

typedef struct {
    char *message;
    int message_length;
    unsigned char hash[HASH_LENGTH];
} Hash;

Hash *create_hash(char *message, int length) {
    Hash *hash = (Hash *)malloc(sizeof(Hash));
    hash->message = message;
    hash->message_length = length;
    return hash;
}

void calculate_md5_hash(Hash *hash) {
    MD5((unsigned char *)hash->message, hash->message_length, hash->hash);
}

void calculate_sha256_hash(Hash *hash) {
    SHA256((unsigned char *)hash->message, hash->message_length, hash->hash);
}

int compare_hashes(Hash *hash1, Hash *hash2) {
    for (int i = 0; i < HASH_LENGTH; i++) {
        if (hash1->hash[i]!= hash2->hash[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char message1[] = "Hello, world!";
    char message2[] = "Hello, world!";
    char message3[] = "Hello, different world!";

    Hash *hash1 = create_hash(message1, strlen(message1));
    Hash *hash2 = create_hash(message2, strlen(message2));
    Hash *hash3 = create_hash(message3, strlen(message3));

    calculate_md5_hash(hash1);
    calculate_sha256_hash(hash2);

    if (compare_hashes(hash1, hash2)) {
        printf("The hashes match!\n");
    } else {
        printf("The hashes do not match.\n");
    }

    return 0;
}