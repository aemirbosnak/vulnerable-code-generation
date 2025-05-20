//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?~"

struct pixel {
    int x, y;
    char value;
};

void print_image(char* image, int width, int height) {
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            printf("%c", image[y * width + x]);
        }
        printf("\n");
    }
}

void convert_to_ascii(char* image, int width, int height, char* ascii) {
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int pixel_value = image[y * width + x];
            int ascii_index = pixel_value % strlen(CHAR_SET);
            ascii[y * width + x] = CHAR_SET[ascii_index];
        }
    }
}

int main() {
    // Load image
    FILE* fp = fopen("image.bmp", "rb");
    if(fp == NULL) {
        printf("Error loading image\n");
        return 1;
    }

    fseek(fp, 18, SEEK_SET);
    int width, height;
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);

    char* image = (char*)malloc(width * height * 3);
    fread(image, 3, width * height, fp);

    fclose(fp);

    // Convert to ASCII art
    char* ascii = (char*)malloc(width * height);
    convert_to_ascii(image, width, height, ascii);

    // Print ASCII art
    print_image(ascii, width, height);

    free(image);
    free(ascii);

    return 0;
}