//FormAI DATASET v1.0 Category: Image Classification system ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_CLASSES 10
#define IMAGE_SIZE 784
#define LEARNING_RATE 0.1
#define EPOCHS 10
#define BATCH_SIZE 100

float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

void forward(float *x, float *w, float *b, float *y) {
    for (int i = 0; i < NUM_CLASSES; i++) {
        y[i] = 0;
        for (int j = 0; j < IMAGE_SIZE; j++) {
            y[i] += x[j] * w[i * IMAGE_SIZE + j];
        }
        y[i] += b[i];
        y[i] = sigmoid(y[i]);
    }
}

void backward(float *x, float *y, float *t, float *w_grad, float *b_grad) {
    for (int i = 0; i < NUM_CLASSES; i++) {
        float d_err = y[i] - t[i];
        float d_sig = y[i] * (1 - y[i]);
        b_grad[i] = d_err * d_sig;
        for (int j = 0; j < IMAGE_SIZE; j++) {
            w_grad[i * IMAGE_SIZE + j] = d_err * d_sig * x[j];
        }
    }
}

void update(float *w, float *b, float *w_grad, float *b_grad) {
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            w[i * IMAGE_SIZE + j] -= LEARNING_RATE * w_grad[i * IMAGE_SIZE + j];
        }
        b[i] -= LEARNING_RATE * b_grad[i];
    }
}

void train(float *x_train, int *y_train, float *w, float *b, int num_samples) {
    float x[IMAGE_SIZE];
    float y[NUM_CLASSES];
    float t[NUM_CLASSES];
    float w_grad[NUM_CLASSES * IMAGE_SIZE];
    float b_grad[NUM_CLASSES];
    int index;

    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        printf("Epoch %d\n", epoch + 1);
        for (int i = 0; i < num_samples; i += BATCH_SIZE) {
            memset(w_grad, 0, sizeof(w_grad));
            memset(b_grad, 0, sizeof(b_grad));

            for (int j = 0; j < BATCH_SIZE; j++) {
                index = i + j;
                if (index >= num_samples) {
                    break;
                }

                memcpy(x, x_train + index * IMAGE_SIZE, sizeof(float) * IMAGE_SIZE);

                for (int k = 0; k < NUM_CLASSES; k++) {
                    if (k == y_train[index]) {
                        t[k] = 1.0;
                    } else {
                        t[k] = 0.0;
                    }
                }

                forward(x, w, b, y);
                backward(x, y, t, w_grad, b_grad);
            }

            update(w, b, w_grad, b_grad);
        }
    }

    printf("Training complete!\n\n");
}

int predict(float *x, float *w, float *b) {
    float y[NUM_CLASSES];
    forward(x, w, b, y);
    int max_index = 0;
    for (int i = 1; i < NUM_CLASSES; i++) {
        if (y[i] > y[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

void test(float *x_test, int *y_test, float *w, float *b, int num_samples) {
    int correct = 0;
    int predicted;
    float x[IMAGE_SIZE];

    for (int i = 0; i < num_samples; i++) {
        memcpy(x, x_test + i * IMAGE_SIZE, sizeof(float) * IMAGE_SIZE);
        predicted = predict(x, w, b);
        if (predicted == y_test[i]) {
            correct += 1;
        }
    }

    printf("Test accuracy: %.2f%%\n\n", (float)correct / (float)num_samples * 100);
}

int main() {
    // Load data
    FILE *f;
    float *x_train = malloc(sizeof(float) * 60000 * IMAGE_SIZE);
    float *x_test = malloc(sizeof(float) * 10000 * IMAGE_SIZE);
    int *y_train = malloc(sizeof(int) * 60000);
    int *y_test = malloc(sizeof(int) * 10000);

    f = fopen("mnist_train_images.bin", "rb");
    fread(x_train, sizeof(float), 60000 * IMAGE_SIZE, f);
    fclose(f);

    f = fopen("mnist_test_images.bin", "rb");
    fread(x_test, sizeof(float), 10000 * IMAGE_SIZE, f);
    fclose(f);

    f = fopen("mnist_train_labels.bin", "rb");
    fread(y_train, sizeof(int), 60000, f);
    fclose(f);

    f = fopen("mnist_test_labels.bin", "rb");
    fread(y_test, sizeof(int), 10000, f);
    fclose(f);

    // Initialize weights and biases
    float *w = malloc(sizeof(float) * NUM_CLASSES * IMAGE_SIZE);
    float *b = malloc(sizeof(float) * NUM_CLASSES);
    for (int i = 0; i < NUM_CLASSES * IMAGE_SIZE; i++) {
        w[i] = ((float)rand()/(float)(RAND_MAX)) * 2 - 1;
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        b[i] = ((float)rand()/(float)(RAND_MAX)) * 2 - 1;
    }

    // Train and test classifier
    train(x_train, y_train, w, b, 60000);
    test(x_test, y_test, w, b, 10000);

    free(x_train);
    free(x_test);
    free(y_train);
    free(y_test);
    free(w);
    free(b);

    return 0;
}