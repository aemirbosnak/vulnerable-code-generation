//FormAI DATASET v1.0 Category: Image Editor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_LENGTH 10000
#define HEADER_SIZE 54

typedef struct {
    unsigned char R;
    unsigned char G;
    unsigned char B;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width;
    int height;
} Image;

Image *read_bmp(const char *filename) {
    unsigned char file_header[HEADER_SIZE];
    Image *img = NULL;
    int padding;
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return NULL;
    }

    fread(file_header, sizeof(unsigned char), HEADER_SIZE, file);

    if (file_header[0] != 'B' || file_header[1] != 'M') {
        printf("Error: Not a BMP file.\n");
        return NULL;
    }

    img = (Image *) malloc(sizeof(Image));
    img->width = *(int *) &file_header[18];
    img->height = *(int *) &file_header[22];
    int row_size = img->width * 3;
    padding = 0;
    while ((row_size + padding) % 4 != 0) {
        padding++;
    }

    unsigned int img_size = (img->width * img->height * 3) + (img->height * padding);
    img->pixels = (Pixel *) malloc(sizeof(Pixel) * img->width * img->height);

    fseek(file, HEADER_SIZE, SEEK_SET);

    unsigned char buffer[3];
    int x, y, i = 0;

    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            fread(buffer, sizeof(unsigned char), 3, file);
            img->pixels[i].R = buffer[2];
            img->pixels[i].G = buffer[1];
            img->pixels[i].B = buffer[0];
            i++;
        }
        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);
    return img;
}

void write_bmp(const char *filename, Image *img) {
    unsigned char file_header[HEADER_SIZE];
    int padding;
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    memset(file_header, 0, HEADER_SIZE);

    file_header[0] = 'B';
    file_header[1] = 'M';

    unsigned int img_size = (img->width * img->height * 3) + (img->height * img->width % 4);

    *(int *) &file_header[2] = img_size + HEADER_SIZE;
    *(int *) &file_header[10] = HEADER_SIZE;
    *(int *) &file_header[18] = img->width;
    *(int *) &file_header[22] = img->height;
    file_header[28] = 24;

    fwrite(file_header, sizeof(unsigned char), HEADER_SIZE, file);

    int row_size = img->width * 3;
    padding = 0;
    while ((row_size + padding) % 4 != 0) {
        padding++;
    }

    unsigned char pad[3] = {0, 0, 0};
    int x, y, i = 0;

    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            fwrite(&img->pixels[i].B, 1, 1, file);
            fwrite(&img->pixels[i].G, 1, 1, file);
            fwrite(&img->pixels[i].R, 1, 1, file);
            i++;
        }
        fwrite(pad, 1, padding, file);
    }

    fclose(file);
}

void grayscale(Image *img) {
    int i;
    int gray_val;

    for (i = 0; i < img->width * img->height; i++) {
        gray_val = img->pixels[i].R * 0.299 + img->pixels[i].G * 0.587 + img->pixels[i].B * 0.114;
        img->pixels[i].R = gray_val;
        img->pixels[i].G = gray_val;
        img->pixels[i].B = gray_val;
    }
}

void threshold(Image *img, int threshold_val) {
    int i;
    int gray_val;

    for (i = 0; i < img->width * img->height; i++) {
        gray_val = img->pixels[i].R * 0.299 + img->pixels[i].G * 0.587 + img->pixels[i].B * 0.114;
        if (gray_val < threshold_val) {
            img->pixels[i].R = 0;
            img->pixels[i].G = 0;
            img->pixels[i].B = 0;
        } else {
            img->pixels[i].R = 255;
            img->pixels[i].G = 255;
            img->pixels[i].B = 255;
        }
    }
}

int main(int argc, char **argv) {
    Image *img = NULL;
    if (argc < 2) {
        printf("Please provide a filename.\n");
        return 1;
    }

    img = read_bmp(argv[1]);

    if (img == NULL) {
        return 1;
    }

    grayscale(img);
    write_bmp("grayscale.bmp", img);

    threshold(img, 128);
    write_bmp("threshold.bmp", img);

    free(img->pixels);
    free(img);

    return 0;
}