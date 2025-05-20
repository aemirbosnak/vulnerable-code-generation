//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    int depth;
    float* data;
} Image;

void displayImage(Image image);
void readImage(char* filename, Image* image);
void writeImage(char* filename, Image* image);

int main() {
    Image image;

    srand(time(NULL));

    image.width = rand() % 1000 + 1;
    image.height = rand() % 1000 + 1;
    image.depth = 3;
    image.data = (float*)malloc(image.width * image.height * image.depth * sizeof(float));

    readImage("input.ppm", &image);

    for (int i = 0; i < image.width * image.height * image.depth; i++) {
        image.data[i] = (float)rand() / (float)RAND_MAX;
    }

    displayImage(image);

    writeImage("output.ppm", &image);

    free(image.data);

    return 0;
}

void displayImage(Image image) {
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            for (int z = 0; z < image.depth; z++) {
                printf("%f ", image.data[y * image.width * image.depth + x * image.depth + z]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void readImage(char* filename, Image* image) {
    FILE* file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    fscanf(file, "%d %d %d\n", &image->width, &image->height, &image->depth);

    image->data = (float*)malloc(image->width * image->height * image->depth * sizeof(float));

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int z = 0; z < image->depth; z++) {
                fscanf(file, "%f\n", &image->data[y * image->width * image->depth + x * image->depth + z]);
            }
        }
    }

    fclose(file);
}

void writeImage(char* filename, Image* image) {
    FILE* file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    fprintf(file, "%d %d %d\n", image->width, image->height, image->depth);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int z = 0; z < image->depth; z++) {
                fprintf(file, "%f ", image->data[y * image->width * image->depth + x * image->depth + z]);
            }
            fprintf(file, "\n");
        }
    }

    fclose(file);
}