//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <image_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    unsigned char *buffer = malloc(filesize);
    if (buffer == NULL) {
        printf("Error: Cannot allocate memory.\n");
        fclose(fp);
        return 1;
    }

    fread(buffer, filesize, 1, fp);
    fclose(fp);

    FILE *outfp = fopen(argv[2], "w");
    if (outfp == NULL) {
        printf("Error: Cannot open output file.\n");
        free(buffer);
        return 1;
    }

    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int value = buffer[(y * WIDTH + x) * 3];
            char c = (value < 128)? value + 33 : '.';
            fprintf(outfp, "%c", c);
        }
        fprintf(outfp, "\n");
    }

    free(buffer);
    fclose(outfp);

    printf("Done.\n");
    return 0;
}