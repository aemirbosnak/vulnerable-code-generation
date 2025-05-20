//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK_SIZE 64

// Function to perform left rotation of x by n bits
#define LEFT_ROTATE(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Pad message with 0's until the message length is a multiple of BLOCK_SIZE bytes
void pad_message(unsigned char* message, int* message_len) {
    // Calculate needed padding
    int remainder = (*message_len % BLOCK_SIZE);
    int padding = (remainder < 56) ? (56 - remainder) : (120 - remainder);
    int new_len = (*message_len) + padding + 8;
    unsigned char* new_message = calloc(new_len, 1);

    // Copy original message into padded message
    memcpy(new_message, message, *message_len);

    // Append 1 bit
    new_message[(*message_len)] = 0x80;

    // Append 0 bits
    for (int i = (*message_len) + 1; i < new_len - 8; i++) {
        new_message[i] = 0x00;
    }

    // Append length of original message
    unsigned long long bit_len = ((unsigned long long) (*message_len)) * 8;
    memcpy(new_message + new_len - 8, &bit_len, 8);

    *message_len = new_len;
    free(message);
    message = new_message;
}

// Main hashing function
unsigned int my_hash(const void* key, int key_length) {
    // Initial hash values
    unsigned int a = 0x67452301;
    unsigned int b = 0xEFCDAB89;
    unsigned int c = 0x98BADCFE;
    unsigned int d = 0x10325476;

    // Pad message if necessary
    unsigned char* message = malloc(key_length);
    memcpy(message, key, key_length);
    pad_message(message, &key_length);

    // Process message in 512-bit blocks
    int num_blocks = key_length / BLOCK_SIZE;
    for (int i = 0; i < num_blocks; i++) {
        unsigned int* block_ptr = (unsigned int*) message + (i * 16);

        // Save a,b,c,d for this block
        unsigned int aa = a, bb = b, cc = c, dd = d;

        // Round 1
        for (int j = 0; j < 16; j++) {
            unsigned int f = (bb & cc) | ((~bb) & dd);
            unsigned int g = j;
            unsigned int tmp = d;
            d = c;
            c = b;
            b = b + LEFT_ROTATE((a + f + block_ptr[g]), 7);
            a  = tmp;
        }

        // Round 2
        for (int j = 16; j < 32; j++) {
            unsigned int f = (b & c) | ((~b) & d);
            unsigned int g = (5 * j + 1) % 16;
            unsigned int tmp = d;
            d = c;
            c = b;
            b = b + LEFT_ROTATE((a + f + block_ptr[g]), 12);
            a = tmp;
        }

        // Round 3
        for (int j = 32; j < 48; j++) {
            unsigned int f = b ^ c ^ d;
            unsigned int g = (3 * j + 5) % 16;
            unsigned int tmp = d;
            d = c;
            c = b;
            b = b + LEFT_ROTATE((a + f + block_ptr[g]), 17);
            a = tmp;
        }

        // Round 4
        for (int j = 48; j < 64; j++) {
            unsigned int f = c ^ (b | (~d));
            unsigned int g = (7 * j) % 16;
            unsigned int tmp = d;
            d = c;
            c = b;
            b = b + LEFT_ROTATE((a + f + block_ptr[g]), 22);
            a = tmp;
        }

        // Add this block's hash to result so far
        a = a + aa;
        b = b + bb;
        c = c + cc;
        d = d + dd;
    }

    free(message);
    return a ^ b ^ c ^ d;
}

// Example usage
int main() {
    char* message = "Hello World!";
    int message_len = strlen(message);

    unsigned int hash = my_hash((const void*) message, message_len);
    printf("Hash: 0x%08x\n", hash);

    return 0;
}