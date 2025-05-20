//FormAI DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 128
#define BLOCK_SIZE 128

// Round Keys
unsigned char round_keys[11][KEY_LENGTH];

// Substitution table
const unsigned char s_box[256] = {
    // values from AES standard
};

// Transformation matrix
const unsigned char r_con[256] = {
    // values from AES standard
};

void sub_bytes(unsigned char *state) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        state[i] = s_box[state[i]];
    }
}

void shift_rows(unsigned char *state) {
    unsigned char temp[BLOCK_SIZE];

    // First row unchanged (shift 0)
    temp[0] = state[0];
    temp[4] = state[4];
    temp[8] = state[8];
    temp[12] = state[12];

    // Second row shifted 1 to the left
    temp[1] = state[5];
    temp[5] = state[9];
    temp[9] = state[13];
    temp[13] = state[1];

    // Third row shifted 2 to the left
    temp[2] = state[10];
    temp[6] = state[14];
    temp[10] = state[2];
    temp[14] = state[6];

    // Fourth row shifted 3 to the left
    temp[3] = state[15];
    temp[7] = state[3];
    temp[11] = state[7];
    temp[15] = state[11];

    memcpy(state, temp, BLOCK_SIZE);
}

unsigned char x_time(unsigned char x) {
    return ((x << 1) ^ ((x & 0x80) ? 0x1B : 0x00));
}

unsigned char multiply(unsigned char x, unsigned char y) {
    unsigned char product = 0;
    for (int i = 0; i < 8; i++) {
        if (y & 1) {
            product ^= x;
        }
        x = x_time(x);
        y >>= 1;
    }
    return product;
}

void mix_columns(unsigned char *state) {
    unsigned char temp[BLOCK_SIZE];

    for (int i = 0; i < 4; i++) {
        temp[i*4] = multiply(0x02, state[i*4]) ^ multiply(0x03, state[i*4+1]) ^ state[i*4+2] ^ state[i*4+3];
        temp[i*4+1] = state[i*4] ^ multiply(0x02, state[i*4+1]) ^ multiply(0x03, state[i*4+2]) ^ state[i*4+3];
        temp[i*4+2] = state[i*4] ^ state[i*4+1] ^ multiply(0x02, state[i*4+2]) ^ multiply(0x03, state[i*4+3]);
        temp[i*4+3] = multiply(0x03, state[i*4]) ^ state[i*4+1] ^ state[i*4+2] ^ multiply(0x02, state[i*4+3]);
    }

    memcpy(state, temp, BLOCK_SIZE);
}

void key_expansion(unsigned char *key) {
    unsigned char temp[4];
    int i = 0;

    // First round key is original key
    while (i < KEY_LENGTH) {
        round_keys[0][i++] = key[i];
    }

    int r_con_index = 1;
    while (i < 176) {
        // Store previous round key
        temp[0] = round_keys[(i-4)/16][i%16];
        temp[1] = round_keys[(i-3)/16][i%16];
        temp[2] = round_keys[(i-2)/16][i%16];
        temp[3] = round_keys[(i-1)/16][i%16];

        // Perform key schedule core
        if (i % 16 == 0) {
            unsigned char temp2 = temp[0];
            temp[0] = s_box[temp[1]] ^ r_con[r_con_index];
            temp[1] = s_box[temp[2]];
            temp[2] = s_box[temp[3]];
            temp[3] = s_box[temp2];
            r_con_index++;
        }

        // XOR with round constant and previous round key
        round_keys[i/16][i%16] = round_keys[(i-16)/16][i%16] ^ temp[0];
        round_keys[(i+1)/16][i%16] = round_keys[(i-15)/16][i%16] ^ temp[1];
        round_keys[(i+2)/16][i%16] = round_keys[(i-14)/16][i%16] ^ temp[2];
        round_keys[(i+3)/16][i%16] = round_keys[(i-13)/16][i%16] ^ temp[3];

        i += 4;
    }
}

void add_round_key(unsigned char *state, int round) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        state[i] ^= round_keys[round][i];
    }
}

void encrypt(unsigned char *plaintext, unsigned char *ciphertext) {
    // Copy plaintext to state
    unsigned char state[BLOCK_SIZE];
    memcpy(state, plaintext, BLOCK_SIZE);

    // Add initial round key
    add_round_key(state, 0);

    // Perform rounds
    for (int i = 1; i < 10; i++) {
        sub_bytes(state);
        shift_rows(state);
        mix_columns(state);
        add_round_key(state, i);
    }

    // Final round (no mix columns)
    sub_bytes(state);
    shift_rows(state);
    add_round_key(state, 10);

    // Copy state to ciphertext
    memcpy(ciphertext, state, BLOCK_SIZE);
}

int main() {
    // Example plaintext and key
    unsigned char plaintext[BLOCK_SIZE] = {
        // fill with plaintext values
    };
    unsigned char key[16] = {
        // fill with key values
    };

    // Expand key
    key_expansion(key);

    // Encrypt plaintext
    unsigned char ciphertext[BLOCK_SIZE];
    encrypt(plaintext, ciphertext);

    // Print output
    printf("Plaintext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", plaintext[i]);
    }
    printf("\nKey: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", key[i]);
    }
    printf("\nCiphertext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    return 0;
}