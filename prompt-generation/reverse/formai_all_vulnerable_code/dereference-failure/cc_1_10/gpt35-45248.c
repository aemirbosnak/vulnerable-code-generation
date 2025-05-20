//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint32_t h0, h1, h2, h3;

void md5_hash(uint32_t *w)
{
    uint32_t a = h0, b = h1, c = h2, d = h3, i, temp;
    
    for(i = 0; i < 64; i++)
    {
        if(i < 16) temp = (b & c) | ((~b) & d);
        else if(i < 32) temp = (d & b) | ((~d) & c);
        else if(i < 48) temp = b ^ c ^ d;
        else temp = c ^ (b | (~d));
        
        temp = temp + a + w[i] + (uint32_t)(0x100000000 * fabs(sin(i + 1)));
        a = d; d = c; c = b; b = b + ((temp << i) | (temp >> (32 - i)));
    }
    
    h0 += a; h1 += b; h2 += c; h3 += d;
}

void generate_hash(char *msg)
{
    size_t len = strlen(msg);
    uint32_t padded_len = (((len + 8) / 64) + 1) * 64;
    uint32_t *msg_padded = malloc(padded_len);
    uint32_t i;
    
    memcpy(msg_padded, msg, len);
    ((char *)msg_padded)[len] = 0x80; 
    
    for(i = len + 1; i < padded_len - 8; i++) ((char *)msg_padded)[i] = 0x00;
    ((uint32_t *)(msg_padded + (padded_len / 4) - 2))[0] = len * 8; 
    
    h0 = 0x67452301; h1 = 0xefcdab89; h2 = 0x98badcfe; h3 = 0x10325476;
    
    for(i = 0; i < padded_len / 64; i++) md5_hash(&msg_padded[i * 16]);
    
    free(msg_padded);
}

int main()
{
    generate_hash("Hello World!");
    printf("%08x%08x%08x%08x", h0, h1, h2, h3);
    
    return 0;
}