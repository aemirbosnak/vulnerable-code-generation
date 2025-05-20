//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// define the length of the key and the message
#define KEY_LEN 8
#define MSG_LEN 24

// the encryption and decryption functions
void encrypt(uint8_t *key, uint8_t *message, uint8_t *ciphertext);
void decrypt(uint8_t *key, uint8_t *ciphertext, uint8_t *message);

int main() {
    uint8_t key[KEY_LEN] = {0xde, 0xad, 0xbe, 0xef, 0x01, 0x23, 0x45, 0x67}; // set the key
    uint8_t message[MSG_LEN] = "Hello, world! This is a secret message."; // set the message

    uint8_t ciphertext[MSG_LEN]; // allocate space for the ciphertext
    memset(ciphertext, 0, sizeof(ciphertext)); // set the ciphertext to all zeros

    uint8_t decrypted_message[MSG_LEN]; // allocate space for the decrypted message
    memset(decrypted_message, 0, sizeof(decrypted_message)); // set the decrypted message to all zeros

    // encrypt the message
    encrypt(key, message, ciphertext);

    // print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < MSG_LEN; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // decrypt the ciphertext
    decrypt(key, ciphertext, decrypted_message);

    // print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}

void encrypt(uint8_t *key, uint8_t *message, uint8_t *ciphertext) {
    uint32_t sum = 0;
    uint32_t delta = 0x9e3779b9;

    uint32_t k[4];
    memcpy(k, key, sizeof(k));

    for (int i = 0; i < MSG_LEN; i += 8) {
        uint32_t v[2];
        memcpy(v, &message[i], sizeof(v));

        sum += delta;
        uint32_t y = v[0];
        uint32_t z = v[1];
        uint32_t a = k[0], b = k[1], c = k[2], d = k[3];

        for (int j = 0; j < 32; j++) {
            y += ((z << 4) + a) ^ (z + sum) ^ ((z >> 5) + b);
            z += ((y << 4) + c) ^ (y + sum) ^ ((y >> 5) + d);
            sum -= delta;
        }

        memcpy(&ciphertext[i], v, sizeof(v));
    }
}

void decrypt(uint8_t *key, uint8_t *ciphertext, uint8_t *message) {
    uint32_t sum = 0xC6EF3720;
    uint32_t delta = 0x9e3779b9;

    uint32_t k[4];
    memcpy(k, key, sizeof(k));

    for (int i = 0; i < MSG_LEN; i += 8) {
        uint32_t v[2];
        memcpy(v, &ciphertext[i], sizeof(v));

        uint32_t y = v[0];
        uint32_t z = v[1];
        uint32_t a = k[0], b = k[1], c = k[2], d = k[3];

        for (int j = 0; j < 32; j++) {
            z -= ((y << 4) + c) ^ (y + sum) ^ ((y >> 5) + d);
            y -= ((z << 4) + a) ^ (z + sum) ^ ((z >> 5) + b);
            sum += delta;
        }

        memcpy(&message[i], v, sizeof(v));
    }
}