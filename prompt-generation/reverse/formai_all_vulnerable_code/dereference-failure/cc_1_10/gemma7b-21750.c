//Gemma-7B DATASET v1.0 Category: Image Classification system ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 5

typedef struct ImageData {
  char **pixels;
  int width;
  int height;
  int label;
} ImageData;

ImageData **loadData(char *filename) {
  // Read image file and create image data structure
  ImageData **image = malloc(sizeof(ImageData *) * MAX_CLASSES);
  for (int i = 0; i < MAX_CLASSES; i++) {
    image[i] = malloc(sizeof(ImageData));
  }

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Get image width and height
  image[0]->width = 224;
  image[0]->height = 224;

  // Allocate pixels
  image[0]->pixels = malloc(image[0]->width * image[0]->height * sizeof(char));

  // Read pixels and label from file
  for (int y = 0; y < image[0]->height; y++) {
    for (int x = 0; x < image[0]->width; x++) {
      image[0]->pixels[y * image[0]->width + x] = fgetc(file);
    }
  }

  image[0]->label = fgetc(file);

  fclose(file);

  return image;
}

int main() {
  // Load image data
  ImageData **image = loadData("image.jpg");

  // Print label
  printf("Label: %d\n", image[0]->label);

  // Free memory
  for (int i = 0; i < MAX_CLASSES; i++) {
    free(image[i]->pixels);
    free(image[i]);
  }
  free(image);

  return 0;
}