//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    char *data;
} Image;

void load_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    if (fread(&image->width, sizeof(int), 1, file) != 1) {
        fprintf(stderr, "Error: could not read image width from file '%s'\n", filename);
        exit(1);
    }

    if (fread(&image->height, sizeof(int), 1, file) != 1) {
        fprintf(stderr, "Error: could not read image height from file '%s'\n", filename);
        exit(1);
    }

    image->data = malloc(image->width * image->height * 3);
    if (!image->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        exit(1);
    }

    if (fread(image->data, 1, image->width * image->height * 3, file) != image->width * image->height * 3) {
        fprintf(stderr, "Error: could not read image data from file '%s'\n", filename);
        exit(1);
    }

    fclose(file);
}

void save_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s' for writing\n", filename);
        exit(1);
    }

    if (fwrite(&image->width, sizeof(int), 1, file) != 1) {
        fprintf(stderr, "Error: could not write image width to file '%s'\n", filename);
        exit(1);
    }

    if (fwrite(&image->height, sizeof(int), 1, file) != 1) {
        fprintf(stderr, "Error: could not write image height to file '%s'\n", filename);
        exit(1);
    }

    if (fwrite(image->data, 1, image->width * image->height * 3, file) != image->width * image->height * 3) {
        fprintf(stderr, "Error: could not write image data to file '%s'\n", filename);
        exit(1);
    }

    fclose(file);
}

void flip_image_horizontal(Image *image) {
    int half = image->width / 2;
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < half; x++) {
            int left = x * 3;
            int right = (image->width - x - 1) * 3;
            int temp = image->data[y * image->width * 3 + left];
            image->data[y * image->width * 3 + left] = image->data[y * image->width * 3 + right];
            image->data[y * image->width * 3 + right] = temp;
            temp = image->data[y * image->width * 3 + left + 1];
            image->data[y * image->width * 3 + left + 1] = image->data[y * image->width * 3 + right + 1];
            image->data[y * image->width * 3 + right + 1] = temp;
            temp = image->data[y * image->width * 3 + left + 2];
            image->data[y * image->width * 3 + left + 2] = image->data[y * image->width * 3 + right + 2];
            image->data[y * image->width * 3 + right + 2] = temp;
        }
    }
}

void flip_image_vertical(Image *image) {
    int half = image->height / 2;
    for (int y = 0; y < half; y++) {
        for (int x = 0; x < image->width; x++) {
            int top = y * image->width * 3;
            int bottom = (image->height - y - 1) * image->width * 3;
            int temp = image->data[top + x * 3];
            image->data[top + x * 3] = image->data[bottom + x * 3];
            image->data[bottom + x * 3] = temp;
            temp = image->data[top + x * 3 + 1];
            image->data[top + x * 3 + 1] = image->data[bottom + x * 3 + 1];
            image->data[bottom + x * 3 + 1] = temp;
            temp = image->data[top + x * 3 + 2];
            image->data[top + x * 3 + 2] = image->data[bottom + x * 3 + 2];
            image->data[bottom + x * 3 + 2] = temp;
        }
    }
}

void change_brightness_contrast(Image *image, float brightness, float contrast) {
    for (int i = 0; i < image->width * image->height * 3; i += 3) {
        image->data[i] = (image->data[i] + brightness) * contrast;
        image->data[i + 1] = (image->data[i + 1] + brightness) * contrast;
        image->data[i + 2] = (image->data[i + 2] + brightness) * contrast;
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <operation> <value>\n", argv[0]);
        fprintf(stderr, "Operations:\n");
        fprintf(stderr, "  flip-horizontal\n");
        fprintf(stderr, "  flip-vertical\n");
        fprintf(stderr, "  change-brightness <value>\n");
        fprintf(stderr, "  change-contrast <value>\n");
        return 1;
    }

    Image image;
    load_image(&image, argv[1]);

    if (strcmp(argv[3], "flip-horizontal") == 0) {
        flip_image_horizontal(&image);
    } else if (strcmp(argv[3], "flip-vertical") == 0) {
        flip_image_vertical(&image);
    } else if (strcmp(argv[3], "change-brightness") == 0) {
        float brightness = atof(argv[4]);
        change_brightness_contrast(&image, brightness, 1.0f);
    } else if (strcmp(argv[3], "change-contrast") == 0) {
        float contrast = atof(argv[4]);
        change_brightness_contrast(&image, 0.0f, contrast);
    } else {
        fprintf(stderr, "Error: unknown operation '%s'\n", argv[3]);
        return 1;
    }

    save_image(&image, argv[2]);

    return 0;
}