//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

#define MAX_INPUT_SIZE 100000

typedef struct {
    char *input;
    char *hash;
} HashPair;

void generateRandomString(char *str, int size) {
    const char alphanum[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < size; ++i) {
        str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    str[size] = '\0';
}

int main() {
    srand(time(NULL));
    HashPair *hashPairs = malloc(10 * sizeof(HashPair));
    if (hashPairs == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < 10; ++i) {
        char input[MAX_INPUT_SIZE];
        generateRandomString(input, rand() % MAX_INPUT_SIZE + 1);
        hashPairs[i].input = strdup(input);
        if (hashPairs[i].input == NULL) {
            printf("Error: Memory allocation failed.\n");
            return 1;
        }
        hashPairs[i].hash = malloc(SHA256_DIGEST_LENGTH * sizeof(char));
        if (hashPairs[i].hash == NULL) {
            printf("Error: Memory allocation failed.\n");
            return 1;
        }
        SHA256_CTX ctx;
        SHA256_Init(&ctx);
        SHA256_Update(&ctx, input, strlen(input));
        SHA256_Final(hashPairs[i].hash, &ctx);
    }
    printf("Input\t\tHash\n");
    for (int i = 0; i < 10; ++i) {
        printf("%s\t\t%s\n", hashPairs[i].input, hashPairs[i].hash);
    }
    for (int i = 0; i < 10; ++i) {
        free(hashPairs[i].input);
        free(hashPairs[i].hash);
    }
    free(hashPairs);
    return 0;
}