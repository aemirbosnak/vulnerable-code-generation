//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_CHARS "0123456789ABCDEF"
#define MAX_BYTES 4

void encode(unsigned char *data, int len, unsigned char *cover) {
    int i, j;
    unsigned char bit;

    for (i = 0; i < len; i++) {
        int n = len - i - 1;
        bit = data[i] & 0xF;
        for (j = 0; j < MAX_BYTES; j++) {
            int offset = (bit & 1) * MAX_BYTES;
            if (offset < n) {
                cover[n - offset] ^= HEX_CHARS[j];
            } else {
                cover[n - offset] ^= HEX_CHARS[j + 1];
            }
            bit = 1;
        }
    }
}

void decode(unsigned char *data, int len, unsigned char *cover) {
    int i, j;
    unsigned char bit;

    for (i = 0; i < len; i++) {
        int n = len - i - 1;
        bit = data[i] & 0xF;
        for (j = 0; j < MAX_BYTES; j++) {
            int offset = (bit & 1) * MAX_BYTES;
            if (offset < n) {
                cover[n - offset] = HEX_CHARS[j];
            } else {
                cover[n - offset] = HEX_CHARS[j + 1];
            }
            bit = 1;
        }
    }
}

int main() {
    unsigned char data[] = "Hello, World!";
    unsigned char cover[] = "This is a cover message.";

    int len = strlen(data);
    len += strlen(cover);

    unsigned char *image = (unsigned char*) malloc(len);
    unsigned char *out = (unsigned char*) malloc(len);

    memcpy(image, cover, len);
    encode(data, len, image);
    memcpy(out, image, len);

    decode(out, len, cover);

    printf("Encoded image: %s\n", out);
    printf("Decoded image: %s\n", cover);

    free(image);
    free(out);

    return 0;
}