//FormAI DATASET v1.0 Category: Image Classification system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 28 * 28
#define HIDDEN_LAYER_SIZE 128
#define OUTPUT_SIZE 10
#define EPOCHS 10
#define LEARNING_RATE 0.1

typedef struct {
    float *values;
    float *bias;
    float **weights;
    int input_size;
    int output_size;
} Layer;

typedef struct {
    Layer *input_layer;
    Layer *hidden_layer;
    Layer *output_layer;
} NeuralNetwork;

float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

float sigmoid_derivative(float x) {
    return x * (1 - x);
}

void initialize_layer(Layer *layer, int input_size, int output_size) {
    layer->values = calloc(output_size, sizeof(float));
    layer->bias = calloc(output_size, sizeof(float));
    layer->weights = malloc(input_size * sizeof(float *));
    for (int i = 0; i < input_size; i++) {
        layer->weights[i] = malloc(output_size * sizeof(float));
        for (int j = 0; j < output_size; j++) {
            layer->weights[i][j] = ((float)rand()/RAND_MAX*2)-1;
        }
    }
    layer->input_size = input_size;
    layer->output_size = output_size;
}

void initialize_network(NeuralNetwork *network) {
    network->input_layer = malloc(sizeof(Layer));
    initialize_layer(network->input_layer, INPUT_SIZE, HIDDEN_LAYER_SIZE);
    network->hidden_layer = malloc(sizeof(Layer));
    initialize_layer(network->hidden_layer, HIDDEN_LAYER_SIZE, OUTPUT_SIZE);
    network->output_layer = malloc(sizeof(Layer));
    initialize_layer(network->output_layer, OUTPUT_SIZE, 0);
}

void feed_forward(Layer *layer, float *inputs) {
    for (int i = 0; i < layer->output_size; i++) {
        float sum = 0;
        for (int j = 0; j < layer->input_size; j++) {
            sum += inputs[j] * layer->weights[j][i];
        }
        layer->values[i] = sigmoid(sum + layer->bias[i]);
    }
}

void backpropagation(NeuralNetwork *network, float *inputs, int label) {
    float *output_error = malloc(OUTPUT_SIZE * sizeof(float));
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output_error[i] = network->output_layer->values[i] - (i == label ? 1 : 0);
    }
    float *hidden_error = malloc(HIDDEN_LAYER_SIZE * sizeof(float));
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        float sum = 0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            sum += network->hidden_layer->weights[i][j] * output_error[j];
        }
        hidden_error[i] = sum * sigmoid_derivative(network->hidden_layer->values[i]);
    }
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            float weight_delta = -LEARNING_RATE * hidden_error[j] * inputs[i];
            network->input_layer->weights[i][j] += weight_delta;
        }
    }
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            float weight_delta = -LEARNING_RATE * output_error[j] * network->hidden_layer->values[i];
            network->hidden_layer->weights[i][j] += weight_delta;
        }
    }
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        float bias_delta = -LEARNING_RATE * hidden_error[i];
        network->hidden_layer->bias[i] += bias_delta;
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        float bias_delta = -LEARNING_RATE * output_error[i];
        network->output_layer->bias[i] += bias_delta;
    }
    free(output_error);
    free(hidden_error);
}

void train(NeuralNetwork *network, float **inputs, int *labels, int size) {
    for (int i = 0; i < size; i++) {
        feed_forward(network->input_layer, inputs[i]);
        feed_forward(network->hidden_layer, network->input_layer->values);
        feed_forward(network->output_layer, network->hidden_layer->values);
        backpropagation(network, network->input_layer->values, labels[i]);
    }
}

int predict(NeuralNetwork *network, float *inputs) {
    feed_forward(network->input_layer, inputs);
    feed_forward(network->hidden_layer, network->input_layer->values);
    feed_forward(network->output_layer, network->hidden_layer->values);
    float max_output = -1;
    int max_index = -1;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        if (network->output_layer->values[i] > max_output) {
            max_output = network->output_layer->values[i];
            max_index = i;
        }
    }
    return max_index;
}

void print_image(float *image) {
    for (int i = 0; i < 28*28; i++) {
        printf("%c", image[i] > 0.5 ? '#' : ' ');
        if ((i+1) % 28 == 0) {
            printf("\n");
        }
    }
}

int main() {
    FILE *fl = fopen("train-images.bin","rb");
    int magic_number;
    int number_of_images;
    int n_rows;
    int n_cols;
    fread(&magic_number,sizeof(int),1,fl);
    magic_number = ntohl(magic_number);
    fread(&number_of_images,sizeof(int),1,fl);
    number_of_images = ntohl(number_of_images);
    fread(&n_rows,sizeof(int),1,fl);
    n_rows = ntohl(n_rows);
    fread(&n_cols,sizeof(int),1,fl);
    n_cols = ntohl(n_cols);
    float **images = malloc(number_of_images * sizeof(float *));
    for (int i = 0; i < number_of_images; i++) {
        images[i] = malloc(INPUT_SIZE * sizeof(float));
        unsigned char buffer[INPUT_SIZE];
        fread(buffer, sizeof(char), INPUT_SIZE, fl);
        for (int j = 0; j < INPUT_SIZE; j++) {
            images[i][j] = buffer[j] / 255.0;
        }
    }
    fclose(fl);
    FILE *fl2 = fopen("train-labels.bin","rb");
    fread(&magic_number,sizeof(int),1,fl2);
    magic_number = ntohl(magic_number);
    fread(&number_of_images,sizeof(int),1,fl2);
    number_of_images = ntohl(number_of_images);
    int *labels = malloc(number_of_images * sizeof(int));
    for (int i = 0; i < number_of_images; i++) {
        unsigned char buffer;
        fread(&buffer, sizeof(char), 1, fl2);
        labels[i] = buffer;
    }
    fclose(fl2);
    NeuralNetwork network;
    initialize_network(&network);
    for (int i = 0; i < EPOCHS; i++) {
        train(&network, images, labels, number_of_images);
        int correct_predictions = 0;
        for (int j = 0; j < number_of_images; j++) {
            int prediction = predict(&network, images[j]);
            if (prediction == labels[j]) {
                correct_predictions++;
            }
        }
        printf("Epoch %d: %d / %d correct predictions\n", i+1, correct_predictions, number_of_images);
    }
    printf("\n");
    while (1) {
        printf("Enter an image number: ");
        int image_number;
        scanf("%d", &image_number);
        if (image_number < 0 || image_number >= number_of_images) {
            break;
        }
        printf("\n");
        print_image(images[image_number]);
        printf("\nPrediction: %d\n\n", predict(&network, images[image_number]));
    }
    for (int i = 0; i < number_of_images; i++) {
        free(images[i]);
    }
    free(images);
    free(labels);
    for (int i = 0; i < INPUT_SIZE; i++) {
        free(network.input_layer->weights[i]);
    }
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        free(network.hidden_layer->weights[i]);
    }
    free(network.input_layer->values);
    free(network.input_layer->bias);
    free(network.input_layer->weights);
    free(network.input_layer);
    free(network.hidden_layer->values);
    free(network.hidden_layer->bias);
    free(network.hidden_layer->weights);
    free(network.hidden_layer);
    free(network.output_layer->bias);
    free(network.output_layer);
    return 0;
}