//FormAI DATASET v1.0 Category: Image Classification system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 3
#define IMAGE_SIZE 784 //28x28

//Dataset struct
typedef struct {
    float *data;
    int label;
} Data;

//Neural Network struct
typedef struct {
    float **weights;
    float *biases;
    int *layers;
    int num_layers;
} NeuralNetwork;

//Activation function - Sigmoid
float sigmoid(float z) {
    return 1.0f / (1.0f + expf(-z));
}

//Derivative of activation function - Sigmoid'
float sigmoid_prime(float z) {
    float s = sigmoid(z);
    return s * (1.0f - s);
}

//Create dataset
Data *create_dataset(float **images, int *labels, int num_images) {
    Data *dataset = malloc(sizeof(Data) * num_images);
    for(int i = 0; i < num_images; i++) {
        dataset[i].data = images[i];
        dataset[i].label = labels[i];
    }
    return dataset;
}

//Load images from file
float **load_images(char *file_path, int num_images) {
    float **images = malloc(sizeof(float *) * num_images);
    FILE *file = fopen(file_path, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    for(int i = 0; i < num_images; i++) {
        images[i] = malloc(sizeof(float) * IMAGE_SIZE);
        int index = 0;
        while((read = getline(&line, &len, file)) != -1) {
            char *tok = strtok(line, ",");
            while(tok != NULL) {
                images[i][index] = strtof(tok, NULL) / 255.0f;
                index++;
                tok = strtok(NULL, ",");
            }
        }
        fseek(file, 0, SEEK_SET);
    }

    fclose(file);
    if(line)
        free(line);

    return images;
}

//Load labels from file
int *load_labels(char *file_path, int num_labels) {
    int *labels = malloc(sizeof(int) * num_labels);
    FILE *file = fopen(file_path, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    for(int i = 0; i < num_labels; i++) {
        read = getline(&line, &len, file);
        labels[i] = atoi(line);
    }

    fclose(file);
    if(line)
        free(line);

    return labels;
}

//Initialize weights and biases for network
void init_network(NeuralNetwork *network) {
    for(int i = 0; i < network->num_layers - 1; i++) {
        int rows = network->layers[i];
        int cols = network->layers[i + 1];
        network->weights[i] = malloc(sizeof(float) * rows * cols);
        for(int j = 0; j < rows; j++) {
            for(int k = 0; k < cols; k++) {
                network->weights[i][j * cols + k] = ((float)rand()/(float)(RAND_MAX)) * 2.0f - 1.0f;
            }
            network->biases[i] = ((float)rand()/(float)(RAND_MAX)) * 2.0f - 1.0f;
        }
    }
}

//Forward propagate inputs through network
void forward(NeuralNetwork *network, float *inputs, float *outputs) {
    for(int i = 0; i < network->num_layers - 1; i++) {
        int rows = network->layers[i];
        int cols = network->layers[i + 1];
        float *z = malloc(sizeof(float) * cols);
        for(int j = 0; j < cols; j++) {
            float dot_prod = 0.0f;
            for(int k = 0; k < rows; k++) {
                dot_prod += inputs[k] * network->weights[i][k * cols + j];
            }
            z[j] = dot_prod + network->biases[i];
        }

        for(int j = 0; j < cols; j++) {
            outputs[j] = sigmoid(z[j]);
        }

        free(z);
        inputs = outputs;
        outputs += cols;
    }
}

//Calculate error between output and expected output
void calc_error(float *expected, float *outputs, int num_outputs, float *deltas) {
    for(int i = 0; i < num_outputs; i++) {
        deltas[i] = (expected[i] - outputs[i]) * sigmoid_prime(outputs[i]);
    }
}

//Backward propagate error through network
void backward(NeuralNetwork *network, float *inputs, float *deltas, float **weight_deltas, float *bias_deltas) {
    for(int i = network->num_layers - 2; i >= 0; i--) {
        int rows = network->layers[i];
        int cols = network->layers[i + 1];
        float *d = malloc(sizeof(float) * rows);

        for(int j = 0; j < rows; j++) {
            float dot_prod = 0.0f;
            for(int k = 0; k < cols; k++) {
                dot_prod += deltas[k] * network->weights[i][j * cols + k];
                weight_deltas[i][j * cols + k] += inputs[j] * deltas[k];
            }
            d[j] = dot_prod * sigmoid_prime(inputs[j]);
            bias_deltas[i] += deltas[j];
        }

        free(d);
        deltas = deltas - cols;
        inputs = inputs - rows;
    }
}

//Update weights and biases for network
void update_network(NeuralNetwork *network, float **weight_deltas, float *bias_deltas, int batch_size, float learning_rate) {
    for(int i = 0; i < network->num_layers - 1; i++) {
        int rows = network->layers[i];
        int cols = network->layers[i + 1];
        for(int j = 0; j < rows; j++) {
            for(int k = 0; k < cols; k++) {
                network->weights[i][j * cols + k] += weight_deltas[i][j * cols + k] * (learning_rate / batch_size);
                weight_deltas[i][j * cols + k] = 0.0f;
            }
            network->biases[i] += bias_deltas[i] * (learning_rate / batch_size);
            bias_deltas[i] = 0.0f;
        }
    }
}

//Train network using backpropagation
void train_network(NeuralNetwork *network, Data *dataset, int num_images, int epochs, int batch_size, float learning_rate) {
    int num_batches = num_images / batch_size;
    float **weight_deltas = malloc(sizeof(float *) * (network->num_layers - 1));
    for(int i = 0; i < network->num_layers - 1; i++) {
        int rows = network->layers[i];
        int cols = network->layers[i + 1];
        weight_deltas[i] = malloc(sizeof(float) * rows * cols);
        memset(weight_deltas[i], 0.0f, sizeof(float) * rows * cols);
    }
    
    float *bias_deltas = malloc(sizeof(float) * (network->num_layers - 1));
    memset(bias_deltas, 0.0f, sizeof(float) * (network->num_layers - 1));
    
    for(int epoch = 0; epoch < epochs; epoch++) {
        printf("Epoch %d\n", epoch + 1);
        for(int batch = 0; batch < num_batches; batch++) {
            int start = batch * batch_size;
            int end = (batch + 1) * batch_size;
            if(end > num_images) end = num_images;
            int num_inputs = end - start;
            float *inputs = malloc(sizeof(float) * num_inputs * IMAGE_SIZE);
            float *expected = malloc(sizeof(float) * num_inputs * NUM_CLASSES);
            float *outputs = malloc(sizeof(float) * num_inputs * NUM_CLASSES);
            float *deltas = malloc(sizeof(float) * num_inputs * NUM_CLASSES);

            for(int i = 0; i < num_inputs; i++) {
                memcpy(inputs + i * IMAGE_SIZE, dataset[start + i].data, sizeof(float) * IMAGE_SIZE);
                memset(expected + i * NUM_CLASSES, 0.0f, sizeof(float) * NUM_CLASSES);
                expected[i * NUM_CLASSES + dataset[start + i].label] = 1.0f;
            }

            forward(network, inputs, outputs);
            calc_error(expected, outputs, num_inputs * NUM_CLASSES, deltas);
            backward(network, inputs + (num_inputs - 1) * IMAGE_SIZE, deltas + (num_inputs - 1) * NUM_CLASSES, weight_deltas, bias_deltas);
            
            for(int i = num_inputs - 2; i >= 0; i--) {
                calc_error(expected + i * NUM_CLASSES, outputs + i * NUM_CLASSES, NUM_CLASSES, deltas + i * NUM_CLASSES);
                backward(network, inputs + i * IMAGE_SIZE, deltas + i * NUM_CLASSES, weight_deltas, bias_deltas);
            }

            update_network(network, weight_deltas, bias_deltas, num_inputs, learning_rate);

            free(inputs);
            free(expected);
            free(outputs);
            free(deltas);
        }
    }

    for(int i = 0; i < network->num_layers - 1; i++) {
        free(weight_deltas[i]);
    }
    free(weight_deltas);
    free(bias_deltas);
}

//Test network on new data
void test_network(NeuralNetwork *network, float **images, int *labels, int num_images) {
    int correct = 0;
    for(int i = 0; i < num_images; i++) {
        float *inputs = images[i];
        float outputs[NUM_CLASSES] = {0};
        forward(network, inputs, outputs);
        int max_index = 0;
        float max_output = outputs[0];
        for(int j = 1; j < NUM_CLASSES; j++) {
            if(outputs[j] > max_output) {
                max_output = outputs[j];
                max_index = j;
            }
        }
        if(max_index == labels[i]) {
            correct++;
        }
    }
    printf("Accuracy: %.2f%%\n", (float)correct / (float)num_images * 100.0f);
}

int main(int argc, char **argv) {
    //Load images and labels
    int train_size = 60000;
    int test_size = 10000;
    float **train_images = load_images("train_images.csv", train_size);
    float **test_images = load_images("test_images.csv", test_size);
    int *train_labels = load_labels("train_labels.csv", train_size);
    int *test_labels = load_labels("test_labels.csv", test_size);

    //Create datasets
    Data *train_data = create_dataset(train_images, train_labels, train_size);
    Data *test_data = create_dataset(test_images, test_labels, test_size);

    //Initialize neural network - 784 input neurons, 10 output neurons (1 for each class), 3 hidden layers with 64 neurons each
    NeuralNetwork network = {
        .num_layers = 5,
        .layers = {IMAGE_SIZE, 64, 64, 64, NUM_CLASSES},
        .weights = malloc(sizeof(float *) * 4),
        .biases = malloc(sizeof(float) * 4)
    };
    init_network(&network);

    //Train neural network
    train_network(&network, train_data, train_size, 10, 32, 0.1f);

    //Test neural network
    test_network(&network, test_images, test_labels, test_size);

    //Cleanup
    for(int i = 0; i < train_size; i++) {
        free(train_images[i]);
    }
    free(train_images);
    free(train_labels);
    for(int i = 0; i < test_size; i++) {
        free(test_images[i]);
    }
    free(test_images);
    free(test_labels);
    free(train_data);
    free(test_data);
    for(int i = 0; i < network.num_layers - 1; i++) {
        free(network.weights[i]);
    }
    free(network.weights);
    free(network.biases);

    return 0;
}