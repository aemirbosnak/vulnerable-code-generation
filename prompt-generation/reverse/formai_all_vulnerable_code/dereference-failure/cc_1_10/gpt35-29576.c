//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Rotation Macros */
#define ROTL(x,y) ((x<<y) | (x>>(32-y)))
#define ROTR(x,y) ((x>>y) | (x<<(32-y)))

/* Chaining Variables */
uint32_t a, b, c, d;

/* Round Function */
void roundFunction(uint32_t *x, uint32_t y, uint32_t z) {
    *x += y;
    *x ^= z;
    *x = ROTL(*x, 16);
    *x += d;
    d = ROTL(d, 10);
    d += a;
}

/* Hash Function */
void hash_function(uint8_t *message, size_t length) {
    a = 0xDEADBEEF;
    b = 0xCAFEBABE;
    c = 0xABCDEF01;
    d = 0x01234567;

    /* Processing message */
    uint32_t *words = (uint32_t*) message;
    uint32_t num_blocks = length / 16;
    for (int i = 0; i < num_blocks; i++) {
        roundFunction(&a, words[i], words[i+1]);
        roundFunction(&b, words[i+1], words[i+2]);
        roundFunction(&c, words[i+2], words[i+3]);
        roundFunction(&d, words[i+3], words[i]);
    }

    /* Finalization */
    uint8_t *last_block = message + num_blocks*16;
    uint32_t last_word = 0;
    uint8_t num_bytes = length%16;

    /* Copy last bytes to uint32_t word */
    memcpy(&last_word, last_block, num_bytes);

    /* Add Padding */
    last_word <<= (8*(3-num_bytes));
    last_word |= 0x1 << (8*(3-num_bytes-1));

    /* Process last block */
    roundFunction(&a, last_word, words[0]);
    roundFunction(&b, words[0], words[1]);
    roundFunction(&c, words[1], words[2]);
    roundFunction(&d, words[2], last_word);

    /* Print hash */
    printf("%08x%08x%08x%08x\n", a, b, c, d);
}

int main() {
    uint8_t message[] = "\xff\xfc\x00\x00\x00\x00\x00\x00" 
                        "\x00\x00\x00\x00\x00\x00\x00\x00" 
                        "This is a test message";
    size_t length = sizeof(message)-1;
    hash_function(message, length);
    return 0;
}