//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLASS_COUNT 10
#define IMAGE_SIZE 28 * 28
#define MAX_ITERATIONS 1000

typedef struct {
    float *data;
    int label;
} Image;

typedef struct {
    float *weights;
    int bias;
} Classifier;

Image *load_image(const char *path) {
    FILE *file = fopen(path, "rb");
    if (!file) {
        perror("Failed to open image file");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    image->data = malloc(IMAGE_SIZE * sizeof(float));
    if (!image->data) {
        perror("Failed to allocate memory for image data");
        fclose(file);
        free(image);
        return NULL;
    }

    fread(image->data, sizeof(float), IMAGE_SIZE, file);
    fclose(file);

    return image;
}

Classifier *create_classifier() {
    Classifier *classifier = malloc(sizeof(Classifier));
    classifier->weights = malloc(CLASS_COUNT * IMAGE_SIZE * sizeof(float));
    classifier->bias = 0;
    return classifier;
}

void train_classifier(Classifier *classifier, Image **images, int image_count) {
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        for (int j = 0; j < image_count; j++) {
            float *image_data = images[j]->data;
            int image_label = images[j]->label;

            float *weights = classifier->weights;
            int bias = classifier->bias;

            float output = 0;
            for (int k = 0; k < IMAGE_SIZE; k++) {
                output += image_data[k] * weights[k];
            }
            output += bias;

            float error = image_label - output;

            for (int k = 0; k < IMAGE_SIZE; k++) {
                weights[k] += error * image_data[k];
            }
            bias += error;
        }
    }
}

int classify_image(Classifier *classifier, Image *image) {
    float *image_data = image->data;
    float *weights = classifier->weights;
    int bias = classifier->bias;

    float output = 0;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        output += image_data[i] * weights[i];
    }
    output += bias;

    return (int)round(output);
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void free_classifier(Classifier *classifier) {
    free(classifier->weights);
    free(classifier);
}

int main() {
    const char *image_paths[] = {
        "image1.dat",
        "image2.dat",
        "image3.dat",
        "image4.dat",
        "image5.dat",
    };

    const int image_labels[] = {
        0,
        1,
        2,
        3,
        4,
    };

    int image_count = sizeof(image_paths) / sizeof(image_paths[0]);

    Image **images = malloc(image_count * sizeof(Image *));
    for (int i = 0; i < image_count; i++) {
        images[i] = load_image(image_paths[i]);
        if (!images[i]) {
            return EXIT_FAILURE;
        }
    }

    Classifier *classifier = create_classifier();
    train_classifier(classifier, images, image_count);

    for (int i = 0; i < image_count; i++) {
        int prediction = classify_image(classifier, images[i]);
        printf("Predicted label for image %d: %d (actual: %d)\n", i + 1, prediction, image_labels[i]);
    }

    for (int i = 0; i < image_count; i++) {
        free_image(images[i]);
    }
    free(images);

    free_classifier(classifier);

    return EXIT_SUCCESS;
}