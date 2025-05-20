//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define CHANNELS 3

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    pixel* data;
    int width, height;
} image;

image* new_image(int width, int height) {
    image* img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));
    return img;
}

void free_image(image* img) {
    free(img->data);
    free(img);
}

void set_pixel(image* img, int x, int y, pixel color) {
    img->data[y * img->width + x] = color;
}

pixel get_pixel(image* img, int x, int y) {
    return img->data[y * img->width + x];
}

void save_ppm(image* img, const char* filename) {
    FILE* fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void load_ppm(image* img, const char* filename) {
    FILE* fp = fopen(filename, "rb");
    fscanf(fp, "P6\n%d %d\n255\n", &img->width, &img->height);
    img->data = malloc(img->width * img->height * sizeof(pixel));
    fread(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void invert(image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel p = get_pixel(img, x, y);
            p.r = 255 - p.r;
            p.g = 255 - p.g;
            p.b = 255 - p.b;
            set_pixel(img, x, y, p);
        }
    }
}

void grayscale(image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel p = get_pixel(img, x, y);
            unsigned char gray = (p.r + p.g + p.b) / 3;
            p.r = gray;
            p.g = gray;
            p.b = gray;
            set_pixel(img, x, y, p);
        }
    }
}

void rotate(image* img, float angle) {
    image* new_img = new_image(img->width, img->height);

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            float x1 = x - img->width / 2;
            float y1 = y - img->height / 2;
            float x2 = x1 * cos(angle) - y1 * sin(angle);
            float y2 = x1 * sin(angle) + y1 * cos(angle);
            int x2i = (int)round(x2 + img->width / 2);
            int y2i = (int)round(y2 + img->height / 2);
            if (x2i >= 0 && x2i < img->width && y2i >= 0 && y2i < img->height) {
                set_pixel(new_img, x, y, get_pixel(img, x2i, y2i));
            }
        }
    }

    free_image(img);
    *img = *new_img;
    free(new_img);
}

int main() {
    image* img = new_image(WIDTH, HEIGHT);

    // Draw a circle
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            float dx = x - WIDTH / 2;
            float dy = y - HEIGHT / 2;
            float dist = sqrt(dx * dx + dy * dy);
            if (dist < WIDTH / 4) {
                set_pixel(img, x, y, (pixel){255, 0, 0});
            }
        }
    }

    // Invert the image
    invert(img);

    // Save the image
    save_ppm(img, "output.ppm");

    // Free the image
    free_image(img);

    return 0;
}