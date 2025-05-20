//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 64
#define HEIGHT 64
#define MAX_COLORS 256

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    Color colors[MAX_COLORS];
    unsigned char data[WIDTH * HEIGHT];
} PixelArt;

PixelArt *pixel_art_new() {
    PixelArt *pa = malloc(sizeof(PixelArt));
    memset(pa, 0, sizeof(PixelArt));
    return pa;
}

void pixel_art_free(PixelArt *pa) {
    free(pa);
}

int pixel_art_load(PixelArt *pa, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return -1;
    }

    // Read the header
    unsigned char header[14];
    if (fread(header, 1, 14, fp) != 14) {
        fclose(fp);
        return -1;
    }

    // Check the header
    if (header[0] != 'B' || header[1] != 'M') {
        fclose(fp);
        return -1;
    }

    // Read the image data
    unsigned char *data = malloc(WIDTH * HEIGHT * 3);
    if (!data) {
        fclose(fp);
        return -1;
    }

    if (fread(data, 1, WIDTH * HEIGHT * 3, fp) != WIDTH * HEIGHT * 3) {
        fclose(fp);
        free(data);
        return -1;
    }

    fclose(fp);

    // Convert the image data to the pixel art format
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        pa->data[i] = data[(i * 3) + 2];
    }

    free(data);

    return 0;
}

int pixel_art_save(const PixelArt *pa, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return -1;
    }

    // Write the header
    unsigned char header[14] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0
    };
    header[2] = (unsigned char) (WIDTH * HEIGHT * 3 + 14);
    header[10] = (unsigned char) (WIDTH * HEIGHT * 3);
    if (fwrite(header, 1, 14, fp) != 14) {
        fclose(fp);
        return -1;
    }

    // Write the image data
    if (fwrite(pa->data, 1, WIDTH * HEIGHT * 3, fp) != WIDTH * HEIGHT * 3) {
        fclose(fp);
        return -1;
    }

    fclose(fp);

    return 0;
}

int pixel_art_color_count(const PixelArt *pa) {
    int count = 0;
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (pa->data[i] != 0) {
            count++;
        }
    }
    return count;
}

Color pixel_art_get_color(const PixelArt *pa, int index) {
    if (index < 0 || index >= MAX_COLORS) {
        return (Color) {0, 0, 0};
    }
    return pa->colors[index];
}

int pixel_art_set_color(PixelArt *pa, int index, Color color) {
    if (index < 0 || index >= MAX_COLORS) {
        return -1;
    }
    pa->colors[index] = color;
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    PixelArt *pa = pixel_art_new();
    if (!pa) {
        printf("Error: Could not allocate memory for pixel art\n");
        return 1;
    }

    if (pixel_art_load(pa, argv[1]) != 0) {
        printf("Error: Could not load pixel art from file\n");
        pixel_art_free(pa);
        return 1;
    }

    int color_count = pixel_art_color_count(pa);
    printf("%d colors found in pixel art\n", color_count);

    for (int i = 0; i < color_count; i++) {
        Color color = pixel_art_get_color(pa, i);
        printf("Color %d: %d, %d, %d\n", i, color.r, color.g, color.b);
    }

    pixel_art_free(pa);

    return 0;
}