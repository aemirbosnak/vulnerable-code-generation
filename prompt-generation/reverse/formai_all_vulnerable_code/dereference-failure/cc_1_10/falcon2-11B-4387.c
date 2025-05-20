//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_IMAGE_WIDTH 640
#define MAX_IMAGE_HEIGHT 480

typedef struct {
    int width;
    int height;
    int* pixels;
} Image;

void load_image(Image* image, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Failed to open file '%s'.\n", filename);
        exit(1);
    }

    int bytes_per_pixel = 4;
    image->width = fread(&image->width, 1, 1, file);
    image->height = fread(&image->height, 1, 1, file);
    image->pixels = (int*)malloc(image->width * image->height * bytes_per_pixel);
    if (!image->pixels) {
        fprintf(stderr, "Error: Failed to allocate memory for image.\n");
        exit(1);
    }

    int pixel;
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fread(&pixel, 1, 1, file);
            image->pixels[y * image->width + x] = pixel;
        }
    }

    fclose(file);
}

void save_image(Image* image, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error: Failed to open file '%s'.\n", filename);
        exit(1);
    }

    int bytes_per_pixel = 4;
    fwrite(&image->width, 1, 1, file);
    fwrite(&image->height, 1, 1, file);
    fwrite(image->pixels, image->width * image->height * bytes_per_pixel, 1, file);

    fclose(file);
}

void draw_pixel(Image* image, int x, int y, int color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }

    image->pixels[y * image->width + x] = color;
}

void draw_line(Image* image, int x1, int y1, int x2, int y2, int color) {
    if (x1 > x2 || y1 > y2) {
        return;
    }

    for (int y = y1; y <= y2; y++) {
        draw_pixel(image, x1, y, color);
        draw_pixel(image, x2, y, color);
    }

    for (int x = x1; x <= x2; x++) {
        draw_pixel(image, x, y1, color);
        draw_pixel(image, x, y2, color);
    }
}

void draw_rectangle(Image* image, int x, int y, int width, int height, int color) {
    for (int y1 = y; y1 <= y + height; y1++) {
        draw_line(image, x, y1, x + width, y1, color);
    }

    for (int x1 = x; x1 <= x + width; x1++) {
        draw_line(image, x1, y, x1, y + height, color);
    }
}

void draw_circle(Image* image, int x, int y, int radius, int color) {
    int dx = 2 * radius - 1;
    int dy = 2 * radius - 1;

    int* circle_points = (int*)malloc(dy * dy * sizeof(int));
    if (!circle_points) {
        fprintf(stderr, "Error: Failed to allocate memory for circle points.\n");
        exit(1);
    }

    for (int y = 0; y < dy; y++) {
        int* point = circle_points + y * dy;
        for (int x = 0; x < dy; x++) {
            *point = x + (y + radius) * dx;
            point++;
        }
    }

    for (int y = 0; y < dy; y++) {
        for (int x = 0; x < dy; x++) {
            draw_pixel(image, circle_points[y * dy + x], y, color);
        }
    }

    free(circle_points);
}

void draw_filled_rectangle(Image* image, int x, int y, int width, int height, int color) {
    for (int y1 = y; y1 <= y + height; y1++) {
        draw_line(image, x, y1, x + width, y1, color);
        draw_line(image, x, y1, x, y1 + height, color);
        draw_line(image, x + width, y1, x + width, y1 + height, color);
    }
}

void draw_filled_circle(Image* image, int x, int y, int radius, int color) {
    int dx = 2 * radius - 1;
    int dy = 2 * radius - 1;

    int* circle_points = (int*)malloc(dy * dy * sizeof(int));
    if (!circle_points) {
        fprintf(stderr, "Error: Failed to allocate memory for circle points.\n");
        exit(1);
    }

    for (int y = 0; y < dy; y++) {
        int* point = circle_points + y * dy;
        for (int x = 0; x < dy; x++) {
            *point = x + (y + radius) * dx;
            point++;
        }
    }

    for (int y = 0; y < dy; y++) {
        for (int x = 0; x < dy; x++) {
            draw_pixel(image, circle_points[y * dy + x], y, color);
        }
    }

    free(circle_points);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    const char* input_filename = argv[1];
    const char* output_filename = argv[2];

    Image input_image;
    load_image(&input_image, input_filename);

    Image output_image;
    output_image.width = input_image.width;
    output_image.height = input_image.height;
    output_image.pixels = (int*)malloc(output_image.width * output_image.height * sizeof(int));
    if (!output_image.pixels) {
        fprintf(stderr, "Error: Failed to allocate memory for output image.\n");
        exit(1);
    }

    for (int y = 0; y < output_image.height; y++) {
        for (int x = 0; x < output_image.width; x++) {
            output_image.pixels[y * output_image.width + x] = input_image.pixels[y * input_image.width + x];
        }
    }

    save_image(&output_image, output_filename);

    free(input_image.pixels);
    free(output_image.pixels);

    return 0;
}