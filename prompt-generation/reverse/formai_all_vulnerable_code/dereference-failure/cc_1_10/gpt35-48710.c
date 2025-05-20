//FormAI DATASET v1.0 Category: Image Classification system ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMG_SIZE 28 // Image size for this example is 28 x 28 pixels
#define IMG_LABELS 10 // Number of possible labels for this dataset

// Structure to hold a single image's data and associated label
typedef struct {
    int label; // Number from 0 to 9 indicating the true label of the image
    int pixels[IMG_SIZE][IMG_SIZE]; // Array of pixel values in the image
} Image;

// Function to train the image classification model
void train(Image *training_data, int num_images, double **weights) {
    int i, j, k;
    double activation, error;
    double learning_rate = 0.1; // Hyperparameter controlling the step size in weight updates

    // Initialize weights randomly between -1 and 1
    for (i = 0; i < IMG_SIZE * IMG_SIZE; i++) {
        for (j = 0; j < IMG_LABELS; j++) {
            weights[i][j] = (double) rand() / RAND_MAX * 2 - 1;
        }
    }

    // Train the model for a fixed number of iterations
    for (i = 0; i < 100; i++) {
        for (j = 0; j < num_images; j++) {
            // Feed the image forward through the network to get the predicted label
            activation = 0;
            for (k = 0; k < IMG_SIZE * IMG_SIZE; k++) {
                activation += training_data[j].pixels[k / IMG_SIZE][k % IMG_SIZE] * weights[k][training_data[j].label];
            }

            // Update the weights based on the prediction error and learning rate
            error = activation - 1;
            for (k = 0; k < IMG_SIZE * IMG_SIZE; k++) {
                weights[k][training_data[j].label] -= learning_rate * error * training_data[j].pixels[k / IMG_SIZE][k % IMG_SIZE];
            }
        }
    }
}

// Function to predict the label of a given image
int predict(Image *test_image, double **weights) {
    int i, j;
    double activation, highest_activation = -1;
    int predicted_label;

    // Feed the test image forward through the network for each label, keeping track of the highest activation score
    for (i = 0; i < IMG_LABELS; i++) {
        activation = 0;
        for (j = 0; j < IMG_SIZE * IMG_SIZE; j++) {
            activation += test_image->pixels[j / IMG_SIZE][j % IMG_SIZE] * weights[j][i];
        }
        if (activation > highest_activation) {
            predicted_label = i;
            highest_activation = activation;
        }
    }

    return predicted_label;
}

int main() {
    int i, j;
    int num_training_images = 60000;
    int num_test_images = 10000;
    double **weights = malloc(sizeof(double *) * IMG_SIZE * IMG_SIZE);
    for (i = 0; i < IMG_SIZE * IMG_SIZE; i++) {
        weights[i] = malloc(sizeof(double) * IMG_LABELS);
    }
    Image *training_data = malloc(sizeof(Image) * num_training_images);
    Image *test_data = malloc(sizeof(Image) * num_test_images);
    char buffer[100];
    FILE *fp;

    // Load the training data from file
    fp = fopen("mnist_train.csv", "r");
    for (i = 0; i < num_training_images; i++) {
        fscanf(fp, "%d,", &training_data[i].label);
        for (j = 0; j < IMG_SIZE * IMG_SIZE; j++) {
            if (j == IMG_SIZE * IMG_SIZE - 1) {
                fscanf(fp, "%d\n", &training_data[i].pixels[j / IMG_SIZE][j % IMG_SIZE]);
            } else {
                fscanf(fp, "%d,", &training_data[i].pixels[j / IMG_SIZE][j % IMG_SIZE]);
            }
        }
    }
    fclose(fp);

    // Load the test data from file
    fp = fopen("mnist_test.csv", "r");
    for (i = 0; i < num_test_images; i++) {
        fscanf(fp, "%d,", &test_data[i].label);
        for (j = 0; j < IMG_SIZE * IMG_SIZE; j++) {
            if (j == IMG_SIZE * IMG_SIZE - 1) {
                fscanf(fp, "%d\n", &test_data[i].pixels[j / IMG_SIZE][j % IMG_SIZE]);
            } else {
                fscanf(fp, "%d,", &test_data[i].pixels[j / IMG_SIZE][j % IMG_SIZE]);
            }
        }
    }
    fclose(fp);

    // Train the image classification model
    train(training_data, num_training_images, weights);

    // Predict the labels of the test images and print the accuracy
    int correct_predictions = 0;
    for (i = 0; i < num_test_images; i++) {
        if (predict(&test_data[i], weights) == test_data[i].label) {
            correct_predictions++;
        }
    }
    printf("Accuracy: %.2f%%\n", (double) correct_predictions / num_test_images * 100);

    // Free memory used by the program
    for (i = 0; i < IMG_SIZE * IMG_SIZE; i++) {
        free(weights[i]);
    }
    free(weights);
    free(training_data);
    free(test_data);

    return 0;
}