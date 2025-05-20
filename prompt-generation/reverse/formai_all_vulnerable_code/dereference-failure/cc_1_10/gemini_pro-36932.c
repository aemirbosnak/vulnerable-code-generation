//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 10

typedef struct {
  char* name;
  int num_images;
  int* images;
} class_t;

typedef struct {
  int num_classes;
  class_t* classes;
} image_classification_system_t;

image_classification_system_t* create_image_classification_system(int num_classes) {
  image_classification_system_t* system = malloc(sizeof(image_classification_system_t));
  system->num_classes = num_classes;
  system->classes = malloc(sizeof(class_t) * num_classes);
  for (int i = 0; i < num_classes; i++) {
    system->classes[i].name = NULL;
    system->classes[i].num_images = 0;
    system->classes[i].images = NULL;
  }
  return system;
}

void destroy_image_classification_system(image_classification_system_t* system) {
  for (int i = 0; i < system->num_classes; i++) {
    free(system->classes[i].name);
    free(system->classes[i].images);
  }
  free(system->classes);
  free(system);
}

int add_class(image_classification_system_t* system, char* name) {
  for (int i = 0; i < system->num_classes; i++) {
    if (strcmp(system->classes[i].name, name) == 0) {
      return -1;
    }
  }
  int class_index = system->num_classes++;
  system->classes = realloc(system->classes, sizeof(class_t) * system->num_classes);
  system->classes[class_index].name = strdup(name);
  system->classes[class_index].num_images = 0;
  system->classes[class_index].images = NULL;
  return class_index;
}

int add_image(image_classification_system_t* system, int class_index, int image_id) {
  if (class_index < 0 || class_index >= system->num_classes) {
    return -1;
  }
  class_t* class = &system->classes[class_index];
  class->num_images++;
  class->images = realloc(class->images, sizeof(int) * class->num_images);
  class->images[class->num_images - 1] = image_id;
  return 0;
}

int classify_image(image_classification_system_t* system, int image_id) {
  int best_class_index = -1;
  int best_num_images = -1;
  for (int i = 0; i < system->num_classes; i++) {
    class_t* class = &system->classes[i];
    int num_images = class->num_images;
    if (num_images > best_num_images) {
      best_class_index = i;
      best_num_images = num_images;
    }
  }
  return best_class_index;
}

int main() {
  image_classification_system_t* system = create_image_classification_system(MAX_CLASSES);
  add_class(system, "cat");
  add_class(system, "dog");
  add_image(system, 0, 1);
  add_image(system, 0, 2);
  add_image(system, 0, 3);
  add_image(system, 1, 4);
  add_image(system, 1, 5);
  add_image(system, 1, 6);
  int class_index = classify_image(system, 1);
  printf("Image 1 is classified as %s\n", system->classes[class_index].name);
  destroy_image_classification_system(system);
  return 0;
}