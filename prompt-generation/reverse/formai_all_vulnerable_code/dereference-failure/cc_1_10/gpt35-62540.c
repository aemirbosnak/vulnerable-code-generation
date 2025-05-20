//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH_FACTOR 2
#define PIXEL_FACTOR 3

void generate_ascii_art(unsigned char* image, int width, int height){
    char ascii_chars[] =  "$$B%8&WM#*oahkbdpqwmZO0QLCJYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
    int num_chars = strlen(ascii_chars);
    char ascii_art[height*WIDTH_FACTOR][width*PIXEL_FACTOR];
    memset(ascii_art, ' ', height*WIDTH_FACTOR*width*PIXEL_FACTOR*sizeof(char));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int gray = (int)image[i*width+j];
            int index = ((num_chars-1)*gray)/255;
            char c = ascii_chars[index];
            ascii_art[i*WIDTH_FACTOR][j*PIXEL_FACTOR] = c;
            ascii_art[i*WIDTH_FACTOR+1][j*PIXEL_FACTOR] = c;
            ascii_art[i*WIDTH_FACTOR][(j*PIXEL_FACTOR)+1] = c;
            ascii_art[i*WIDTH_FACTOR+1][(j*PIXEL_FACTOR)+1] = c;
            ascii_art[i*WIDTH_FACTOR][(j*PIXEL_FACTOR)+2] = c;
            ascii_art[i*WIDTH_FACTOR+1][(j*PIXEL_FACTOR)+2] = c;
        }
    }

    for (int i = 0; i < height*WIDTH_FACTOR; i++) {
        for (int j = 0; j < width*PIXEL_FACTOR; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *f = fopen("example_image.pgm", "rb");
    if (!f) {
        perror("Could not open file");
        return 1;
    }

    char buffer[100];
    fgets(buffer, 100, f);
    if (strncmp(buffer, "P5", 2)) {
        fprintf(stderr, "Invalid file format");
        return 1;
    }

    fgets(buffer, 100, f);
    int width, height;
    sscanf(buffer, "%d %d", &width, &height);

    fgets(buffer, 100, f);
    int maxval;
    sscanf(buffer, "%d", &maxval);
    if (maxval > 255) {
        fprintf(stderr, "Invalid Maxval");
        return 1;
    }

    unsigned char* image = (unsigned char*) malloc(width*height*sizeof(unsigned char));
    fread(image, sizeof(unsigned char), width*height, f);
    fclose(f);

    generate_ascii_art(image, width, height);

    free(image);
    return 0;
}