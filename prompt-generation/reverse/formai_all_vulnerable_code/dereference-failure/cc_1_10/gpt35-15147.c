//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROTL(x,y) ((x<<y) | (x>>(32-y)))

unsigned int h0, h1, h2, h3;

void sha1(unsigned char *str, unsigned int len){
    unsigned int a, b, c, d, e;
    unsigned int i, j;
    unsigned int w[80];
    unsigned int temp;

    len = (len + 8)/64 + 1;
    unsigned char *padded_message = (unsigned char *)malloc(len*64);
    memcpy(padded_message, str, len*64);
    padded_message[len*64-1] = '\0';

    padded_message[(len-1)*64+56] = 0x80;

    unsigned int *bit_len_ptr = (unsigned int *)(padded_message+(len-1)*64+60);
    *bit_len_ptr = len*64;

    a = h0;
    b = h1;
    c = h2;
    d = h3;
    e = 0;

    for(i=0;i<len;i++){
        for(j=0;j<16;j++){
            w[j] = ((unsigned int)(padded_message[i*64+j*4+0]) << 24) |
                    ((unsigned int)(padded_message[i*64+j*4+1]) << 16) |
                    ((unsigned int)(padded_message[i*64+j*4+2]) << 8) |
                    ((unsigned int)(padded_message[i*64+j*4+3]) << 0);
        }

        for(j=16;j<80;j++){
            w[j] = ROTL(w[j-3] ^ w[j-8] ^ w[j-14] ^ w[j-16], 1);
        }

        for(j=0;j<80;j++){
            if(j<20){
                temp = ROTL(a, 5) + ((b & c) ^ (~b & d)) + e + w[j] + 0x5A827999;
            }
            else if(j<40){
                temp = ROTL(a, 5) + (b ^ c ^ d) + e + w[j] + 0x6ED9EBA1;
            }
            else if(j<60){
                temp = ROTL(a, 5) + ((b & c) ^ (b & d) ^ (c & d)) + e + w[j] + 0x8F1BBCDC;
            }
            else{
                temp = ROTL(a, 5) + (b ^ c ^ d) + e + w[j] + 0xCA62C1D6;
            }

            e=d;
            d=c;
            c=ROTL(b,30);
            b=a;
            a=temp;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }

    free(padded_message);
}

void compute_hash(unsigned char *message, unsigned int len){
    h0 = 0x67452301;
    h1 = 0xEFCDAB89;
    h2 = 0x98BADCFE;
    h3 = 0x10325476;

    sha1(message, len);

    printf("\nHash output for the given message is: %08x %08x %08x %08x\n", h0, h1, h2, h3);
}

int main(){
    char *message = "This is a sample input message for hashing";
    unsigned int len = strlen(message);

    printf("Input message is: %s\n", message);

    compute_hash(message, len);

    return 0;
}