//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1024
#define PRIME 53

typedef struct {
    int *pub_key;
    int *priv_key;
} RSA_KEY;

RSA_KEY *generate_key() {
    RSA_KEY *key = malloc(sizeof(RSA_KEY));
    int *pub_key = malloc(sizeof(int) * 2);
    int *priv_key = malloc(sizeof(int) * 2);

    // Generate random prime numbers
    srand(time(NULL));
    priv_key[0] = rand() % (PRIME - 2) + 2;
    priv_key[1] = rand() % (PRIME - 2) + 2;

    // Calculate public keys
    pub_key[0] = priv_key[0] * priv_key[1] % PRIME;
    pub_key[1] = (PRIME - 1) / (priv_key[0] * priv_key[1]);

    key->pub_key = pub_key;
    key->priv_key = priv_key;

    return key;
}

int *encrypt(int *pub_key, int message) {
    int *result = malloc(sizeof(int) * 2);
    result[0] = message % PRIME;
    result[1] = pub_key[0] * result[0] % PRIME;
    return result;
}

int *decrypt(int *priv_key, int *cipher_text) {
    int *result = malloc(sizeof(int) * 2);
    result[0] = cipher_text[0] * priv_key[1] % PRIME;
    result[1] = (cipher_text[1] - result[0]) * priv_key[0] % PRIME;
    return result;
}

int main() {
    RSA_KEY *key = generate_key();
    int *pub_key = key->pub_key;
    int *priv_key = key->priv_key;

    int message = 12345;
    int *cipher_text = encrypt(pub_key, message);
    printf("Encrypted message: %d %d\n", cipher_text[0], cipher_text[1]);

    int *decrypted_message = decrypt(priv_key, cipher_text);
    printf("Decrypted message: %d\n", decrypted_message[0]);

    free(key->pub_key);
    free(key->priv_key);
    free(cipher_text);
    free(decrypted_message);

    return 0;
}