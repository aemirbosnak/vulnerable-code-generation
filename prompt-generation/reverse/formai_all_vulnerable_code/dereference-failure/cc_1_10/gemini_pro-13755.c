//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 10
#define MAX_FEATURES 100

typedef struct {
    char name[50];
    int features[MAX_FEATURES];
} Image;

Image images[MAX_CLASSES];
int num_classes;

void load_images() {
    FILE *fp = fopen("images.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        char *name = strtok(line, ",");
        int features[MAX_FEATURES];
        for (int i = 0; i < MAX_FEATURES; i++) {
            features[i] = atoi(strtok(NULL, ","));
        }

        strcpy(images[num_classes].name, name);
        memcpy(images[num_classes].features, features, sizeof(features));
        num_classes++;
    }

    fclose(fp);
}

void classify_image(Image image) {
    int distances[MAX_CLASSES];
    for (int i = 0; i < num_classes; i++) {
        int distance = 0;
        for (int j = 0; j < MAX_FEATURES; j++) {
            distance += abs(image.features[j] - images[i].features[j]);
        }
        distances[i] = distance;
    }

    int min_distance = distances[0];
    int min_distance_index = 0;
    for (int i = 1; i < num_classes; i++) {
        if (distances[i] < min_distance) {
            min_distance = distances[i];
            min_distance_index = i;
        }
    }

    printf("The image is most likely a %s.\n", images[min_distance_index].name);
}

int main() {
    load_images();

    Image image;
    printf("Enter the name of the image: ");
    scanf("%s", image.name);

    printf("Enter the features of the image (comma-separated): ");
    char line[100];
    scanf(" %[^\n]", line);
    char *features = strtok(line, ",");
    for (int i = 0; i < MAX_FEATURES; i++) {
        image.features[i] = atoi(features);
        features = strtok(NULL, ",");
    }

    classify_image(image);

    return 0;
}