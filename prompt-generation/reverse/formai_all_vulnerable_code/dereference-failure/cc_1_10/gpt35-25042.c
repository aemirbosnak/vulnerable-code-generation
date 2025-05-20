//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    char *pixels;
    int width;
    int height;
} Image;

char* ascii_chars = "@#S%?*+/:-.";

Image* read_image(char *filename);
char get_ascii_char(char pixel);
void convert_to_ascii(Image *image);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ascii_converter <filename>\n");
        exit(1);
    }

    Image *image = read_image(argv[1]);
    convert_to_ascii(image);

    return 0;
}

Image* read_image(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    char buffer[MAX_WIDTH+2];
    int width = 0, height = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
            len--;
        }

        if (width == 0) {
            width = len;
        } else if (width != len) {
            printf("Invalid image size.\n");
            exit(1);
        }

        height++;
    }

    Image *image = (Image*) malloc(sizeof(Image));
    image->pixels = (char*) malloc(width * height + 1);

    rewind(file);

    int index = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
            len--;
        }

        strncpy(image->pixels + index, buffer, len);
        index += width;
    }

    image->width = width;
    image->height = height;

    fclose(file);

    return image;
}

char get_ascii_char(char pixel) {
    int num_chars = strlen(ascii_chars);
    int index = (int)(pixel / 255.0 * num_chars);
    return ascii_chars[index];
}

void convert_to_ascii(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            char pixel = *(image->pixels + y * image->width + x);
            char ascii_char = get_ascii_char(pixel);
            putchar(ascii_char);
        }
        putchar('\n');
    }
}