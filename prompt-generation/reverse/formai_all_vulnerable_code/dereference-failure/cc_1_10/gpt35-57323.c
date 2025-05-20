//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: scientific
/*
 * Intrusion Detection System Example Program in C
 * 
 * The program reads and analyzes log files to detect potential security breaches. 
 * Specifically, it looks for suspicious activity such as failed login attempts, 
 * system crashes, or logins at unusual times of day.
 * 
 * The program uses a neural network to identify patterns in the log data and 
 * flag any unusual activity that deviates from the norm.
 * 
 * Author: John Doe
 * Date: 2021/05/01
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "system.log"
#define TRAINING_FILE "training.data"
#define NEURAL_NETWORK_FILE "model.nn"
#define INPUT_SIZE 5 /* number of features in log data */
#define HIDDEN_SIZE 5 /* number of hidden neurons */
#define OUTPUT_SIZE 1 /* number of outputs: 0 for normal, 1 for anomaly */
#define LEARNING_RATE 0.1 /* neural network learning rate */
#define MOMENTUM 0.5 /* neural network momentum term */
#define EPOCHS 1000 /* number of training epochs */

typedef struct {
    double *input;
    double *hidden;
    double *output;
    double **w_input_hidden;
    double **w_hidden_output;
    double *bias_hidden;
    double *bias_output;
} NeuralNetwork;

void read_log_file(const char *filename, double *data, int data_size);
void normalize_data(double *data, int data_size);
void save_training_data(const char *filename, double *data, int data_size);
void load_training_data(const char *filename, double *data, int data_size);
void initialize_neural_network(NeuralNetwork *nn);
void train_neural_network(NeuralNetwork *nn, double *data, int data_size);
void save_neural_network(NeuralNetwork *nn, const char *filename);
void load_neural_network(NeuralNetwork *nn, const char *filename);
double sigmoid(double x);
void feed_forward(NeuralNetwork *nn);
void backpropagation(NeuralNetwork *nn);

int main() {
    double *data = (double*) malloc(INPUT_SIZE * sizeof(double));
    read_log_file(LOG_FILE, data, INPUT_SIZE);
    normalize_data(data, INPUT_SIZE);
    save_training_data(TRAINING_FILE, data, INPUT_SIZE);

    NeuralNetwork nn;
    initialize_neural_network(&nn);
    train_neural_network(&nn, data, INPUT_SIZE);
    save_neural_network(&nn, NEURAL_NETWORK_FILE);

    free(data);
    return 0;
}

void read_log_file(const char *filename, double *data, int data_size) {
    /* read log file and extract relevant data */
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error: could not open log file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "failed login attempt", 20) == 0) {
            /* feature 1: login failed */
            data[0]++;

            /* feature 2: system crash */
            time_t t = time(NULL);
            struct tm *now = localtime(&t);
            if (now->tm_hour >= 0 && now->tm_hour < 6) {
                data[1]++;
            }

            /* feature 3: logins between 12pm and 2pm */
            if (now->tm_hour >= 12 && now->tm_hour < 14) {
                data[2]++;
            }
        }
        else {
            /* feature 4: successful login */
            data[3]++;
        }

        /* feature 5: total number of log entries */
        data[4]++;
    }

    fclose(fp);
}

void normalize_data(double *data, int data_size) {
    /* normalize data to range [0, 1] */
    double max_val = 0;
    for (int i = 0; i < data_size; i++) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }

    for (int i = 0; i < data_size; i++) {
        data[i] /= max_val;
    }
}

void save_training_data(const char *filename, double *data, int data_size) {
    /* save training data to file */
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error: could not save training data");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < data_size; i++) {
        fprintf(fp, "%lf ", data[i]);
    }

    fclose(fp);
}

void load_training_data(const char *filename, double *data, int data_size) {
    /* load training data from file */
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error: could not load training data");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < data_size; i++) {
        fscanf(fp, "%lf", &data[i]);
    }

    fclose(fp);
}

void initialize_neural_network(NeuralNetwork *nn) {
    /* allocate memory for neural network */
    nn->input = (double*) calloc(INPUT_SIZE, sizeof(double));
    nn->hidden = (double*) calloc(HIDDEN_SIZE, sizeof(double));
    nn->output = (double*) calloc(OUTPUT_SIZE, sizeof(double));
    nn->w_input_hidden = (double**) malloc(INPUT_SIZE * sizeof(double*));
    nn->w_hidden_output = (double**) malloc(HIDDEN_SIZE * sizeof(double*));
    nn->bias_hidden = (double*) calloc(HIDDEN_SIZE, sizeof(double));
    nn->bias_output = (double*) calloc(OUTPUT_SIZE, sizeof(double));

    /* initialize weights to random values */
    for (int i = 0; i < INPUT_SIZE; i++) {
        nn->w_input_hidden[i] = (double*) malloc(HIDDEN_SIZE * sizeof(double));
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            nn->w_input_hidden[i][j] = (double) rand() / RAND_MAX;
        }
    }

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        nn->w_hidden_output[i] = (double*) malloc(OUTPUT_SIZE * sizeof(double));
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            nn->w_hidden_output[i][j] = (double) rand() / RAND_MAX;
        }
    }
}

void train_neural_network(NeuralNetwork *nn, double *data, int data_size) {
    /* load training data from file */
    double *training_data = (double*) malloc(data_size * sizeof(double));
    load_training_data(TRAINING_FILE, training_data, data_size);

    /* train neural network using backpropagation */
    for (int i = 0; i < EPOCHS; i++) {
        /* set input layer */
        for (int j = 0; j < INPUT_SIZE; j++) {
            nn->input[j] = training_data[j];
        }

        /* feed forward */
        feed_forward(nn);

        /* calculate error and update weights */
        backpropagation(nn);
    }

    free(training_data);
}

void save_neural_network(NeuralNetwork *nn, const char *filename) {
    /* save neural network to file */
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error: could not save neural network");
        exit(EXIT_FAILURE);
    }

    /* save hidden layer weights */
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            fprintf(fp, "%lf ", nn->w_input_hidden[i][j]);
        }
    }

    /* save output layer weights */
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            fprintf(fp, "%lf ", nn->w_hidden_output[i][j]);
        }
    }

    /* save bias values */
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        fprintf(fp, "%lf ", nn->bias_hidden[i]);
    }

    fprintf(fp, "%lf ", nn->bias_output[0]);

    fclose(fp);
}

void load_neural_network(NeuralNetwork *nn, const char *filename) {
    /* load neural network from file */
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error: could not load neural network");
        exit(EXIT_FAILURE);
    }

    /* load hidden layer weights */
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            fscanf(fp, "%lf", &nn->w_input_hidden[i][j]);
        }
    }

    /* load output layer weights */
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            fscanf(fp, "%lf", &nn->w_hidden_output[i][j]);
        }
    }

    /* load bias values */
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        fscanf(fp, "%lf", &nn->bias_hidden[i]);
    }

    fscanf(fp, "%lf", &nn->bias_output[0]);

    fclose(fp);
}

double sigmoid(double x) {
    /* sigmoid activation function */
    return 1 / (1 + exp(-x));
}

void feed_forward(NeuralNetwork *nn) {
    /* feed forward through neural network */
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            sum += nn->input[j] * nn->w_input_hidden[j][i];
        }
        nn->hidden[i] = sigmoid(sum + nn->bias_hidden[i]);
    }

    double sum = 0;
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        sum += nn->hidden[i] * nn->w_hidden_output[i][0];
    }
    nn->output[0] = sigmoid(sum + nn->bias_output[0]);
}

void backpropagation(NeuralNetwork *nn) {
    /* backpropagation algorithm to update weights */
    double error = nn->output[0] - nn->input[0];

    double delta_output = error * nn->output[0] * (1 - nn->output[0]);

    double delta_hidden[HIDDEN_SIZE];
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        delta_hidden[i] = nn->hidden[i] * (1 - nn->hidden[i]) * nn->w_hidden_output[i][0] * delta_output;
    }

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            double temp = nn->w_hidden_output[i][j];
            nn->w_hidden_output[i][j] += LEARNING_RATE * delta_output * nn->hidden[i] + MOMENTUM * (nn->w_hidden_output[i][j] - nn->bias_hidden[i]);
            nn->bias_output[j] += LEARNING_RATE * delta_output * nn->bias_output[j];
            nn->w_hidden_output[i][j] += MOMENTUM * (nn->w_hidden_output[i][j] - temp);
        }
    }

    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            double temp = nn->w_input_hidden[i][j];
            nn->w_input_hidden[i][j] += LEARNING_RATE * delta_hidden[j] * nn->input[i] + MOMENTUM * (nn->w_input_hidden[i][j] - nn->bias_hidden[j]);
            nn->bias_hidden[j] += LEARNING_RATE * delta_hidden[j] * nn->bias_hidden[j];
            nn->w_input_hidden[i][j] += MOMENTUM * (nn->w_input_hidden[i][j] - temp);
        }
    }
}