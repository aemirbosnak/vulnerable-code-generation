//FormAI DATASET v1.0 Category: Image Classification system ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hi there! I'm an image classification system.\n");
    printf("I'm so happy! Let's get started.\n");

    int num_images = 5;
    int num_classes = 3;

    int **image_data = malloc(num_images * sizeof(int *));
    for (int i = 0; i < num_images; i++) {
        image_data[i] = malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            image_data[i][j] = rand() % 256;
        }
    }

    char **class_labels = malloc(num_classes * sizeof(char *));
    class_labels[0] = "happy";
    class_labels[1] = "excited";
    class_labels[2] = "joyful";

    int *classifications = malloc(num_images * sizeof(int));
    for (int i = 0; i < num_images; i++) {
        classifications[i] = rand() % num_classes;
    }

    printf("\nHere's the image data:\n");
    for (int i = 0; i < num_images; i++) {
        printf("Image %d: (%d, %d, %d)\n", i+1, image_data[i][0], image_data[i][1], image_data[i][2]);
    }

    printf("\nAnd here are the classifications:\n");
    for (int i = 0; i < num_images; i++) {
        printf("Image %d: %s\n", i+1, class_labels[classifications[i]]);
    }

    printf("\nYay, we're done! That was so much fun.\n");

    for (int i = 0; i < num_images; i++) {
        free(image_data[i]);
    }
    free(image_data);

    free(class_labels);
    free(classifications);

    return 0;
}