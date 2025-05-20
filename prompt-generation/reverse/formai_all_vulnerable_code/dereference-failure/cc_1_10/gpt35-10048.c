//FormAI DATASET v1.0 Category: Image Editor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480

// function to check if pixel is within image bounds
int isWithinBounds(int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

// function to set RGB values of a pixel
void setPixel(int* image, int x, int y, int red, int green, int blue) {
    int offset = (y * WIDTH + x) * 3;
    if (isWithinBounds(x, y)) {
        image[offset] = red;
        image[offset + 1] = green;
        image[offset + 2] = blue;
    }
}

int main() {
    // allocate memory for image
    int* image = calloc(WIDTH * HEIGHT * 3, sizeof(int));

    // set background color to blue
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            setPixel(image, i, j, 0, 0, 255);
        }
    }

    // draw a smiley face
    setPixel(image, 200, 200, 255, 255, 0);
    setPixel(image, 400, 200, 255, 255, 0);
    for (int i = 250; i <= 350; i++) {
        setPixel(image, i, 350, 255, 255, 0);
    }
    for (int i = 200; i <= 400; i++) {
        for (int j = 150; j <= 250; j++) {
            int distance = ((i - 300) * (i - 300)) + ((j - 200) * (j - 200));
            if (distance <= 2500) {
                setPixel(image, i, j, 255, 255, 0);
            }
        }
    }

    // save image to file
    FILE* outfile = fopen("smiley.ppm", "wb");
    fprintf(outfile, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(char), WIDTH * HEIGHT * 3, outfile);
    fclose(outfile);

    // free memory
    free(image);

    return 0;
}