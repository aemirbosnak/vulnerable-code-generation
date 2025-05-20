//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    int **data;
} Image;

void create_image(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        img->data[i] = (int *)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            img->data[i][j] = rand() % 256;
        }
    }
}

void destroy_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
}

void flip_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            int temp = img->data[i][j];
            img->data[i][j] = img->data[i][img->width - j - 1];
            img->data[i][img->width - j - 1] = temp;
        }
    }
}

void change_brightness(Image *img, int delta) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->data[i][j] += delta;
            if (img->data[i][j] > 255) {
                img->data[i][j] = 255;
            } else if (img->data[i][j] < 0) {
                img->data[i][j] = 0;
            }
        }
    }
}

void change_contrast(Image *img, int delta) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int new_value = (img->data[i][j] + delta) * (255 - delta) / 255;
            img->data[i][j] = new_value;
            if (new_value > 255) {
                img->data[i][j] = 255;
            } else if (new_value < 0) {
                img->data[i][j] = 0;
            }
        }
    }
}

void save_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    for (int i = 0; i < img->height; i++) {
        fwrite(img->data[i], img->width, sizeof(int), fp);
    }
    fclose(fp);
}

int main() {
    srand(time(NULL));

    Image img;
    create_image(&img, 500, 500);

    flip_image(&img);
    save_image(&img, "flipped.png");

    change_brightness(&img, 50);
    save_image(&img, "brightened.png");

    change_contrast(&img, 50);
    save_image(&img, "contrasted.png");

    destroy_image(&img);

    return 0;
}