//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: beginner-friendly
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
  float *weights;
  float *biases;
} Classifier;

Image load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  int width, height, channels;
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);
  fread(&channels, sizeof(int), 1, fp);

  Image image = {width, height, channels, malloc(width * height * channels * sizeof(float))};

  fread(image.data, sizeof(float), width * height * channels, fp);

  fclose(fp);

  return image;
}

void free_image(Image image) {
  free(image.data);
}

Classifier load_classifier(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  int num_classes;
  fread(&num_classes, sizeof(int), 1, fp);

  Classifier classifier = {num_classes, malloc(num_classes * sizeof(float)), malloc(num_classes * sizeof(float))};

  fread(classifier.weights, sizeof(float), num_classes, fp);
  fread(classifier.biases, sizeof(float), num_classes, fp);

  fclose(fp);

  return classifier;
}

void free_classifier(Classifier classifier) {
  free(classifier.weights);
  free(classifier.biases);
}

float *predict(Image image, Classifier classifier) {
  float *scores = malloc(classifier.num_classes * sizeof(float));

  for (int i = 0; i < classifier.num_classes; i++) {
    float score = 0;
    for (int j = 0; j < image.width * image.height * image.channels; j++) {
      score += image.data[j] * classifier.weights[i * image.width * image.height * image.channels + j];
    }
    score += classifier.biases[i];
    scores[i] = score;
  }

  return scores;
}

int main() {
  Image image = load_image("image.jpg");
  Classifier classifier = load_classifier("classifier.dat");

  float *scores = predict(image, classifier);

  int max_score_index = 0;
  for (int i = 1; i < classifier.num_classes; i++) {
    if (scores[i] > scores[max_score_index]) {
      max_score_index = i;
    }
  }

  printf("Predicted class: %d\n", max_score_index);

  free_image(image);
  free_classifier(classifier);
  free(scores);

  return 0;
}