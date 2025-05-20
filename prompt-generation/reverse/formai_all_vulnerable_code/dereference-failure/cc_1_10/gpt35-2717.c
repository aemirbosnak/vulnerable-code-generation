//FormAI DATASET v1.0 Category: Image Classification system ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of classes and the number of features per image
#define NUM_CLASSES 5
#define NUM_FEATURES 10
#define MAX_LINE 100

// Define the data structure for each image
typedef struct Image {
    int class;
    float features[NUM_FEATURES];
} Image;

// Define the data structure for the classification model
typedef struct Model {
    float weights[NUM_FEATURES];
} Model;

// Function to read the data from a file and store it in an array of Images
int readData(char* filename, Image* data[]) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening %s\n", filename);
        return -1;
    }

    char line[MAX_LINE];
    int imageIndex = 0;
    while (fgets(line, MAX_LINE, fp) != NULL) {
        char* token = strtok(line, ",");
        Image* image = (Image*)malloc(sizeof(Image));

        // First token is the class label
        image->class = atoi(token);

        // Remaining tokens are feature values
        int featureIndex = 0;
        while ((token = strtok(NULL, ",")) != NULL) {
            image->features[featureIndex++] = atof(token);
        }

        data[imageIndex++] = image;
    }

    fclose(fp);
    return imageIndex;
}

// Function to train the classification model
void trainModel(Image* trainingData[], int numTrainingData, Model* model) {
    // Initialize weights to 0
    for (int i = 0; i < NUM_FEATURES; i++) {
        model->weights[i] = 0.0f;
    }

    // Iterate through each training data and update weights based on predicted class
    for (int i = 0; i < numTrainingData; i++) {
        Image* image = trainingData[i];
        float predictedClass = 0.0f;

        // Calculate predicted class using dot product
        for (int j = 0; j < NUM_FEATURES; j++) {
            predictedClass += image->features[j] * model->weights[j];
        }

        // Update weights if predicted class is different from actual class
        if (predictedClass >= 0.0f && image->class == 0) {
            for (int j = 0; j < NUM_FEATURES; j++) {
                model->weights[j] = model->weights[j] - image->features[j];
            }
        } else if (predictedClass < 0.0f && image->class == 1) {
            for (int j = 0; j < NUM_FEATURES; j++) {
                model->weights[j] = model->weights[j] + image->features[j];
            }
        }
    }
}

// Function to classify a single image using the model
int classifyImage(Image* image, Model* model) {
    float predictedClass = 0.0f;

    // Calculate predicted class using dot product
    for (int j = 0; j < NUM_FEATURES; j++) {
        predictedClass += image->features[j] * model->weights[j];
    }

    return predictedClass >= 0.0f ? 0 : 1;
}

int main() {
    // Read training data
    Image* trainingData[100];
    int numTrainingData = readData("training_data.txt", trainingData);

    // Train model
    Model model;
    trainModel(trainingData, numTrainingData, &model);

    // Read test data
    Image* testData[100];
    int numTestData = readData("test_data.txt", testData);

    // Test model on test data
    int numCorrect = 0;
    for (int i = 0; i < numTestData; i++) {
        Image* image = testData[i];
        int predictedClass = classifyImage(image, &model);
        if (predictedClass == image->class) {
            numCorrect++;
        }
    }

    float accuracy = (float)numCorrect / numTestData * 100.0f;

    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}