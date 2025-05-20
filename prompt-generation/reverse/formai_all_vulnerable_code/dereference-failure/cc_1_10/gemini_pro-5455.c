//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char* data;
    int width;
    int height;
} Image;

Image* load_image(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char* data = malloc(size);
    fread(data, 1, size, fp);

    fclose(fp);

    Image* image = malloc(sizeof(Image));
    image->data = data;
    image->width = 0;
    image->height = 0;

    return image;
}

void free_image(Image* image) {
    free(image->data);
    free(image);
}

void invert_image(Image* image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void blur_image(Image* image) {
    int kernel[3][3] = {
        {1, 2, 1},
        {2, 4, 2},
        {1, 2, 1}
    };

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += kernel[i][j];
        }
    }

    for (int i = 1; i < image->width - 1; i++) {
        for (int j = 1; j < image->height - 1; j++) {
            int new_value = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    new_value += image->data[(i + k) * image->width + (j + l)] * kernel[k + 1][l + 1];
                }
            }
            new_value /= sum;
            image->data[i * image->width + j] = new_value;
        }
    }
}

void save_image(Image* image, const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }

    fwrite(image->data, 1, image->width * image->height, fp);

    fclose(fp);
}

int main() {
    Image* image = load_image("image.bmp");
    if (!image) {
        printf("Could not load image!\n");
        return 1;
    }

    invert_image(image);
    blur_image(image);

    save_image(image, "output.bmp");

    free_image(image);

    return 0;
}