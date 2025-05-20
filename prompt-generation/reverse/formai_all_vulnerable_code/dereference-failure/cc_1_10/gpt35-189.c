//FormAI DATASET v1.0 Category: Image Classification system ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_INPUTS 784 // 28*28 pixels
#define NUM_HIDDEN 256
#define NUM_OUTPUTS 10
#define LEARNING_RATE 0.5
#define NUM_ITERATIONS 2000
#define BATCH_SIZE 100

typedef struct {
    double inputs[NUM_INPUTS];
    double hidden[NUM_HIDDEN];
    double outputs[NUM_OUTPUTS];
    int label;
} Image;

typedef struct {
    double w_ih[NUM_INPUTS][NUM_HIDDEN];
    double w_ho[NUM_HIDDEN][NUM_OUTPUTS];
    double b_h[NUM_HIDDEN];
    double b_o[NUM_OUTPUTS];
} NeuralNet;

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double sigmoid_deriv(double x) {
    return x * (1 - x);
}

void initialize_weights(NeuralNet *net) {
    for (int i = 0; i < NUM_INPUTS; i++) {
        for (int j = 0; j < NUM_HIDDEN; j++) {
            net->w_ih[i][j] = ((double) rand() / (double) RAND_MAX) - 0.5;
        }
    }

    for (int i = 0; i < NUM_HIDDEN; i++) {
        for (int j = 0; j < NUM_OUTPUTS; j++) {
            net->w_ho[i][j] = ((double) rand() / (double) RAND_MAX) - 0.5;
        }
    }

    for (int i = 0; i < NUM_HIDDEN; i++) {
        net->b_h[i] = ((double) rand() / (double) RAND_MAX) - 0.5;
    }

    for (int i = 0; i < NUM_OUTPUTS; i++) {
        net->b_o[i] = ((double) rand() / (double) RAND_MAX) - 0.5;
    }
}

void forward_pass(NeuralNet *net, Image *img) {
    // calculate hidden layer activations
    for (int i = 0; i < NUM_HIDDEN; i++) {
        double sum = 0.0;
        for (int j = 0; j < NUM_INPUTS; j++) {
            sum += img->inputs[j] * net->w_ih[j][i];
        }
        sum += net->b_h[i];
        img->hidden[i] = sigmoid(sum);
    }

    // calculate output layer activations
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        double sum = 0.0;
        for (int j = 0; j < NUM_HIDDEN; j++) {
            sum += img->hidden[j] * net->w_ho[j][i];
        }
        sum += net->b_o[i];
        img->outputs[i] = sigmoid(sum);
    }
}

void backward_pass(NeuralNet *net, Image *img) {
    // calculate delta for output layer
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        double error = img->outputs[i] - (img->label == i ? 1.0 : 0.0);
        double derivative = sigmoid_deriv(img->outputs[i]);
        double delta = error * derivative;
        for (int j = 0; j < NUM_HIDDEN; j++) {
            net->w_ho[j][i] -= LEARNING_RATE * delta * img->hidden[j];
        }
        net->b_o[i] -= LEARNING_RATE * delta;
    }

    // calculate delta for hidden layer
    for (int i = 0; i < NUM_HIDDEN; i++) {
        double error = 0.0;
        for (int j = 0; j < NUM_OUTPUTS; j++) {
            error += net->w_ho[i][j] * (img->outputs[j] - (img->label == j ? 1.0 : 0.0));
        }
        double derivative = sigmoid_deriv(img->hidden[i]);
        double delta = error * derivative;
        for (int j = 0; j < NUM_INPUTS; j++) {
            net->w_ih[j][i] -= LEARNING_RATE * delta * img->inputs[j];
        }
        net->b_h[i] -= LEARNING_RATE * delta;
    }
}

int main() {
    // load dataset
    FILE *fp = fopen("train-images-idx3-ubyte", "rb");
    fseek(fp, 16, SEEK_SET);
    Image *images = malloc(sizeof(Image) * 60000);
    for (int i = 0; i < 60000; i++) {
        for (int j = 0; j < NUM_INPUTS; j++) {
            unsigned char pixel;
            fread(&pixel, 1, 1, fp);
            images[i].inputs[j] = (double) pixel / 255.0;
        }
    }
    fclose(fp);

    fp = fopen("train-labels-idx1-ubyte", "rb");
    fseek(fp, 8, SEEK_SET);
    for (int i = 0; i < 60000; i++) {
        unsigned char label;
        fread(&label, 1, 1, fp);
        images[i].label = (int) label;
    }
    fclose(fp);

    // initialize neural network
    NeuralNet net;
    initialize_weights(&net);

    // train network
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        double total_error = 0.0;
        for (int j = 0; j < BATCH_SIZE; j++) {
            int index = rand() % 60000;
            Image *img = &images[index];
            forward_pass(&net, img);
            backward_pass(&net, img);
            double error = 0.0;
            for (int k = 0; k < NUM_OUTPUTS; k++) {
                error += (img->outputs[k] - (img->label == k ? 1.0 : 0.0)) * (img->outputs[k] - (img->label == k ? 1.0 : 0.0));
            }
            total_error += error;
        }
        printf("Iteration %d complete. Average squared error: %lf\n", i, total_error / BATCH_SIZE);
    }

    // test network on validation set
    fp = fopen("t10k-images-idx3-ubyte", "rb");
    fseek(fp, 16, SEEK_SET);
    Image *validation = malloc(sizeof(Image) * 10000);
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < NUM_INPUTS; j++) {
            unsigned char pixel;
            fread(&pixel, 1, 1, fp);
            validation[i].inputs[j] = (double) pixel / 255.0;
        }
    }
    fclose(fp);

    fp = fopen("t10k-labels-idx1-ubyte", "rb");
    fseek(fp, 8, SEEK_SET);
    for (int i = 0; i < 10000; i++) {
        unsigned char label;
        fread(&label, 1, 1, fp);
        validation[i].label = (int) label;
    }
    fclose(fp);

    int correct = 0;
    for (int i = 0; i < 10000; i++) {
        forward_pass(&net, &validation[i]);
        int predicted = 0;
        for (int j = 1; j < NUM_OUTPUTS; j++) {
            if (validation[i].outputs[j] > validation[i].outputs[predicted]) {
                predicted = j;
            }
        }
        if (predicted == validation[i].label) {
            correct++;
        }
    }
    printf("Validation accuracy: %lf\n", (double) correct / 10000.0);

    return 0;
}