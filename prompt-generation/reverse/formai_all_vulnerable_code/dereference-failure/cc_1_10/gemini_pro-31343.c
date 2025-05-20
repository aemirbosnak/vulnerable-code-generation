//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: brave
// Welcome to the realm of image manipulation, dear adventurer!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Our trusty image structure, a canvas for our artistic endeavors
typedef struct Image {
    unsigned int width;
    unsigned int height;
    unsigned char* data;
} Image;

// Let's load an image from the depths of the digital world
Image* loadImage(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Alas! Could not find the image.\n");
        return NULL;
    }

    Image* img = malloc(sizeof(Image));

    // Seek the dimensions of the image
    fseek(fp, 18, SEEK_SET);
    fread(&img->width, sizeof(unsigned int), 1, fp);
    fread(&img->height, sizeof(unsigned int), 1, fp);

    // Now, let's allocate memory for the image data
    img->data = malloc(img->width * img->height * 3);

    // Time to fill our canvas with color!
    fseek(fp, 54, SEEK_SET);
    fread(img->data, img->width * img->height * 3, 1, fp);

    fclose(fp);
    return img;
}

// Shall we flip the image horizontally, like a mirror?
Image* flipHorizontal(Image* img) {
    // Let's create a duplicate canvas, its twin
    Image* flipped = malloc(sizeof(Image));
    flipped->width = img->width;
    flipped->height = img->height;
    flipped->data = malloc(flipped->width * flipped->height * 3);

    // Row by row, we'll swap the pixels
    for (unsigned int i = 0; i < flipped->height; i++) {
        for (unsigned int j = 0; j < flipped->width; j++) {
            int offset = i * flipped->width * 3 + j * 3;
            int flippedOffset = i * flipped->width * 3 + (flipped->width - j - 1) * 3;
            flipped->data[flippedOffset] = img->data[offset];
            flipped->data[flippedOffset + 1] = img->data[offset + 1];
            flipped->data[flippedOffset + 2] = img->data[offset + 2];
        }
    }

    return flipped;
}

// Now, let's adjust the brightness and contrast, like a brave photographer
Image* adjustBrightnessContrast(Image* img, double brightness, double contrast) {
    // A new canvas for our transformed masterpiece
    Image* adjusted = malloc(sizeof(Image));
    adjusted->width = img->width;
    adjusted->height = img->height;
    adjusted->data = malloc(adjusted->width * adjusted->height * 3);

    // Tweak the colors pixel by pixel, embracing the magic of math
    for (unsigned int i = 0; i < adjusted->height; i++) {
        for (unsigned int j = 0; j < adjusted->width; j++) {
            int offset = i * adjusted->width * 3 + j * 3;
            double r = img->data[offset];
            double g = img->data[offset + 1];
            double b = img->data[offset + 2];

            // Brightness adjustment, like adding light to the scene
            r += brightness;
            g += brightness;
            b += brightness;

            // Contrast enhancement, adding depth and detail
            r = (r - 128) * contrast + 128;
            g = (g - 128) * contrast + 128;
            b = (b - 128) * contrast + 128;

            // Clamp the values to keep them within the bounds of color
            r = fmin(fmax(r, 0), 255);
            g = fmin(fmax(g, 0), 255);
            b = fmin(fmax(b, 0), 255);

            adjusted->data[offset] = r;
            adjusted->data[offset + 1] = g;
            adjusted->data[offset + 2] = b;
        }
    }

    return adjusted;
}

// Time to save our masterpiece to the digital realm!
void saveImage(Image* img, char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Alas! Could not save the image.\n");
        return;
    }

    // Write the header information
    unsigned char header[54] = {0};
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + img->width * img->height * 3;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;
    header[26] = 1;
    header[28] = 24;
    fwrite(header, 54, 1, fp);

    // Write the pixel data
    fwrite(img->data, img->width * img->height * 3, 1, fp);

    fclose(fp);
}

// And now, let's showcase our image processing skills!
int main() {
    // Load our canvas from the depths of the file system
    Image* img = loadImage("image.bmp");
    if (!img) {
        return 1;
    }

    // Flip the image horizontally, like a mirror in the digital realm
    Image* flipped = flipHorizontal(img);

    // Adjust the brightness and contrast, enhancing the image's details
    Image* adjusted = adjustBrightnessContrast(flipped, 50, 1.5);

    // Save our transformed masterpiece to the digital world for all to behold
    saveImage(adjusted, "transformed.bmp");

    // Release our images back to the digital ether
    free(img->data);
    free(img);
    free(flipped->data);
    free(flipped);
    free(adjusted->data);
    free(adjusted);

    // And so, our image manipulation adventure ends. Until next time, brave adventurer!
    return 0;
}