//Falcon2-11B DATASET v1.0 Category: Image Classification system ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int numImages = 0;
int numClasses = 0;
float *imageData;
int *classLabels;

// Function to classify an image
void classifyImage(float imageData[], int classLabels[], int numImages, int numClasses) {
    int maxClass = 0;
    float maxScore = 0.0;

    for (int i = 0; i < numClasses; i++) {
        float score = 0.0;
        for (int j = 0; j < numImages; j++) {
            score += imageData[j * numClasses + i];
        }
        score /= numImages;

        if (score > maxScore) {
            maxScore = score;
            maxClass = i;
        }
    }

    printf("Classification: %d\n", maxClass);
}

int main() {
    // Read image data
    char *imageDataFile = "imageData.bin";
    FILE *fp = fopen(imageDataFile, "rb");
    if (!fp) {
        printf("Error opening image data file!\n");
        return 1;
    }

    int numImages = fread(&numImages, sizeof(int), 1, fp);
    if (numImages!= 1) {
        printf("Error reading number of images from file!\n");
        fclose(fp);
        return 1;
    }

    int numClasses = fread(&numClasses, sizeof(int), 1, fp);
    if (numClasses!= 1) {
        printf("Error reading number of classes from file!\n");
        fclose(fp);
        return 1;
    }

    imageData = (float *)malloc(numImages * numClasses * sizeof(float));
    classLabels = (int *)malloc(numClasses * sizeof(int));

    if (!imageData ||!classLabels) {
        printf("Error allocating memory for image data and class labels!\n");
        fclose(fp);
        return 1;
    }

    fread(imageData, sizeof(float), numImages * numClasses, fp);
    fread(classLabels, sizeof(int), numClasses, fp);
    fclose(fp);

    // Classify the images
    classifyImage(imageData, classLabels, numImages, numClasses);

    free(imageData);
    free(classLabels);

    return 0;
}