//FormAI DATASET v1.0 Category: Image Classification system ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int id;
    char* name;
    double* features;
} Image;

typedef struct {
    int id;
    char* name;
    double* weights;
} Classifier;

double dotProduct(double* a, double* b, int size) {
    double result = 0.0;
    for (int i=0; i<size; i++) {
        result += a[i] * b[i];
    }
    return result;
}

double euclideanDistance(double* a, double* b, int size) {
    double result = 0.0;
    for (int i=0; i<size; i++) {
        result += pow(a[i] - b[i], 2.0);
    }
    return sqrt(result);
}

int classify(Image* image, Classifier* classifiers, int num_classifiers, int num_features) {
    double* similarities = (double*) malloc(num_classifiers * sizeof(double));
    for (int i=0; i<num_classifiers; i++) {
        double similarity = dotProduct(image->features, classifiers[i].weights, num_features);
        similarities[i] = similarity;
    }

    int max_index = 0;
    double max_value = similarities[0];
    for (int i=1; i<num_classifiers; i++) {
        if (similarities[i] > max_value) {
            max_index = i;
            max_value = similarities[i];
        }
    }
    free(similarities);
    return max_index;
}

int main() {
    Image image1 = {1, "Romeo", (double[]) {1.0, 3.0, 5.0}};
    Image image2 = {2, "Juliet", (double[]) {2.0, 4.0, 6.0}};

    Classifier classifier1 = {1, "Knight", (double[]) {1.0, 0.0, 0.0}};
    Classifier classifier2 = {2, "Lady", (double[]) {0.0, 1.0, 0.0}};
    Classifier classifier3 = {3, "Family", (double[]) {0.0, 0.0, 1.0}};

    Image* images = (Image*) malloc(2 * sizeof(Image));
    images[0] = image1;
    images[1] = image2;

    Classifier* classifiers = (Classifier*) malloc(3 * sizeof(Classifier));
    classifiers[0] = classifier1;
    classifiers[1] = classifier2;
    classifiers[2] = classifier3;

    int num_images = 2;
    int num_classifiers = 3;
    int num_features = 3;

    for (int i=0; i<num_images; i++) {
        Image* image = &images[i];
        int label_index = classify(image, classifiers, num_classifiers, num_features);
        Classifier* classifier = &classifiers[label_index];
        printf("%s is classified as %s.\n", image->name, classifier->name);
    }

    free(images);
    free(classifiers);
    return 0;
}