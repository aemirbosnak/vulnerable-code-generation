//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>

#define WIDTH 80 // Set the width of ASCII art output
#define HEIGHT 60 // Set the height of ASCII art output

// Function to convert pixel brightness to character
char brightnessToChar(int brightness) {
    char chars[] = {' ', '.', '*', ':', 'o', '&', 'O', '8', '#', '@'};
    int numChars = sizeof(chars)/sizeof(chars[0]);
    int index = brightness * numChars / 256;
    return chars[index];
}

int main() {
    // Read in image file
    FILE *fp = fopen("image.ppm", "rb");
    char buffer[100];
    fgets(buffer, 100, fp); // Read magic number
    fgets(buffer, 100, fp); // Read comment
    fgets(buffer, 100, fp); // Read width, height, and maxval
    int width, height, maxVal;
    sscanf(buffer, "%d %d %d", &width, &height, &maxVal);

    // Calculate scaling factor based on image dimensions and desired output size
    float scaleX = (float)width / WIDTH;
    float scaleY = (float)height / HEIGHT;
    float scale = scaleX > scaleY ? scaleX : scaleY;

    // Loop over pixels and convert to ASCII art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Calculate average brightness of pixels in corresponding area of original image
            int totalBrightness = 0;
            int numPixels = 0;
            for (int i = 0; i < scale; i++) {
                for (int j = 0; j < scale; j++) {
                    int origX = x * scale + j;
                    int origY = y * scale + i;
                    if (origX < width && origY < height) {
                        fseek(fp, 3*(origY*width+origX)+3, SEEK_SET); // Seek to pixel in image file
                        int r, g, b;
                        fread(&r, 1, 1, fp); // Read red component
                        fread(&g, 1, 1, fp); // Read green component
                        fread(&b, 1, 1, fp); // Read blue component
                        int brightness = (r + g + b) / 3;
                        totalBrightness += brightness;
                        numPixels++;
                    }
                }
            }
            int avgBrightness = totalBrightness / numPixels;

            // Convert brightness to ASCII character and print
            char c = brightnessToChar(avgBrightness);
            putchar(c);
        }
        putchar('\n');
    }

    fclose(fp);

    return 0;
}