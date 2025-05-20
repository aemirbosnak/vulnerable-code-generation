//FormAI DATASET v1.0 Category: Image Classification system ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEARNING_RATE 0.1
#define NUM_CLASSES 10
#define IMAGE_SIZE 28

typedef struct {
    double *weights;
    double bias;
} Neuron;

typedef struct {
    Neuron *neurons;
    int num_neurons;
} Layer;

typedef struct {
    int label;
    double *pixels;
} Image;

Layer create_layer(int num_neurons, int num_inputs) {
    Neuron *neurons = malloc(sizeof(Neuron)*num_neurons);
    for(int i = 0; i < num_neurons; i++) {
        neurons[i].weights = malloc(sizeof(double)*num_inputs);
        for(int j = 0; j < num_inputs; j++) {
            neurons[i].weights[j] = (double)rand()/RAND_MAX;
        }
        neurons[i].bias = (double)rand()/RAND_MAX;
    }
    Layer layer = {neurons, num_neurons};
    return layer;
}

void forward(double *inputs, Layer layer, double *outputs) {
    for(int i = 0; i < layer.num_neurons; i++) {
        double sum = layer.neurons[i].bias;
        for(int j = 0; j < IMAGE_SIZE*IMAGE_SIZE; j++) {
            sum += inputs[j]*layer.neurons[i].weights[j];
        }
        outputs[i] = 1/(1+exp(-sum));
    }
}

double sigmoid_prime(double x) {
    return exp(-x)/pow(1+exp(-x), 2);
}

void backward(double *outputs, double *expected_output, Layer layer, double *deltas) {
    for(int i = 0; i < layer.num_neurons; i++) {
        deltas[i] = (outputs[i] - expected_output[i])*sigmoid_prime(outputs[i]);
    }
}

void update_weights(double *inputs, Layer layer, double *deltas) {
    for(int i = 0; i < layer.num_neurons; i++) {
        for(int j = 0; j < IMAGE_SIZE*IMAGE_SIZE; j++) {
            layer.neurons[i].weights[j] -= LEARNING_RATE*deltas[i]*inputs[j];
        }
        layer.neurons[i].bias -= LEARNING_RATE*deltas[i];
    }
}

int predict(double *pixels, Layer hidden_layer, Layer output_layer) {
    double hidden_outputs[hidden_layer.num_neurons];
    forward(pixels, hidden_layer, hidden_outputs);
    double output[output_layer.num_neurons];
    forward(hidden_outputs, output_layer, output);
    int max_idx = 0;
    double max_val = output[0];
    for(int i = 1; i < output_layer.num_neurons; i++) {
        if(output[i] > max_val) {
            max_val = output[i];
            max_idx = i;
        }
    }
    return max_idx;
}

int main() {
    Layer hidden_layer = create_layer(20, IMAGE_SIZE*IMAGE_SIZE);
    Layer output_layer = create_layer(NUM_CLASSES, hidden_layer.num_neurons);
    Image train_set[60000];
    Image test_set[10000];
    printf("Loading training set...\n");
    FILE* train_file = fopen("train-images.idx3-ubyte", "r");
    FILE* label_file = fopen("train-labels.idx1-ubyte", "r");
    int magic_number, num_images, num_rows, num_cols;
    fread(&magic_number, sizeof(int), 1, train_file);
    fread(&num_images, sizeof(int), 1, train_file);
    fread(&num_rows, sizeof(int), 1, train_file);
    fread(&num_cols, sizeof(int), 1, train_file);
    magic_number = (magic_number>>24) | ((magic_number<<8)&0x00FF0000) | 
                   ((magic_number>>8)&0x0000FF00) | (magic_number<<24);
    num_images = (num_images>>24) | ((num_images<<8)&0x00FF0000) | 
                 ((num_images>>8)&0x0000FF00) | (num_images<<24);
    num_rows = (num_rows>>24) | ((num_rows<<8)&0x00FF0000) | 
               ((num_rows>>8)&0x0000FF00) | (num_rows<<24);
    num_cols = (num_cols>>24) | ((num_cols<<8)&0x00FF0000) | 
               ((num_cols>>8)&0x0000FF00) | (num_cols<<24);
    fread(&magic_number, sizeof(int), 1, label_file);
    fread(&num_images, sizeof(int), 1, label_file);
    magic_number = (magic_number>>24) | ((magic_number<<8)&0x00FF0000) | 
                   ((magic_number>>8)&0x0000FF00) | (magic_number<<24);
    num_images = (num_images>>24) | ((num_images<<8)&0x00FF0000) | 
                 ((num_images>>8)&0x0000FF00) | (num_images<<24);
    for(int i = 0; i < 60000; i++) {
        train_set[i].pixels = malloc(sizeof(double)*IMAGE_SIZE*IMAGE_SIZE);
        char pixel;
        fread(&pixel, sizeof(char), 1, train_file);
        for(int j = 0; j < IMAGE_SIZE*IMAGE_SIZE; j++) {
            fread(&pixel, sizeof(char), 1, train_file);
            train_set[i].pixels[j] = (double)pixel/255.0;
        }
        char label;
        fread(&label, sizeof(char), 1, label_file);
        train_set[i].label = label;
    }
    fclose(train_file);
    fclose(label_file);
    printf("Training network...\n");
    for(int i = 0; i < 10000; i++) {
        test_set[i].pixels = malloc(sizeof(double)*IMAGE_SIZE*IMAGE_SIZE);
        char pixel;
        FILE* test_file = fopen("t10k-images.idx3-ubyte", "r");
        FILE* test_label_file = fopen("t10k-labels.idx1-ubyte", "r");
        fread(&magic_number, sizeof(int), 1, test_file);
        fread(&num_images, sizeof(int), 1, test_file);
        fread(&num_rows, sizeof(int), 1, test_file);
        fread(&num_cols, sizeof(int), 1, test_file);
        magic_number = (magic_number>>24) | ((magic_number<<8)&0x00FF0000) | 
                       ((magic_number>>8)&0x0000FF00) | (magic_number<<24);
        num_images = (num_images>>24) | ((num_images<<8)&0x00FF0000) | 
                     ((num_images>>8)&0x0000FF00) | (num_images<<24);
        num_rows = (num_rows>>24) | ((num_rows<<8)&0x00FF0000) | 
                   ((num_rows>>8)&0x0000FF00) | (num_rows<<24);
        num_cols = (num_cols>>24) | ((num_cols<<8)&0x00FF0000) | 
                   ((num_cols>>8)&0x0000FF00) | (num_cols<<24);
        fread(&magic_number, sizeof(int), 1, test_label_file);
        fread(&num_images, sizeof(int), 1, test_label_file);
        magic_number = (magic_number>>24) | ((magic_number<<8)&0x00FF0000) | 
                       ((magic_number>>8)&0x0000FF00) | (magic_number<<24);
        num_images = (num_images>>24) | ((num_images<<8)&0x00FF0000) | 
                     ((num_images>>8)&0x0000FF00) | (num_images<<24);
        for(int j = 0; j < IMAGE_SIZE*IMAGE_SIZE; j++) {
            fread(&pixel, sizeof(char), 1, test_file);
            test_set[i].pixels[j] = (double)pixel/255.0;
        }
        char label;
        fread(&label, sizeof(char), 1, test_label_file);
        test_set[i].label = label;
        fclose(test_file);
        fclose(test_label_file);
        double hidden_outputs[hidden_layer.num_neurons];
        forward(test_set[i].pixels, hidden_layer, hidden_outputs);
        double output[output_layer.num_neurons];
        forward(hidden_outputs, output_layer, output);
        int prediction = predict(test_set[i].pixels, hidden_layer, output_layer);
        if(prediction == test_set[i].label) {
            printf("Test %d: Correct\n", i);
        } else {
            printf("Test %d: Incorrect\n", i);
        }
    }
    return 0;
}