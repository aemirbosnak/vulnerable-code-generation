//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_SIZE 64

typedef struct {
    char *message;
    size_t length;
} HashData;

void hash_init(HashData *data) {
    data->message = NULL;
    data->length = 0;
}

void hash_update(HashData *data, const char *message, size_t length) {
    if (data->message == NULL) {
        data->message = malloc(length + 1);
        memcpy(data->message, message, length);
        data->length = length;
    } else {
        data->message = realloc(data->message, data->length + length + 1);
        memcpy(data->message + data->length, message, length);
        data->length += length;
    }
}

void hash_final(HashData *data, unsigned char *digest) {
    unsigned long long hash = 0xdeadbeef;
    size_t i;

    for (i = 0; i < data->length; i++) {
        hash = (hash << 8) ^ data->message[i];
    }

    memcpy(digest, &hash, HASH_SIZE);
}

int main() {
    HashData data;
    unsigned char digest[HASH_SIZE];
    char message[] = "Hello, world!";

    hash_init(&data);
    hash_update(&data, message, strlen(message));
    hash_final(&data, digest);

    printf("Digest: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}