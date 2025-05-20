//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
// A simple image processing program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the image structure
struct image {
    int width;
    int height;
    int channels;
    int **data;
};

// Flip the image horizontally
void flip_horizontal(struct image *img) {
    int width = img->width;
    int height = img->height;
    int **data = img->data;
    int tmp;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            tmp = data[i][j];
            data[i][j] = data[i][width - j - 1];
            data[i][width - j - 1] = tmp;
        }
    }
}

// Change the brightness and contrast of the image
void adjust_brightness_contrast(struct image *img, float brightness, float contrast) {
    int width = img->width;
    int height = img->height;
    int **data = img->data;
    int tmp;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            tmp = data[i][j];
            tmp = (tmp * contrast) + brightness;
            if (tmp < 0) tmp = 0;
            if (tmp > 255) tmp = 255;
            data[i][j] = tmp;
        }
    }
}

// Load the image from a file
struct image *load_image(char *filename) {
    struct image *img = (struct image *)malloc(sizeof(struct image));
    FILE *fp = fopen(filename, "r");
    char line[256];
    char *token;

    // Read the image width and height
    fgets(line, 256, fp);
    token = strtok(line, " ");
    img->width = atoi(token);
    token = strtok(NULL, " ");
    img->height = atoi(token);

    // Read the image data
    img->data = (int **)malloc(img->height * sizeof(int *));
    for (int i = 0; i < img->height; i++) {
        img->data[i] = (int *)malloc(img->width * sizeof(int));
        for (int j = 0; j < img->width; j++) {
            fgets(line, 256, fp);
            token = strtok(line, " ");
            img->data[i][j] = atoi(token);
        }
    }

    fclose(fp);
    return img;
}

// Save the image to a file
void save_image(struct image *img, char *filename) {
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%d %d\n", img->width, img->height);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(fp, "%d ", img->data[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    // Load the image
    struct image *img = load_image("image.ppm");

    // Flip the image horizontally
    flip_horizontal(img);

    // Adjust the brightness and contrast of the image
    adjust_brightness_contrast(img, 50, 1.5);

    // Save the image
    save_image(img, "output.ppm");

    return 0;
}