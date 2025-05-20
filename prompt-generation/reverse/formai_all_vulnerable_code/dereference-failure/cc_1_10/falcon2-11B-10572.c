//Falcon2-11B DATASET v1.0 Category: Image Classification system ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <float.h>

// Define the data structure for the image
struct Image {
    int width;
    int height;
    char** pixels;
};

// Function to read the image from a file
struct Image read_image(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    struct Image image;
    fscanf(file, "%d %d\n", &image.width, &image.height);
    image.pixels = (char**)malloc(image.width * sizeof(char*));
    for (int i = 0; i < image.width; i++) {
        image.pixels[i] = (char*)malloc(image.height * sizeof(char));
        for (int j = 0; j < image.height; j++) {
            fscanf(file, "%c", image.pixels[i][j]);
        }
    }
    fclose(file);

    return image;
}

// Function to classify the image
void classify_image(struct Image image) {
    int correct_classification = 0;

    // Convert the image to a feature vector
    int features[3] = {0};
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            if (image.pixels[i][j] == '1') {
                features[0]++;
            } else if (image.pixels[i][j] == '2') {
                features[1]++;
            } else {
                features[2]++;
            }
        }
    }

    // Perform the classification
    int classes[] = {0, 1, 2};
    int max_class = -1;
    for (int i = 0; i < 3; i++) {
        if (features[i] > max_class) {
            max_class = features[i];
            correct_classification = i;
        }
    }

    // Print the results
    printf("Image class: %d\n", correct_classification);
}

// Main function
int main() {
    struct Image image = read_image("image.txt");
    classify_image(image);
    return 0;
}