//Gemma-7B DATASET v1.0 Category: Image Classification system ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGES 10

typedef struct Image {
    char *name;
    int label;
    struct Image *next;
} Image;

Image *addImage(Image *head, char *name, int label) {
    Image *newImage = malloc(sizeof(Image));
    newImage->name = strdup(name);
    newImage->label = label;
    newImage->next = NULL;

    if (head == NULL) {
        head = newImage;
    } else {
        head->next = newImage;
    }

    return head;
}

int classifyImage(Image *head, char *name) {
    Image *currentImage = head;

    while (currentImage) {
        if (strcmp(currentImage->name, name) == 0) {
            return currentImage->label;
        }
        currentImage = currentImage->next;
    }

    return -1;
}

int main() {
    Image *images = NULL;

    addImage(images, "image1.jpg", 1);
    addImage(images, "image2.jpg", 2);
    addImage(images, "image3.jpg", 1);
    addImage(images, "image4.jpg", 2);

    int label = classifyImage(images, "image3.jpg");

    if (label != -1) {
        printf("Image %s is classified as label %d\n", "image3.jpg", label);
    } else {
        printf("Image not found\n");
    }

    return 0;
}