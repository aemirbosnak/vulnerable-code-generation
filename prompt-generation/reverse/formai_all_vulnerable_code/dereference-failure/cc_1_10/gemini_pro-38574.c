//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    int channels;
    float *data;
} Image;

typedef struct {
    int num_classes;
    int class_dim;
    float *weights;
} Classifier;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    Image image;
    fread(&image.width, sizeof(int), 1, fp);
    fread(&image.height, sizeof(int), 1, fp);
    fread(&image.channels, sizeof(int), 1, fp);

    image.data = malloc(image.width * image.height * image.channels * sizeof(float));
    fread(image.data, sizeof(float), image.width * image.height * image.channels, fp);

    fclose(fp);

    return image;
}

void free_image(Image image) {
    free(image.data);
}

Classifier load_classifier(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    Classifier classifier;
    fread(&classifier.num_classes, sizeof(int), 1, fp);
    fread(&classifier.class_dim, sizeof(int), 1, fp);

    classifier.weights = malloc(classifier.num_classes * classifier.class_dim * sizeof(float));
    fread(classifier.weights, sizeof(float), classifier.num_classes * classifier.class_dim, fp);

    fclose(fp);

    return classifier;
}

void free_classifier(Classifier classifier) {
    free(classifier.weights);
}

float *predict(Image image, Classifier classifier) {
    float *scores = malloc(classifier.num_classes * sizeof(float));

    for (int i = 0; i < classifier.num_classes; i++) {
        float score = 0;
        for (int j = 0; j < image.width * image.height * image.channels; j++) {
            score += image.data[j] * classifier.weights[i * classifier.class_dim + j];
        }
        scores[i] = score;
    }

    return scores;
}

void print_scores(float *scores, int num_classes) {
    for (int i = 0; i < num_classes; i++) {
        printf("Class %d: %.2f\n", i, scores[i]);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image> <classifier>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Image image = load_image(argv[1]);
    Classifier classifier = load_classifier(argv[2]);

    float *scores = predict(image, classifier);

    print_scores(scores, classifier.num_classes);

    free_image(image);
    free_classifier(classifier);
    free(scores);

    return 0;
}