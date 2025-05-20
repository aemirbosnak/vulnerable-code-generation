//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40

unsigned char *load_bmp(char *filename, int *width, int *height);
void print_ascii_art(unsigned char *bitmap, int width, int height);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [bitmap file]\n", argv[0]);
        return 1;
    }

    int width, height;
    unsigned char *bitmap = load_bmp(argv[1], &width, &height);

    if (bitmap == NULL) {
        printf("Error loading bitmap!\n");
        return 1;
    }

    print_ascii_art(bitmap, width, height);

    free(bitmap);
    return 0;
}

void print_ascii_art(unsigned char *bitmap, int width, int height) {
    const char *ascii_chars = "@#*+=-:. ";

    for (int y = 0; y < height; y += 2) {
        for (int x = 0; x < width; x++) {
            int r = bitmap[(y * width + x) * 3 + 2];
            int g = bitmap[(y * width + x) * 3 + 1];
            int b = bitmap[(y * width + x) * 3];

            int gray = 0.2126 * r + 0.7152 * g + 0.0722 * b;
            int char_index = gray * strlen(ascii_chars) / 256;
            printf("%c", ascii_chars[char_index]);
        }
        printf("\n");
    }
}

unsigned char *load_bmp(char *filename, int *width, int *height) {
    FILE *fp;
    unsigned char *data;
    int data_size;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    fseek(fp, 10, SEEK_SET);
    fread(&data_size, 4, 1, fp);
    fseek(fp, 18, SEEK_SET);
    fread(width, 4, 1, fp);
    fread(height, 4, 1, fp);
    fseek(fp, 54, SEEK_SET);

    data = (unsigned char *)malloc(data_size);
    if (data == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(data, data_size, 1, fp);
    fclose(fp);

    return data;
}