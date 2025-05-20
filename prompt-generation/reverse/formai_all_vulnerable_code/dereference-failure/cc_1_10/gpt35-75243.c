//FormAI DATASET v1.0 Category: Image Classification system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784
#define HIDDEN_LAYER_SIZE 128
#define OUTPUT_SIZE 10
#define LEARNING_RATE 0.01
#define EPOCHS 50

void initialize_weights(double** weights, int rows, int cols) {
    double bound = sqrt(6.0 / (rows + cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            weights[i][j] = (rand() / (double)RAND_MAX) * 2 * bound - bound;
        }
    }
}

void feed_forward(double* input, double** weights_1, double** weights_2, double* hidden_layer_output, double* output, int input_size, int hidden_layer_size, int output_size) {
    for(int i = 0; i < hidden_layer_size; i++) {
        double sum = 0.0;
        for(int j = 0; j < input_size; j++) {
            sum += weights_1[i][j] * input[j];
        }
        hidden_layer_output[i] = 1.0 / (1.0 + exp(-sum));
    }
    for(int i = 0; i < output_size; i++) {
        double sum = 0.0;
        for(int j = 0; j < hidden_layer_size; j++) {
            sum += weights_2[i][j] * hidden_layer_output[j];
        }
        output[i] = exp(sum);
    }
    double sum_exp_output = 0.0;
    for(int i = 0; i < output_size; i++) {
        sum_exp_output += output[i];
    }
    for(int i = 0; i < output_size; i++) {
        output[i] /= sum_exp_output;
    }
}

void back_propagation(double* input, double* expected_output, double** weights_1, double** weights_2, double* hidden_layer_output, double* output, int input_size, int hidden_layer_size, int output_size) {
    double delta_output[output_size];
    for(int i = 0; i < output_size; i++) {
        delta_output[i] = output[i] - expected_output[i];
    }
    double delta_hidden_layer[hidden_layer_size];
    for(int i = 0; i < hidden_layer_size; i++) {
        double sum = 0.0;
        for(int j = 0; j < output_size; j++) {
            sum += weights_2[j][i] * delta_output[j];
        }
        delta_hidden_layer[i] = hidden_layer_output[i] * (1 - hidden_layer_output[i]) * sum;
    }
    for(int i = 0; i < output_size; i++) {
        for(int j = 0; j < hidden_layer_size; j++) {
            weights_2[i][j] -= LEARNING_RATE * delta_output[i] * hidden_layer_output[j];
        }
    }
    for(int i = 0; i < hidden_layer_size; i++) {
        for(int j = 0; j < input_size; j++) {
            weights_1[i][j] -= LEARNING_RATE * delta_hidden_layer[i] * input[j];
        }
    }
}

double calculate_loss(double* output, double* expected_output, int output_size) {
    double loss = 0.0;
    for(int i = 0; i < output_size; i++) {
        loss -= expected_output[i] * log(output[i]);
    }
    return loss;
}

void train(double** training_set_input, double** training_set_output, int num_training_examples, double** weights_1, double** weights_2, int input_size, int hidden_layer_size, int output_size) {
    for(int epoch = 0; epoch < EPOCHS; epoch++) {
        double total_loss = 0.0;
        for(int example = 0; example < num_training_examples; example++) {
            double input[INPUT_SIZE];
            double expected_output[OUTPUT_SIZE];
            for(int i = 0; i < INPUT_SIZE; i++) {
                input[i] = training_set_input[example][i];
            }
            for(int i = 0; i < OUTPUT_SIZE; i++) {
                expected_output[i] = training_set_output[example][i];
            }
            double hidden_layer_output[HIDDEN_LAYER_SIZE];
            double output[OUTPUT_SIZE];
            feed_forward(input, weights_1, weights_2, hidden_layer_output, output, input_size, hidden_layer_size, output_size);
            back_propagation(input, expected_output, weights_1, weights_2, hidden_layer_output, output, input_size, hidden_layer_size, output_size);
            total_loss += calculate_loss(output, expected_output, output_size);
        }
        printf("Epoch %d, Loss: %f\n", epoch + 1, total_loss / num_training_examples);
    }
}

int main() {
    srand(42);
    double** weights_1 = (double**)malloc(HIDDEN_LAYER_SIZE * sizeof(double*));
    for(int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        weights_1[i] = (double*)malloc(INPUT_SIZE * sizeof(double));
    }
    initialize_weights(weights_1, HIDDEN_LAYER_SIZE, INPUT_SIZE);
    double** weights_2 = (double**)malloc(OUTPUT_SIZE * sizeof(double*));
    for(int i = 0; i < OUTPUT_SIZE; i++) {
        weights_2[i] = (double*)malloc(HIDDEN_LAYER_SIZE * sizeof(double));
    }
    initialize_weights(weights_2, OUTPUT_SIZE, HIDDEN_LAYER_SIZE);
    double** training_set_input = (double**)malloc(60000 * sizeof(double*));
    for(int i = 0; i < 60000; i++) {
        training_set_input[i] = (double*)malloc(INPUT_SIZE * sizeof(double));
    }
    FILE* file;
    file = fopen("train-images-idx3-ubyte", "rb");
    fseek(file, 16, SEEK_SET);
    for(int i = 0; i < 60000; i++) {
        unsigned char buf[INPUT_SIZE];
        fread(buf, sizeof(unsigned char), INPUT_SIZE, file);
        for(int j = 0; j < INPUT_SIZE; j++) {
            training_set_input[i][j] = buf[j] / 255.0;
        }
    }
    fclose(file);
    double** training_set_output = (double**)malloc(60000 * sizeof(double*));
    for(int i = 0; i < 60000; i++) {
        training_set_output[i] = (double*)malloc(OUTPUT_SIZE * sizeof(double));
    }
    file = fopen("train-labels-idx1-ubyte", "rb");
    fseek(file, 8, SEEK_SET);
    for(int i = 0; i < 60000; i++) {
        unsigned char buf;
        fread(&buf, sizeof(unsigned char), 1, file);
        for(int j = 0; j < OUTPUT_SIZE; j++) {
            training_set_output[i][j] = (buf == j) ? 1.0 : 0.0;
        }
    }
    fclose(file);
    train(training_set_input, training_set_output, 60000, weights_1, weights_2, INPUT_SIZE, HIDDEN_LAYER_SIZE, OUTPUT_SIZE);
    for(int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        free(weights_1[i]);
    }
    free(weights_1);
    for(int i = 0; i < OUTPUT_SIZE; i++) {
        free(weights_2[i]);
    }
    free(weights_2);
    for(int i = 0; i < 60000; i++) {
        free(training_set_input[i]);
        free(training_set_output[i]);
    }
    free(training_set_input);
    free(training_set_output);
    return 0;
}