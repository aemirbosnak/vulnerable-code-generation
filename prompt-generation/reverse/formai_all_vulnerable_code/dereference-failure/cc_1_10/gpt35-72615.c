//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: synchronous
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

#define SHA256_DIGEST_LENGTH 32

uint32_t rotate_right(uint32_t val, uint32_t shift){
    return (val >> shift) | (val << (32 - shift));
}

uint32_t ch(uint32_t x, uint32_t y, uint32_t z){
    return (x & y) ^ (~x & z);
}

uint32_t ma(uint32_t x, uint32_t y, uint32_t z){
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t sigma0(uint32_t x){
    return rotate_right(x, 7) ^ rotate_right(x, 18) ^ (x >> 3);
}

uint32_t sigma1(uint32_t x){
    return rotate_right(x, 17) ^ rotate_right(x, 19) ^ (x >> 10);
}

uint32_t Sigma0(uint32_t x){
    return rotate_right(x, 2) ^ rotate_right(x, 13) ^ rotate_right(x, 22);
}

uint32_t Sigma1(uint32_t x){
    return rotate_right(x, 6) ^ rotate_right(x, 11) ^ rotate_right(x, 25);
}

uint32_t* sha256(char* message){

    uint32_t* K = (uint32_t*)calloc(64, sizeof(uint32_t));
    uint32_t* H = (uint32_t*)calloc(8, sizeof(uint32_t));

    K[0] = 0x428a2f98;
    K[1] = 0x71374491;
    K[2] = 0xb5c0fbcf;
    K[3] = 0xe9b5dba5;
    K[4] = 0x3956c25b;
    K[5] = 0x59f111f1;
    K[6] = 0x923f82a4;
    K[7] = 0xab1c5ed5;

    K[8] = 0xd807aa98;
    K[9] = 0x12835b01;
    K[10] = 0x243185be;
    K[11] = 0x550c7dc3;
    K[12] = 0x72be5d74;
    K[13] = 0x80deb1fe;
    K[14] = 0x9bdc06a7;
    K[15] = 0xc19bf174;

    K[16] = 0xe49b69c1;
    K[17] = 0xefbe4786;
    K[18] = 0x0fc19dc6;
    K[19] = 0x240ca1cc;
    K[20] = 0x2de92c6f;
    K[21] = 0x4a7484aa;
    K[22] = 0x5cb0a9dc;
    K[23] = 0x76f988da;

    K[24] = 0x983e5152;
    K[25] = 0xa831c66d;
    K[26] = 0xb00327c8;
    K[27] = 0xbf597fc7;
    K[28] = 0xc6e00bf3;
    K[29] = 0xd5a79147;
    K[30] = 0x06ca6351;
    K[31] = 0x14292967;

    K[32] = 0x27b70a85;
    K[33] = 0x2e1b2138;
    K[34] = 0x4d2c6dfc;
    K[35] = 0x53380d13;
    K[36] = 0x650a7354;
    K[37] = 0x766a0abb;
    K[38] = 0x81c2c92e;
    K[39] = 0x92722c85;

    K[40] = 0xa2bfe8a1;
    K[41] = 0xa81a664b;
    K[42] = 0xc24b8b70;
    K[43] = 0xc76c51a3;
    K[44] = 0xd192e819;
    K[45] = 0xd6990624;
    K[46] = 0xf40e3585;
    K[47] = 0x106aa070;

    K[48] = 0x19a4c116;
    K[49] = 0x1e376c08;
    K[50] = 0x2748774c;
    K[51] = 0x34b0bcb5;
    K[52] = 0x391c0cb3;
    K[53] = 0x4ed8aa4a;
    K[54] = 0x5b9cca4f;
    K[55] = 0x682e6ff3;

    K[56] = 0x748f82ee;
    K[57] = 0x78a5636f;
    K[58] = 0x84c87814;
    K[59] = 0x8cc70208;
    K[60] = 0x90befffa;
    K[61] = 0xa4506ceb;
    K[62] = 0xbef9a3f7;
    K[63] = 0xc67178f2;

    H[0] = 0x6a09e667;
    H[1] = 0xbb67ae85;
    H[2] = 0x3c6ef372;
    H[3] = 0xa54ff53a;
    H[4] = 0x510e527f;
    H[5] = 0x9b05688c;
    H[6] = 0x1f83d9ab;
    H[7] = 0x5be0cd19;

    uint32_t W[64];
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t T1, T2;

    int len = strlen(message);
    int new_len = ((((len + 8) / 64) + 1) * 64) - 8;
    uint8_t* msg = (uint8_t*)calloc(new_len + 64, sizeof(uint8_t));
    memcpy(msg, message, len);

    msg[len] = 0x80;
    uint32_t bit_len = len * 8;
    memcpy(msg + new_len, &bit_len, 4);

    for(int i = 0; i < (new_len+64)/64;i++){
        memcpy(W, msg + i * 64, 64);

        for(int j = 16; j < 64; j++){
            W[j] = sigma1(W[j-2]) + W[j-7] + sigma0(W[j-15]) + W[j-16];
        }

        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];
        e = H[4];
        f = H[5];
        g = H[6];
        h = H[7];

        for(int j = 0; j < 64;j++){
            T1 = h + Sigma1(e) + ch(e, f, g) + K[j] + W[j];
            T2 = Sigma0(a) + ma(a, b, c);

            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
        
    }
    free(msg);
    free(K);
    return H;
}


int main(){

    char* message = "Hello World!";
    uint32_t* result = sha256(message);

    printf("Hash of \"%s\" is: ", message);

    for(int i = 0; i < SHA256_DIGEST_LENGTH/4; i++){
        printf("%08x", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}