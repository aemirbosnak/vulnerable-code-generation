//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_LENGTH 64
#define HASH_ALGORITHM "SHA-256"

/*
 * Calculates the hash of a given string using the specified algorithm.
 * Returns the hash as a hexadecimal string.
 */
char *calculate_hash(const char *data, const char *algorithm) {
    unsigned char hash[HASH_LENGTH];
    char hex_hash[HASH_LENGTH * 2 + 1];
    int hash_length;

    hash_length = EVP_Digest(data, strlen(data), hash, NULL, EVP_get_digestbyname(algorithm), NULL);

    for (int i = 0; i < hash_length; i++) {
        sprintf(&hex_hash[i * 2], "%02x", hash[i]);
    }

    hex_hash[hash_length * 2] = '\0';

    return strdup(hex_hash);
}

/*
 * Generates a random string of the given length.
 */
char *generate_random_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = rand() % 26 + 'a';
    }
    string[length] = '\0';

    return string;
}

/*
 * Tests the hash function by generating a random string and calculating its hash.
 */
int main() {
    char *random_string = generate_random_string(32);
    char *hash = calculate_hash(random_string, HASH_ALGORITHM);

    printf("Random string: %s\n", random_string);
    printf("Hash: %s\n", hash);

    free(random_string);
    free(hash);

    return 0;
}