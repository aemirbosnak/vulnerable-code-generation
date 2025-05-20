//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *scale_to_ascii(int scale);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image>\n", argv[0]);
        return 1;
    }

    const char *image_path = argv[1];
    FILE *f = fopen(image_path, "rb");
    if (!f) {
        printf("Failed to open %s\n", image_path);
        return 1;
    }

    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    unsigned char *img = malloc(fsize);
    fread(img, fsize, 1, f);
    fclose(f);

    int width = img[18] + (img[19] << 8);
    int height = img[22] + (img[23] << 8);
    int bits_per_pixel = img[28];

    printf("Image width: %d\n", width);
    printf("Image height: %d\n", height);
    printf("Bits per pixel: %d\n", bits_per_pixel);

    int padding = (4 - (width * (bits_per_pixel / 8)) % 4) % 4;

    int scale = 5;

    char *ascii_img = scale_to_ascii(scale);

    int x, y, i;
    char c;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            i = (y * width + x) * (bits_per_pixel / 8);
            c = ascii_img[(img[i] + img[i + 1] + img[i + 2]) / 3 / (256 / strlen(ascii_img))];

            printf("%c%c", c, c);
        }
        for (i = 0; i < padding; i++) {
            printf(" ");
        }
        printf("\n");
    }

    free(img);
    free(ascii_img);
    return 0;
}

char *scale_to_ascii(int scale) {
    char *ascii_arr = malloc(sizeof(char) * scale * scale + 1);
    int x, y, i;
    for (y = 0; y < scale; y++) {
        for (x = 0; x < scale; x++) {
            i = y * scale + x;
            if (i < scale * scale / 2) {
                ascii_arr[i] = (char) (33 + (i * 94) / (scale * scale / 2));
            } else {
                ascii_arr[i] = (char) (32 + ((i - scale * scale / 2) * 94) / (scale * scale / 2));
            }
        }
    }
    ascii_arr[scale * scale] = '\0';
    return ascii_arr;
}