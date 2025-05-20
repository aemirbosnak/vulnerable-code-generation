//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_SIZE 32

typedef struct {
    char *data;
    int length;
} HashData;

typedef struct {
    char hash[HASH_SIZE];
    int length;
} HashValue;

void generate_hash(HashData *data, HashValue *hash) {
    unsigned char md[HASH_SIZE];
    char hex[HASH_SIZE * 2];
    int i;

    if (data->length == 0) {
        strcpy(hash->hash, "00000000000000000000000000000000");
        hash->length = 0;
        return;
    }

    MD5((unsigned char *)data->data, data->length, md);

    for (i = 0; i < HASH_SIZE; i++) {
        sprintf(&hex[i * 2], "%02x", md[i]);
    }

    strcpy(hash->hash, hex);
    hash->length = strlen(hash->hash);
}

int main() {
    HashData data;
    HashValue hash;

    data.data = "This is a test.";
    data.length = strlen(data.data);

    generate_hash(&data, &hash);

    printf("Data: %s\n", data.data);
    printf("Hash: %s\n", hash.hash);
    printf("Length: %d\n", hash.length);

    return 0;
}