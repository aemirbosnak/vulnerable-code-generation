//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    int x;
    int y;
} Point;

Point* generate_keys() {
    Point* keys = (Point*)malloc(sizeof(Point) * 2);

    keys[0].x = rand() % (MAX_SIZE - 1) + 1;
    keys[0].y = rand() % (MAX_SIZE - 1) + 1;

    keys[1].x = rand() % (MAX_SIZE - 1) + 1;
    keys[1].y = rand() % (MAX_SIZE - 1) + 1;

    return keys;
}

int encrypt(int message, Point* public_key) {
    return (message * public_key->x + public_key->y) % MAX_SIZE;
}

int decrypt(int cipher_text, Point* private_key) {
    return (cipher_text - private_key->x * private_key->y) % MAX_SIZE;
}

int main() {
    Point* keys = generate_keys();

    printf("Public key: (%d, %d)\n", keys[0].x, keys[0].y);
    printf("Private key: (%d, %d)\n", keys[1].x, keys[1].y);

    int message = 42;
    int cipher_text = encrypt(message, &keys[0]);

    printf("Encrypted message: %d\n", cipher_text);

    int decrypted_message = decrypt(cipher_text, &keys[1]);

    printf("Decrypted message: %d\n", decrypted_message);

    free(keys);

    return 0;
}