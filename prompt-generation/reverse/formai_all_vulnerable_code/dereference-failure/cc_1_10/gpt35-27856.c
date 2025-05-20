//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: beginner-friendly
#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint8_t* md5(const uint8_t* message, const size_t len);

int main(void) {
    uint8_t message[] = "This is my message";
    uint8_t* hash = md5(message, strlen((const char*) message));    
    for(int i = 0; i < 16; i++) {
        printf("%.2x", hash[i]);
    }
    return 0;
}

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

uint8_t* md5(const uint8_t* message, const size_t len) {    
    static const uint32_t init[]={
        0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476
    };
    
    static const uint32_t T[]={
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x2441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x4881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };
    
    //initialization
    uint32_t H[4];
    memcpy(H, init, sizeof(init));
    
    //padding
    size_t new_len = ((((len + 8) / 64) + 1) * 64);
    uint8_t* msg = (uint8_t*)calloc(new_len + 64, sizeof(uint8_t));
    memcpy(msg, message, len);
    msg[len] = 0x80;
    uint32_t bits = 8 * len;
    memcpy(msg + new_len, &bits, sizeof(bits));
    
    //processing
    for(size_t offset = 0; offset < new_len; offset += 64) {
        uint32_t* M = (uint32_t*)&msg[offset];
        uint32_t A = H[0];
        uint32_t B = H[1];
        uint32_t C = H[2];
        uint32_t D = H[3];
        for(int i = 0; i < 64; i++) {
            uint32_t F, g;
            if(i < 16) {
                F = (B & C) | ((~B) & D);
                g = i;
            } else if(i < 32) {
                F = (D & B) | ((~D) & C);
                g = (5 * i + 1) % 16;
            } else if(i < 48) {
                F = B ^ C ^ D;
                g = (3 * i + 5) % 16;
            } else {
                F = C ^ (B | (~D));
                g = (7 * i) % 16;
            }
            uint32_t temp = D;
            D = C;
            C = B;
            B = B + ROTATE_LEFT((A + F + T[i] + M[g]), 7);
            A = temp;
        }
        H[0] += A;
        H[1] += B;
        H[2] += C;
        H[3] += D;
    }
    free(msg);
    
    //output
    uint8_t* hash = (uint8_t*)calloc(16, sizeof(uint8_t));
    for(int i = 0; i < 4; i++) {
        hash[i*4] = (H[i] >> 0) & 0xff;
        hash[i*4+1] = (H[i] >> 8) & 0xff;
        hash[i*4+2] = (H[i] >> 16) & 0xff;
        hash[i*4+3] = (H[i] >> 24) & 0xff;
    }
    return hash;
}