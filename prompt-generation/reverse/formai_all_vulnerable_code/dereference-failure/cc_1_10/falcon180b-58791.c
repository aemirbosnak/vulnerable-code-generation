//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 20

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    char *buffer = malloc(filesize);
    if (buffer == NULL) {
        printf("Error: Could not allocate memory.\n");
        fclose(fp);
        return 1;
    }

    fread(buffer, filesize, 1, fp);
    fclose(fp);

    int pixels = filesize / 3;
    int x = 0, y = 0;
    int i = 0;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int r = buffer[i] & 0xFF;
            int g = buffer[i + 1] & 0xFF;
            int b = buffer[i + 2] & 0xFF;

            if (r < 128) {
                printf(" ");
            } else if (r < 256) {
                printf(".");
            } else {
                printf("X");
            }

            i += 3;
        }
        printf("\n");
    }

    free(buffer);
    return 0;
}