//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    int* pixels;
} Image;

Image create_image(int width, int height) {
    Image img;
    img.width = width;
    img.height = height;
    img.pixels = (int*) malloc(width * height * sizeof(int));
    for (int i = 0; i < width * height; i++) {
        img.pixels[i] = 0;
    }
    return img;
}

void print_image(Image img) {
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            printf("%3d ", img.pixels[y * img.width + x]);
        }
        printf("\n");
    }
}

void draw_point(Image img, int x, int y) {
    if (x < 0 || x >= img.width || y < 0 || y >= img.height) {
        printf("Invalid position\n");
        return;
    }
    img.pixels[y * img.width + x] = 1;
}

int main() {
    Image img = create_image(MAX_WIDTH, MAX_HEIGHT);
    print_image(img);

    while (1) {
        char c;
        scanf("%c", &c);

        switch (c) {
            case 'q':
                return 0;
            case 'p':
                print_image(img);
                break;
            case 'd':
                draw_point(img, 0, 0);
                print_image(img);
                break;
            case 'a':
                draw_point(img, img.width - 1, 0);
                print_image(img);
                break;
            case 'w':
                draw_point(img, 0, img.height - 1);
                print_image(img);
                break;
            case's':
                draw_point(img, img.width - 1, img.height - 1);
                print_image(img);
                break;
            case 'x':
                draw_point(img, img.width / 2, img.height / 2);
                print_image(img);
                break;
            case 'z':
                draw_point(img, img.width / 2, img.height / 2);
                draw_point(img, img.width / 2, img.height - 1);
                draw_point(img, img.width - 1, img.height - 1);
                draw_point(img, 0, img.height - 1);
                draw_point(img, img.width / 2, 0);
                draw_point(img, img.width / 2, img.height / 2);
                draw_point(img, 0, img.height / 2);
                print_image(img);
                break;
            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}