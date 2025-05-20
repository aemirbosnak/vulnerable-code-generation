//FormAI DATASET v1.0 Category: Image Classification system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 5
#define IMAGE_SIZE 100
#define MAX_FILENAME_LENGTH 100

// Function to read images from file
void read_images(float ***images, char **filenames, int num_images) {
    *images = (float **)malloc(num_images * sizeof(float *));
    for (int i = 0; i < num_images; i++) {
        (*images)[i] = (float *)malloc(IMAGE_SIZE * IMAGE_SIZE * sizeof(float));
        FILE *fp = fopen(filenames[i], "r");
        if (fp == NULL) {
            printf("File %s not found!\n", filenames[i]);
            exit(1);
        }
        // Read the image data into the memory
        for (int j = 0; j < IMAGE_SIZE * IMAGE_SIZE; j++) {
            fscanf(fp, "%f", &(*images)[i][j]);
        }
        fclose(fp);
    }
}

// Function to read labels from file
void read_labels(int **labels, char *filename, int num_images) {
    *labels = (int *)malloc(num_images * sizeof(int));
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File %s not found!\n", filename);
        exit(1);
    }
    // Read the label data into the memory
    for (int i = 0; i < num_images; i++) {
        fscanf(fp, "%d", &(*labels)[i]);
    }
    fclose(fp);
}

// Function to train the image classification model
void train_model(float **images, int *labels, float **weights, float *bias, int num_images, int num_epochs, float learning_rate) {
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        float cost = 0;
        for (int i = 0; i < num_images; i++) {
            float *image = images[i];
            int label = labels[i];

            // Calculate the predicted label
            float predicted_label = 0;
            for (int j = 0; j < IMAGE_SIZE * IMAGE_SIZE; j++) {
                predicted_label += image[j] * weights[label][j];
            }
            predicted_label += *bias;

            // Calculate the cost and update the weight and bias values
            float error = (predicted_label - label);
            if (error != 0) {
                *bias = *bias - learning_rate * error;
                for (int j = 0; j < IMAGE_SIZE * IMAGE_SIZE; j++) {
                    weights[label][j] -= learning_rate * error * image[j];
                }
                cost += error * error;
            }
        }
        printf("Epoch %d: Cost = %f\n", epoch+1, cost);
    }
}

// Function to predict the label of a given image
int predict_label(float *image, float **weights, float bias) {
    int predicted_label = 0;
    float max_score = -1;
    for (int i = 0; i < NUM_CLASSES; i++) {
        float score = 0;
        for (int j = 0; j < IMAGE_SIZE * IMAGE_SIZE; j++) {
            score += image[j] * weights[i][j];
        }
        score += bias;
        if (score > max_score) {
            predicted_label = i;
            max_score = score;
        }
    }
    return predicted_label;
}

// Function to test the accuracy of the image classification model
void test_model(float **images, int *labels, float **weights, float bias, int num_images) {
    int correct_count = 0;
    for (int i = 0; i < num_images; i++) {
        float *image = images[i];
        int label = labels[i];
        int predicted_label = predict_label(image, weights, bias);
        if (predicted_label == label) {
            correct_count++;
        }
    }
    float accuracy = ((float) correct_count / num_images) * 100;
    printf("Accuracy: %.2f%%\n", accuracy);
}

int main() {
    // Define the filenames and other parameters
    char *train_image_filenames[] = { "class0_train.txt", "class1_train.txt", "class2_train.txt", "class3_train.txt", "class4_train.txt" };
    char *train_label_filename = "train_labels.txt";

    char *test_image_filenames[] = { "class0_test.txt", "class1_test.txt", "class2_test.txt", "class3_test.txt", "class4_test.txt" };
    char *test_label_filename = "test_labels.txt";

    int num_train_images = 40;
    int num_test_images = 10;
    int num_epochs = 50;
    float learning_rate = 0.1;

    // Read the training images and labels
    float **train_images;
    read_images(&train_images, train_image_filenames, num_train_images);
    int *train_labels;
    read_labels(&train_labels, train_label_filename, num_train_images);

    // Initialize the weight and bias values randomly
    float **weights = (float **)malloc(NUM_CLASSES * sizeof(float *));
    for (int i = 0; i < NUM_CLASSES; i++) {
        weights[i] = (float *)malloc(IMAGE_SIZE * IMAGE_SIZE * sizeof(float));
        for (int j = 0; j < IMAGE_SIZE * IMAGE_SIZE; j++) {
            weights[i][j] = ((float) rand()) / RAND_MAX;
        }
    }
    float bias = 0;

    // Train the model
    train_model(train_images, train_labels, weights, &bias, num_train_images, num_epochs, learning_rate);

    // Read the test images and labels
    float **test_images;
    read_images(&test_images, test_image_filenames, num_test_images);
    int *test_labels;
    read_labels(&test_labels, test_label_filename, num_test_images);

    // Test the model
    test_model(test_images, test_labels, weights, bias, num_test_images);

    // Free the allocated memory
    for (int i = 0; i < num_train_images; i++) {
        free(train_images[i]);
    }
    free(train_images);
    free(train_labels);

    for (int i = 0; i < NUM_CLASSES; i++) {
        free(weights[i]);
    }
    free(weights);

    for (int i = 0; i < num_test_images; i++) {
        free(test_images[i]);
    }
    free(test_images);
    free(test_labels);

    return 0;
}