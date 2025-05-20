//FormAI DATASET v1.0 Category: Image Editor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 30

typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

void swap_colors(Pixel *pixels, int num_pixels) {
    for (int i = 0; i < num_pixels; i++) {
        int temp_r = pixels[i].red;
        int temp_g = pixels[i].green;
        int temp_b = pixels[i].blue;
        pixels[i].red = temp_g;
        pixels[i].green = temp_b;
        pixels[i].blue = temp_r;
    }
}

void blur_image(Pixel **image, int width, int height) {
    for (int i = 1; i < width-1; i++) {
        for (int j = 1; j < height-1; j++) {
            int total_r = 0;
            int total_g = 0;
            int total_b = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    total_r += image[i+x][j+y].red;
                    total_g += image[i+x][j+y].green;
                    total_b += image[i+x][j+y].blue;
                }
            }
            image[i][j].red = total_r / 9;
            image[i][j].green = total_g / 9;
            image[i][j].blue = total_b / 9;
        }
    }
}

int main() {
    char filename[MAX_LENGTH];
    printf("Enter the filename for the image you'd like to edit: ");
    fgets(filename, MAX_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;
    FILE *image_file = fopen(filename, "rb");
    if (!image_file) {
        fprintf(stderr, "Could not open file");
        return 1;
    }
    Pixel **image;
    char buffer[1024];
    int width, height, max_color;
    // read the image header
    fgets(buffer, sizeof(buffer), image_file);
    if (buffer[0] != 'P' || buffer[1] != '3') {
        fprintf(stderr, "Invalid image format");
        return 1;
    }
    fgets(buffer, sizeof(buffer), image_file);
    sscanf(buffer, "%d %d", &width, &height);
    fgets(buffer, sizeof(buffer), image_file);
    sscanf(buffer, "%d", &max_color);
    image = malloc(sizeof(Pixel*) * width);
    for (int i = 0; i < width; i++) {
        image[i] = malloc(sizeof(Pixel) * height);
    }
    // read the image pixels
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            int r, g, b;
            fscanf(image_file, "%d %d %d ", &r, &g, &b);
            image[i][j].red = r;
            image[i][j].green = g;
            image[i][j].blue = b;
        }
    }
    fclose(image_file);
    // manipulate the image
    swap_colors(&image[0][0], width*height);
    blur_image(image, width, height);
    // write the modified image to a new file
    char *output_filename = "output.ppm";
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        fprintf(stderr, "Could not create output file");
        return 1;
    }
    fprintf(output_file, "P3\n%d %d\n%d\n", width, height, max_color);
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            fprintf(output_file, "%d %d %d ", image[i][j].red, image[i][j].green, image[i][j].blue);
        }
        fprintf(output_file, "\n");
    }
    fclose(output_file);
    printf("Modifications saved to %s\n", output_filename);
    for (int i = 0; i < width; i++) {
        free(image[i]);
    }
    free(image);
    return 0;
}