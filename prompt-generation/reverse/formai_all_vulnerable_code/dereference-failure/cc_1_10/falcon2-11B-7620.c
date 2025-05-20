//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_image_to_ascii(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[1024];
    int height = 0;
    int width = 0;
    char *ascii_image = NULL;
    int ascii_width = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        int count = 0;
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '\n') {
                height++;
                if (ascii_image!= NULL) {
                    ascii_width += 2;
                }
                ascii_image = realloc(ascii_image, ascii_width * sizeof(char));
            }
            if (line[i] == '*') {
                width++;
                if (ascii_image!= NULL) {
                    ascii_image[ascii_width++] = '*';
                }
                ascii_image[ascii_width++] = '\n';
            }
        }
    }

    if (ascii_image!= NULL) {
        fclose(file);
        printf("Converted image to ASCII art:\n");
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                printf("%c", ascii_image[ascii_width - 1 - j]);
            }
            printf("\n");
        }
    }

    free(ascii_image);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    convert_image_to_ascii(argv[1]);

    return 0;
}