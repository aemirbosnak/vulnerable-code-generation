//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned int *md5(const char *message);

unsigned int *input;

unsigned int s[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                   5, 9,  14, 20, 5,  9, 14, 20, 5,  9,  14, 20, 5,  9,  14, 20,
                   4, 11, 16, 23, 4, 11, 16, 23, 4,  11, 16, 23, 4,  11, 16, 23,
                   6, 10, 15, 21, 6, 10, 15, 21, 6,  10, 15, 21, 6,  10, 15, 21};

unsigned int K[] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
                    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
                    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
                    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
                    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
                    0xd62f105d, 0x2441453,  0xd8a1e681, 0xe7d3fbc8,
                    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
                    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
                    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
                    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
                    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x4881d05,
                    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
                    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
                    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
                    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
                    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

int main()
{
    char message[] = "Hello, world!";
    unsigned int *result = md5(message);
    
    int i;
    for(i = 0; i < 4; i++) {
        printf("%02x%02x%02x%02x", (result[i] & 0xff), ((result[i] >> 8) & 0xff), ((result[i] >> 16) & 0xff), ((result[i] >> 24) & 0xff));
    }
    
    printf("\n");
    
    free(result);
    
    return 0;
}

unsigned int *md5(const char *message)
{
    int message_len = strlen(message);
    int bit_len = message_len * 8;
    
    int padding_len = (448 - (bit_len % 512)) % 512;
    if(padding_len == 0) {
        padding_len = 512;
    }
    
    int num_blocks = ((bit_len + padding_len + 64) / 512);
    
    input = calloc(num_blocks, 64);
    
    memcpy((unsigned char *)input, message, message_len);
    ((unsigned char *)input)[message_len] = 0x80;
    
    int i;
    for(i = 0; i < num_blocks; i++) {
        input[(i * 16) + 14] = bit_len;
        input[(i * 16) + 15] = bit_len >> 8;
        input[(i * 16) + 14] = bit_len >> 16;
        input[(i * 16) + 13] = bit_len >> 24;
    }
    
    unsigned int A = 0x67452301;
    unsigned int B = 0xefcdab89;
    unsigned int C = 0x98badcfe;
    unsigned int D = 0x10325476;
    
    for(i = 0; i < num_blocks; i++) {
        unsigned int *chunk = &input[i * 16];
        
        unsigned int AA = A;
        unsigned int BB = B;
        unsigned int CC = C;
        unsigned int DD = D;
        
        unsigned int j;
        for(j = 0; j < 64; j++) {
            unsigned int f;
            unsigned int g;
            
            if(j < 16) {
                f = (B & C) | ((~B) & D);
                g = j;
            } else if(j < 32) {
                f = (D & B) | ((~D) & C);
                g = (5 * j + 1) % 16;
            } else if(j < 48) {
                f = B ^ C ^ D;
                g = (3 * j + 5) % 16;
            } else {
                f = C ^ (B | (~D));
                g = (7 * j) % 16;
            }
            
            f = f + A + K[j] + chunk[g];
            A = D;
            D = C;
            C = B;
            B = B + ((f << s[j]) | (f >> (32 - s[j])));
        }
        
        A += AA;
        B += BB;
        C += CC;
        D += DD;
    }
    
    unsigned int *result = calloc(4, sizeof(unsigned int));
    result[0] = A;
    result[1] = B;
    result[2] = C;
    result[3] = D;
    
    return result;
}