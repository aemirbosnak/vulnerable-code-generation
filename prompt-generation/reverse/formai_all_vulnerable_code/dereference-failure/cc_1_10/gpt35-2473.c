//FormAI DATASET v1.0 Category: Image Classification system ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_FILENAME_LENGTH 1024
#define MAX_LABEL_LENGTH 256
#define NUM_LABELS 10
#define IMAGE_SIZE 784 // 28x28 pixels
#define TRAIN_SIZE 5000
#define TEST_SIZE 1000

// Training and testing data
int training_data[TRAIN_SIZE][IMAGE_SIZE];
int training_labels[TRAIN_SIZE];
int test_data[TEST_SIZE][IMAGE_SIZE];
int test_labels[TEST_SIZE];

// Function to load data from file
void load_data(char *filename, int data[][IMAGE_SIZE], int labels[], int size) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    char line[MAX_FILENAME_LENGTH];
    int i = 0;
    while (fgets(line, MAX_FILENAME_LENGTH, fp) != NULL && i < size) {
        char *token = strtok(line, ",");
        labels[i] = atoi(token);
        for (int j = 0; j < IMAGE_SIZE; j++) {
            token = strtok(NULL, ",");
            data[i][j] = atoi(token);
        }
        i++;
    }
    fclose(fp);
}

// Function to classify test data using k-nearest neighbors algorithm
int knn(int k, int test_image[]) {
    // Calculate distances to all training images
    double distances[TRAIN_SIZE];
    for (int i = 0; i < TRAIN_SIZE; i++) {
        double dist = 0.0;
        for (int j = 0; j < IMAGE_SIZE; j++) {
            dist += (test_image[j] - training_data[i][j]) * (test_image[j] - training_data[i][j]);
        }
        distances[i] = dist;
    }
    // Sort distances in ascending order
    int sorted_indices[TRAIN_SIZE];
    for (int i = 0; i < TRAIN_SIZE; i++) {
        sorted_indices[i] = i;
    }
    for (int i = 0; i < TRAIN_SIZE - 1; i++) {
        for (int j = i + 1; j < TRAIN_SIZE; j++) {
            if (distances[sorted_indices[i]] > distances[sorted_indices[j]]) {
                int temp = sorted_indices[i];
                sorted_indices[i] = sorted_indices[j];
                sorted_indices[j] = temp;
            }
        }
    }
    // Find the most common label among the k nearest neighbors
    int labels_count[NUM_LABELS] = {0};
    for (int i = 0; i < k; i++) {
        labels_count[training_labels[sorted_indices[i]]]++;
    }
    int max_count = 0;
    int max_label = -1;
    for (int i = 0; i < NUM_LABELS; i++) {
        if (labels_count[i] > max_count) {
            max_count = labels_count[i];
            max_label = i;
        }
    }
    return max_label;
}

int main() {
    // Load training and testing data
    load_data("mnist_train.csv", training_data, training_labels, TRAIN_SIZE);
    load_data("mnist_test.csv", test_data, test_labels, TEST_SIZE);
    // Test classification accuracy using k-nearest neighbors algorithm with various values of k
    printf("k\tAccuracy\n");
    for (int k = 1; k <= 10; k++) {
        int correct = 0;
        for (int i = 0; i < TEST_SIZE; i++) {
            if (knn(k, test_data[i]) == test_labels[i]) {
                correct++;
            }
        }
        double accuracy = (double) correct / TEST_SIZE;
        printf("%d\t%.2f%%\n", k, accuracy * 100);
    }
    return 0;
}