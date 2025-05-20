//FormAI DATASET v1.0 Category: Image Classification system ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define INPUT_WIDTH 32
#define INPUT_HEIGHT 32
#define INPUT_CHANNELS 3
#define NUM_CLASSES 10

// Define the fully connected layer
typedef struct FullyConnectedLayer {
    int input_size;
    int output_size;
    float** weights;
    float* output;
} FullyConnectedLayer;

// Initialize the fully connected layer with random weights
FullyConnectedLayer* init_fc_layer(int input_size, int output_size) {
    FullyConnectedLayer* layer = (FullyConnectedLayer*)malloc(sizeof(FullyConnectedLayer));
    layer->input_size = input_size;
    layer->output_size = output_size;
    layer->output = (float*)malloc(output_size * sizeof(float));
    layer->weights = (float**)malloc(output_size * sizeof(float*));
    for (int i = 0; i < output_size; i++) {
        layer->weights[i] = (float*)malloc(input_size * sizeof(float));
        for (int j = 0; j < input_size; j++) {
            layer->weights[i][j] = (float)rand() / RAND_MAX - 0.5f;
        }
    }
    return layer;
}

// Perform a forward pass on the fully connected layer
void fc_layer_forward(FullyConnectedLayer* layer, float* input) {
    for (int i = 0; i < layer->output_size; i++) {
        float sum = 0.0f;
        for (int j = 0; j < layer->input_size; j++) {
            sum += layer->weights[i][j] * input[j];
        }
        layer->output[i] = sum;
    }
}

int main() {
    // Initialize the input array with zeros (represents the image)
    float input[INPUT_WIDTH * INPUT_HEIGHT * INPUT_CHANNELS] = {0.0f};
    
    // Initialize the fully connected layers
    FullyConnectedLayer* fc_layer1 = init_fc_layer(INPUT_WIDTH * INPUT_HEIGHT * INPUT_CHANNELS, 128);
    FullyConnectedLayer* fc_layer2 = init_fc_layer(128, 64);
    FullyConnectedLayer* fc_layer3 = init_fc_layer(64, NUM_CLASSES);
    
    // Perform a forward pass through the layers
    fc_layer_forward(fc_layer1, input);
    fc_layer_forward(fc_layer2, fc_layer1->output);
    fc_layer_forward(fc_layer3, fc_layer2->output);
    
    // Print out the output probabilities for each class
    printf("Output probabilities:\n");
    for (int i = 0; i < NUM_CLASSES; i++) {
        printf("%d: %f\n", i, fc_layer3->output[i]);
    }

    // Clean up memory
    free(fc_layer1->output);
    for (int i = 0; i < fc_layer1->output_size; i++) {
        free(fc_layer1->weights[i]);
    }
    free(fc_layer1->weights);
    free(fc_layer1);
    free(fc_layer2->output);
    for (int i = 0; i < fc_layer2->output_size; i++) {
        free(fc_layer2->weights[i]);
    }
    free(fc_layer2->weights);
    free(fc_layer2);
    free(fc_layer3->output);
    for (int i = 0; i < fc_layer3->output_size; i++) {
        free(fc_layer3->weights[i]);
    }
    free(fc_layer3->weights);
    free(fc_layer3);

    return 0;
}