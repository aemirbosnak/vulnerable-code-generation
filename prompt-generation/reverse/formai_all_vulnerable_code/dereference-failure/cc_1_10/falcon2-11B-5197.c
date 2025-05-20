//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

void convert_image(const char* filename, int pixSize) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file\n");
        return;
    }
    
    int width = 0, height = 0;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    fread(&pixSize, sizeof(int), 1, file);
    
    int* pixels = (int*)malloc(width * height * pixSize * sizeof(int));
    if (!pixels) {
        printf("Error allocating memory\n");
        return;
    }
    
    fread(pixels, sizeof(int), width * height * pixSize, file);
    fclose(file);
    
    int ascii_art[width][height];
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (pixSize == 3) {
                if (pixels[i * height + j] == 0) {
                    ascii_art[i][j] = '\n';
                } else if (pixels[i * height + j] == 1) {
                    ascii_art[i][j] = '*';
                } else if (pixels[i * height + j] == 2) {
                    ascii_art[i][j] = 'o';
                } else if (pixels[i * height + j] == 3) {
                    ascii_art[i][j] = '-';
                } else if (pixels[i * height + j] == 4) {
                    ascii_art[i][j] = 'x';
                }
            }
        }
    }
    
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    const char* filename = "image.bmp";
    int pixSize = 3;
    
    convert_image(filename, pixSize);
    
    return 0;
}