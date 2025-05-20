//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define WORD_SIZE 4
#define ADAM3_MAGIC 0x67454321
uint32_t adam3_rotl(uint32_t x, int shift) {
    return (x << shift) | (x >> (32 - shift));
}
uint32_t adam3_f(uint32_t x, uint32_t y, uint32_t z) {
    x = x ^ y ^ z;
    y = adam3_rotl(y, 16);
    z = adam3_rotl(z, 12);
    return x ^ y ^ z;
}
uint32_t adam3_g(uint32_t x, uint32_t y, uint32_t z) {
    x = x ^ y ^ z;
    y = adam3_rotl(y, 7);
    z = adam3_rotl(z, 9);
    return x ^ y ^ z;
}
void adam3_transform(uint8_t *block, uint32_t *state) {
    uint32_t a = *state;
    uint32_t b = *state + ADAM3_MAGIC;
    uint32_t c = *state + (ADAM3_MAGIC << 2);
    uint32_t x, y, z;
    for (int i = 0; i < 16; i++) {
        x = ((uint32_t *) block)[i];
        y = adam3_f(a, b, c);
        z = adam3_g(y, a, b);
        a = x;
        b = y;
        c = z;
    }
    *state = a + b + c;
}
int main() {
    uint32_t state = ADAM3_MAGIC;
    uint8_t input[] = "Hello, World!";
    for (int i = 0; i < 17; i++) {
        if (i < 14) {
            uint8_t block[4];
            memcpy(block, input + i * 4, 4);
            adam3_transform(block, &state);
        } else {
            uint32_t checksum = state;
            printf("Checksum of %s is %x\n", input, checksum);
            break;
        }
    }
    return 0;
}