//FormAI DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    unsigned char r, g, b;
} pixel_t;

void encode(char *img, char *msg, char *out) {
    FILE *f = fopen(img, "rb");
    if (!f) {
        perror(img);
        exit(1);
    }

    char header[54];
    fread(header, sizeof(char), 54, f);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int size = *(int*)&header[34];

    if (size == 0) {
        size = width*height*3;
    }

    unsigned char *data = (unsigned char*) malloc(size);
    fread(data, sizeof(char), size, f);
    fclose(f);

    int i, j, k=0;

    for (i=0; i<MAX_SIZE && msg[i]!='\0'; i++) {
        unsigned char letter = msg[i];

        for (j=0; j<8; j++) {
            pixel_t *p = (pixel_t*)(data+k);
            unsigned char bit = (letter >> j) & 1;

            if (bit) {
                if (p->b % 2 == 0) {
                    p->b++;
                }
            } else {
                if (p->b % 2 == 1) {
                    p->b--;
                }
            }

            k += 3;
        }
    }

    f = fopen(out, "wb");
    if (!f) {
        perror(out);
        exit(1);
    }

    fwrite(header, sizeof(char), 54, f);
    fwrite(data, sizeof(char), size, f);
    fclose(f);

    printf("Encoded message: %s\n", msg);
}

void decode(char *img) {
    FILE *f = fopen(img, "rb");
    if (!f) {
        perror(img);
        exit(1);
    }

    char header[54];
    fread(header, sizeof(char), 54, f);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int size = *(int*)&header[34];

    if (size == 0) {
        size = width*height*3;
    }

    unsigned char *data = (unsigned char*) malloc(size);
    fread(data, sizeof(char), size, f);
    fclose(f);

    int i, j, k=0;
    char msg[MAX_SIZE];

    for (i=0; i<MAX_SIZE; i++) {
        unsigned char letter = 0;

        for (j=0; j<8; j++) {
            pixel_t *p = (pixel_t*)(data+k);
            unsigned char bit = p->b & 1;
            letter = (letter >> 1) | (bit << 7);
            k += 3;
        }

        msg[i] = letter;

        if (letter == '\0') {
            break;
        }
    }

    printf("Decoded message: %s\n", msg);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <encode/decode> <image> [message]\n", argv[0]);
        return 0;
    }

    char *img = argv[2];

    if (strcmp(argv[1], "encode") == 0 && argc == 4) {
        char *msg = argv[3];
        char *out = "out.bmp";
        encode(img, msg, out);
    } else if (strcmp(argv[1], "decode") == 0) {
        decode(img);
    } else {
        printf("Usage: %s <encode/decode> <image> [message]\n", argv[0]);
    }

    return 0;
}