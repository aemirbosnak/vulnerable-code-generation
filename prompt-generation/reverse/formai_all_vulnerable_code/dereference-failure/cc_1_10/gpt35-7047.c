//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480

// Function to flip the image horizontally
void flipImage(unsigned char *image, unsigned char *flippedImage)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int offset = (i * WIDTH + j) * 3;
            int flippedOffset = (i * WIDTH + (WIDTH - j - 1)) * 3;

            flippedImage[flippedOffset] = image[offset];
            flippedImage[flippedOffset + 1] = image[offset + 1];
            flippedImage[flippedOffset + 2] = image[offset + 2];
        }
    }
}

// Function to change the brightness of the image
void changeBrightness(unsigned char *image, unsigned char *brightImage, int brightness)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int offset = (i * WIDTH + j) * 3;

            int red = image[offset];
            int green = image[offset + 1];
            int blue = image[offset + 2];

            // Calculate the new brightness value for each color channel
            red = (int)((float)red * ((float)brightness / 255.0));
            green = (int)((float)green * ((float)brightness / 255.0));
            blue = (int)((float)blue * ((float)brightness / 255.0));

            // Clip the values to stay within the valid range of 0 - 255
            red = (red < 0) ? 0 : ((red > 255) ? 255 : red);
            green = (green < 0) ? 0 : ((green > 255) ? 255 : green);
            blue = (blue < 0) ? 0 : ((blue > 255) ? 255 : blue);

            brightImage[offset] = red;
            brightImage[offset + 1] = green;
            brightImage[offset + 2] = blue;
        }
    }
}

int main()
{
    // Allocate memory for the image
    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT * 3);
    unsigned char *flippedImage = (unsigned char *)malloc(WIDTH * HEIGHT * 3);
    unsigned char *brightImage = (unsigned char *)malloc(WIDTH * HEIGHT * 3);

    // Read the image data from a file into memory
    FILE *fp = fopen("image.bin", "rb");
    fread(image, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    // Flip the image
    flipImage(image, flippedImage);

    // Change the brightness of the image
    int brightness = 200; // Set the brightness value to 200
    changeBrightness(image, brightImage, brightness);

    // Write the flipped image to a new file
    fp = fopen("flippedImage.bin", "wb");
    fwrite(flippedImage, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    // Write the brightened image to a new file
    fp = fopen("brightImage.bin", "wb");
    fwrite(brightImage, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    // Free the allocated memory
    free(image);
    free(flippedImage);
    free(brightImage);

    return 0;
}