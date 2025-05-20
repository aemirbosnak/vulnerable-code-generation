//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int width, height;
} Image;

Image *new_image(int width, int height) {
    Image *img = malloc(sizeof(Image));
    img->data = malloc(width * height * sizeof(unsigned char));
    img->width = width;
    img->height = height;
    return img;
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

void save_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fwrite(img->data, 1, img->width * img->height, fp);
    fclose(fp);
}

void load_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "rb");
    fread(img->data, 1, img->width * img->height, fp);
    fclose(fp);
}

void invert_image(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i] = 255 - img->data[i];
    }
}

void grayscale_image(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char avg = (img->data[i] + img->data[i + 1] + img->data[i + 2]) / 3;
        img->data[i] = avg;
        img->data[i + 1] = avg;
        img->data[i + 2] = avg;
    }
}

void blur_image(Image *img) {
    int kernel[9] = {
        1, 2, 1,
        2, 4, 2,
        1, 2, 1
    };

    Image *new_img = new_image(img->width, img->height);

    for (int i = 0; i < img->width * img->height; i++) {
        int x = i % img->width;
        int y = i / img->width;

        int sum = 0;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                int px = x + j;
                int py = y + k;

                if (px >= 0 && px < img->width && py >= 0 && py < img->height) {
                    sum += img->data[py * img->width + px] * kernel[j + 1 + (k + 1) * 3];
                }
            }
        }

        new_img->data[i] = sum / 16;
    }

    free_image(img);
    img = new_img;
}

void sharpen_image(Image *img) {
    int kernel[9] = {
        0, -1, 0,
        -1, 5, -1,
        0, -1, 0
    };

    Image *new_img = new_image(img->width, img->height);

    for (int i = 0; i < img->width * img->height; i++) {
        int x = i % img->width;
        int y = i / img->width;

        int sum = 0;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                int px = x + j;
                int py = y + k;

                if (px >= 0 && px < img->width && py >= 0 && py < img->height) {
                    sum += img->data[py * img->width + px] * kernel[j + 1 + (k + 1) * 3];
                }
            }
        }

        new_img->data[i] = sum;
    }

    free_image(img);
    img = new_img;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    Image *img = new_image(640, 480);
    load_image(img, argv[1]);

    // Apply some image effects
    invert_image(img);
    grayscale_image(img);
    blur_image(img);
    sharpen_image(img);

    save_image(img, argv[2]);
    free_image(img);

    printf("Image edited and saved to %s!\n", argv[2]);
    return 0;
}