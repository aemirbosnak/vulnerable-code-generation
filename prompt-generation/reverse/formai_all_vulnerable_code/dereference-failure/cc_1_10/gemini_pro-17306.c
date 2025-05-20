//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: Sherlock Holmes
// In the eerie confines of 221B Baker Street, amidst the haze of pipe smoke, Sherlock Holmes embarks on a cerebral pursuit: data compression.

#include <stdio.h>
#include <stdlib.h>

// A coded message from Professor Moriarty, intercepted by our trusty Watson:
unsigned char cipher[] = { 0x41, 0x54, 0x42, 0x42, 0x42, 0x42, 0x46, 0x47, 0x48, 0x1F };

// Elementary, Watson! A simple compression algorithm to decipher Moriarty's machinations:
unsigned char decompress(unsigned char *src, int size) {
    unsigned char seq, count = 1;
    int i, out_idx = 0;
    unsigned char *out = (unsigned char *) malloc(size * 2);

    for (i = 0; i < size; i++) {
        seq = src[i];
        if (i + 1 < size && src[i+1] == seq) {
            count++;
        } else {
            out[out_idx++] = seq;
            if (count > 1) {
                out[out_idx++] = count;
            }
            count = 1;
        }
    }

    return out_idx;
}

// The game is afoot! Let us unravel the mystery:
int main() {
    int i, decompressed_size;
    unsigned char *decompressed = decompress(cipher, sizeof(cipher));

    printf("Moriarty's coded message: ");
    for (i = 0; i < sizeof(cipher); i++) {
        printf("%02X ", cipher[i]);
    }
    printf("\n");

    printf("Decompressed data: ");
    for (i = 0; i < decompressed_size; i++) {
        printf("%02X ", decompressed[i]);
    }
    printf("\n");

    free(decompressed);
    return 0;
}