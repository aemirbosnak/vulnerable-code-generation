//FormAI DATASET v1.0 Category: Image Classification system ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define NUM_CLASSES 3
#define NUM_SAMPLES_PER_CLASS 5
#define IMAGE_SIZE 28

typedef struct {
    int label;
    int** pixels;
} Image;

typedef struct {
    int num_images_per_class;
    Image* images;
} Class;

typedef struct {
    int num_classes;
    Class* classes;
} ClassificationModel;


// Function for creating a new image
Image* create_image(int label, int** pixels) {
    Image* img = malloc(sizeof(Image));
    img->label = label;
    img->pixels = pixels;
    return img;
}

// Function for creating a new class
Class* create_class(int num_images_per_class) {
    Class* cls = malloc(sizeof(Class));
    cls->num_images_per_class = num_images_per_class;
    cls->images = malloc(sizeof(Image) * num_images_per_class);
    return cls;
}

// Function for computing the similarity between two images
float similarity(Image* img1, Image* img2) {
    float sim = 0.0;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            sim += abs(img1->pixels[i][j] - img2->pixels[i][j]);
        }
    }
    return sim;
}

// Function for classifying an image
int classify_image(Image* img, ClassificationModel* model) {
    int predicted_label = 0;
    float min_similarity = -1.0;
    for (int i = 0; i < model->num_classes; i++) {
        for (int j = 0; j < model->classes[i].num_images_per_class; j++) {
            float sim = similarity(img, &(model->classes[i].images[j]));
            if (sim < min_similarity || min_similarity == -1.0) {
                min_similarity = sim;
                predicted_label = model->classes[i].images[j].label;
            }
        }
    }
    return predicted_label;
}

// Main function for testing the program
int main() {
    ClassificationModel model;
    model.num_classes = NUM_CLASSES;
    model.classes = malloc(sizeof(Class) * NUM_CLASSES);
    int label = 0;
    int** pixels;
    for (int i = 0; i < NUM_CLASSES; i++) {
        model.classes[i] = *create_class(NUM_SAMPLES_PER_CLASS);
        for (int j = 0; j < NUM_SAMPLES_PER_CLASS; j++) {
            pixels = malloc(sizeof(int*) * IMAGE_SIZE);
            for (int k = 0; k < IMAGE_SIZE; k++) {
                pixels[k] = malloc(sizeof(int) * IMAGE_SIZE);
                for (int l = 0; l < IMAGE_SIZE; l++) {
                    pixels[k][l] = (rand() % 256);
                }
            }
            model.classes[i].images[j] = *create_image(label, pixels);
        }
        label++;
    }

    Image test_image;
    test_image.label = 0;
    test_image.pixels = malloc(sizeof(int*) * IMAGE_SIZE);
    for (int k = 0; k < IMAGE_SIZE; k++) {
        test_image.pixels[k] = malloc(sizeof(int) * IMAGE_SIZE);
        for (int l = 0; l < IMAGE_SIZE; l++) {
            test_image.pixels[k][l] = (rand() % 256);
        }
    }

    int predicted_label = classify_image(&test_image, &model);
    printf("Predicted label: %d\n", predicted_label);

    return 0;
}