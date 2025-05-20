//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

#define KEY_SIZE 16

// AES encryption function
void encrypt(char* plaintext, char* key, char* ciphertext) {
    int i, j, k;
    char* state = malloc(16 * sizeof(char));
    char* roundKey = malloc(KEY_SIZE * sizeof(char));

    // Initialize AES state and round keys
    for (i = 0; i < 16; i++) {
        state[i] = (char) plaintext[i];
    }
    for (i = 0; i < KEY_SIZE; i++) {
        roundKey[i] = (char) key[i];
    }

    // Perform AES encryption
    for (i = 1; i < 10; i++) {
        // SubBytes
        for (j = 0; j < 16; j++) {
            state[j] = roundKey[state[j]];
        }

        // ShiftRows
        for (k = 0; k < 4; k++) {
            int temp;
            temp = state[0];
            state[0] = state[3];
            state[3] = state[2];
            state[2] = state[1];
            state[1] = temp;
        }

        // MixColumns
        for (j = 0; j < 16; j++) {
            if (j % 2 == 0) {
                roundKey[j] ^= state[j / 2];
                roundKey[j / 2] ^= state[j];
                roundKey[j] ^= state[j / 2];
            } else {
                roundKey[j] ^= state[j / 2];
                roundKey[j / 2] ^= state[j];
                roundKey[j] ^= state[j / 2] ^ roundKey[j];
            }
        }

        // AddRoundKey
        for (j = 0; j < 16; j++) {
            state[j] ^= roundKey[j];
        }
    }

    // XOR ciphertext with state
    for (i = 0; i < 16; i++) {
        ciphertext[i] ^= state[i];
    }

    // Free memory
    free(state);
    free(roundKey);
}

int main() {
    char plaintext[100];
    char key[100];
    char ciphertext[100];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // Pad plaintext with 16 bytes of 0x05
    int plaintextLength = strlen(plaintext);
    plaintext[plaintextLength] = 0x05;
    for (int i = plaintextLength; i < 16; i++) {
        plaintext[i] = 0x05;
    }

    // Encrypt plaintext
    encrypt(plaintext, key, ciphertext);

    // Print ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}