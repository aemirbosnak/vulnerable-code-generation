//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS " .:-=+*%@#"

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel pixels[MAX_HEIGHT][MAX_WIDTH];
} Image;

void load_image(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    
    img->width = *(int*)&header[18];
    img->height = *(int*)&header[22];
    
    if (img->width > MAX_WIDTH || img->height > MAX_HEIGHT) {
        fprintf(stderr, "Error: Image dimensions exceed maximum allowed size.\n");
        fclose(fp);
        exit(1);
    }
    
    int size = img->width * img->height * 3;
    unsigned char *data = (unsigned char*)malloc(size);
    fread(data, sizeof(unsigned char), size, fp);
    
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel_index = (y * img->width + x) * 3;
            img->pixels[y][x].b = data[pixel_index];
            img->pixels[y][x].g = data[pixel_index + 1];
            img->pixels[y][x].r = data[pixel_index + 2];
        }
    }

    free(data);
    fclose(fp);
}

char get_ascii_char(Pixel pixel) {
    float brightness = (0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b) / 255.0;
    int index = (int)(brightness * (strlen(ASCII_CHARS) - 1));
    return ASCII_CHARS[index];
}

void convert_to_ascii(const Image *img) {
    printf("Generating ASCII Art:\n");
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            char ascii_char = get_ascii_char(img->pixels[y][x]);
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file.bmp>\n", argv[0]);
        exit(1);
    }

    Image img;
    load_image(argv[1], &img);
    convert_to_ascii(&img);

    return 0;
}