//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel_t;

typedef struct {
    unsigned int width;
    unsigned int height;
    pixel_t *pixels;
} image_t;

image_t* load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    if (image == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(unsigned int), 1, fp);
    fread(&image->height, sizeof(unsigned int), 1, fp);
    image->pixels = malloc(sizeof(pixel_t) * image->width * image->height);
    if (image->pixels == NULL) {
        free(image);
        fclose(fp);
        return NULL;
    }

    fread(image->pixels, sizeof(pixel_t), image->width * image->height, fp);
    fclose(fp);

    return image;
}

void save_image(char *filename, image_t *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(&image->width, sizeof(unsigned int), 1, fp);
    fwrite(&image->height, sizeof(unsigned int), 1, fp);
    fwrite(image->pixels, sizeof(pixel_t), image->width * image->height, fp);
    fclose(fp);
}

void invert_image(image_t *image) {
    for (unsigned int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].red = 255 - image->pixels[i].red;
        image->pixels[i].green = 255 - image->pixels[i].green;
        image->pixels[i].blue = 255 - image->pixels[i].blue;
    }
}

void grayscale_image(image_t *image) {
    for (unsigned int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->pixels[i].red + image->pixels[i].green + image->pixels[i].blue) / 3;
        image->pixels[i].red = gray;
        image->pixels[i].green = gray;
        image->pixels[i].blue = gray;
    }
}

void blur_image(image_t *image) {
    pixel_t *new_pixels = malloc(sizeof(pixel_t) * image->width * image->height);
    if (new_pixels == NULL) {
        return;
    }

    for (unsigned int i = 0; i < image->width * image->height; i++) {
        int x = i % image->width;
        int y = i / image->width;

        int sum_red = 0;
        int sum_green = 0;
        int sum_blue = 0;
        int count = 0;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < image->width && ny >= 0 && ny < image->height) {
                    sum_red += image->pixels[ny * image->width + nx].red;
                    sum_green += image->pixels[ny * image->width + nx].green;
                    sum_blue += image->pixels[ny * image->width + nx].blue;
                    count++;
                }
            }
        }

        new_pixels[i].red = sum_red / count;
        new_pixels[i].green = sum_green / count;
        new_pixels[i].blue = sum_blue / count;
    }

    free(image->pixels);
    image->pixels = new_pixels;
}

void sharpen_image(image_t *image) {
    pixel_t *new_pixels = malloc(sizeof(pixel_t) * image->width * image->height);
    if (new_pixels == NULL) {
        return;
    }

    for (unsigned int i = 0; i < image->width * image->height; i++) {
        int x = i % image->width;
        int y = i / image->width;

        int sum_red = 0;
        int sum_green = 0;
        int sum_blue = 0;
        int count = 0;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < image->width && ny >= 0 && ny < image->height) {
                    sum_red += image->pixels[ny * image->width + nx].red;
                    sum_green += image->pixels[ny * image->width + nx].green;
                    sum_blue += image->pixels[ny * image->width + nx].blue;
                    count++;
                }
            }
        }

        int avg_red = sum_red / count;
        int avg_green = sum_green / count;
        int avg_blue = sum_blue / count;

        new_pixels[i].red = image->pixels[i].red + (avg_red - image->pixels[i].red) * 2;
        new_pixels[i].green = image->pixels[i].green + (avg_green - image->pixels[i].green) * 2;
        new_pixels[i].blue = image->pixels[i].blue + (avg_blue - image->pixels[i].blue) * 2;
    }

    free(image->pixels);
    image->pixels = new_pixels;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_image> [output_image]\n", argv[0]);
        return 1;
    }

    image_t *image = load_image(argv[1]);
    if (image == NULL) {
        printf("Error loading image: %s\n", argv[1]);
        return 1;
    }

    char *output_image = NULL;
    if (argc >= 3) {
        output_image = argv[2];
    } else {
        output_image = "output.bmp";
    }

    char *command = NULL;
    while (1) {
        printf("Enter a command (invert, grayscale, blur, sharpen, save, quit): ");
        scanf("%s", command);

        if (strcmp(command, "invert") == 0) {
            invert_image(image);
        } else if (strcmp(command, "grayscale") == 0) {
            grayscale_image(image);
        } else if (strcmp(command, "blur") == 0) {
            blur_image(image);
        } else if (strcmp(command, "sharpen") == 0) {
            sharpen_image(image);
        } else if (strcmp(command, "save") == 0) {
            save_image(output_image, image);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    free(image->pixels);
    free(image);

    return 0;
}