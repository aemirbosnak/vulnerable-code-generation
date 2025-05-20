//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 28
#define IMAGE_HEIGHT 28

typedef struct {
    float data[IMAGE_WIDTH * IMAGE_HEIGHT];
    int label;
} Image;

typedef struct {
    float weights[IMAGE_WIDTH * IMAGE_HEIGHT][10];
    float biases[10];
} Classifier;

Image read_image(char *filename) {
    Image image;
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }
    fread(image.data, sizeof(float), IMAGE_WIDTH * IMAGE_HEIGHT, file);
    fread(&image.label, sizeof(int), 1, file);
    fclose(file);
    return image;
}

Classifier train_classifier(Image *images, int num_images) {
    Classifier classifier;
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
        for (int j = 0; j < 10; j++) {
            classifier.weights[i][j] = 0.0;
        }
    }
    for (int i = 0; i < 10; i++) {
        classifier.biases[i] = 0.0;
    }
    for (int i = 0; i < num_images; i++) {
        for (int j = 0; j < IMAGE_WIDTH * IMAGE_HEIGHT; j++) {
            for (int k = 0; k < 10; k++) {
                classifier.weights[j][k] += images[i].data[j] * (images[i].label == k ? 1.0 : 0.0);
            }
        }
        for (int k = 0; k < 10; k++) {
            classifier.biases[k] += images[i].label == k ? 1.0 : 0.0;
        }
    }
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
        for (int j = 0; j < 10; j++) {
            classifier.weights[i][j] /= num_images;
        }
    }
    for (int i = 0; i < 10; i++) {
        classifier.biases[i] /= num_images;
    }
    return classifier;
}

int classify_image(Classifier classifier, Image image) {
    float scores[10];
    for (int i = 0; i < 10; i++) {
        scores[i] = 0.0;
        for (int j = 0; j < IMAGE_WIDTH * IMAGE_HEIGHT; j++) {
            scores[i] += classifier.weights[j][i] * image.data[j];
        }
        scores[i] += classifier.biases[i];
    }
    int max_score_index = 0;
    for (int i = 1; i < 10; i++) {
        if (scores[i] > scores[max_score_index]) {
            max_score_index = i;
        }
    }
    return max_score_index;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <training-data> <test-data>\n", argv[0]);
        exit(1);
    }
    Image *training_images = malloc(sizeof(Image) * 60000);
    for (int i = 0; i < 60000; i++) {
        char filename[256];
        sprintf(filename, "%s/%d.pgm", argv[1], i);
        training_images[i] = read_image(filename);
    }
    Classifier classifier = train_classifier(training_images, 60000);
    Image *test_images = malloc(sizeof(Image) * 10000);
    for (int i = 0; i < 10000; i++) {
        char filename[256];
        sprintf(filename, "%s/%d.pgm", argv[2], i);
        test_images[i] = read_image(filename);
    }
    int num_correct = 0;
    for (int i = 0; i < 10000; i++) {
        int predicted_label = classify_image(classifier, test_images[i]);
        if (predicted_label == test_images[i].label) {
            num_correct++;
        }
    }
    printf("Accuracy: %f\n", (float)num_correct / 10000);
    free(training_images);
    free(test_images);
    return 0;
}