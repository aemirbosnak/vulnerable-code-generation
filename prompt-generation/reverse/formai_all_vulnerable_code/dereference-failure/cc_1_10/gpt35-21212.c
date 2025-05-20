//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: all-encompassing
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Function to rotate bits */
#define ROTL(x,n) ((x << n) | (x >> (32 - n)))

unsigned int U1 = 0x5F7A23ED;
unsigned int U2 = 0x6D52AEE1;
unsigned int U3 = 0x8659EB9F;
unsigned int U4 = 0x40EFF1E6;
unsigned int U5 = 0x7A879D8A;
unsigned int U6 = 0x19A8D34D;
unsigned int U7 = 0x81F87789;
unsigned int U8 = 0x7C0C5E5A;
unsigned int U9 = 0xFE17C758;
unsigned int U10 = 0x8B3C5911;
unsigned int U11 = 0x7A09E667;
unsigned int U12 = 0xF423FD7D;
unsigned int U13 = 0x6A09E667;
unsigned int U14 = 0xBB67AE85;
unsigned int U15 = 0x3C6EF372;
unsigned int U16 = 0xA54FF53A;
unsigned int U17 = 0x510E527F;
unsigned int U18 = 0x9B05688C;
unsigned int U19 = 0x1F83D9AB;
unsigned int U20 = 0x5BE0CD19;

/* Function to perform the compression */
void BCH(unsigned int *h, unsigned int N, unsigned int *X) {
    unsigned int a,b,c,d,f,g,k;
    unsigned int e[16];
    unsigned int I;
    memcpy(e, X, 64);
    for (I = 0; I < N; I+=16) {
        a = h[0];
        b = h[1];
        c = h[2];
        d = h[3];
        f = h[4];
        g = h[5];
        k = h[6];
        for (unsigned int j = 0; j < 80; j++) {
            if (j < 16) {
                f = ((b & c) | (~b & d));
                k = j;
            } else if (j < 32) {
                f = ((b & c) | (b & d) | (c & d));
                k = (5*j + 1) % 16;
            } else if (j < 48) {
                f = (b ^ c ^ d);
                k = (3*j + 5) % 16;
            } else {
                f = (c ^ (b | ~d));
                k = (7*j) % 16;
            }
            f = f + e[k] + ROTL(a, 5) + g + k;
            g = d;
            d = c;
            c = ROTL(b, 30);
            b = a;
            a = f;
        }
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += f;
        h[5] += g;
        h[6] += k;
    }
}

/* Helper function */
void sha1_helper(unsigned char *data, unsigned int datalen, unsigned char *hash) {
    unsigned int i;
    unsigned int blocks;
    unsigned int *W;
    unsigned int *H;
    unsigned int *p;
    unsigned int N;
    unsigned char *data2;
    unsigned int datalen2;
    unsigned char *p2;

    H = (unsigned int *)calloc(7, sizeof(unsigned int));
    W = (unsigned int *)calloc(80, sizeof(unsigned int));
    data2 = (unsigned char *)calloc(datalen+128, sizeof(unsigned char));
    memcpy(data2, data, datalen);
    data2[datalen] = 0x80;

    datalen2 = datalen + 1;
    p2 = data2 + datalen2;
    datalen2 += (64 - (datalen2 % 64));
    memset(p2, 0, datalen2 - datalen - 8);

    blocks = datalen2 / 64;
    p = (unsigned int *)data2;
    for (i = 0; i < blocks; i++) {
        N = 16;
        BCH(H, N, p);
        BCH(H, 14, &U1);
        memcpy(W, p, N*sizeof(unsigned int));
        for (unsigned int j = N; j < 80; j++) {
            W[j] = ROTL(W[j-3] ^ W[j-8] ^ W[j-14] ^ W[j-16], 1);
        }
        BCH(H, 80, W);
        p += 16;
    }
    for (i = 0; i < 7; i++) {
        hash[4*i + 0] = H[i] >> 24;
        hash[4*i + 1] = H[i] >> 16;
        hash[4*i + 2] = H[i] >> 8;
        hash[4*i + 3] = H[i];
    }
    free(H);
    free(W);
    free(data2);
}

/* Wrapper function */
void sha1(unsigned char *data, unsigned int datalen, unsigned char *hash) {
    sha1_helper(data, datalen, hash);
}

/* Test the hash function */
int main(void) {
    unsigned char hashval[20];
    char message[] = "Test message for SHA-1";

    sha1((unsigned char *)message, strlen(message), hashval);

    printf("The hash of the message is: ");
    for (int i = 0; i < 20; i++) {
        printf("%02x", hashval[i]);
    }
    printf("\n");

    return 0;
}