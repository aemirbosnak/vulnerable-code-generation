//FormAI DATASET v1.0 Category: Image Classification system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

/* Data structure to store an image */
struct image {
    int width;
    int height;
    int channels;
    unsigned char *data;
};

/* Function to read an image from file */
struct image read_image(const char *filename) {
    struct image img;
    FILE *fp = fopen(filename, "rb");

    /* Read the width and height */
    fread(&img.width, sizeof(int), 1, fp);
    fread(&img.height, sizeof(int), 1, fp);

    /* Read the number of channels */
    fread(&img.channels, sizeof(int), 1, fp);

    /* Calculate the size of the image data */
    int size = img.width * img.height * img.channels;

    /* Allocate memory for the image data */
    img.data = (unsigned char*) malloc(size);

    /* Read the image data */
    fread(img.data, sizeof(unsigned char), size, fp);

    /* Close the file */
    fclose(fp);

    return img;
}

/* Function to classify an image */
int classify_image(struct image img) {
    int red_pixels = 0;
    int green_pixels = 0;
    int blue_pixels = 0;

    /* Count the number of pixels of each color */
    for (int i = 0; i < img.width * img.height * img.channels; i += img.channels) {
        if (img.data[i] == 255) {
            red_pixels++;
        } else if (img.data[i + 1] == 255) {
            green_pixels++;
        } else if (img.data[i + 2] == 255) {
            blue_pixels++;
        }
    }

    /* Return the color with the most pixels */
    if (red_pixels > green_pixels && red_pixels > blue_pixels) {
        return 0;
    } else if (green_pixels > red_pixels && green_pixels > blue_pixels) {
        return 1;
    } else {
        return 2;
    }
}

/* Main function */
int main(int argc, char *argv[]) {
    /* Check if the correct number of arguments was provided */
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    /* Read the image from file */
    struct image img = read_image(argv[1]);

    /* Classify the image */
    int class_id = classify_image(img);

    /* Print the result */
    if (class_id == 0) {
        printf("The image is mostly red.\n");
    } else if (class_id == 1) {
        printf("The image is mostly green.\n");
    } else {
        printf("The image is mostly blue.\n");
    }

    /* Free the memory used by the image data */
    free(img.data);

    return 0;
}