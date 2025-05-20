//Gemma-7B DATASET v1.0 Category: Image Classification system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_CLASSES 10

typedef struct ImageData {
  int label;
  double **pixels;
} ImageData;

ImageData **loadData(char *path) {
  ImageData **data = (ImageData **)malloc(sizeof(ImageData *) * NUM_CLASSES);
  for (int i = 0; i < NUM_CLASSES; i++) {
    data[i] = (ImageData *)malloc(sizeof(ImageData));
    data[i]->label = i;
    data[i]->pixels = (double **)malloc(sizeof(double *) * 224);
    for (int j = 0; j < 224; j++) {
      data[i]->pixels[j] = (double *)malloc(sizeof(double) * 3);
    }
  }

  FILE *fp = fopen(path, "r");
  if (fp == NULL) {
    return NULL;
  }

  // Read image data
  for (int i = 0; i < NUM_CLASSES; i++) {
    fscanf(fp, "%d ", &data[i]->label);
    for (int j = 0; j < 224; j++) {
      for (int k = 0; k < 3; k++) {
        fscanf(fp, "%lf ", &data[i]->pixels[j][k]);
      }
    }
  }

  fclose(fp);
  return data;
}

int main() {
  char *path = "images.txt";
  ImageData **data = loadData(path);

  // Classify image
  for (int i = 0; i < NUM_CLASSES; i++) {
    printf("Image %d belongs to class %d\n", i, data[i]->label);
  }

  // Free memory
  for (int i = 0; i < NUM_CLASSES; i++) {
    free(data[i]->pixels);
    free(data[i]);
  }
  free(data);

  return 0;
}