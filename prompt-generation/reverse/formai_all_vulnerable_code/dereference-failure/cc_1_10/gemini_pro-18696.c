//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

const char *welcome = "Welcome to the Cryptographic Hash Carnival!";

// Our data circus tent
char *data = "Abracadabra, hocus pocus, presto!";

// The hash wizard
unsigned char hash[SHA256_DIGEST_LENGTH];

int main() {
    // Step into the carnival of hashes
    printf("%s\n", welcome);

    // Prepare for the data's grand entrance
    printf("Your data, dear magician: %s\n", data);

    // Summon the hash wizard, SHA256, with an incantation
    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    // Feed the wizard the data, transforming it into a mystical trance
    SHA256_Update(&ctx, data, strlen(data));

    // Witness the wizard's enigmatic creation!
    SHA256_Final(hash, &ctx);

    // Unveiling the hash, a string of cryptographic wonders
    printf("Behold, the hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    // Time for data duplication, a mischievous illusion
    char *copy = calloc(strlen(data) + 1, sizeof(char));
    strcpy(copy, data);

    // A subtle twist, a touch of confusion
    copy[0] = 'H';

    // The wizard's magic fails under scrutiny
    SHA256_Update(&ctx, copy, strlen(copy));
    SHA256_Final(hash, &ctx);

    // Exposing the illusion, a different hash emerges
    printf("The deceptive hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    // The carnival ends, leaving behind a world of cryptographic marvels
    free(copy);
    return 0;
}