//FormAI DATASET v1.0 Category: Image Classification system ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 28 * 28
#define HIDDEN_SIZE 128
#define OUTPUT_SIZE 10

#define LEARNING_RATE 0.1
#define EPOCHS 10
#define BATCH_SIZE 32

// Struct to hold a neural network layer
typedef struct {
    double *weights;
    double *biases;
    int input_size;
    int output_size;
} Layer;

// Struct to hold a minibatch of training examples
typedef struct {
    double **inputs;
    double **labels;
    int size;
} MiniBatch;

// Function to create a new layer for a neural network
Layer create_layer(int input_size, int output_size) {
    Layer layer;
    layer.input_size = input_size;
    layer.output_size = output_size;

    // Allocate memory for weights and biases
    layer.weights = (double *) malloc(input_size * output_size * sizeof(double));
    layer.biases = (double *) malloc(output_size * sizeof(double));

    // Initialize weights and biases randomly
    for (int i = 0; i < input_size * output_size; i++) {
        layer.weights[i] = (double) rand() / RAND_MAX - 0.5;
    }
    for (int i = 0; i < output_size; i++) {
        layer.biases[i] = (double) rand() / RAND_MAX - 0.5;
    }

    return layer;
}

// Function to free the memory used by a layer
void free_layer(Layer layer) {
    free(layer.weights);
    free(layer.biases);
}

// Function to compute the output of a layer
void compute_layer_output(Layer layer, double *inputs, double *outputs) {
    // Compute weighted sum of inputs and biases
    for (int i = 0; i < layer.output_size; i++) {
        outputs[i] = layer.biases[i];
        for (int j = 0; j < layer.input_size; j++) {
            outputs[i] += inputs[j] * layer.weights[i * layer.input_size + j];
        }
    }

    // Apply sigmoid activation function to get final output
    for (int i = 0; i < layer.output_size; i++) {
        outputs[i] = 1.0 / (1.0 + exp(-outputs[i]));
    }
}

// Function to compute the derivative of the sigmoid function
double sigmoid_derivative(double x) {
    return exp(-x) / pow(1.0 + exp(-x), 2);
}

// Function to train a neural network using stochastic gradient descent
void train_network(Layer *layers, int num_layers, MiniBatch *mini_batches, int num_mini_batches) {
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        printf("Epoch %d/%d\n", epoch + 1, EPOCHS);

        double total_loss = 0.0;

        for (int batch_idx = 0; batch_idx < num_mini_batches; batch_idx++) {
            MiniBatch batch = mini_batches[batch_idx];

            // Perform forward pass through network
            double *prev_layer_output = batch.inputs[0];
            double **layer_outputs = (double **) malloc(num_layers * sizeof(double *));
            for (int i = 0; i < num_layers; i++) {
                double *output = (double *) malloc(layers[i].output_size * sizeof(double));
                compute_layer_output(layers[i], prev_layer_output, output);
                layer_outputs[i] = output;
                prev_layer_output = output;
            }

            // Compute output error and total loss
            double *output_error = (double *) malloc(OUTPUT_SIZE * sizeof(double));
            double *label = batch.labels[0];
            double *output = layer_outputs[num_layers - 1];
            for (int i = 0; i < OUTPUT_SIZE; i++) {
                double error = label[i] - output[i];
                output_error[i] = error;
                total_loss += pow(error, 2);
            }

            // Backpropagate error through network
            for (int i = num_layers - 1; i >= 0; i--) {
                double *prev_layer_output = i == 0 ? batch.inputs[0] : layer_outputs[i - 1];
                double *output = layer_outputs[i];

                double *input_error = (double *) malloc(layers[i].input_size * sizeof(double));
                for (int j = 0; j < layers[i].output_size; j++) {
                    double error = output_error[j] * sigmoid_derivative(output[j]);
                    for (int k = 0; k < layers[i].input_size; k++) {
                        input_error[k] += layers[i].weights[j * layers[i].input_size + k] * error;
                        layers[i].weights[j * layers[i].input_size + k] += LEARNING_RATE * error * prev_layer_output[k];
                    }
                    layers[i].biases[j] += LEARNING_RATE * error;
                }
                output_error = input_error;
                free(input_error);
            }

            // Free layer outputs and output error
            for (int i = 0; i < num_layers; i++) {
                free(layer_outputs[i]);
            }
            free(output_error);
        }

        printf("Total Loss: %f\n", total_loss);

        // Shuffle mini-batches for next epoch
        for (int i = 0; i < num_mini_batches; i++) {
            int rand_idx = rand() % num_mini_batches;
            MiniBatch temp = mini_batches[rand_idx];
            mini_batches[rand_idx] = mini_batches[i];
            mini_batches[i] = temp;
        }
    }
}

// Function to predict the class of an input image using a trained neural network
int predict_class(Layer *layers, int num_layers, double *input) {
    double *prev_layer_output = input;
    double **layer_outputs = (double **) malloc(num_layers * sizeof(double *));
    for (int i = 0; i < num_layers; i++) {
        double *output = (double *) malloc(layers[i].output_size * sizeof(double));
        compute_layer_output(layers[i], prev_layer_output, output);
        layer_outputs[i] = output;
        prev_layer_output = output;
    }

    int predicted_class = 0;
    double max_output = 0.0;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        if (layer_outputs[num_layers - 1][i] > max_output) {
            predicted_class = i;
            max_output = layer_outputs[num_layers - 1][i];
        }
    }

    // Free memory used by layer outputs
    for (int i = 0; i < num_layers; i++) {
        free(layer_outputs[i]);
    }
    free(layer_outputs);

    return predicted_class;
}

int main() {
    // Load MNIST training data
    FILE *images_file = fopen("train-images-idx3-ubyte", "r");
    FILE *labels_file = fopen("train-labels-idx1-ubyte", "r");

    // Skip header bytes
    fseek(images_file, 16, SEEK_SET);
    fseek(labels_file, 8, SEEK_SET);

    // Read image and label data
    double **images = (double **) malloc(60000 * sizeof(double *));
    double **labels = (double **) malloc(60000 * sizeof(double *));
    for (int i = 0; i < 60000; i++) {
        // Read image data
        double *image = (double *) malloc(INPUT_SIZE * sizeof(double));
        unsigned char image_data[INPUT_SIZE];
        fread(image_data, sizeof(unsigned char), INPUT_SIZE, images_file);
        for (int j = 0; j < INPUT_SIZE; j++) {
            image[j] = (double) image_data[j] / 255.0;
        }
        images[i] = image;

        // Read label data
        double *label = (double *) malloc(OUTPUT_SIZE * sizeof(double));
        unsigned char label_data;
        fread(&label_data, sizeof(unsigned char), 1, labels_file);
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            label[j] = j == label_data ? 1.0 : 0.0;
        }
        labels[i] = label;
    }

    fclose(images_file);
    fclose(labels_file);

    // Create neural network with one hidden layer
    Layer hidden_layer = create_layer(INPUT_SIZE, HIDDEN_SIZE);
    Layer output_layer = create_layer(HIDDEN_SIZE, OUTPUT_SIZE);
    Layer layers[] = { hidden_layer, output_layer };
    int num_layers = sizeof(layers) / sizeof(layers[0]);

    // Create mini-batches for training
    MiniBatch *mini_batches = (MiniBatch *) malloc(60000 / BATCH_SIZE * sizeof(MiniBatch));
    for (int i = 0, j = 0; i < 60000; i += BATCH_SIZE, j++) {
        MiniBatch batch;
        batch.inputs = &images[i];
        batch.labels = &labels[i];
        batch.size = BATCH_SIZE;
        mini_batches[j] = batch;
    }

    // Train neural network
    train_network(layers, num_layers, mini_batches, 60000 / BATCH_SIZE);

    // Load MNIST test data
    images_file = fopen("t10k-images-idx3-ubyte", "r");
    labels_file = fopen("t10k-labels-idx1-ubyte", "r");

    // Skip header bytes
    fseek(images_file, 16, SEEK_SET);
    fseek(labels_file, 8, SEEK_SET);

    // Read image and label data
    double **test_images = (double **) malloc(10000 * sizeof(double *));
    int *test_labels = (int *) malloc(10000 * sizeof(int));
    for (int i = 0; i < 10000; i++) {
        // Read image data
        double *image = (double *) malloc(INPUT_SIZE * sizeof(double));
        unsigned char image_data[INPUT_SIZE];
        fread(image_data, sizeof(unsigned char), INPUT_SIZE, images_file);
        for (int j = 0; j < INPUT_SIZE; j++) {
            image[j] = (double) image_data[j] / 255.0;
        }
        test_images[i] = image;

        // Read label data
        unsigned char label_data;
        fread(&label_data, sizeof(unsigned char), 1, labels_file);
        test_labels[i] = label_data;
    }

    fclose(images_file);
    fclose(labels_file);

    // Test neural network on test data
    int num_correct = 0;
    for (int i = 0; i < 10000; i++) {
        int predicted_class = predict_class(layers, num_layers, test_images[i]);
        if (predicted_class == test_labels[i]) {
            num_correct++;
        }
    }

    printf("Accuracy: %f\n", (double) num_correct / 10000.0);

    // Free memory used by neural network and data
    for (int i = 0; i < 60000; i++) {
        free(images[i]);
        free(labels[i]);
    }
    free(images);
    free(labels);

    for (int i = 0; i < 10000; i++) {
        free(test_images[i]);
    }
    free(test_images);
    free(test_labels);

    free_layer(hidden_layer);
    free_layer(output_layer);

    return 0;
}