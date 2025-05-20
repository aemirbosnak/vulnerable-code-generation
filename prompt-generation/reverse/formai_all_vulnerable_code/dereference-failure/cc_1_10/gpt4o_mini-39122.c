//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 16 // AES standard block size
#define KEY_SIZE 32   // Length of the key in bytes (256 bits)
#define NUM_ROUNDS 14 // Number of rounds for AES-256

// Function prototypes
void generate_key(unsigned char *key);
void add_round_key(unsigned char state[BLOCK_SIZE], unsigned char key[KEY_SIZE]);
void sub_bytes(unsigned char state[BLOCK_SIZE]);
void shift_rows(unsigned char state[BLOCK_SIZE]);
void mix_columns(unsigned char state[BLOCK_SIZE]);
void aes_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext);
void print_state(unsigned char state[BLOCK_SIZE]);

int main() {
    unsigned char key[KEY_SIZE];
    unsigned char plaintext[BLOCK_SIZE] = "Hello, World!!!"; // 16 bytes plaintext
    unsigned char ciphertext[BLOCK_SIZE];

    // Initialize random seed and generate key
    srand(time(NULL));
    generate_key(key);
    
    printf("Generated Key: ");
    for(int i = 0; i < KEY_SIZE; i++) {
        printf("%02x", key[i]);
    }
    printf("\n");

    // Encrypt the plaintext
    aes_encrypt(plaintext, key, ciphertext);
    
    printf("Ciphertext: ");
    for(int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    return 0;
}

// Function to generate a random key
void generate_key(unsigned char *key) {
    for(int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256; // Generate random byte
    }
}

// Function to add round key
void add_round_key(unsigned char state[BLOCK_SIZE], unsigned char key[KEY_SIZE]) {
    for(int i = 0; i < BLOCK_SIZE; i++) {
        state[i] ^= key[i]; // XOR operation
    }
}

// Function for substitution step
void sub_bytes(unsigned char state[BLOCK_SIZE]) {
    // Simplified substitution using a static S-box (for demonstration purposes)
    unsigned char sbox[256] = {
        // Populate with S-box values...
        0x63, 0x7c, 0x77, 0x7b, 0xF2, 0x6b, 0x6f, 0xc5,
        0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0x1e, 0x7c,
        // (Fill in other S-box values)
        //...
    };

    for(int i = 0; i < BLOCK_SIZE; i++) {
        state[i] = sbox[state[i]]; // Substitute bytes
    }
}

// Function for row shifting step
void shift_rows(unsigned char state[BLOCK_SIZE]) {
    unsigned char temp[BLOCK_SIZE];

    // Shift rows based on AES specification
    temp[0] = state[0]; temp[1] = state[1]; temp[2] = state[2]; temp[3] = state[3];
    temp[4] = state[5]; temp[5] = state[6]; temp[6] = state[7]; temp[7] = state[4];
    temp[8] = state[10]; temp[9] = state[8]; temp[10] = state[9]; temp[11] = state[11];
    temp[12] = state[15]; temp[13] = state[12]; temp[14] = state[13]; temp[15] = state[14];

    for(int i = 0; i < BLOCK_SIZE; i++) {
        state[i] = temp[i]; // Update state
    }
}

// Function to mix columns (not fully implemented for brevity)
void mix_columns(unsigned char state[BLOCK_SIZE]) {
    // This function would multiply columns by a fixed polynomial
    // (Implementation omitted for brevity)
}

// Main AES encryption function
void aes_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext) {
    unsigned char state[BLOCK_SIZE];

    // Copy plaintext to state
    memcpy(state, plaintext, BLOCK_SIZE);

    // Initial round
    add_round_key(state, key);

    // Main rounds
    for(int round = 1; round < NUM_ROUNDS; round++) {
        sub_bytes(state);
        shift_rows(state);
        mix_columns(state);
        add_round_key(state, key + (round * BLOCK_SIZE)); // Key schedule simplified
    }
    
    // Final round
    sub_bytes(state);
    shift_rows(state);
    add_round_key(state, key + (NUM_ROUNDS * BLOCK_SIZE));

    // Copy state to ciphertext
    memcpy(ciphertext, state, BLOCK_SIZE);
}

// Helper function to print the state
void print_state(unsigned char state[BLOCK_SIZE]) {
    for(int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", state[i]);
    }
    printf("\n");
}