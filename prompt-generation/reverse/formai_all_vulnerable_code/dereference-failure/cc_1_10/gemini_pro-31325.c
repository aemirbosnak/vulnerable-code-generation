//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned char* load_image(char* filename, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    unsigned char header[18];
    fread(header, 1, 18, fp);

    *width = header[8] << 8 | header[9];
    *height = header[10] << 8 | header[11];

    unsigned char* data = malloc(*width * *height);
    fread(data, 1, *width * *height, fp);

    fclose(fp);

    return data;
}

void save_image(char* filename, unsigned char* data, int width, int height) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    unsigned char header[18] = {
        0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, (width & 0xFF), (width >> 8), (height & 0xFF), (height >> 8), 24, 0
    };

    fwrite(header, 1, 18, fp);
    fwrite(data, 1, width * height, fp);

    fclose(fp);
}

void flip_image(unsigned char* data, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        data[i] = 255 - data[i];
    }
}

void change_brightness(unsigned char* data, int width, int height, int brightness) {
    for (int i = 0; i < width * height; i++) {
        data[i] = data[i] + brightness;
    }
}

void change_contrast(unsigned char* data, int width, int height, int contrast) {
    for (int i = 0; i < width * height; i++) {
        data[i] = data[i] * contrast;
    }
}

int main(int argc, char** argv) {
    if (argc != 5) {
        printf("Usage: %s <filename> <flip/brightness/contrast> <value> <output>\n", argv[0]);
        return 1;
    }

    int width, height;
    unsigned char* data = load_image(argv[1], &width, &height);
    if (data == NULL) {
        return 1;
    }

    if (strcmp(argv[2], "flip") == 0) {
        flip_image(data, width, height);
    } else if (strcmp(argv[2], "brightness") == 0) {
        change_brightness(data, width, height, atoi(argv[3]));
    } else if (strcmp(argv[2], "contrast") == 0) {
        change_contrast(data, width, height, atoi(argv[3]));
    }

    save_image(argv[4], data, width, height);

    free(data);

    return 0;
}