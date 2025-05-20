//FormAI DATASET v1.0 Category: Image Classification system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 50
#define HEIGHT 50

// Function to read the image
int* read_image(char* filename) {
    int* image = malloc(sizeof(int) * WIDTH * HEIGHT);

    FILE *fp;
    fp = fopen(filename, "r");

    char line[255];
    int row = 0;
    while (fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, ",");
        int col = 0;
        while (token != NULL) {
            image[row * WIDTH + col] = atoi(token);
            token = strtok(NULL, ",");
            col++;
        }
        row++;
    }

    fclose(fp);
    return image;
}

// Function to classify the image
int classify_image(int* image) {
    int num_pixels = WIDTH * HEIGHT;
    int sum = 0;
    for (int i = 0; i < num_pixels; i++) {
        sum += image[i];
    }

    int avg = sum / num_pixels;
    if (avg > 128) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int* image = read_image("image.csv");

    int result = classify_image(image);
    printf("The image is classified as: %d\n", result);

    free(image);
    return 0;
}