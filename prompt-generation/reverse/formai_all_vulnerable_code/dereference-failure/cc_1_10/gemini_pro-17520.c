//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CLASSES 10
#define MAX_FEATURES 100

typedef struct {
  char *name;
  int num_features;
  float *features;
} Image;

typedef struct {
  char *name;
  int num_images;
  Image *images;
} Class;

Class classes[MAX_CLASSES];
int num_classes;

void load_data() {
  FILE *fp = fopen("data.csv", "r");
  if (fp == NULL) {
    perror("Error opening data file");
    exit(1);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    char *name = strtok(line, ",");
    int num_features = atoi(strtok(NULL, ","));
    float *features = malloc(num_features * sizeof(float));
    for (int i = 0; i < num_features; i++) {
      features[i] = atof(strtok(NULL, ","));
    }

    Image image = {name, num_features, features};

    if (num_classes == MAX_CLASSES) {
      fprintf(stderr, "Error: Too many classes\n");
      exit(1);
    }

    Class *class = &classes[num_classes];
    class->name = strdup(name);
    class->num_images = 1;
    class->images = malloc(sizeof(Image));
    class->images[0] = image;
    
    num_classes++;
  }

  fclose(fp);
}

void free_data() {
  for (int i = 0; i < num_classes; i++) {
    Class *class = &classes[i];
    free(class->name);
    for (int j = 0; j < class->num_images; j++) {
      Image *image = &class->images[j];
      free(image->name);
      free(image->features);
    }
    free(class->images);
  }
}

void print_data() {
  for (int i = 0; i < num_classes; i++) {
    Class *class = &classes[i];
    printf("Class: %s\n", class->name);
    for (int j = 0; j < class->num_images; j++) {
      Image *image = &class->images[j];
      printf("  Image: %s\n", image->name);
      for (int k = 0; k < image->num_features; k++) {
        printf("    Feature %d: %f\n", k, image->features[k]);
      }
    }
  }
}

int main() {
  load_data();
  print_data();
  free_data();

  return 0;
}