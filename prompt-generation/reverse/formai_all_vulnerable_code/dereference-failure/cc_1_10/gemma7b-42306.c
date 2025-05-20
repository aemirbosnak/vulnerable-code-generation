//Gemma-7B DATASET v1.0 Category: Image Classification system ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGES 10

struct Image {
  char *name;
  int label;
  struct Image *next;
};

struct Image *addImage(struct Image **head, char *name, int label) {
  struct Image *new_image = malloc(sizeof(struct Image));
  new_image->name = strdup(name);
  new_image->label = label;
  new_image->next = NULL;

  if (*head == NULL) {
    *head = new_image;
  } else {
    (*head)->next = new_image;
  }

  return new_image;
}

int classifyImage(struct Image *head, char *name) {
  struct Image *current = head;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      return current->label;
    }
    current = current->next;
  }

  return -1;
}

int main() {
  struct Image *head = NULL;

  addImage(&head, "image1.jpg", 1);
  addImage(&head, "image2.jpg", 2);
  addImage(&head, "image3.jpg", 1);

  int label = classifyImage(head, "image2.jpg");

  if (label != -1) {
    printf("Image label: %d\n", label);
  } else {
    printf("Image not found.\n");
  }

  return 0;
}