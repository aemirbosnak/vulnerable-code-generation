//FormAI DATASET v1.0 Category: Image Classification system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

// define a struct for storing image data
typedef struct _image {
    char filename[MAX_LEN];
    int width;
    int height;
    int** data;
} Image;

// define an array of Image structs to hold training data
Image trainingData[10];

// function to read image data from file
void readImageData(char* filename, Image* img) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    char line[MAX_LEN];
    fgets(line, MAX_LEN, file);
    sscanf(line, "%d %d", &img->width, &img->height);
    img->data = (int**) malloc(img->height * sizeof(int*));
    for (int i = 0; i < img->height; i++) {
        img->data[i] = (int*) malloc(img->width * sizeof(int));
        fgets(line, MAX_LEN, file);
        for (int j = 0; j < img->width; j++) {
            img->data[i][j] = (int) (line[j] - '0');
        }
    }
    fclose(file);
}

// function to train the classifier
void trainClassifier() {
    // read training data
    for (int i = 0; i < 10; i++) {
        char filename[MAX_LEN];
        sprintf(filename, "training_data/%d.txt", i);
        readImageData(filename, &trainingData[i]);
    }
    printf("Training complete\n");
}

// function to classify an image
int classifyImage(Image* img) {
    int bestMatch = -1;
    double bestMatchScore = 0.0;

    // calculate score for each training image
    for (int i = 0; i < 10; i++) {
        double score = 0.0;
        for (int j = 0; j < img->height; j++) {
            for (int k = 0; k < img->width; k++) {
                score += img->data[j][k] * trainingData[i].data[j][k];
            }
        }
        if (score > bestMatchScore) {
            bestMatch = i;
            bestMatchScore = score;
        }
    }

    return bestMatch;
}

int main() {
    trainClassifier();

    Image testImage;
    readImageData("test_data/5.txt", &testImage);
    int classificationResult = classifyImage(&testImage);

    printf("Classification result: %d\n", classificationResult);

    return 0;
}