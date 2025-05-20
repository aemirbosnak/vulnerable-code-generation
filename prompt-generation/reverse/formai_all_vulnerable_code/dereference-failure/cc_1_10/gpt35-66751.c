//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hash(char* message, int message_length, unsigned char* output) {
    int i;
    int j;
    int k;
    int f;
    char* padded_message;
    int padded_message_length;
    int block_count;
    int block_index;
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned char temp;
    unsigned int w[80];
    unsigned int t;

    // Calculate the length of the padded message
    padded_message_length = message_length;
    while ((padded_message_length + 1) % 64 != 56) {
        padded_message_length++;
    }
    padded_message_length += 1 + 8;

    // Allocate memory for the padded message
    padded_message = (char*)calloc(padded_message_length, sizeof(char));
    memcpy(padded_message, message, message_length);
    padded_message[message_length] = (char)0x80;

    // Append the length of the message to the padded message
    for (i = 0; i < 8; i++) {
        padded_message[padded_message_length - 8 + i] = (char)(message_length * 8 >> 8 * (7 - i) & 0xff);
    }

    // Initialize the hash values
    a = 0x01;
    b = 0x23;
    c = 0x45;
    d = 0x67;

    // Calculate the number of 512-bit blocks
    block_count = padded_message_length / 64;

    // Process each 512-bit block
    for (block_index = 0; block_index < block_count; block_index++) {
        // Copy the block into the message schedule
        for (i = 0; i < 16; i++) {
            w[i] = (unsigned int)(padded_message[block_index * 64 + i * 4]) << 24 |
                (unsigned int)(padded_message[block_index * 64 + i * 4 + 1]) << 16 |
                (unsigned int)(padded_message[block_index * 64 + i * 4 + 2]) << 8 |
                (unsigned int)(padded_message[block_index * 64 + i * 4 + 3]);
        }

        // Extend the message schedule
        for (i = 16; i < 80; i++) {
            w[i] = (w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16]);
            t = (w[i] << 1) | (w[i] >> 31);
            w[i] = t;
        }

        // Initialize the working variables
        unsigned int aa = a;
        unsigned int bb = b;
        unsigned int cc = c;
        unsigned int dd = d;

        // Perform the main hash loop
        for (i = 0; i < 80; i++) {
            if (i < 20) {
                f = (b & c) | ((~b) & d);
                k = 0x5a827999;
            }
            else if (i < 40) {
                f = b ^ c ^ d;
                k = 0x6ed9eba1;
            }
            else if (i < 60) {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8f1bbcdc;
            }
            else {
                f = b ^ c ^ d;
                k = 0xca62c1d6;
            }

            t = (unsigned int)(a << 5) | (unsigned int)(a >> 27);
            a = b;
            b = c;
            c = (unsigned int)(d << 30) | (unsigned int)(d >> 2);
            d = dd;
            dd = (unsigned int)(f + dd + k + w[i] + t);
        }

        a += aa;
        b += bb;
        c += cc;
        d += dd;
    }

    // Copy the hash to the output buffer
    output[0] = (unsigned char)(a >> 24 & 0xff);
    output[1] = (unsigned char)(a >> 16 & 0xff);
    output[2] = (unsigned char)(a >> 8 & 0xff);
    output[3] = (unsigned char)(a & 0xff);
    output[4] = (unsigned char)(b >> 24 & 0xff);
    output[5] = (unsigned char)(b >> 16 & 0xff);
    output[6] = (unsigned char)(b >> 8 & 0xff);
    output[7] = (unsigned char)(b & 0xff);
    output[8] = (unsigned char)(c >> 24 & 0xff);
    output[9] = (unsigned char)(c >> 16 & 0xff);
    output[10] = (unsigned char)(c >> 8 & 0xff);
    output[11] = (unsigned char)(c & 0xff);
    output[12] = (unsigned char)(d >> 24 & 0xff);
    output[13] = (unsigned char)(d >> 16 & 0xff);
    output[14] = (unsigned char)(d >> 8 & 0xff);
    output[15] = (unsigned char)(d & 0xff);
}

int main(void) {
    char message[] = "This is a unique C Cryptographic hash function example program!";
    int message_length = sizeof(message);
    int i;
    unsigned char output[16];

    hash(message, message_length, output);

    printf("Input message : %s\n", message);
    printf("Hash function output : ");

    for (i = 0; i < 16; i++) {
        printf("%02x", output[i]);
    }

    printf("\n");

    return 0;
}