//FormAI DATASET v1.0 Category: Image Classification system ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_IMAGES 1000
#define MAX_IMAGE_SIZE 1000

// Struct for storing image data
typedef struct Image {
    int height;
    int width;
    int pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} Image;

// Struct for storing training data
typedef struct TrainingData {
    int num_images;
    Image images[MAX_NUM_IMAGES];
    int labels[MAX_NUM_IMAGES];
} TrainingData;

// Function for reading in image data from file
void read_image_file(char *filename, Image *image) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read in image dimensions
    fscanf(fp, "%d %d", &image->height, &image->width);

    // Read in pixel values
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fscanf(fp, "%d", &image->pixels[i][j]);
        }
    }

    fclose(fp);
}

// Function for reading in training data from file
void read_training_data(char *filename, TrainingData *data) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read in number of images
    fscanf(fp, "%d", &data->num_images);

    // Read in each image and its corresponding label
    for (int i = 0; i < data->num_images; i++) {
        char image_filename[100];
        int label;
        fscanf(fp, "%s %d", image_filename, &label);
        read_image_file(image_filename, &data->images[i]);
        data->labels[i] = label;
    }

    fclose(fp);
}

// Function for classifying a new image
int classify_image(Image *image, TrainingData *data) {
    // Initialize counts for each label
    int label_count[10] = {0};

    // For each training image, calculate its distance from the new image
    for (int i = 0; i < data->num_images; i++) {
        int distance = 0;
        for (int j = 0; j < image->height; j++) {
            for (int k = 0; k < image->width; k++) {
                distance += abs(image->pixels[j][k] - data->images[i].pixels[j][k]);
            }
        }
        label_count[data->labels[i]] += distance;
    }

    // Find the label with the smallest count
    int min_count = label_count[0];
    int min_label = 0;
    for (int i = 1; i < 10; i++) {
        if (label_count[i] < min_count) {
            min_count = label_count[i];
            min_label = i;
        }
    }

    return min_label;
}

// Main function
int main() {
    // Read in training data
    TrainingData data;
    read_training_data("training_data.txt", &data);

    // Read in test image
    Image test_image;
    read_image_file("test_image.txt", &test_image);

    // Classify test image and print result
    int result = classify_image(&test_image, &data);
    printf("Test image classified as: %d\n", result);

    return 0;
}