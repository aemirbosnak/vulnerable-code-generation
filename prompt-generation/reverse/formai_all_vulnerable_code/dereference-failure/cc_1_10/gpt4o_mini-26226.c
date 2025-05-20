//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 70
#define CHAR_MAPPER " .:-+*%#@"
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

Image* loadPGM(const char* filename) {
    FILE* pgmFile = fopen(filename, "rb");
    if (!pgmFile) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    }

    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), pgmFile)) {
        fprintf(stderr, "Error: Invalid PGM file.\n");
        fclose(pgmFile);
        return NULL;
    }
    
    if (strncmp(buffer, "P5", 2) != 0) {
        fprintf(stderr, "Error: Not a PGM P5 file.\n");
        fclose(pgmFile);
        return NULL;
    }

    int width, height, maxval;
    fscanf(pgmFile, "%d %d %d", &width, &height, &maxval);
    fgetc(pgmFile);  // Read the newline character after maxval

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Error: Image size exceeds max dimensions.\n");
        fclose(pgmFile);
        return NULL;
    }

    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height);

    fread(img->data, 1, width * height, pgmFile);
    fclose(pgmFile);
    return img;
}

void freeImage(Image* img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

char getAsciiChar(unsigned char pixel) {
    return CHAR_MAPPER[pixel * (strlen(CHAR_MAPPER) - 1) / 255];
}

void convertToAscii(Image* img) {
    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            unsigned char pixel = img->data[y * img->width + x];
            putchar(getAsciiChar(pixel));
        }
        putchar('\n');
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image* img = loadPGM(argv[1]);
    if (!img) {
        return EXIT_FAILURE;
    }

    convertToAscii(img);
    freeImage(img);

    return EXIT_SUCCESS;
}