//FormAI DATASET v1.0 Category: Image Classification system ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_SIZE 28*28
#define NUM_CLASSES 10

typedef struct {
    float input[IMAGE_SIZE];
    int label;
} Image;

typedef struct {
    float weights[IMAGE_SIZE][NUM_CLASSES];
} Model;

// Function to load image data from file
Image* load_image_data(char* filepath, int num_images) {
    FILE* fp = fopen(filepath, "r");
    Image* images = malloc(sizeof(Image) * num_images);
    if (fp == NULL || images == NULL) {
        printf("Error: Could not open file or allocate memory for images\n");
        exit(1);
    }

    for (int i = 0; i < num_images; i++) {
        // Read label
        images[i].label = fgetc(fp);

        // Read pixel values
        for (int j = 0; j < IMAGE_SIZE; j++) {
            images[i].input[j] = (float)fgetc(fp) / 255.0;
        }
    }
    fclose(fp);
    return images;
}

// Function to load model data from file
Model* load_model_data(char* filepath) {
    FILE* fp = fopen(filepath, "r");
    Model* model = malloc(sizeof(Model));
    if (fp == NULL || model == NULL) {
        printf("Error: Could not open file or allocate memory for model\n");
        exit(1);
    }

    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < NUM_CLASSES; j++) {
            fscanf(fp, "%f", &model->weights[i][j]);
        }
    }
    fclose(fp);
    return model;
}

// Function to classify an image using a given model
int classify_image(Image* image, Model* model) {
    int max_class = 0;
    float max_score = 0.0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        float score = 0.0;
        for (int j = 0; j < IMAGE_SIZE; j++) {
            score += image->input[j] * model->weights[j][i];
        }
        if (score > max_score) {
            max_score = score;
            max_class = i;
        }
    }
    return max_class;
}

int main(int argc, char* argv[]) {
    // Load test data
    int num_images = 5;
    Image* test_images = load_image_data("test_images.txt", num_images);

    // Load model data
    Model* model = load_model_data("model.txt");

    // Test classification accuracy
    int num_correct = 0;
    for (int i = 0; i < num_images; i++) {
        int prediction = classify_image(&test_images[i], model);
        if (prediction == test_images[i].label) {
            num_correct++;
        }
    }
    printf("Classification accuracy on test data: %d/%d\n", num_correct, num_images);

    // Free allocated memory
    free(test_images);
    free(model);
    return 0;
}