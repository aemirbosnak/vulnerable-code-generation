//FormAI DATASET v1.0 Category: Image Editor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *color;
} Image;

// Resizes the image to a new width and height
void resize_image(Image *img, int new_width, int new_height) {
    Pixel *new_pixels = calloc(new_width * new_height, sizeof(Pixel));
    int x_ratio = (int)((img->width << 16) / new_width) + 1;
    int y_ratio = (int)((img->height << 16) / new_height) + 1;
    int x2, y2;
    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < new_width; j++) {
            x2 = ((j * x_ratio) >> 16);
            y2 = ((i * y_ratio) >> 16);
            new_pixels[(i * new_width) + j] = img->color[(y2 * img->width) + x2];
        }
    }
    free(img->color);
    img->color = new_pixels;
    img->width = new_width;
    img->height = new_height;
}

// Changes the brightness of an image by a given percentage
void change_brightness(Image *img, float percent) {
    for (int i = 0; i < (img->width * img->height); i++) {
        img->color[i].red *= percent;
        img->color[i].green *= percent;
        img->color[i].blue *= percent;
    }
}

// Saves the image to a file in binary format
void save_image(Image *img, char *filename) {
    FILE *file;
    file = fopen(filename, "wb");
    fwrite(&img->width, sizeof(int), 1, file);
    fwrite(&img->height, sizeof(int), 1, file);
    fwrite(img->color, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

int main() {
    Image img;
    img.width = 100;
    img.height = 100;
    img.color = calloc(img.width * img.height, sizeof(Pixel));

    // Fill the image with black pixels
    for (int i = 0; i < (img.width * img.height); i++) {
        img.color[i].red = 0;
        img.color[i].green = 0;
        img.color[i].blue = 0;
    }

    // Draw a red diagonal line
    for (int i = 0; i < img.width; i++) {
        img.color[i * img.width + i].red = 255;
        img.color[i * img.width + i].green = 0;
        img.color[i * img.width + i].blue = 0;
    }

    // Resize the image to be twice as wide
    resize_image(&img, img.width * 2, img.height);

    // Change the brightness of the image by 50%
    change_brightness(&img, 1.5);

    // Save the image to file
    save_image(&img, "example.bin");

    free(img.color);

    return 0;
}