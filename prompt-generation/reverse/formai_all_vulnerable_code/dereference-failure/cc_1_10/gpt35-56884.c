//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: expert-level
#include <stdio.h>
#include <stdint.h>

// ROTL function to rotate the bits of a number to the left
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Constants used in the hash function
#define K0 0x5a827999
#define K1 0x6ed9eba1
#define K2 0x8f1bbcdc
#define K3 0xca62c1d6

// Hash function that takes a message and its length as input
void c_hash(const uint8_t *message, uint32_t length, uint32_t *hash) {
    // Initialize hash values
    uint32_t H[5] = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476, 0xc3d2e1f0};
    
    // Calculate number of blocks
    uint32_t num_blocks = (length + 8) / 64 + 1; // 512 bits = 64 bytes
    
    // Allocate memory for message and pad with zeros
    uint8_t *padded_msg = (uint8_t *)calloc(num_blocks * 64, 1);
    if (padded_msg == NULL) {
        printf("Memory allocation failure.\n");
        return;
    }
    for (uint32_t i = 0; i < length; i++) {
        padded_msg[i] = message[i];
    }
    padded_msg[length] = 0x80; // Add bit '1' after message
    *((uint64_t *)(padded_msg + num_blocks * 64 - 8)) = length * 8; // Add message length at the end
    
    // Loop through each block
    for (uint32_t i = 0; i < num_blocks; i++) {
        // Initialize working variables
        uint32_t A = H[0];
        uint32_t B = H[1];
        uint32_t C = H[2];
        uint32_t D = H[3];
        uint32_t E = H[4];
        uint32_t *W = (uint32_t *)(padded_msg + i * 64);
        
        // Perform Round 1
        for (uint32_t j = 0; j < 16; j++) {
            uint32_t temp = ROTL(A, 5) + ((B & C) | ((~B) & D)) + E + W[j] + K0;
            E = D;
            D = C;
            C = ROTL(B, 30);
            B = A;
            A = temp;
        }
        
        // Perform Round 2
        for (uint32_t j = 16; j < 20; j++) {
            uint32_t temp = ROTL(A, 5) + (B ^ C ^ D) + E + W[j] + K1;
            E = D;
            D = C;
            C = ROTL(B, 30);
            B = A;
            A = temp;
        }
        
        // Perform Round 3
        for (uint32_t j = 20; j < 32; j++) {
            uint32_t temp = ROTL(A, 5) + ((B & C) | (B & D) | (C & D)) + E + W[j] + K2;
            E = D;
            D = C;
            C = ROTL(B, 30);
            B = A;
            A = temp;
        }
        
        // Perform Round 4
        for (uint32_t j = 32; j < 40; j++) {
            uint32_t temp = ROTL(A, 5) + (B ^ C ^ D) + E + W[j] + K3;
            E = D;
            D = C;
            C = ROTL(B, 30);
            B = A;
            A = temp;
        }
        
        // Perform Round 5
        for (uint32_t j = 40; j < 60; j++) {
            uint32_t temp = ROTL(A, 5) + ((B & C) | (B & D) | (C & D)) + E + W[j] + K2;
            E = D;
            D = C;
            C = ROTL(B, 30);
            B = A;
            A = temp;
        }
        
        // Perform Round 6
        for (uint32_t j = 60; j < 80; j++) {
            uint32_t temp = ROTL(A, 5) + (B ^ C ^ D) + E + W[j] + K3;
            E = D;
            D = C;
            C = ROTL(B, 30);
            B = A;
            A = temp;
        }
        
        // Update hash values with result of block
        H[0] += A;
        H[1] += B;
        H[2] += C;
        H[3] += D;
        H[4] += E;
    }
    
    // Free memory allocated for padded message
    free(padded_msg);
    
    // Set hash output
    for (uint32_t i = 0; i < 5; i++) {
        hash[i] = H[i];
    }
}

int main() {
    // Test message
    uint8_t message[] = "This is a test message.";
    uint32_t length = sizeof(message) - 1; // Don't include null terminator
    
    // Calculate hash
    uint32_t hash[5];
    c_hash(message, length, hash);
    
    // Print hash
    printf("Hash:");
    for (uint32_t i = 0; i < 5; i++) {
        printf(" %08x", hash[i]);
    }
    printf("\n");
    
    return 0;
}