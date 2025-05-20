//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} Image;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    unsigned char *buffer = malloc(filesize);
    if (!buffer) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }

    if (fread(buffer, 1, filesize, fp)!= filesize) {
        fprintf(stderr, "Error: Could not read file '%s'\n", filename);
        exit(1);
    }

    fclose(fp);

    int width, height;
    unsigned int header_size = *(unsigned int*)buffer;
    buffer += header_size;

    if (memcmp(buffer, "BM", 2)!= 0) {
        fprintf(stderr, "Error: File '%s' is not a valid BMP image\n", filename);
        exit(1);
    }

    buffer += 10;
    width = *(int*)buffer;
    buffer += 4;
    height = *(int*)buffer;

    Image image = {buffer + header_size, width, height};
    return image;
}

void print_ascii_art(const Image *image) {
    const unsigned char *data = image->data;
    int width = image->width;
    int height = image->height;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int value = data[y * width + x];

            if (value == 0) {
                printf(" ");
            } else if (value == 0xFF) {
                printf("X");
            } else {
                printf("%c", 'A' + (value >> 4));
            }
        }

        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s input_image output_ascii_art\n", argv[0]);
        return 1;
    }

    Image image = load_image(argv[1]);
    const char *output_filename = argv[2];

    FILE *fp = fopen(output_filename, "w");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file '%s' for writing\n", output_filename);
        exit(1);
    }

    print_ascii_art(&image);

    fclose(fp);

    printf("ASCII art saved to '%s'\n", output_filename);

    return 0;
}