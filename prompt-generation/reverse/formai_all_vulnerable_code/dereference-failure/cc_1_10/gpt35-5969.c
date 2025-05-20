//FormAI DATASET v1.0 Category: Image Classification system ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define NUM_CLASSES 3
#define IMG_SIZE 28

typedef unsigned char byte;

// Shape-shifting variables
int layers[NUM_CLASSES] = {IMG_SIZE, 10, 5, 3};
int num_layers = sizeof(layers) / sizeof(int);

// Helper function for the sigmoid activation function
float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

// Neural network prediction function
int predict(byte*** img, float**** weights_array) {
    float** layer_outputs = malloc(sizeof(float*) * num_layers);  

    // Input layer
    float* input_output = malloc(sizeof(float) * IMG_SIZE);
    for(int i = 0; i < IMG_SIZE; i++) {
        input_output[i] = (float) img[0][i / IMG_SIZE][i % IMG_SIZE] / 255.0;
    }
    layer_outputs[0] = input_output;

    // Hidden and output layers
    for(int l = 1; l < num_layers; l++) {  
        float* curr_output = malloc(sizeof(float) * layers[l]);
        for(int i = 0; i < layers[l]; i++) {  // For each node in the current layer
            float weighted_sum = 0;
            for(int j = 0; j < layers[l - 1]; j++) {  // For each node in the previous layer
                weighted_sum += layer_outputs[l - 1][j] * weights_array[l - 1][i][j / IMG_SIZE][j % IMG_SIZE];
            }
            curr_output[i] = sigmoid(weighted_sum);
        }
        layer_outputs[l] = curr_output;
    }

    // Prediction is the index of the output layer node with the highest value
    int pred = 0;
    for(int i = 0; i < layers[num_layers - 1]; i++) {
        if(layer_outputs[num_layers - 1][i] > layer_outputs[num_layers - 1][pred]) {
            pred = i;
        }
    }

    // Free memory
    for(int l = 0; l < num_layers; l++) {
        free(layer_outputs[l]);
    }
    free(layer_outputs);

    return pred;
}

int main() {
    // Load trained weights from files
    float**** weights_array = malloc(sizeof(float***) * (num_layers - 1));
    for(int l = 1; l < num_layers; l++) {  // For each layer (excluding input layer)
        weights_array[l - 1] = malloc(sizeof(float**) * layers[l]);
        for(int i = 0; i < layers[l]; i++) {  // For each node in the current layer
            weights_array[l - 1][i] = malloc(sizeof(float*) * layers[l - 1]);
            for(int j = 0; j < layers[l - 1]; j++) { // For each node in the previous layer
                char filename[MAX_FILENAME_LEN];
                sprintf(filename, "weights/layer%i_node%i_to_layer%i_node%i.txt", l - 1, j, l, i);
                FILE* f = fopen(filename, "r");
                weights_array[l - 1][i][j / IMG_SIZE][j % IMG_SIZE] = 0;
                fscanf(f, "%f", weights_array[l - 1][i][j / IMG_SIZE] + (j % IMG_SIZE));
                fclose(f);
            }
        }
    }

    // Path of image file to classify
    char filename[MAX_FILENAME_LEN] = "test_img.txt";
    byte*** img = malloc(sizeof(byte**) * IMG_SIZE);
    FILE* f = fopen(filename, "r");
    for(int i = 0; i < IMG_SIZE; i++) {
        img[i] = malloc(sizeof(byte*) * IMG_SIZE);
        for(int j = 0; j < IMG_SIZE; j++) {
            fscanf(f, "%hhu", img[i] + j);
        }
    }
    fclose(f);

    // Make prediction and print result
    int pred = predict(&img, weights_array);
    printf("The image is classified as class %i.\n", pred);

    // Free memory
    for(int i = 0; i < IMG_SIZE; i++) {
        free(img[i]);
    }
    free(img);
    for(int l = 1; l < num_layers; l++) {  // For each layer (excluding input layer)
        for(int i = 0; i < layers[l]; i++) {  // For each node in the current layer
            for(int j = 0; j < layers[l - 1]; j++) { // For each node in the previous layer
                free(weights_array[l - 1][i][j / IMG_SIZE]);
            }
            free(weights_array[l - 1][i]);
        }
        free(weights_array[l - 1]);
    }
    free(weights_array);

    return 0;
}