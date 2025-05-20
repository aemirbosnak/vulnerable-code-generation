//FormAI DATASET v1.0 Category: Image Classification system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMBER_OF_SAMPLES 10
#define NUMBER_OF_FEATURES 4
#define NUMBER_OF_CLASSES 3
#define MAX_ITERATIONS 1000
#define LEARNING_RATE 0.5

// Define Sample struct
typedef struct Sample {
    double *features;  // array of features
    int label;  // class label
} Sample;

// Define Perceptron struct
typedef struct Perceptron {
    double *weights;  // array of weights
    double bias;  // the bias weight
} Perceptron;

// Function to initialize a sample
Sample *initialize_sample(double *features, int label) {
    Sample *sample = malloc(sizeof(Sample));
    sample->features = features;
    sample->label = label;
    return sample;
}

// Function to initialize a perceptron
Perceptron *initialize_perceptron() {
    Perceptron *perceptron = malloc(sizeof(Perceptron));
    perceptron->weights = malloc(sizeof(double) * NUMBER_OF_FEATURES);
    for (int i = 0; i < NUMBER_OF_FEATURES; i++) {
        perceptron->weights[i] = 0.0;
    }
    perceptron->bias = 0.0;
    return perceptron;
}

// Function to calculate the dot product of two arrays
double dot_product(double *a, double *b, int length) {
    double result = 0.0;
    for (int i = 0; i < length; i++) {
        result += a[i] * b[i];
    }
    return result;
}

// Function to calculate the output of a perceptron for a given sample
int perceptron_output(Perceptron *perceptron, Sample *sample) {
    double output = dot_product(perceptron->weights, sample->features, NUMBER_OF_FEATURES) + perceptron->bias;
    if (output > 0) {
        return 1;
    } else {
        return -1;
    }
}

// Function to train a perceptron on a set of samples
void train_perceptron(Perceptron *perceptron, Sample **samples, int *labels, int num_samples) {
    int iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        int misclassified = 0;
        for (int i = 0; i < num_samples; i++) {
            Sample *sample = samples[i];
            int label = labels[i];
            int output = perceptron_output(perceptron, sample);
            if (output != label) {
                double error = label - output;
                for (int j = 0; j < NUMBER_OF_FEATURES; j++) {
                    perceptron->weights[j] += LEARNING_RATE * error * sample->features[j];
                }
                perceptron->bias += LEARNING_RATE * error;
                misclassified = 1;
            }
        }
        if (!misclassified) {
            break;
        }
        iteration++;
    }
}

// Function to print the weights and bias of a trained perceptron
void print_perceptron(Perceptron *perceptron) {
    printf("Weights: ");
    for (int i = 0; i < NUMBER_OF_FEATURES; i++) {
        printf("%f, ", perceptron->weights[i]);
    }
    printf("\nBias: %f\n", perceptron->bias);
}

int main() {
    // Define three classes of random sample data
    double class1_samples[NUMBER_OF_SAMPLES][NUMBER_OF_FEATURES] = {
        {4.3, 3.0, 1.1, 0.1},
        {5.0, 3.6, 1.4, 0.2},
        {5.2, 3.4, 1.4, 0.2},
        {4.7, 3.2, 1.3, 0.2},
        {4.8, 3.1, 1.6, 0.2},
        {5.4, 3.4, 1.5, 0.4},
        {5.1, 3.5, 1.4, 0.3},
        {5.7, 4.4, 1.5, 0.4},
        {5.4, 3.9, 1.3, 0.4},
        {4.6, 3.4, 1.4, 0.3},
    };
    double class2_samples[NUMBER_OF_SAMPLES][NUMBER_OF_FEATURES] = {
        {7.0, 3.2, 4.7, 1.4},
        {6.4, 3.2, 4.5, 1.5},
        {6.9, 3.1, 4.9, 1.5},
        {5.5, 2.3, 4.0, 1.3},
        {6.5, 2.8, 4.6, 1.5},
        {5.7, 2.8, 4.5, 1.3},
        {6.3, 3.3, 4.7, 1.6},
        {4.9, 2.4, 3.3, 1.0},
        {6.6, 2.9, 4.6, 1.3},
        {5.2, 2.7, 3.9, 1.4},
    };
    double class3_samples[NUMBER_OF_SAMPLES][NUMBER_OF_FEATURES] = {
        {6.3, 2.5, 5.0, 1.9},
        {5.8, 2.7, 5.1, 1.9},
        {7.1, 3.0, 5.9, 2.1},
        {6.3, 3.3, 6.0, 2.5},
        {6.5, 3.0, 5.8, 2.2},
        {7.6, 3.0, 6.6, 2.1},
        {4.9, 2.5, 4.5, 1.7},
        {7.3, 2.9, 6.3, 1.8},
        {6.7, 2.5, 5.8, 1.8},
        {7.2, 3.6, 6.1, 2.5},
    };
    // Create array of Sample pointers for each class
    Sample *class1[NUMBER_OF_SAMPLES];
    Sample *class2[NUMBER_OF_SAMPLES];
    Sample *class3[NUMBER_OF_SAMPLES];
    for (int i = 0; i < NUMBER_OF_SAMPLES; i++) {
        double *feat_ptr = class1_samples[i];
        class1[i] = initialize_sample(feat_ptr, 1);
        feat_ptr = class2_samples[i];
        class2[i] = initialize_sample(feat_ptr, 2);
        feat_ptr = class3_samples[i];
        class3[i] = initialize_sample(feat_ptr, 3);
    }
    // Concatenate the sets of Sample pointers into training set arrays
    Sample **training_set = malloc(sizeof(Sample *) * NUMBER_OF_SAMPLES * NUMBER_OF_CLASSES);
    int *labels = malloc(sizeof(int) * NUMBER_OF_SAMPLES * NUMBER_OF_CLASSES);
    for (int i = 0; i < NUMBER_OF_SAMPLES; i++) {
        training_set[i] = class1[i];
        labels[i] = 1;
        training_set[NUMBER_OF_SAMPLES + i] = class2[i];
        labels[NUMBER_OF_SAMPLES + i] = -1;
        training_set[NUMBER_OF_SAMPLES * 2 + i] = class3[i];
        labels[NUMBER_OF_SAMPLES * 2 + i] = -1;
    }
    // Initialize the perceptron and train it on the training set
    Perceptron *perceptron = initialize_perceptron();
    train_perceptron(perceptron, training_set, labels, NUMBER_OF_SAMPLES * NUMBER_OF_CLASSES);
    // Print the learned weights and bias
    print_perceptron(perceptron);
    // Free memory allocated for samples, training set, labels, and perceptron
    for (int i = 0; i < NUMBER_OF_SAMPLES; i++) {
        free(class1[i]->features);
        free(class1[i]);
        free(class2[i]->features);
        free(class2[i]);
        free(class3[i]->features);
        free(class3[i]);
    }
    free(training_set);
    free(labels);
    free(perceptron->weights);
    free(perceptron);
    return 0;
}