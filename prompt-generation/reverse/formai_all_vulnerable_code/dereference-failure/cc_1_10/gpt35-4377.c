//FormAI DATASET v1.0 Category: Image Classification system ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Define constants for the image size
#define ROWS 28
#define COLS 28

// Define the number of classes
#define NUM_CLASSES 10

// Function to get user input for the file path
char* get_file_path() {
    char* file_path = malloc(100 * sizeof(char));
    printf("Enter the file path for the image: ");
    scanf("%s", file_path);
    return file_path;
}

// Function to convert the input image into a binary array
void convert_image_to_binary(char* file_path, int* image) {
    FILE* fp = fopen(file_path, "r");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            char c = fgetc(fp);
            while (!isdigit(c)) {
                c = fgetc(fp);
            }
            image[i * COLS + j] = (int) c - '0';
        }
    }

    fclose(fp);
}

// Function to display the input image as binary
void display_image(int* image) {
    printf("Input Image:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", image[i * COLS + j]);
        }
        printf("\n");
    }
}

// Function to classify the input image
int classify_image(int* image, int** model) {
    // Initialize max probability and predicted class
    float max_prob = 0.0;
    int predicted_class = -1;

    // Loop through each class
    for (int i = 0; i < NUM_CLASSES; i++) {
        // Initialize probability for current class
        float prob = 1.0;

        // Loop through each pixel in the image and calculate the probability for the current class
        for (int j = 0; j < ROWS * COLS; j++) {
            if (image[j] == 0) {
                prob *= 1.0 - (float) model[i][j] / 255.0;
            } else {
                prob *= (float) model[i][j] / 255.0;
            }
        }

        // If the probability for the current class is greater than the max probability, update the max probability and predicted class
        if (prob > max_prob) {
            max_prob = prob;
            predicted_class = i;
        }
    }

    return predicted_class;
}

int main() {
    // Load the model from file
    int** model = malloc(NUM_CLASSES * sizeof(int*));
    for (int i = 0; i < NUM_CLASSES; i++) {
        model[i] = malloc(ROWS * COLS * sizeof(int));
        char file_name[20];
        sprintf(file_name, "class%d.txt", i);
        FILE* fp = fopen(file_name, "r");
        for (int j = 0; j < ROWS * COLS; j++) {
            fscanf(fp, "%d", &model[i][j]);
        }
        fclose(fp);
    }

    // Get the input image and display it
    char* file_path = get_file_path();
    int* image = malloc(ROWS * COLS * sizeof(int));
    convert_image_to_binary(file_path, image);
    display_image(image);

    // Classify the input image and display the predicted class
    int pred = classify_image(image, model);
    printf("Predicted Class: %d\n", pred);

    // Free memory
    free(file_path);
    free(image);
    for (int i = 0; i < NUM_CLASSES; i++) {
        free(model[i]);
    }
    free(model);

    return 0;
}