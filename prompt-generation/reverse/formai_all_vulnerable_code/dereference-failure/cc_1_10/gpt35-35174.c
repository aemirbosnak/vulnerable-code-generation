//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define ROTL(x,n) ((x << n) | (x >> (32-n)))

uint32_t magic_constants[4] = {
    0x6A09E667,
    0xBB67AE85,
    0x3C6EF372,
    0xA54FF53A
};

uint32_t sum_words(uint32_t a, uint32_t b) {
    uint32_t sum = a + b;
    return sum;
}

uint32_t rotate_xor_sum(uint32_t a, uint32_t b, uint8_t n) {
    uint32_t xor_sum = a ^ b;
    uint32_t rot_xor_sum = ROTL(xor_sum, n);
    return sum_words(a, rot_xor_sum);
}

uint32_t hash(const char* message, uint32_t len) {
    uint32_t hash_value[8];
    
    memcpy(hash_value, magic_constants, sizeof(magic_constants));
    
    uint32_t* message_words = (uint32_t*) message;
    uint32_t n_words = len / 4;
    
    for (uint32_t i = 0; i < n_words; i += 8) {
        for (uint32_t j = 0; j < 8; j++) {
            uint32_t a = hash_value[j];
            uint32_t b = message_words[i + j];
            
            hash_value[j] = rotate_xor_sum(a, b, 13);
        }
        hash_value[4] = sum_words(hash_value[4], 8 * n_words);
    }
    
    return hash_value[0];
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s MESSAGE\n", argv[0]);
        exit(1);
    }
    
    const char* message = argv[1];
    uint32_t len = strlen(message);
    
    uint32_t hash_value = hash(message, len);
    
    printf("%s: %08x\n", message, hash_value);
    
    return 0;
}