//FormAI DATASET v1.0 Category: Image Classification system ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000
#define NUM_CLASSES 3
#define NUM_FEATURES 4
#define TRAIN_FILE "train_data.csv"
#define TEST_FILE "test_data.csv"
#define ACC_THRESHOLD 0.75

// function for loading data from a CSV file
void load_data(char *filename, int data[NUM_CLASSES][MAX_LEN][NUM_FEATURES]) {
    FILE *csv_file = fopen(filename, "r");

    char line[MAX_LEN];
    int row = 0;
    while (fgets(line, MAX_LEN, csv_file)) {
        char *token;
        token = strtok(line, ",");
        int col = 0;
        while (token != NULL) {
            data[row / MAX_LEN][row % MAX_LEN][col++] = atoi(token);
            token = strtok(NULL, ",");
        }
        row++;
    }

    fclose(csv_file);
}

// function for classifying a test feature vector
int classify(int *test_feature, int train_data[NUM_CLASSES][MAX_LEN][NUM_FEATURES]) {
    int max_class = -1;
    float max_prob = -1;

    for (int c = 0; c < NUM_CLASSES; c++) {
        float prob = 1;
        for (int f = 0; f < NUM_FEATURES; f++) {
            float feature_prob = 0;
            for (int i = 0; i < MAX_LEN; i++) {
                feature_prob += train_data[c][i][f] == test_feature[f] ? 1 : 0;
            }
            prob *= feature_prob / MAX_LEN;
        }
        if (prob > max_prob) {
            max_prob = prob;
            max_class = c;
        }
    }

    return max_class;
}

int main() {
    // load training and test data
    int train_data[NUM_CLASSES][MAX_LEN][NUM_FEATURES];
    load_data(TRAIN_FILE, train_data);
    int test_data[MAX_LEN][NUM_FEATURES];
    load_data(TEST_FILE, test_data);

    // classify test data and calculate accuracy
    float accuracy = 0;
    for (int i = 0; i < MAX_LEN; i++) {
        int predicted_class = classify(test_data[i], train_data);
        accuracy += predicted_class == test_data[i][NUM_FEATURES - 1] ? 1 : 0;
    }
    accuracy /= MAX_LEN;

    // print results
    printf("Accuracy: %.2f\n", accuracy);
    if (accuracy >= ACC_THRESHOLD) {
        printf("Model passed accuracy threshold\n");
    } else {
        printf("Model failed accuracy threshold\n");
    }

    return 0;
}