//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    int* data;
    int width;
    int height;
} Image;

Image* createImage(int width, int height) {
    Image* image = (Image*)malloc(sizeof(Image));
    image->data = (int*)malloc(sizeof(int) * width * height);
    image->width = width;
    image->height = height;
    return image;
}

void destroyImage(Image* image) {
    free(image->data);
    free(image);
}

void flipImage(Image* image) {
    int i, j;
    for(i = 0; i < image->height; i++) {
        for(j = 0; j < image->width/2; j++) {
            int temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - j - 1];
            image->data[i * image->width + image->width - j - 1] = temp;
        }
    }
}

void changeBrightness(Image* image, int brightness) {
    int i, j;
    for(i = 0; i < image->height; i++) {
        for(j = 0; j < image->width; j++) {
            int value = image->data[i * image->width + j];
            value += brightness;
            if(value > 255) {
                value = 255;
            } else if(value < 0) {
                value = 0;
            }
            image->data[i * image->width + j] = value;
        }
    }
}

void changeContrast(Image* image, int contrast) {
    int i, j;
    for(i = 0; i < image->height; i++) {
        for(j = 0; j < image->width; j++) {
            int value = image->data[i * image->width + j];
            value = (value * contrast) / 100;
            if(value > 255) {
                value = 255;
            } else if(value < 0) {
                value = 0;
            }
            image->data[i * image->width + j] = value;
        }
    }
}

void drawImage(Image* image) {
    int i, j;
    for(i = 0; i < image->height; i++) {
        for(j = 0; j < image->width; j++) {
            printf("%d ", image->data[i * image->width + j]);
        }
        printf("\n");
    }
}

int main() {
    Image* image = createImage(WIDTH, HEIGHT);
    srand(time(NULL));
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            image->data[i * WIDTH + j] = rand() % 256;
        }
    }
    drawImage(image);
    flipImage(image);
    drawImage(image);
    changeBrightness(image, 50);
    drawImage(image);
    changeContrast(image, 150);
    drawImage(image);
    destroyImage(image);
    return 0;
}