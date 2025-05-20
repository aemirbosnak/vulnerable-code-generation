//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

typedef struct {
    unsigned int width;
    unsigned int height;
    pixel* pixels;
} image;

unsigned char get_bit(unsigned char num, int pos) {
    return (num >> pos) & 1;
}

void set_bit(unsigned char* num, int pos, unsigned char bit) {
    *num &= ~(1 << pos);
    *num |= (bit << pos);
}

image* read_image(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    unsigned char header[54];
    fread(header, 1, 54, file);

    unsigned int width = *(unsigned int*)(header + 18);
    unsigned int height = *(unsigned int*)(header + 22);

    pixel* pixels = malloc(width * height * sizeof(pixel));
    fread(pixels, 1, width * height * sizeof(pixel), file);

    fclose(file);

    image* img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->pixels = pixels;

    return img;
}

void write_image(char* filename, image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        return;
    }

    unsigned char header[54];
    memcpy(header, "\x42\x4D\x36\x58", 4);
    *(unsigned int*)(header + 2) = img->width * img->height * 3 + 54;
    memcpy(header + 10, "\x28\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x01\x00\x18\x00\x00\x00\x00\x00\x00\x00\x00\x00\xC0\x3E\x00\x00\xC0\x3E\x00\x00", 28);
    *(unsigned int*)(header + 18) = img->width;
    *(unsigned int*)(header + 22) = img->height;
    memcpy(header + 26, "\x01\x00\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 18);

    fwrite(header, 1, 54, file);
    fwrite(img->pixels, 1, img->width * img->height * sizeof(pixel), file);

    fclose(file);
}

int main() {
    image* img = read_image("image.bmp");
    if (!img) {
        printf("Could not read image.\n");
        return 1;
    }

    FILE* file = fopen("secret.txt", "rb");
    if (!file) {
        printf("Could not read secret file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    unsigned int secret_size = ftell(file);
    rewind(file);

    unsigned char* secret = malloc(secret_size);
    fread(secret, 1, secret_size, file);

    unsigned int bit_index = 0;
    for (unsigned int i = 0; i < img->width * img->height; i++) {
        unsigned char r = img->pixels[i].r;
        unsigned char g = img->pixels[i].g;
        unsigned char b = img->pixels[i].b;

        if (bit_index < secret_size * 8) {
            set_bit(&r, 0, get_bit(secret[bit_index / 8], bit_index % 8));
            bit_index++;
        }
        if (bit_index < secret_size * 8) {
            set_bit(&g, 0, get_bit(secret[bit_index / 8], bit_index % 8));
            bit_index++;
        }
        if (bit_index < secret_size * 8) {
            set_bit(&b, 0, get_bit(secret[bit_index / 8], bit_index % 8));
            bit_index++;
        }

        img->pixels[i].r = r;
        img->pixels[i].g = g;
        img->pixels[i].b = b;
    }

    fclose(file);

    write_image("output.bmp", img);

    printf("Secret data hidden in output.bmp.\n");

    free(img->pixels);
    free(img);

    return 0;
}