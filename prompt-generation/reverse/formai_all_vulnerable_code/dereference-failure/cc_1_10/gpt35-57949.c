//FormAI DATASET v1.0 Category: Image Classification system ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define INPUT_SIZE 784
#define HIDDEN_SIZE 16
#define OUTPUT_SIZE 10

#define LEARNING_RATE 0.01
#define MOMENTUM 0.9

#define TRAINING_FILES 5
#define EPOCHS 50
#define BATCH_SIZE 200

#define PARANOID_LEVEL 3

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double sigmoid_derivative(double x) {
    return x * (1 - x);
}

void forward_propagation(double **input, double **hidden_weights, double **output_weights, double **hidden_layer, double **output_layer) {
    double hidden_layer_inputs[HIDDEN_SIZE];
    double output_layer_inputs[OUTPUT_SIZE];

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            sum += input[0][j] * hidden_weights[j][i];
        }
        hidden_layer_inputs[i] = sum;
    }

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        hidden_layer[0][i] = sigmoid(hidden_layer_inputs[i]);
    }

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            sum += hidden_layer[0][j] * output_weights[j][i];
        }
        output_layer_inputs[i] = sum;
    }

    double output_layer_sum = 0;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output_layer[0][i] = sigmoid(output_layer_inputs[i]);
        output_layer_sum += output_layer[0][i];
    }

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output_layer[0][i] /= output_layer_sum;
    }
}

double **create_matrix(int rows, int cols) {
    double **matrix = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = calloc(cols, sizeof(double));
    }
    return matrix;
}

void destroy_matrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void initialize_weights(double **hidden_weights, double **output_weights) {
    srand(time(NULL));
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            hidden_weights[j][i] = (double) (rand() % 101) / 100 - 0.5;
        }
    }

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            output_weights[j][i] = (double) (rand() % 101) / 100 - 0.5;
        }
    }
}

void normalize_inputs(double **input) {
    double mean = 0;
    double std_dev = 0;
    for (int i = 0; i < INPUT_SIZE; i++) {
        mean += input[0][i];
    }
    mean /= INPUT_SIZE;

    for (int i = 0; i < INPUT_SIZE; i++) {
        std_dev += pow(input[0][i] - mean, 2);
    }
    std_dev /= INPUT_SIZE - 1;
    std_dev = sqrt(std_dev);

    for (int i = 0; i < INPUT_SIZE; i++) {
        input[0][i] = (input[0][i] - mean) / std_dev;
    }
}

void train_network(double **hidden_weights, double **output_weights, char **image_filenames, char *label_filename) {
    double **hidden_layer = create_matrix(1, HIDDEN_SIZE);
    double **output_layer = create_matrix(1, OUTPUT_SIZE);

    double **hidden_delta = create_matrix(1, HIDDEN_SIZE);
    double **output_delta = create_matrix(1, OUTPUT_SIZE);

    double **hidden_weights_new = create_matrix(INPUT_SIZE, HIDDEN_SIZE);
    double **output_weights_new = create_matrix(HIDDEN_SIZE, OUTPUT_SIZE);

    double **input = create_matrix(1, INPUT_SIZE);
    FILE *label_file = fopen(label_filename, "r");

    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        for (int file_nr = 0; file_nr < TRAINING_FILES; file_nr++) {
            FILE *image_file = fopen(image_filenames[file_nr], "r");
            int label;

            for (int batch_idx = 0; batch_idx < BATCH_SIZE; batch_idx++) {
                label = getc(label_file);
                fgetc(label_file);

                for (int i = 0; i < INPUT_SIZE; i++) {
                    input[0][i] = getc(image_file) / 255.0;
                }
                fgetc(image_file);
                normalize_inputs(input);

                forward_propagation(input, hidden_weights, output_weights, hidden_layer, output_layer);

                for (int i = 0; i < OUTPUT_SIZE; i++) {
                    output_delta[0][i] = output_layer[0][i] - (label == i);
                }

                double output_error_sq = 0;
                for (int i = 0; i < OUTPUT_SIZE; i++) {
                    output_error_sq += pow(output_delta[0][i], 2);
                }

                if (PARANOID_LEVEL >= 1 && output_error_sq > 0.1) {
                    printf("\nError at output layer in file %d, batch %d, epoch %d\n", file_nr + 1, batch_idx + 1, epoch + 1);
                    printf("Label: %d\n", label);
                    printf("Output: ");
                    for (int i = 0; i < OUTPUT_SIZE; i++) {
                        printf("%.3f ", output_layer[0][i]);
                    }
                    printf("\n");
                }

                for (int i = 0; i < OUTPUT_SIZE; i++) {
                    output_delta[0][i] *= sigmoid_derivative(output_layer[0][i]);
                }

                for (int i = 0; i < HIDDEN_SIZE; i++) {
                    double sum = 0;
                    for (int j = 0; j < OUTPUT_SIZE; j++) {
                        sum += output_weights[i][j] * output_delta[0][j];
                    }
                    hidden_delta[0][i] = sum * sigmoid_derivative(hidden_layer[0][i]);
                }

                if (PARANOID_LEVEL >= 2) {
                    double hidden_error_sq = 0;
                    for (int i = 0; i < HIDDEN_SIZE; i++) {
                        hidden_error_sq += pow(hidden_delta[0][i], 2);
                    }
                    if (hidden_error_sq > 0.1) {
                        printf("\nError at hidden layer in file %d, batch %d, epoch %d\n", file_nr + 1, batch_idx + 1, epoch + 1);
                        printf("Label: %d\n", label);
                        printf("Output: ");
                        for (int i = 0; i < OUTPUT_SIZE; i++) {
                            printf("%.3f ", output_layer[0][i]);
                        }
                        printf("\n");
                    }
                }

                for (int i = 0; i < HIDDEN_SIZE; i++) {
                    for (int j = 0; j < INPUT_SIZE; j++) {
                        hidden_weights_new[j][i] = hidden_weights[j][i] - LEARNING_RATE * (input[0][j] * hidden_delta[0][i]) + MOMENTUM * (hidden_weights[j][i] - hidden_weights_new[j][i]);  
                    }
                }

                for (int i = 0; i < OUTPUT_SIZE; i++) {
                    for (int j = 0; j < HIDDEN_SIZE; j++) {
                        output_weights_new[j][i] = output_weights[j][i] - LEARNING_RATE * (hidden_layer[0][j] * output_delta[0][i]) + MOMENTUM * (output_weights[j][i] - output_weights_new[j][i]);
                    }
                }

                for (int i = 0; i < HIDDEN_SIZE; i++) {
                    for (int j = 0; j < INPUT_SIZE; j++) {
                        hidden_weights[j][i] = hidden_weights_new[j][i];
                    }
                }

                for (int i = 0; i < OUTPUT_SIZE; i++) {
                    for (int j = 0; j < HIDDEN_SIZE; j++) {
                        output_weights[j][i] = output_weights_new[j][i];
                    }
                }
            }
            fclose(image_file);
        }
        printf("Epoch %d completed\n", epoch + 1);
    }

    fclose(label_file);
    destroy_matrix(hidden_layer, 1);
    destroy_matrix(output_layer, 1);
    destroy_matrix(hidden_delta, 1);
    destroy_matrix(output_delta, 1);
    destroy_matrix(hidden_weights_new, INPUT_SIZE);
    destroy_matrix(output_weights_new, HIDDEN_SIZE);
    destroy_matrix(input, 1);
}

int main(void) {
    double **hidden_weights = create_matrix(INPUT_SIZE, HIDDEN_SIZE);
    double **output_weights = create_matrix(HIDDEN_SIZE, OUTPUT_SIZE);

    initialize_weights(hidden_weights, output_weights);

    char *image_filenames[] = {"train-images-idx3-ubyte", "t10k-images-idx3-ubyte"};
    char *label_filenames[] = {"train-labels-idx1-ubyte", "t10k-labels-idx1-ubyte"};

    for (int i = 0; i < 2; i++) {
        printf("Training on %s\n", image_filenames[i]);
        train_network(hidden_weights, output_weights, &image_filenames[i], label_filenames[i]);
    }

    destroy_matrix(hidden_weights, INPUT_SIZE);
    destroy_matrix(output_weights, HIDDEN_SIZE);

    return 0;
}