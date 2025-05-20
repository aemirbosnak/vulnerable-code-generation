//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int num_classes;
    int width;
    int height;
    float* data;
} Image;

typedef struct {
    int num_classes;
    float* data;
} Label;

Image* load_image(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    Image* image = malloc(sizeof(Image));
    fscanf(fp, "%d %d %d", &image->num_classes, &image->width, &image->height);
    image->data = malloc(image->num_classes * image->width * image->height * sizeof(float));
    fread(image->data, sizeof(float), image->num_classes * image->width * image->height, fp);
    fclose(fp);

    return image;
}

Label* load_label(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    Label* label = malloc(sizeof(Label));
    fscanf(fp, "%d", &label->num_classes);
    label->data = malloc(label->num_classes * sizeof(float));
    fread(label->data, sizeof(float), label->num_classes, fp);
    fclose(fp);

    return label;
}

int main() {
    Image* image = load_image("image.dat");
    Label* label = load_label("label.dat");

    // Your image classification code here

    free(image->data);
    free(image);
    free(label->data);
    free(label);

    return 0;
}