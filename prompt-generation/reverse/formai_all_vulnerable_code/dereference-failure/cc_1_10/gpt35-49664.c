//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Invasive Cryptographic hash function */

#define HASH_SEED 0xFACEB00C
#define ROTATE_LEFT(x,n) ((x << n) | (x >> (32 - n))) // Circular Bit Shift
#define F1(x,y,z) (x^y^z)
#define F2(x,y,z) ((x & y) | (~x & z))
#define F3(x,y,z) ((x | ~y) ^ z)
#define F4(x,y,z) ((x & z) | (y & ~z))
#define F5(x,y,z) (x ^ (y | ~z))

unsigned int h0, h1, h2, h3, h4;

unsigned int* invasive_hash_func(const unsigned char* message, const unsigned int message_len) {
    unsigned int message_pad_len, i, j, *words;
    unsigned char *message_pad;
    unsigned int a, b, c, d, e, f, g, h, temp1, temp2;

    message_pad_len = message_len + 9 + (message_len * 8) % 512; // Padding message
    message_pad = (unsigned char *)calloc(message_pad_len, sizeof(unsigned char));
    
    memcpy(message_pad, message, message_len); // Copy message to padded message
    message_pad[message_len] = 0x80; // Add 1 bit padding at end of message
    
    words = (unsigned int *)&message_pad[message_pad_len - 8];
    *words++ = message_len >> 29;
    *words = message_len * 8;
    
    h0 = HASH_SEED; h1 = HASH_SEED; h2 = HASH_SEED; h3 = HASH_SEED; h4 = HASH_SEED; // Initialize hash values
    
    for (i = 0; i < message_pad_len; i += 64) { // Process each 512-bit block
        words = (unsigned int *)&message_pad[i];
        a = h0; b = h1; c = h2; d = h3; e = h4;
        
        for (j = 0; j < 80; j++) { // 80 rounds
            if (j < 16) {
                f = F1(b, c, d);
                g = j;
            }
            else if (j < 32) {
                f = F2(b, c, d);
                g = (5 * j + 1) % 16;
            }
            else if (j < 48) {
                f = F3(b, c, d);
                g = (3 * j + 5) % 16;
            }
            else if (j < 64) {
                f = F4(b, c, d);
                g = (7 * j) % 16;
            }
            else {
                f = F5(b, c, d);
                g = (j) % 16;
            }
            
            temp1 = e + f + ROTATE_LEFT(a, 5) + words[g];
            temp2 = ROTATE_LEFT(b, 30) + (c^d);
            a = d; d = c; c = ROTATE_LEFT(b, 30); b = a; a = temp1;
            e = f; f = temp1; h = g; g = temp2; // Update variables
        }
        
        h0 += a; h1 += b; h2 += c; h3 += d; h4 += e; // Update hash values
    }
    
    free(message_pad);
    words = (unsigned int *)malloc(5 * sizeof(unsigned int));
    words[0] = h0; words[1] = h1; words[2] = h2; words[3] = h3; words[4] = h4;
    
    return words; // Return hash
}

int main() {
    unsigned int *hash;
    int i;
    char message[] = "Hello World"; // Message to hash
    int message_len = strlen(message);
    
    hash = invasive_hash_func((unsigned char *)message, message_len);
    
    printf("Message: %s\n", message);
    printf("Hash:");
    for (i = 0; i < 5; i++) {
        printf(" %08x", hash[i]);
    }
    printf("\n");
    
    free(hash);
    
    return 0;
}