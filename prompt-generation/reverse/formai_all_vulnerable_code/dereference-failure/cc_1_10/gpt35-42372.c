//FormAI DATASET v1.0 Category: Image Editor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_FILENAME 1000
#define MAX_LINE_SIZE 2000
#define MAX_PIXEL_VALUE 255

typedef struct {
    int width;
    int height;
    unsigned char **pixels;
} image;

void free_image(image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

image *create_image(int width, int height) {
    image *img = (image *) malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->pixels = (unsigned char **) malloc(height * sizeof(unsigned char *));
    for (int i = 0; i < height; i++) {
        img->pixels[i] = (unsigned char *) malloc(width * sizeof(unsigned char));
    }
    return img;
}

image *read_image(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Unable to open file %s\n", filename);
        exit(1);
    }

    char buffer[MAX_LINE_SIZE];
    int width, height, pixel_value;

    // Read PGM file header
    fgets(buffer, MAX_LINE_SIZE, fp);
    if (buffer[0] != 'P' || buffer[1] != '5') {
        printf("Invalid PGM file format\n");
        exit(1);
    }

    fgets(buffer, MAX_LINE_SIZE, fp);
    while (buffer[0] == '#') {
        fgets(buffer, MAX_LINE_SIZE, fp);
    }

    sscanf(buffer, "%d %d", &width, &height);

    fgets(buffer, MAX_LINE_SIZE, fp);
    sscanf(buffer, "%d", &pixel_value);
    if (pixel_value != MAX_PIXEL_VALUE) {
        printf("Invalid pixel value\n");
        exit(1);
    }

    // Read pixel data
    image *img = create_image(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img->pixels[i][j] = fgetc(fp);
        }
    }

    fclose(fp);
    return img;
}

void write_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Unable to open file %s\n", filename);
        exit(1);
    }

    // Write PGM file header
    fprintf(fp, "P5\n");
    fprintf(fp, "# Created by Image Editor\n");
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "%d\n", MAX_PIXEL_VALUE);

    // Write pixel data
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fputc(img->pixels[i][j], fp);
        }
    }

    fclose(fp);
}

void invert(image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j] = MAX_PIXEL_VALUE - img->pixels[i][j];
        }
    }
}

void gray_scale(image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            unsigned char pixel = img->pixels[i][j];
            img->pixels[i][j] = (unsigned char) round(0.299 * pixel + 0.587 * pixel + 0.114 * pixel);
        }
    }
}

void blur(image *img) {
    unsigned char **tmp_pixels = (unsigned char **) malloc(img->height * sizeof(unsigned char *));
    for (int i = 0; i < img->height; i++) {
        tmp_pixels[i] = (unsigned char *) malloc(img->width * sizeof(unsigned char));
    }

    for (int i = 1; i < img->height - 1; i++) {
        for (int j = 1; j < img->width - 1; j++) {
            int sum = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    sum += img->pixels[i + y][j + x];
                }
            }
            tmp_pixels[i][j] = (unsigned char) (sum / 9);
        }
    }

    for (int i = 1; i < img->height - 1; i++) {
        for (int j = 1; j < img->width - 1; j++) {
            img->pixels[i][j] = tmp_pixels[i][j];
        }
    }

    for (int i = 0; i < img->height; i++) {
        free(tmp_pixels[i]);
    }
    free(tmp_pixels);
}

int main() {
    char input_filename[MAX_FILENAME], output_filename[MAX_FILENAME];
    printf("Enter input filename: ");
    scanf("%s", input_filename);
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    // Read input image 
    image *img = read_image(input_filename);

    // Apply image processing 
    invert(img);
    gray_scale(img);
    blur(img);

    // Write output image 
    write_image(img, output_filename);

    // Free memory 
    free_image(img);

    return 0;
}