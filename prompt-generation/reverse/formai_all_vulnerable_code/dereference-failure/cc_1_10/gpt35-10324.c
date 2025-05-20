//FormAI DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

void encrypt(unsigned char* plaintext, unsigned char* key, unsigned char* ciphertext) {
    int i;
    unsigned char state[BLOCK_SIZE];  // State of the cipher
    
    memcpy(state, plaintext, BLOCK_SIZE);  // Copy plaintext into state
    
    for (i = 0; i < BLOCK_SIZE; i++) {
        state[i] ^= key[i];  // Perform key xor on the state
    }
    
    memcpy(ciphertext, state, BLOCK_SIZE);  // Copy the state into ciphertext
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <input file> <key file> <output file>\n", argv[0]);
        exit(1);
    }
    
    FILE* input = fopen(argv[1], "rb");
    FILE* key = fopen(argv[2], "rb");
    FILE* output = fopen(argv[3], "wb");
    
    if (!input || !key || !output) {
        printf("Error opening files.\n");
        exit(1);
    }
    
    unsigned char plaintext[BLOCK_SIZE];  // Plaintext block
    unsigned char key_block[BLOCK_SIZE];  // Key block
    unsigned char ciphertext[BLOCK_SIZE];  // Ciphertext block
    
    while (fread(plaintext, sizeof(unsigned char), BLOCK_SIZE, input) == BLOCK_SIZE) {
        fread(key_block, sizeof(unsigned char), BLOCK_SIZE, key);
        
        encrypt(plaintext, key_block, ciphertext);
        
        fwrite(ciphertext, sizeof(unsigned char), BLOCK_SIZE, output);
    }
    
    fclose(input);
    fclose(key);
    fclose(output);
    
    return 0;
}