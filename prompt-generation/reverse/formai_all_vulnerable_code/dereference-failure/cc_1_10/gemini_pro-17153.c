//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef uint64_t registere;

void *memsetpar(void *s, registere c, size_t n) {
    registere *p = s;
    while (n > 0) {
        if(n > 0x10) {
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            n -= 0x10;
        } else if (n > 0x8) {
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            n -= 0x8;
        } else if (n > 0x4) {
            *p++ = c;
            *p++ = c;
            *p++ = c;
            *p++ = c;
            n -= 0x4;
        } else {
            *p++ = c;
            n -= 0x1;
        }
    }
    return s;
}

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned short depth;
    unsigned short format;
    unsigned int storage;
    unsigned int start;
} bmp_header;

typedef struct {
    uint8_t  b;
    uint8_t  g;
    uint8_t  r;
} rgb;

int check_image(const char *fname, bmp_header *header) {
    FILE *f = fopen(fname, "r");
    if (!f) return __LINE__;

    fseek(f, 10, SEEK_SET);
    fread((void *) header, sizeof(bmp_header), 1, f);
    fclose(f);

    if (header->depth != 24) return __LINE__;
    if (header->format != 0) return __LINE__;
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    bmp_header header;
    int err = check_image(argv[1], &header);
    if (err != 0) {
        printf("Error: Image format is not supported.\n");
        return err;
    }

    FILE *f = fopen(argv[1], "r+");
    if (!f) return __LINE__;

    rgb *image = malloc(header.width * header.height * sizeof(rgb));
    if (!image) {
        fclose(f);
        return __LINE__;
    }
    fseek(f, 54, SEEK_SET);
    fread(image, header.width * header.height * sizeof(rgb), 1, f);
    fclose(f);

    for (unsigned int i = 0; i < header.width * header.height; i++) {
        uint8_t r = 255 - image[i].r;
        uint8_t g = 255 - image[i].g;
        uint8_t b = 255 - image[i].b;

        image[i].r = r;
        image[i].g = g;
        image[i].b = b;
    }

    f = fopen(argv[1], "r+");
    if (!f) {
        free(image);
        return __LINE__;
    }

    fseek(f, 54, SEEK_SET);
    memsetpar(image, 0, header.width * header.height * sizeof(rgb));
    fwrite(image, header.width * header.height * sizeof(rgb), 1, f);
    fclose(f);

    free(image);
    return 0;
}