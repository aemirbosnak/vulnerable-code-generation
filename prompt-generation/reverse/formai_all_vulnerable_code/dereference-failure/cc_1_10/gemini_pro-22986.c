//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

unsigned char *read_image(char *filename, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    unsigned char *buffer;
    fread(&buffer, sizeof(buffer), 1, fp);

    *width = buffer[0];
    *height = buffer[1];

    return buffer;
}

void write_image(char *filename, unsigned char *buffer, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    fwrite(buffer, sizeof(buffer), 1, fp);
    fclose(fp);
}

void flip_image(unsigned char *buffer, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            unsigned char tmp = buffer[i * width + j];
            buffer[i * width + j] = buffer[i * width + width - 1 - j];
            buffer[i * width + width - 1 - j] = tmp;
        }
    }
}

void change_brightness(unsigned char *buffer, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = buffer[i * width + j] + brightness;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            buffer[i * width + j] = new_value;
        }
    }
}

void change_contrast(unsigned char *buffer, int width, int height, int contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = (buffer[i * width + j] - 128) * contrast + 128;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            buffer[i * width + j] = new_value;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <operation> <value>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    unsigned char *buffer = read_image(argv[1], &width, &height);
    if (!buffer) {
        fprintf(stderr, "Error reading image: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    int value = atoi(argv[4]);

    if (strcmp(argv[3], "flip") == 0) {
        flip_image(buffer, width, height);
    } else if (strcmp(argv[3], "brightness") == 0) {
        change_brightness(buffer, width, height, value);
    } else if (strcmp(argv[3], "contrast") == 0) {
        change_contrast(buffer, width, height, value);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[3]);
        free(buffer);
        return EXIT_FAILURE;
    }

    write_image(argv[2], buffer, width, height);
    free(buffer);

    return EXIT_SUCCESS;
}