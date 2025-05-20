//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    char **image;
} Image;

Image *create_image(int width, int height) {
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->image = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        img->image[i] = (char *)malloc(width * sizeof(char));
    }
    return img;
}

void free_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->image[i]);
    }
    free(img->image);
    free(img);
}

void display_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%c", img->image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Image *img = create_image(3, 4);
    img->image[0][0] = 'X';
    img->image[0][1] = 'X';
    img->image[0][2] = 'X';
    img->image[0][3] = 'X';

    img->image[1][0] = 'O';
    img->image[1][1] = 'O';
    img->image[1][2] = 'O';
    img->image[1][3] = 'O';

    img->image[2][0] = 'O';
    img->image[2][1] = 'O';
    img->image[2][2] = 'O';
    img->image[2][3] = 'O';

    display_image(img);
    printf("\n");

    img->image[0][0] = 'X';
    img->image[0][1] = 'X';
    img->image[0][2] = 'X';
    img->image[0][3] = 'X';

    img->image[1][0] = 'O';
    img->image[1][1] = 'O';
    img->image[1][2] = 'O';
    img->image[1][3] = 'O';

    img->image[2][0] = 'O';
    img->image[2][1] = 'O';
    img->image[2][2] = 'O';
    img->image[2][3] = 'O';

    display_image(img);
    printf("\n");

    free_image(img);
    return 0;
}