//FormAI DATASET v1.0 Category: Image Classification system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define NUM_CLASSES 10
#define NUM_FEATURES 784
#define NUM_TEST_SAMPLES 1000
#define NUM_TRAIN_SAMPLES 60000

// Define data structures
typedef struct {
    int label;
    double features[NUM_FEATURES];
} Sample;

typedef struct {
    Sample samples[NUM_TRAIN_SAMPLES];
    int num_samples;
} TrainData;

typedef struct {
    Sample samples[NUM_TEST_SAMPLES];
    int num_samples;
} TestData;

typedef struct {
    double weights[NUM_CLASSES][NUM_FEATURES];
} Model;

// Define helper functions
int read_train_data(FILE *file, TrainData *data) {
    int num_samples = 0;
    
    char line[1024];
    while (fgets(line, 1024, file)) {
        // Parse label and features from line and store in sample
        Sample sample;
        sscanf(line, "%d,", &sample.label);
        char *feature_str = strchr(line, ',') + 1;
        char *ptr;
        for (int i = 0; i < NUM_FEATURES; i++) {
            sample.features[i] = strtod(feature_str, &ptr);
            feature_str = ptr;
        }
        
        // Add sample to train data
        data->samples[num_samples++] = sample;
    }
    
    data->num_samples = num_samples;
    return num_samples;
}

int read_test_data(FILE *file, TestData *data) {
    int num_samples = 0;
    
    char line[1024];
    while (fgets(line, 1024, file)) {
        // Parse label and features from line and store in sample
        Sample sample;
        sscanf(line, "%d,", &sample.label);
        char *feature_str = strchr(line, ',') + 1;
        char *ptr;
        for (int i = 0; i < NUM_FEATURES; i++) {
            sample.features[i] = strtod(feature_str, &ptr);
            feature_str = ptr;
        }
        
        // Add sample to test data
        data->samples[num_samples++] = sample;
    }
    
    data->num_samples = num_samples;
    return num_samples;
}

int get_predicted_label(Model *model, Sample sample) {
    double max_score = -1;
    int predicted_label = -1;
    
    // Compute score for each class and find class with highest score
    for (int c = 0; c < NUM_CLASSES; c++) {
        double score = 0;
        for (int f = 0; f < NUM_FEATURES; f++) {
            score += model->weights[c][f] * sample.features[f];
        }
        
        if (score > max_score) {
            max_score = score;
            predicted_label = c;
        }
    }
    
    return predicted_label;
}

double train_model(TrainData *train_data, Model *model) {
    double overall_loss = 0;
    
    // Loop over each training sample
    for (int i = 0; i < train_data->num_samples; i++) {
        Sample sample = train_data->samples[i];
        int label = sample.label;
        
        // Compute scores for each class
        double scores[NUM_CLASSES];
        for (int c = 0; c < NUM_CLASSES; c++) {
            double score = 0;
            for (int f = 0; f < NUM_FEATURES; f++) {
                score += model->weights[c][f] * sample.features[f];
            }
            scores[c] = score;
        }
        
        // Compute softmax probabilities and loss
        double softmax[NUM_CLASSES];
        double loss = 0;
        for (int c = 0; c < NUM_CLASSES; c++) {
            softmax[c] = exp(scores[c]);
            loss += (c == label ? -log(softmax[c]) : 0);
        }
        overall_loss += loss;
        
        // Update weights using stochastic gradient descent
        for (int f = 0; f < NUM_FEATURES; f++) {
            double gradient = 0;
            for (int c = 0; c < NUM_CLASSES; c++) {
                double target = (c == label ? 1 : 0);
                gradient += (softmax[c] / (1 + exp(-scores[c]))) * (target - softmax[c]) * sample.features[f];
            }
            model->weights[label][f] += gradient;
        }
    }
    
    return overall_loss / train_data->num_samples;
}

void test_model(TestData *test_data, Model *model) {
    int num_correct = 0;
    
    // Loop over each test sample
    for (int i = 0; i < test_data->num_samples; i++) {
        Sample sample = test_data->samples[i];
        int label = sample.label;
        
        // Compute predicted label
        int predicted_label = get_predicted_label(model, sample);
        
        // Check if predicted label is correct
        if (predicted_label == label) {
            num_correct++;
        }
    }
    
    double accuracy = (double) num_correct / test_data->num_samples;
    printf("Test accuracy: %.2f%%\n", accuracy * 100);
}

int main(int argc, char *argv[]) {
    // Read training and test data from files
    FILE *train_file = fopen("mnist_train.csv", "r");
    TrainData train_data;
    int num_train_samples = read_train_data(train_file, &train_data);
    fclose(train_file);
    
    FILE *test_file = fopen("mnist_test.csv", "r");
    TestData test_data;
    int num_test_samples = read_test_data(test_file, &test_data);
    fclose(test_file);
    
    printf("Loaded %d training samples and %d test samples.\n", num_train_samples, num_test_samples);
    
    // Initialize model weights
    Model model;
    for (int c = 0; c < NUM_CLASSES; c++) {
        for (int f = 0; f < NUM_FEATURES; f++) {
            model.weights[c][f] = 0;
        }
    }
    
    // Train model
    double prev_loss = 1e9;
    double curr_loss = train_model(&train_data, &model);
    int num_epochs = 1;
    while (prev_loss - curr_loss > 1e-4) {
        printf("Epoch %d: average loss = %f\n", num_epochs++, curr_loss);
        prev_loss = curr_loss;
        curr_loss = train_model(&train_data, &model);
    }
    
    // Test model
    test_model(&test_data, &model);
    
    return 0;
}