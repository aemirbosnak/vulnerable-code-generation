//FormAI DATASET v1.0 Category: Image Classification system ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome message
  printf("Welcome to our Image Classification System!\n");

  // Collect data
  printf("\nPlease input the number of images to classify: ");
  int num_images;
  scanf("%d", &num_images);

  // Allocate memory for arrays
  int* image_ids = malloc(num_images * sizeof(int));
  char** image_names = malloc(num_images * sizeof(char*));
  int* image_labels = malloc(num_images * sizeof(int));

  // Get image data
  printf("\nPlease input the data for each image.\n");
  for (int i = 0; i < num_images; i++) {
    printf("Image %d:\n", i+1);

    // Get ID
    printf("ID: ");
    scanf("%d", &image_ids[i]);

    // Get name
    printf("Name: ");
    char name[50];
    scanf("%s", name);
    image_names[i] = malloc(50 * sizeof(char));
    strcpy(image_names[i], name);

    // Get label
    printf("Label (1-10): ");
    int label;
    scanf("%d", &label);
    image_labels[i] = label;
  }

  // Classify images
  printf("\nClassifying images...\n");
  srand(time(NULL)); // Seed random number generator
  for (int i = 0; i < num_images; i++) {
    printf("Image %d (%s) classified as ", image_ids[i], image_names[i]);

    // Generate random label
    int random_label = rand() % 10 + 1;
    printf("%d\n", random_label);
  }

  // Free allocated memory
  for (int i = 0; i < num_images; i++) {
    free(image_names[i]);
  }
  free(image_ids);
  free(image_names);
  free(image_labels);

  // End program
  return 0;
}