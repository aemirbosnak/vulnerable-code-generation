//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

#define ROTL(x,n) ((x << n) | (x >> (32-n)))

uint32_t f1(uint32_t x, uint32_t y, uint32_t z){
    return ((x & y) | ((~x) & z));
}

uint32_t f2(uint32_t x, uint32_t y, uint32_t z){
    return ((x & y) | (x & z) | (y & z));
}

uint32_t f3(uint32_t x){
    return (ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22));
}

uint32_t f4(uint32_t x){
    return (ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25));
}

uint32_t f5(uint32_t x){
    return (ROTL(x, 7) ^ ROTL(x, 18) ^ (x >> 3));
}

uint32_t f6(uint32_t x){
    return (ROTL(x, 17) ^ ROTL(x, 19) ^ (x >> 10));
}

void printHash(uint32_t* hash){
    printf("%02x%02x%02x%02x%02x%02x%02x%02x\n", hash[0] & 0xff, (hash[0] >> 8) & 0xff, (hash[0] >> 16) & 0xff, (hash[0] >> 24) & 0xff, hash[1] & 0xff, (hash[1] >> 8) & 0xff, (hash[1] >> 16) & 0xff, (hash[1] >> 24) & 0xff);
}

void sha256(uint8_t *message, uint32_t messageLength, uint32_t *hash){
    uint32_t w[64], temp1, temp2, a, b, c, d, e, f, g, h;
    uint32_t k[64] = {
        0x428a2f98,
        0x71374491,
        0xb5c0fbcf,
        0xe9b5dba5,
        0x3956c25b,
        0x59f111f1,
        0x923f82a4,
        0xab1c5ed5,
        0xd807aa98,
        0x12835b01,
        0x243185be,
        0x550c7dc3,
        0x72be5d74,
        0x80deb1fe,
        0x9bdc06a7,
        0xc19bf174,
        0xe49b69c1,
        0xefbe4786,
        0x0fc19dc6,
        0x240ca1cc,
        0x2de92c6f,
        0x4a7484aa,
        0x5cb0a9dc,
        0x76f988da,
        0x983e5152,
        0xa831c66d,
        0xb00327c8,
        0xbf597fc7,
        0xc6e00bf3,
        0xd5a79147,
        0x06ca6351,
        0x14292967,
        0x27b70a85,
        0x2e1b2138,
        0x4d2c6dfc,
        0x53380d13,
        0x650a7354,
        0x766a0abb,
        0x81c2c92e,
        0x92722c85,
        0xa2bfe8a1,
        0xa81a664b,
        0xc24b8b70,
        0xc76c51a3,
        0xd192e819,
        0xd6990624,
        0xf40e3585,
        0x106aa070,
        0x19a4c116,
        0x1e376c08,
        0x2748774c,
        0x34b0bcb5,
        0x391c0cb3,
        0x4ed8aa4a,
        0x5b9cca4f,
        0x682e6ff3,
        0x748f82ee,
        0x78a5636f,
        0x84c87814,
        0x8cc70208,
        0x90befffa,
        0xa4506ceb,
        0xbef9a3f7,
        0xc67178f2
    };

    // define initial hash value
    hash[0] = 0x6a09e667;
    hash[1] = 0xbb67ae85;
    uint32_t h0 = hash[0], h1 = hash[1], h2 = 0x3c6ef372, h3 = 0xa54ff53a;
    uint32_t h4 = 0x510e527f, h5 = 0x9b05688c, h6 = 0x1f83d9ab, h7 = 0x5be0cd19;

    // loop through each 512-bit block of input message
    for (int i=0; i<messageLength; i+=64){
        // prepare message schedule
        for (int j=0; j<16; j++){
            w[j] = (message[(i+(4*j))]<<24) | (message[(i+(4*j)+1)]<<16) | (message[(i+(4*j)+2)]<<8) | (message[(i+(4*j)+3)]);
        }
        for (int j=16; j<64; j++){
            w[j] = f5(w[j-2]) + w[j-7] + f5(w[j-15]) + w[j-16];
        }

        // initialize working variables
        a = h0;
        b = h1;
        c = h2;
        d = h3;
        e = h4;
        f = h5;
        g = h6;
        h = h7;

        // compression function main loop
        for (int j=0; j<64; j++){
            temp1 = h + f4(e) + f1(e, f, g) + k[j] + w[j];
            temp2 = f3(a) + f2(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // update hash value
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }

    // output final hash value
    hash[0] = h0;
    hash[1] = h1;
    hash[2] = h2;
    hash[3] = h3;
    hash[4] = h4;
    hash[5] = h5;
    hash[6] = h6;
    hash[7] = h7;
}

int main(){
    // test program with example message
    uint8_t message[] = "Hello, World!";
    uint32_t hash[8];
    sha256(message, strlen((char*)message), hash);
    printHash(hash);
    return 0;
}