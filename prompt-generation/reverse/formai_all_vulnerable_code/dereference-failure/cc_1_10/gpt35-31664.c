//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200

char ascii_chars[] = {'@', '#', 'S', '%', '?', '*', '/', ';', ':', ',', '.'};
int num_chars = 10;

void convert_to_ascii(int *image_data, int width, int height) {
    int pixels_per_char = 256 / num_chars;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_avg = (image_data[i * width + j] >> 16) & 0xff;
            int char_index = pixel_avg / pixels_per_char;
            printf("%c", ascii_chars[char_index]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int width = 0, height = 0, maxval = 0;

    int pixels[MAX_WIDTH * MAX_WIDTH];

    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == '#') continue; // ignore comments
        if (line[0] == 'P' && line[1] == '6') continue; // ignore format

        if (width == 0 && height == 0) {
            sscanf(line, "%d %d", &width, &height);
        } else if (maxval == 0) {
            sscanf(line, "%d", &maxval);
        } else {
            char *ptr = line;
            for (int i = 0; i < width; i++) {
                int red = (int) *ptr++; // red channel
                int green = (int) *ptr++; // green channel
                int blue = (int) *ptr++; // blue channel
                int pixel_value = ((red << 16) & 0xff0000) | ((green << 8) & 0xff00) | (blue & 0xff);
                pixels[(height - 1) * width + i] = pixel_value;
            }
            height--;
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    convert_to_ascii(pixels, width, height);

    return 0;
}