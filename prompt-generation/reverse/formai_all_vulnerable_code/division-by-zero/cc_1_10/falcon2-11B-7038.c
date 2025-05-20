//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024 * 1024

typedef struct {
    unsigned char* data;
    int width;
    int height;
} Image;

int load_image(const char* filename, Image* image) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Failed to open image file: %s\n", filename);
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    image->data = malloc(size);
    if (!image->data) {
        fclose(fp);
        return -1;
    }

    if (fread(image->data, 1, size, fp)!= size) {
        free(image->data);
        fclose(fp);
        return -1;
    }

    fclose(fp);

    image->width = size / (image->height * sizeof(unsigned char));
    image->height = (size + image->width - 1) / image->width;

    return 0;
}

void save_image(const char* filename, Image image) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Failed to open image file: %s\n", filename);
        return;
    }

    fwrite(image.data, 1, image.width * image.height, fp);
    fclose(fp);
}

void display_image(Image image) {
    int i, j;
    for (i = 0; i < image.height; i++) {
        for (j = 0; j < image.width; j++) {
            printf("%02X ", image.data[i * image.width + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Image image;

    if (load_image("input.jpg", &image)!= 0) {
        return 1;
    }

    display_image(image);

    save_image("output.jpg", image);

    return 0;
}