//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#define IMAGE_WIDTH 28
#define IMAGE_HEIGHT 28
#define NUM_CLASSES 10

typedef struct {
    float data[IMAGE_WIDTH * IMAGE_HEIGHT];
    uint8_t label;
} Image;

typedef struct {
    float weights[NUM_CLASSES * IMAGE_WIDTH * IMAGE_HEIGHT];
    float biases[NUM_CLASSES];
} Model;

Image* load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    Image* image = malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        return NULL;
    }

    fread(image->data, sizeof(float), IMAGE_WIDTH * IMAGE_HEIGHT, file);
    fread(&image->label, sizeof(uint8_t), 1, file);

    fclose(file);
    return image;
}

Model* load_model(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    Model* model = malloc(sizeof(Model));
    if (!model) {
        fclose(file);
        return NULL;
    }

    fread(model->weights, sizeof(float), NUM_CLASSES * IMAGE_WIDTH * IMAGE_HEIGHT, file);
    fread(model->biases, sizeof(float), NUM_CLASSES, file);

    fclose(file);
    return model;
}

float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

float dot_product(const float* a, const float* b, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

int predict(const Image* image, const Model* model) {
    float logits[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        logits[i] = dot_product(image->data, model->weights + i * IMAGE_WIDTH * IMAGE_HEIGHT, IMAGE_WIDTH * IMAGE_HEIGHT) + model->biases[i];
    }

    int max_index = 0;
    float max_value = -INFINITY;
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (logits[i] > max_value) {
            max_index = i;
            max_value = logits[i];
        }
    }

    return max_index;
}

int main() {
    Image* image = load_image("image.bin");
    if (!image) {
        printf("Error loading image.\n");
        return 1;
    }

    Model* model = load_model("model.bin");
    if (!model) {
        printf("Error loading model.\n");
        return 1;
    }

    int prediction = predict(image, model);
    printf("Predicted label: %d\n", prediction);

    free(image);
    free(model);
    return 0;
}