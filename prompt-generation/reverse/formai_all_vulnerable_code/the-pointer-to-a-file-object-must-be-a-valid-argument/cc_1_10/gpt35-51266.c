//FormAI DATASET v1.0 Category: Image Classification system ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMG_HEIGHT 28
#define IMG_WIDTH 28
#define NUM_LABELS 10
#define NUM_PIXELS (IMG_HEIGHT * IMG_WIDTH)
#define NUM_SAMPLES 10000
#define TRAIN_SIZE 8000
#define TEST_SIZE 2000
#define EPOCHS 100
#define BATCH_SIZE 16
#define LEARNING_RATE 0.01

typedef struct {
    float data[NUM_PIXELS];
    int label;
} Sample;

void load_data(Sample *samples, char *filename, int num_samples);
void random_shuffle(Sample *samples, int size);
float sigmoid(float x);
float sigmoid_derivative(float x);

int main() {
    Sample *train_data = malloc(TRAIN_SIZE * sizeof(Sample));
    Sample *test_data = malloc(TEST_SIZE * sizeof(Sample));
    load_data(train_data, "train_data.txt", TRAIN_SIZE);
    load_data(test_data, "test_data.txt", TEST_SIZE);
    random_shuffle(train_data, TRAIN_SIZE);

    float *weights = malloc(NUM_PIXELS * NUM_LABELS * sizeof(float));
    float *bias = malloc(NUM_LABELS * sizeof(float));
    memset(weights, 0, NUM_PIXELS * NUM_LABELS * sizeof(float));
    memset(bias, 0, NUM_LABELS * sizeof(float));

    int num_batches = TRAIN_SIZE / BATCH_SIZE;

    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        for (int batch = 0; batch < num_batches; batch++) {
            int start_index = batch * BATCH_SIZE;
            
            // Forward pass
            float *outputs = malloc(BATCH_SIZE * NUM_LABELS * sizeof(float));
            memset(outputs, 0, BATCH_SIZE * NUM_LABELS * sizeof(float));
            for (int i = 0; i < BATCH_SIZE; i++) {
                for (int j = 0; j < NUM_LABELS; j++) {
                    float sum = 0;
                    for (int k = 0; k < NUM_PIXELS; k++) {
                        sum += train_data[start_index + i].data[k] * weights[k * NUM_LABELS + j];
                    }
                    outputs[i * NUM_LABELS + j] = sigmoid(sum + bias[j]);
                }
            }

            // Backward pass
            float *errors = malloc(BATCH_SIZE * NUM_LABELS * sizeof(float));
            memset(errors, 0, BATCH_SIZE * NUM_LABELS * sizeof(float));
            for (int i = 0; i < BATCH_SIZE; i++) {
                for (int j = 0; j < NUM_LABELS; j++) {
                    if (j == train_data[start_index + i].label) {
                        errors[i * NUM_LABELS + j] = outputs[i * NUM_LABELS + j] - 1;
                    } else {
                        errors[i * NUM_LABELS + j] = outputs[i * NUM_LABELS + j];
                    }
                }
            }

            float *grad_weights = malloc(NUM_PIXELS * NUM_LABELS * sizeof(float));
            memset(grad_weights, 0, NUM_PIXELS * NUM_LABELS * sizeof(float));
            float *grad_bias = malloc(NUM_LABELS * sizeof(float));
            memset(grad_bias, 0, NUM_LABELS * sizeof(float));
            for (int i = 0; i < BATCH_SIZE; i++) {
                for (int j = 0; j < NUM_LABELS; j++) {
                    for (int k = 0; k < NUM_PIXELS; k++) {
                        grad_weights[k * NUM_LABELS + j] += train_data[start_index + i].data[k] * errors[i * NUM_LABELS + j];
                    }
                    grad_bias[j] += errors[i * NUM_LABELS + j];
                }
            }

            for (int i = 0; i < NUM_PIXELS * NUM_LABELS; i++) {
                weights[i] -= LEARNING_RATE * grad_weights[i] / BATCH_SIZE;
            }
            for (int i = 0; i < NUM_LABELS; i++) {
                bias[i] -= LEARNING_RATE * grad_bias[i] / BATCH_SIZE;
            }

            free(outputs);
            free(errors);
            free(grad_weights);
            free(grad_bias);
        }

        // Test accuracy
        int correct = 0;
        for (int i = 0; i < TEST_SIZE; i++) {
            float max_val = -1;
            int max_index = -1;
            for (int j = 0; j < NUM_LABELS; j++) {
                float sum = 0;
                for (int k = 0; k < NUM_PIXELS; k++) {
                    sum += test_data[i].data[k] * weights[k * NUM_LABELS + j];
                }
                float output = sigmoid(sum + bias[j]);
                if (output > max_val) {
                    max_val = output;
                    max_index = j;
                }
            }
            if (max_index == test_data[i].label) {
                correct++;
            }
        }
        float accuracy = (float) correct / TEST_SIZE;
        printf("Epoch %d test accuracy: %.2f%%\n", epoch+1, accuracy * 100);
    }

    free(train_data);
    free(test_data);
    free(weights);
    free(bias);
    return 0;
}

void load_data(Sample *samples, char *filename, int num_samples) {
    FILE *fp = fopen(filename, "r");
    char line[IMG_HEIGHT * IMG_WIDTH + 2];

    for (int i = 0; i < num_samples; i++) {
        fgets(line, IMG_HEIGHT * IMG_WIDTH + 2, fp);
        for (int j = 0; j < IMG_HEIGHT * IMG_WIDTH; j++) {
            samples[i].data[j] = (float) (line[j] - '0') / 255;
        }
        samples[i].label = line[IMG_HEIGHT * IMG_WIDTH] - '0';
    }

    fclose(fp);
}

void random_shuffle(Sample *samples, int size) {
    for (int i = 0; i < size - 1; i++) {
        int j = i + rand() % (size - i);
        Sample temp = samples[j];
        samples[j] = samples[i];
        samples[i] = temp;
    }
}

float sigmoid(float x) {
    return 1 / (1 + expf(-x));
}

float sigmoid_derivative(float x) {
    float s = sigmoid(x);
    return s * (1 - s);
}