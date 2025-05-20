//FormAI DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red, green, blue;
} Pixel;

void save_image(Pixel *image, int width, int height, char *filename) {
    FILE *fp;
    fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(Pixel), width*height, fp);
    fclose(fp);
}

void grayscale(Pixel *image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            unsigned char gray = (image[i*width+j].red + image[i*width+j].green + image[i*width+j].blue)/3;
            image[i*width+j].red = gray;
            image[i*width+j].green = gray;
            image[i*width+j].blue = gray;
        }
    }
}

int main() {
    char *filename = "test.ppm";
    int width = 100;
    int height = 100;
    int i, j;
    Pixel *image = malloc(width*height*sizeof(Pixel));

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {

            // Draw a gradient with red and white colors
            image[i*width+j].red = (255*i)/height;
            image[i*width+j].green = 255;
            image[i*width+j].blue = (255*j)/width;

        }
    }

    // Create and save the image
    save_image(image, width, height, filename);

    // Convert the image to grayscale and save it
    grayscale(image, width, height);
    char *gray_filename = "gray_test.ppm";
    save_image(image, width, height, gray_filename);

    free(image);
    return 0;
}