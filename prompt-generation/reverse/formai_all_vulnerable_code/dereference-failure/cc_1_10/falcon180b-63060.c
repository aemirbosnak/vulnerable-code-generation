//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS ".,-+*0123456789ABCDEF"

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

void load_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    image->data = malloc(filesize);
    fread(image->data, filesize, 1, fp);
    fclose(fp);

    image->width = filesize / image->height;
}

void save_ascii_art(const char *filename, const char *ascii_art) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    fwrite(ascii_art, strlen(ascii_art), 1, fp);
    fclose(fp);
}

void image_to_ascii_art(Image *image, char *ascii_art) {
    int x, y;
    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width; x++) {
            int pixel_value = image->data[y * image->width + x];
            int ascii_char_index = pixel_value * (strlen(ASCII_CHARS) - 1) / 255;
            ascii_art[y * MAX_WIDTH + x] = ASCII_CHARS[ascii_char_index];
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s input_image output_ascii_art\n", argv[0]);
        exit(1);
    }

    Image image;
    load_image(argv[1], &image);

    char ascii_art[MAX_HEIGHT * MAX_WIDTH];
    image_to_ascii_art(&image, ascii_art);

    save_ascii_art(argv[2], ascii_art);

    printf("Conversion complete!\n");

    return 0;
}