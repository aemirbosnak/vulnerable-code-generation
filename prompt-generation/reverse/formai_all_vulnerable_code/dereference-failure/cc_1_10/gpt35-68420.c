//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80  // width of the output ASCII art
#define HEIGHT 40  // height of the output ASCII art

// This function converts a color pixel to a grayscale intensity value
unsigned char pixelToGray(unsigned char* pixel) {
    return (unsigned char)((0.299 * pixel[0]) + (0.587 * pixel[1]) + (0.114 * pixel[2]));
}

// This function converts an RGB image to grayscale and generates ASCII art
char* imageToASCII(char* filename) {
    // load the input image file
    FILE* fp = fopen(filename, "rb");
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = (4 - (width * 3) % 4) % 4;

    unsigned char* data = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);
    fread(data, sizeof(unsigned char), width * height * 3, fp);
    fclose(fp);

    // convert RGB image to grayscale
    unsigned char* gray = (unsigned char*)malloc(sizeof(unsigned char) * width * height);
    for (int i = 0; i < width * height; i++) {
        gray[i] = pixelToGray(&data[i * 3]);
    }

    // scale the grayscale values to fit in the 95 characters of our ASCII art
    char ascii[] = " .:-=+*#%@";
    int scale = 256 / (strlen(ascii) - 1);

    // generate the ASCII art
    char* art = (char*)malloc(sizeof(char) * (WIDTH * HEIGHT + HEIGHT + 1));
    int pos = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int pixel = gray[((y * height) / HEIGHT) * width + ((x * width) / WIDTH)];
            int index = pixel / scale;
            art[pos++] = ascii[index];
        }
        art[pos++] = '\n';
    }
    art[pos] = '\0';

    free(gray);
    free(data);
    return art;
}

int main() {
    char* filename = "example.jpg";
    char* ascii = imageToASCII(filename);
    printf("%s\n", ascii);
    free(ascii);
    return 0;
}