//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char *data; // RGB data
} Image;

Image* load_ppm(const char *filename);
void save_ppm(const char *filename, Image *img);
void invert_colors(Image *img);
void grayscale(Image *img);
void rotate_image(Image *img);
void free_image(Image *img);

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input.ppm> <output.ppm> [option]\n", argv[0]);
        printf("Options:\n");
        printf("  1 - Invert colors\n");
        printf("  2 - Convert to grayscale\n");
        printf("  3 - Rotate image 90 degrees\n");
        return 1;
    }

    Image *img = load_ppm(argv[1]);
    if (!img) {
        fprintf(stderr, "Error loading image: %s\n", argv[1]);
        return 1;
    }

    // Apply the chosen option
    switch (atoi(argv[3])) {
        case 1:
            invert_colors(img);
            break;
        case 2:
            grayscale(img);
            break;
        case 3:
            rotate_image(img);
            break;
        default:
            printf("Invalid option. Please choose 1, 2, or 3.\n");
            free_image(img);
            return 1;
    }

    save_ppm(argv[2], img);
    free_image(img);
    printf("Image processed and saved as %s\n", argv[2]);
    return 0;
}

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    char header[3];
    fscanf(file, "%2s", header);
    if (strcmp(header, "P6") != 0) {
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // Consume the newline character after maxval

    img->data = malloc(img->width * img->height * 3);
    fread(img->data, 3, img->width * img->height, file);
    fclose(file);
    return img;
}

void save_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 3, img->width * img->height, file);
    fclose(file);
}

void invert_colors(Image *img) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        img->data[i] = 255 - img->data[i];
    }
}

void grayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char r = img->data[i * 3];
        unsigned char g = img->data[i * 3 + 1];
        unsigned char b = img->data[i * 3 + 2];
        unsigned char gray = (r + g + b) / 3;
        img->data[i * 3] = gray;
        img->data[i * 3 + 1] = gray;
        img->data[i * 3 + 2] = gray;
    }
}

void rotate_image(Image *img) {
    unsigned char *new_data = malloc(img->width * img->height * 3);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int new_x = img->height - 1 - y;
            int new_y = x;
            new_data[(new_y * img->height + new_x) * 3 + 0] = img->data[(y * img->width + x) * 3 + 0];
            new_data[(new_y * img->height + new_x) * 3 + 1] = img->data[(y * img->width + x) * 3 + 1];
            new_data[(new_y * img->height + new_x) * 3 + 2] = img->data[(y * img->width + x) * 3 + 2];
        }
    }
    free(img->data);
    img->data = new_data;
    int temp = img->width;
    img->width = img->height;
    img->height = temp;
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}