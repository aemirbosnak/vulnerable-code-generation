//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_IMAGES 1000
#define MAX_PIXELS 1000000
#define MAX_CLASSES 100

typedef struct {
  int width;
  int height;
  int channels;
  unsigned char *data;
} Image;

typedef struct {
  int num_images;
  Image images[MAX_IMAGES];
  int labels[MAX_IMAGES];
} Dataset;

typedef struct {
  int num_classes;
  float weights[MAX_CLASSES][MAX_PIXELS];
  float biases[MAX_CLASSES];
} Model;

void load_dataset(Dataset *dataset, char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fread(&dataset->num_images, sizeof(int), 1, file);

  for (int i = 0; i < dataset->num_images; i++) {
    fread(&dataset->images[i].width, sizeof(int), 1, file);
    fread(&dataset->images[i].height, sizeof(int), 1, file);
    fread(&dataset->images[i].channels, sizeof(int), 1, file);
    dataset->images[i].data = malloc(dataset->images[i].width * dataset->images[i].height * dataset->images[i].channels);
    fread(dataset->images[i].data, 1, dataset->images[i].width * dataset->images[i].height * dataset->images[i].channels, file);
    fread(&dataset->labels[i], sizeof(int), 1, file);
  }

  fclose(file);
}

void load_model(Model *model, char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fread(&model->num_classes, sizeof(int), 1, file);

  for (int i = 0; i < model->num_classes; i++) {
    fread(model->weights[i], sizeof(float), MAX_PIXELS, file);
    fread(&model->biases[i], sizeof(float), 1, file);
  }

  fclose(file);
}

void predict(Model *model, Image *image, int *prediction) {
  float scores[model->num_classes];

  for (int i = 0; i < model->num_classes; i++) {
    scores[i] = 0;
    for (int j = 0; j < image->width * image->height * image->channels; j++) {
      scores[i] += model->weights[i][j] * image->data[j];
    }
    scores[i] += model->biases[i];
  }

  *prediction = 0;
  float max_score = scores[0];
  for (int i = 1; i < model->num_classes; i++) {
    if (scores[i] > max_score) {
      max_score = scores[i];
      *prediction = i;
    }
  }
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <dataset_file> <model_file> <image_file>\n", argv[0]);
    exit(1);
  }

  Dataset dataset;
  load_dataset(&dataset, argv[1]);

  Model model;
  load_model(&model, argv[2]);

  Image image;
  FILE *file = fopen(argv[3], "rb");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fread(&image.width, sizeof(int), 1, file);
  fread(&image.height, sizeof(int), 1, file);
  fread(&image.channels, sizeof(int), 1, file);
  image.data = malloc(image.width * image.height * image.channels);
  fread(image.data, 1, image.width * image.height * image.channels, file);
  fclose(file);

  int prediction;
  predict(&model, &image, &prediction);

  printf("Predicted class: %d\n", prediction);

  return 0;
}