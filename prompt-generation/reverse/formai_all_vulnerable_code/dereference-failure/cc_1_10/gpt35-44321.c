//FormAI DATASET v1.0 Category: Image Classification system ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 64
#define NUM_CLASSES 3

typedef struct {
    char label[20];
    float features[INPUT_SIZE];
} Sample;

typedef struct {
    float weights[INPUT_SIZE];
    float bias;
} Model;

void load_data(Sample data[], const char* filename) {
    FILE* file = fopen(filename, "r");
    char line[1024];

    int i = 0;
    while (fgets(line, 1024, file)) {
        char* tok;
        int j = 0;
        tok = strtok(line, ",");
        strcpy(data[i].label, tok);
        while (tok != NULL) {
            tok = strtok(NULL, ",");
            if (tok != NULL)
                data[i].features[j++] = atof(tok);
        }
        i++;
    }

    fclose(file);
}

void train(Model* model, Sample data[], int num_samples, float learning_rate, int num_epochs) {
    int i, j, k;
    float z, y, error, delta;

    for (i = 0; i < num_epochs; i++) {
        error = 0.0;
        for (j = 0; j < num_samples; j++) {
            z = 0.0;
            for (k = 0; k < INPUT_SIZE; k++) {
                z += model->weights[k] * data[j].features[k];
            }
            z += model->bias;
            y = 1.0 / (1.0 + exp(-z));
            delta = y - (float)(strcmp(data[j].label, "class0") == 0);
            error += delta * delta;
            for (k = 0; k < INPUT_SIZE; k++) {
                model->weights[k] -= learning_rate * delta * data[j].features[k];
            }
            model->bias -= learning_rate * delta;
        }
        error /= num_samples;
        printf("Epoch %d, loss = %f\n", i+1, error);
    }
}

int predict(Model* model, float features[]) {
    int i;
    float z = 0.0, y;
    for (i = 0; i < INPUT_SIZE; i++) {
        z += model->weights[i] * features[i];
    }
    z += model->bias;
    y = 1.0 / (1.0 + exp(-z));
    if (y > 0.5)
        return 1;
    else
        return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <train_file> <test_file>\n", argv[0]);
        return 1;
    }

    Model model;
    memset(&model, 0, sizeof(Model));
    Sample train_data[100], test_data[100];
    int num_train = 0, num_test = 0;
    float learning_rate = 0.01;
    int num_epochs = 100;

    load_data(train_data, argv[1]);
    num_train = sizeof(train_data) / sizeof(train_data[0]);
    load_data(test_data, argv[2]);
    num_test = sizeof(test_data) / sizeof(test_data[0]);

    printf("Training...\n");
    train(&model, train_data, num_train, learning_rate, num_epochs);

    printf("Testing...\n");
    int correct = 0;
    for (int i = 0; i < num_test; i++) {
        int label = (strcmp(test_data[i].label, "class0") == 0) ? 0 : 1;
        int prediction = predict(&model, test_data[i].features);
        if (label == prediction) {
            correct++;
        }
    }
    printf("Accuracy: %f\n", (float)correct / num_test);

    return 0;
}