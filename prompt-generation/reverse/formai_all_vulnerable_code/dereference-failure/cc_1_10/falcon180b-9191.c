//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 25

char* load_image(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* buffer = malloc(filesize);
    if (!buffer) {
        printf("Error: Could not allocate memory\n");
        exit(1);
    }

    fread(buffer, filesize, 1, fp);
    fclose(fp);

    return buffer;
}

void print_ascii_art(char* buffer, int x, int y) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            int index = (i * WIDTH + j) * 3;

            int r = buffer[index] * 0.299 + buffer[index + 1] * 0.587 + buffer[index + 2] * 0.114;
            char c = (r > 127)? '*' : (r > 63)? ':' : '.';

            printf("%c", c);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    char* buffer = load_image(argv[1]);
    if (!buffer) {
        return 1;
    }

    print_ascii_art(buffer, 0, 0);

    free(buffer);
    return 0;
}