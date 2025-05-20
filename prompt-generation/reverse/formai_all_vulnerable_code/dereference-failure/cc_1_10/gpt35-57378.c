//FormAI DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

void load_image(const char* filename, Image* img) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Cannot open file '%s'\n", filename);
        exit(1);
    }

    //Read header information
    char magic[3];
    fscanf(fp, "%2s", magic);
    if (strcmp(magic, "P5")) {
        fprintf(stderr, "Invalid image format (must be PGM)\n");
        exit(1);
    }

    int maxval;
    fscanf(fp, "%d %d %d\n", &img->width, &img->height, &maxval);
    if (maxval != 255) {
        fprintf(stderr, "Invalid bit depth (must be 8)\n");
        exit(1);
    }

    //Allocate memory for image data
    img->data = (unsigned char*)malloc(img->width * img->height * sizeof(unsigned char));
    if (!img->data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    //Read image data
    fread(img->data, sizeof(unsigned char), img->width * img->height, fp);

    fclose(fp);
}

void save_image(const char* filename, Image* img) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Cannot open file '%s'\n", filename);
        exit(1);
    }

    //Write header information
    fprintf(fp, "P5\n%d %d\n%d\n", img->width, img->height, 255);

    //Write image data
    fwrite(img->data, sizeof(unsigned char), img->width * img->height, fp);

    fclose(fp);
}

void flip_image(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            unsigned char temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + img->width - x - 1];
            img->data[y * img->width + img->width - x - 1] = temp;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 0;
    }

    Image img;
    load_image(argv[1], &img);

    flip_image(&img);

    save_image(argv[2], &img);

    free(img.data);

    return 0;
}