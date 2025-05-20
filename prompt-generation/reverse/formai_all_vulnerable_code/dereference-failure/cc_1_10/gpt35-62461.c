//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLOCK_SIZE 64

unsigned int h0, h1, h2, h3, a, b, c, d, f, g;
unsigned int message_digest[4];

unsigned char *msg_for_digest;
unsigned char *chunk;
unsigned char *p;
unsigned int *w;

unsigned int s[] = {
    7, 12, 17, 22,
    5, 9, 14, 20,
    4, 11, 16, 23,
    6, 10, 15, 21
};

unsigned int k[] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

void md5_transform()
{
    int i;
    
    for (i = 0; i < 16; i++) {
        w[i] = ((unsigned int)p[i * 4])&0xff;
        w[i] |= ((unsigned int)p[i * 4 + 1] << 8)&0xff00;
        w[i] |= ((unsigned int)p[i * 4 + 2] << 16)&0xff0000;
        w[i] |= ((unsigned int)p[i * 4 + 3] << 24)&0xff000000;
    }
    
    a = h0; b = h1; c = h2; d = h3;
    
    for (i = 0; i < 64; i++) {
        if (i < 16) {
            f = (b & c) | ((~b) & d);
            g = i;
        }
        else if (i < 32) {
            f = (d & b) | ((~d) & c);
            g = (5 * i + 1) % 16;
        }
        else if (i < 48) {
            f = b ^ c ^ d;
            g = (3 * i + 5) % 16;
        }
        else {
            f = c ^ (b | (~d));
            g = (7 * i) % 16;
        }
        
        f = f + a + k[i] + w[g];
        a = d;
        d = c;
        c = b;
        b = b + ((f << s[i]) | (f >> (32 - s[i])));
    }
    
    h0 += a;
    h1 += b;
    h2 += c;
    h3 += d;
}

void md5_hash(char *msg, int len)
{
    int new_len;
    int offset;
    int i;
    
    new_len = ((((len + 8) / 64) + 1) * 64) - 8;
    msg_for_digest = (unsigned char*)calloc(new_len + 64, 1);
    memcpy(msg_for_digest, msg, len);
    msg_for_digest[len] = 0x80;
    *(unsigned int*)(msg_for_digest + new_len) = (unsigned int)len * 8;
    
    h0 = 0x67452301;
    h1 = 0xefcdab89;
    h2 = 0x98badcfe;
    h3 = 0x10325476;
    
    for (offset = 0; offset < new_len; offset += BLOCK_SIZE) {
        p = msg_for_digest + offset;
        md5_transform();
    }
    
    message_digest[0] = h0;
    message_digest[1] = h1;
    message_digest[2] = h2;
    message_digest[3] = h3;
}

int main()
{
    int i, len;
    char message[1024];
    
    printf("Enter a message to hash: ");
    scanf("%s", message);
    len = strlen(message);
    
    chunk = (unsigned char*)calloc(1, BLOCK_SIZE);
    msg_for_digest = (unsigned char*)calloc(1, BLOCK_SIZE);
    w = (unsigned int*)calloc(1, BLOCK_SIZE);
    
    md5_hash(message, len);
    
    printf("\n\nDigest is: ");
    for (i = 0; i < 4; i++) {
        printf("%08x", message_digest[i]);
    }
    
    printf("\n\n");
    free(chunk);
    free(msg_for_digest);
    free(w);
    
    return 0;
}