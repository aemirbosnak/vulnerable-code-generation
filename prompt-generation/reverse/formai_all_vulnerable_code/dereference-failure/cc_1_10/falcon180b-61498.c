//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
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
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(filesize);
    if (!data) {
        printf("Error: could not allocate memory for image data\n");
        exit(1);
    }

    fread(data, filesize, 1, fp);
    fclose(fp);

    return (Image) {
       .data = data,
       .width = WIDTH,
       .height = HEIGHT
    };
}

void print_ascii_art(const Image *image) {
    for (int y = 0; y < image->height; ++y) {
        for (int x = 0; x < image->width; ++x) {
            int value = *(image->data + y * image->width + x) / 32;
            putchar(value % 10 + '0');
        }
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image image = load_image(argv[1]);
    print_ascii_art(&image);

    FILE *fp = fopen(argv[2], "w");
    if (!fp) {
        printf("Error: could not open file '%s' for writing\n", argv[2]);
        return 1;
    }

    fwrite(image.data, image.width * image.height, 1, fp);
    fclose(fp);

    printf("ASCII art saved to '%s'\n", argv[2]);

    return 0;
}