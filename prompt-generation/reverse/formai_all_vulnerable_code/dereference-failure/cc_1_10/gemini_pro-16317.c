//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Remember, a picture is worth a thousand bytes. Let's create some space for our artistic endeavors!
typedef struct {
    int width, height, channels;
    unsigned char *data;
} Image;

// Every journey begins with a blank canvas. Let's create a new image for our masterpiece.
Image *new_image(int width, int height, int channels) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->channels = channels;
    image->data = malloc(width * height * channels);
    return image;
}

// Lo and behold, our pixel magician! The ability to read and write the secrets hidden within an image.
void read_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }
    fread(image->data, image->width * image->height * image->channels, 1, fp);
    fclose(fp);
}

// Beware, for a flip can change the fate of pixels forever!
void flip_image(Image *image) {
    int i, j, k;
    for (i = 0; i < image->height / 2; i++) {
        for (j = 0; j < image->width; j++) {
            for (k = 0; k < image->channels; k++) {
                // Swapping pixels is like a dance, a graceful exchange of colors and intensities.
                unsigned char temp = image->data[i * image->width * image->channels + j * image->channels + k];
                image->data[i * image->width * image->channels + j * image->channels + k] = image->data[(image->height - i - 1) * image->width * image->channels + j * image->channels + k];
                image->data[(image->height - i - 1) * image->width * image->channels + j * image->channels + k] = temp;
            }
        }
    }
}

// Now, let's delve into the realms of illumination, where darkness bows to the dance of light.
void adjust_brightness(Image *image, float brightness) {
    // Brightness enhancement: a subtle touch to illuminate your images.
    int i, j, k;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            for (k = 0; k < image->channels; k++) {
                // Each pixel, a tiny world of colors, glows brighter or softer as we command.
                image->data[i * image->width * image->channels + j * image->channels + k] = (unsigned char) fmin(255, image->data[i * image->width * image->channels + j * image->channels + k] + brightness);
            }
        }
    }
}

// A twist of contrast, like a dash of spice added to your visual feast.
void adjust_contrast(Image *image, float contrast) {
    // Contrast manipulation: enhancing the drama and definition of your images.
    int i, j, k;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            for (k = 0; k < image->channels; k++) {
                // Pixels dance to the rhythm of contrast, their intensity reaching new heights.
                image->data[i * image->width * image->channels + j * image->channels + k] = (unsigned char) fmin(255, image->data[i * image->width * image->channels + j * image->channels + k] * contrast);
            }
        }
    }
}

// Our journey's end, where the canvas of pixels transforms into a masterpiece.
void write_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }
    fwrite(image->data, image->width * image->height * image->channels, 1, fp);
    fclose(fp);
}

// The grand finale, where dreams become reality. Let the digital tapestry unfold before your eyes!
int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <input image> <output image> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    // Unveil the hidden image, ready to be transformed by our artistic touch.
    Image *image = new_image(1920, 1080, 3);
    read_image(image, argv[1]);

    // Flip it like a seasoned photographer, capturing a new perspective.
    flip_image(image);

    // Adjust the brightness, like a master of illumination.
    float brightness = atof(argv[3]);
    adjust_brightness(image, brightness);

    // Enhance the contrast, like a virtuoso of shadows and highlights.
    float contrast = atof(argv[4]);
    adjust_contrast(image, contrast);

    // Preserve the masterpiece for eternity, a digital treasure to be admired.
    write_image(image, argv[2]);

    // Our odyssey concludes, but the realm of image processing remains a boundless canvas for your creativity. Farewell, fellow pixel adventurer!
    free(image->data);
    free(image);
    return 0;
}