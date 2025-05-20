//FormAI DATASET v1.0 Category: Image Classification system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// global variables
int image_size = 784; // 28x28 image
int num_labels = 10; // 10 possible labels (0-9)
int num_epochs = 50; // number of epochs for training
float learning_rate = 0.01; // learning rate for gradient descent

// function to load MNIST dataset
float** load_dataset(char* filename) {  
    float** dataset = (float**)malloc(sizeof(float*) * 60000);
    for (int i = 0; i < 60000; i++) {
        dataset[i] = (float*)malloc(sizeof(float) * (image_size + 1));
    }
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Unable to open dataset file.\n");
        exit(1);
    }
    for (int i = 0; i < 60000; i++) {
        // read label as first byte
        unsigned char label;
        fread(&label, sizeof(unsigned char), 1, file);
        dataset[i][0] = (float)label;
        // read image pixel values as 28x28 array of bytes
        unsigned char pixels[image_size];
        fread(pixels, sizeof(unsigned char), image_size, file);
        for (int j = 0; j < image_size; j++) {
            dataset[i][j+1] = (float)pixels[j] / 255.0;
        }
    }
    fclose(file);
    return dataset;
}

// function to generate random weights
float** initialize_weights(int num_inputs, int num_outputs) {
    float** weights = (float**)malloc(sizeof(float*) * num_inputs);
    for (int i = 0; i < num_inputs; i++) {
        weights[i] = (float*)malloc(sizeof(float) * num_outputs);
        for (int j = 0; j < num_outputs; j++) {
            weights[i][j] = ((float)rand() / (float)RAND_MAX) - 0.5;
        }
    }
    return weights;
}

// function to calculate softmax of inputs
float* softmax(float* inputs, int num_inputs) {
    float* outputs = (float*)calloc(num_inputs, sizeof(float));
    float max_val = inputs[0];
    for (int i = 1; i < num_inputs; i++) {
        if (inputs[i] > max_val) {
            max_val = inputs[i];
        }
    }
    float sum = 0.0;
    for (int i = 0; i < num_inputs; i++) {
        outputs[i] = exp(inputs[i] - max_val);
        sum += outputs[i];
    }
    for (int i = 0; i < num_inputs; i++) {
        outputs[i] /= sum;
    }
    return outputs;
}

// function to calculate cross-entropy loss
float calculate_loss(float* predicted, float* actual, int num_labels) {
    float loss = 0.0;
    for (int i = 0; i < num_labels; i++) {
        loss -= actual[i] * log(predicted[i]);
    }
    return loss;
}

// main function
int main(int argc, char** argv) {
    // load training and test datasets
    float** train_dataset = load_dataset("mnist_train.bin");
    float** test_dataset = load_dataset("mnist_test.bin");

    // initialize weights and biases
    int num_inputs = image_size;
    int num_outputs = num_labels;
    float** weights = initialize_weights(num_inputs, num_outputs);
    float* biases = (float*)calloc(num_outputs, sizeof(float));

    // training loop
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        float total_loss = 0.0;
        for (int i = 0; i < 60000; i++) {
            // forward pass
            float* inputs = train_dataset[i] + 1;
            float* targets = (float*)calloc(num_outputs, sizeof(float));
            int label = (int)train_dataset[i][0];
            targets[label] = 1.0;
            float* outputs = softmax(inputs, num_outputs);
            float loss = calculate_loss(outputs, targets, num_outputs);
            total_loss += loss;

            // backward pass
            float* d_outputs = (float*)calloc(num_outputs, sizeof(float));
            for (int j = 0; j < num_outputs; j++) {
                d_outputs[j] = outputs[j] - targets[j];
            }
            float** d_weights = (float**)malloc(sizeof(float*) * num_inputs);
            for (int j = 0; j < num_inputs; j++) {
                d_weights[j] = (float*)malloc(sizeof(float) * num_outputs);
                for (int k = 0; k < num_outputs; k++) {
                    d_weights[j][k] = d_outputs[k] * inputs[j];
                }
            }
            float* d_biases = d_outputs;

            // update weights and biases using gradient descent
            for (int j = 0; j < num_inputs; j++) {
                for (int k = 0; k < num_outputs; k++) {
                    weights[j][k] -= learning_rate * d_weights[j][k];
                }
            }
            for (int j = 0; j < num_outputs; j++) {
                biases[j] -= learning_rate * d_biases[j];
            }
        }
        printf("Epoch %d: total_loss=%f\n", epoch, total_loss);
    }

    // testing loop
    int num_correct = 0;
    for (int i = 0; i < 10000; i++) {
        float* inputs = test_dataset[i] + 1;
        int label = (int)test_dataset[i][0];
        float* outputs = softmax(inputs, num_outputs);
        int prediction = 0;
        float max_val = outputs[0];
        for (int j = 1; j < num_outputs; j++) {
            if (outputs[j] > max_val) {
                max_val = outputs[j];
                prediction = j;
            }
        }
        if (prediction == label) {
            num_correct++;
        }
    }
    float accuracy = (float)num_correct / 10000.0;
    printf("Test accuracy: %f\n", accuracy);

    // free memory
    for (int i = 0; i < 60000; i++) {
        free(train_dataset[i]);
    }
    free(train_dataset);
    for (int i = 0; i < 10000; i++) {
        free(test_dataset[i]);
    }
    free(test_dataset);
    for (int i = 0; i < num_inputs; i++) {
        free(weights[i]);
    }
    free(weights);
    free(biases);

    return 0;
}