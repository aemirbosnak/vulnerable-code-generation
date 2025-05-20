//FormAI DATASET v1.0 Category: Image Classification system ; Style: safe
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define MAX_INPUT_LENGTH 1000 
#define MAX_NUM_CLASSES 10 
#define NUM_FEATURES 28 
#define TRAIN_SET_SIZE 7000 
#define TEST_SET_SIZE 3000 

float sigmoid(float x)
{
    return 1 / (1 + exp(-x));
}

float relu(float x)
{
    if (x < 0) {
        return 0;
    } else {
        return x;
    }
}

float activation_function(float x, char *activation)
{
    if (strcmp(activation, "sigmoid") == 0) {
        return sigmoid(x);
    } else if (strcmp(activation, "relu") == 0) {
        return relu(x);
    } else {
        return x;
    }
}

float **read_data(char *filename, int num_samples, int num_features)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    float **data = (float **) malloc(num_samples * sizeof(float *));
    for (int i = 0; i < num_samples; i++) {
        data[i] = (float *) malloc(num_features * sizeof(float));
    }

    char *line = (char *) malloc(MAX_INPUT_LENGTH * sizeof(char));
    char *token;
    int sample_count = 0, feature_count = 0;

    while (fgets(line, MAX_INPUT_LENGTH, fp) != NULL) {
        token = strtok(line, ",");
        feature_count = 0;
        while (token != NULL) {
            data[sample_count][feature_count++] = atof(token);
            token = strtok(NULL, ",");
        }
        sample_count++;
    }

    fclose(fp);
    free(line);

    return data;
}

float **read_labels(char *filename, int num_samples)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    float **labels = (float **) malloc(num_samples * sizeof(float *));
    for (int i = 0; i < num_samples; i++) {
        labels[i] = (float *) malloc(MAX_NUM_CLASSES * sizeof(float));
        for (int j = 0; j < MAX_NUM_CLASSES; j++) {
            labels[i][j] = 0;
        }
    }

    char *line = (char *) malloc(MAX_INPUT_LENGTH * sizeof(char));
    char *token;
    int sample_count = 0, class;

    while (fgets(line, MAX_INPUT_LENGTH, fp) != NULL) {
        class = atoi(line);
        labels[sample_count][class] = 1;
        sample_count++;
    }

    fclose(fp);
    free(line);

    return labels;
}

float **transpose(float **matrix, int rows, int cols)
{
    float **transpose = (float **) malloc(cols * sizeof(float *));
    for (int i = 0; i < cols; i++) {
        transpose[i] = (float *) malloc(rows * sizeof(float));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    return transpose;
}

float **matrix_multiply(float **matrix1, float **matrix2, int rows1, int cols1, int cols2)
{
    float **product = (float **) malloc(rows1 * sizeof(float *));
    for (int i = 0; i < rows1; i++) {
        product[i] = (float *) malloc(cols2 * sizeof(float));
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            product[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return product;
}

void print_matrix(float **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Load training data
    float **train_data = read_data("train_data.csv", TRAIN_SET_SIZE, NUM_FEATURES);
    float **train_labels = read_labels("train_labels.csv", TRAIN_SET_SIZE);

    // Load test data
    float **test_data = read_data("test_data.csv", TEST_SET_SIZE, NUM_FEATURES);
    float **test_labels = read_labels("test_labels.csv", TEST_SET_SIZE);

    // Transpose training data and test data
    float **train_data_T = transpose(train_data, TRAIN_SET_SIZE, NUM_FEATURES);
    float **test_data_T = transpose(test_data, TEST_SET_SIZE, NUM_FEATURES);

    // Initialize Weights
    float learning_rate = 0.1;
    int num_epochs = 200;
    float **input_weights = (float **) malloc(NUM_FEATURES * sizeof(float *));
    float **hidden_weights = (float **) malloc(MAX_NUM_CLASSES * sizeof(float *));
    float **output_weights = (float **) malloc(MAX_NUM_CLASSES * sizeof(float *));

    for (int i = 0; i < NUM_FEATURES; i++) {
        input_weights[i] = (float *) malloc(MAX_NUM_CLASSES * sizeof(float));
        for (int j = 0; j < MAX_NUM_CLASSES; j++) {
            input_weights[i][j] = ((float) rand() / (float) RAND_MAX) * 2 - 1;
        }
    }

    for (int i = 0; i < MAX_NUM_CLASSES; i++) {
        hidden_weights[i] = (float *) malloc(MAX_NUM_CLASSES * sizeof(float));
        output_weights[i] = (float *) malloc(MAX_NUM_CLASSES * sizeof(float));
        for (int j = 0; j < MAX_NUM_CLASSES; j++) {
            hidden_weights[i][j] = ((float) rand() / (float) RAND_MAX) * 2 - 1;
            output_weights[i][j] = ((float) rand() / (float) RAND_MAX) * 2 - 1;
        }
    }

    // Train the network
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        // Forward Pass
        float **hidden_layer_inputs = matrix_multiply(train_data, input_weights, TRAIN_SET_SIZE, NUM_FEATURES, MAX_NUM_CLASSES);
        float **hidden_layer_outputs = (float **) malloc(TRAIN_SET_SIZE * sizeof(float *));
        for (int i = 0; i < TRAIN_SET_SIZE; i++) {
            hidden_layer_outputs[i] = (float *) malloc(MAX_NUM_CLASSES * sizeof(float));
            for (int j = 0; j < MAX_NUM_CLASSES; j++) {
                hidden_layer_outputs[i][j] = activation_function(hidden_layer_inputs[i][j], "sigmoid");
            }
        }

        float **output_layer_inputs = matrix_multiply(hidden_layer_outputs, hidden_weights, TRAIN_SET_SIZE, MAX_NUM_CLASSES, MAX_NUM_CLASSES);
        float **predicted_labels = (float **) malloc(TRAIN_SET_SIZE * sizeof(float *));
        for (int i = 0; i < TRAIN_SET_SIZE; i++) {
            predicted_labels[i] = (float *) malloc(MAX_NUM_CLASSES * sizeof(float));
            for (int j = 0; j < MAX_NUM_CLASSES; j++) {
                predicted_labels[i][j] = activation_function(output_layer_inputs[i][j], "sigmoid");
            }
        }

        // Backward Pass
        float **output_layer_error = (float **) malloc(TRAIN_SET_SIZE * sizeof(float *));
        for (int i = 0; i < TRAIN_SET_SIZE; i++) {
            output_layer_error[i] = (float *) malloc(MAX_NUM_CLASSES * sizeof(float));
            for (int j = 0; j < MAX_NUM_CLASSES; j++) {
                output_layer_error[i][j] = (predicted_labels[i][j] - train_labels[i][j]) * (predicted_labels[i][j] * (1 - predicted_labels[i][j]));
            }
        }

        float **hidden_layer_error = matrix_multiply(output_layer_error, transpose(output_weights, MAX_NUM_CLASSES, MAX_NUM_CLASSES), TRAIN_SET_SIZE, MAX_NUM_CLASSES, MAX_NUM_CLASSES);
        for (int i = 0; i < TRAIN_SET_SIZE; i++) {
            for (int j = 0; j < MAX_NUM_CLASSES; j++) {
                hidden_layer_error[i][j] *= (hidden_layer_outputs[i][j] * (1 - hidden_layer_outputs[i][j]));
            }
        }

        float **output_weight_adjustment = matrix_multiply(transpose(hidden_layer_outputs, TRAIN_SET_SIZE, MAX_NUM_CLASSES), output_layer_error, MAX_NUM_CLASSES, TRAIN_SET_SIZE, MAX_NUM_CLASSES);
        float **hidden_weight_adjustment = matrix_multiply(transpose(train_data, TRAIN_SET_SIZE, NUM_FEATURES), hidden_layer_error, NUM_FEATURES, TRAIN_SET_SIZE, MAX_NUM_CLASSES);
        float **input_weight_error = matrix_multiply(hidden_layer_error, hidden_weights, TRAIN_SET_SIZE, MAX_NUM_CLASSES, MAX_NUM_CLASSES);
        float **input_weight_adjustment = matrix_multiply(transpose(train_data, TRAIN_SET_SIZE, NUM_FEATURES), input_weight_error, NUM_FEATURES, TRAIN_SET_SIZE, MAX_NUM_CLASSES);

        for (int i = 0; i < NUM_FEATURES; i++) {
            for (int j = 0; j < MAX_NUM_CLASSES; j++) {
                input_weights[i][j] -= learning_rate * input_weight_adjustment[i][j];
            }
        }

        for (int i = 0; i < MAX_NUM_CLASSES; i++) {
            for (int j = 0; j < MAX_NUM_CLASSES; j++) {
                hidden_weights[i][j] -= learning_rate * hidden_weight_adjustment[i][j];
                output_weights[i][j] -= learning_rate * output_weight_adjustment[i][j];
            }
        }
    }

    // Test the network
    float **hidden_layer_inputs = matrix_multiply(test_data, input_weights, TEST_SET_SIZE, NUM_FEATURES, MAX_NUM_CLASSES);
    float **hidden_layer_outputs = (float **) malloc(TEST_SET_SIZE * sizeof(float *));
    for (int i = 0; i < TEST_SET_SIZE; i++) {
        hidden_layer_outputs[i] = (float *) malloc(MAX_NUM_CLASSES * sizeof(float));
        for (int j = 0; j < MAX_NUM_CLASSES; j++) {
            hidden_layer_outputs[i][j] = activation_function(hidden_layer_inputs[i][j], "sigmoid");
        }
    }

    float **output_layer_inputs = matrix_multiply(hidden_layer_outputs, hidden_weights, TEST_SET_SIZE, MAX_NUM_CLASSES, MAX_NUM_CLASSES);
    float **predicted_labels = (float **) malloc(TEST_SET_SIZE * sizeof(float *));
    for (int i = 0; i < TEST_SET_SIZE; i++) {
        predicted_labels[i] = (float *) malloc(MAX_NUM_CLASSES * sizeof(float));
        for (int j = 0; j < MAX_NUM_CLASSES; j++) {
            predicted_labels[i][j] = activation_function(output_layer_inputs[i][j], "sigmoid");
        }
    }

    int num_correct = 0;
    for (int i = 0; i < TEST_SET_SIZE; i++) {
        float max_val = -1;
        int max_index = -1;
        for (int j = 0; j < MAX_NUM_CLASSES; j++) {
            if (predicted_labels[i][j] > max_val) {
                max_val = predicted_labels[i][j];
                max_index = j;
            }
        }
        if (test_labels[i][max_index] == 1) {
            num_correct++;
        }
    }

    float accuracy = (float) num_correct / TEST_SET_SIZE;
    printf("Test Accuracy: %.2f%%\n", accuracy * 100);

    // Free allocated memory
    for (int i = 0; i < TRAIN_SET_SIZE; i++) {
        free(train_data[i]);
        free(train_labels[i]);
    }
    free(train_data);
    free(train_labels);

    for (int i = 0; i < TEST_SET_SIZE; i++) {
        free(test_data[i]);
        free(test_labels[i]);
    }
    free(test_data);
    free(test_labels);

    for (int i = 0; i < NUM_FEATURES; i++) {
        free(input_weights[i]);
    }
    free(input_weights);

    for (int i = 0; i < MAX_NUM_CLASSES; i++) {
        free(hidden_weights[i]);
        free(output_weights[i]);
    }
    free(hidden_weights);
    free(output_weights);

    return 0;
}