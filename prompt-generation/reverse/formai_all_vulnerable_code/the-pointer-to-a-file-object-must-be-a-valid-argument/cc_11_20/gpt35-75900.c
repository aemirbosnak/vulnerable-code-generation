//FormAI DATASET v1.0 Category: Image Classification system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 100
#define MAX_IMAGES 1000

int main(int argc, char *argv[]) {

    // Define variables
    int i, j, k, l, m, n;
    int imageCount = 0;
    int imageSize = 0;
    int targetLabel = 0;
    int targetImageIndex = 0;
    double image[MAX_IMAGES][MAX_LINE_LENGTH];
    double weights[MAX_LINE_LENGTH];
    double tolerance = 0.1;
    double eta = 0.1;

    // Read input file
    FILE *filePtr = fopen(argv[1], "r");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, filePtr) != NULL) {
        if (imageCount >= MAX_IMAGES) {
            printf("Error: Too many images.\n");
            return 1;
        }
        char *token = strtok(line, ",");
        j = 0;
        while (token != NULL) {
            image[imageCount][j++] = atof(token);
            token = strtok(NULL, ",");
        }
        imageCount++;
        imageSize = j;
    }
    fclose(filePtr);

    // Initialize weights randomly
    for (i = 0; i < imageSize; i++) {
        weights[i] = (double) rand() / RAND_MAX;
    }

    // Train the model
    printf("Training...\n");
    int iterations = 0;
    while (1) {
        double maxDiff = 0.0;
        for (i = 0; i < imageCount; i++) {
            // Find the target label and calculate the net input
            targetLabel = (int) image[i][imageSize-1];
            double netInput = 0.0;
            for (j = 0; j < imageSize-1; j++) {
                netInput += image[i][j] * weights[j];
            }

            // Apply the activation function and calculate error
            double activation = netInput >= 0 ? 1 : -1;
            double error = targetLabel - activation;

            // Update the weights
            maxDiff = error > maxDiff ? error : maxDiff;
            for (k = 0; k < imageSize-1; k++) {
                weights[k] += eta * error * image[i][k];
            }
        }
        if (maxDiff < tolerance) break;
        iterations++;
    }
    printf("Training finished after %d iterations.\n", iterations);

    // Test the model
    printf("Testing...\n");
    int correctCount = 0;
    int testCount = 0;
    for (i = 0; i < imageCount; i++) {
        // Find the target label and calculate the net input
        targetLabel = (int) image[i][imageSize-1];
        double netInput = 0.0;
        for (j = 0; j < imageSize-1; j++) {
            netInput += image[i][j] * weights[j];
        }

        // Apply the activation function and calculate error
        double activation = netInput >= 0 ? 1 : -1;
        double error = targetLabel - activation;

        // Check if the prediction is correct
        if (error == 0) correctCount++;
        testCount++;
    }
    printf("Testing finished. Accuracy: %.2f%%\n", (double) correctCount / testCount * 100);

    return 0;
}