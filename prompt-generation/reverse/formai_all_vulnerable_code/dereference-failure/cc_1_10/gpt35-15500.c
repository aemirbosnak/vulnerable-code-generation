//FormAI DATASET v1.0 Category: Image Classification system ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define IMG_SIZE 784 // 28x28 pixels

typedef struct {
    float* pixels;
    int label;
} Image;

Image* loadImage(FILE* fp) {
    Image* img = malloc(sizeof(Image));
    img->pixels = malloc(sizeof(float) * IMG_SIZE);
    fread(&(img->label), sizeof(int), 1, fp);
    for (int i = 0; i < IMG_SIZE; i++) {
        unsigned char pixel;
        fread(&pixel, sizeof(unsigned char), 1, fp);
        img->pixels[i] = (float)pixel / 255.0; // normalize pixel values to [0, 1]
    }
    return img;
}

float sigmoid(float x) {
    return 1.0 / (1.0 + exp(-x));
}

float dot(float* a, float* b, int len) {
    float sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

void train(int num_epochs, float learning_rate, Image** images, int num_images) {
    // Initialize weights to random values between -1 and 1
    float weights[IMG_SIZE];
    for (int i = 0; i < IMG_SIZE; i++) {
        weights[i] = (float)rand() / RAND_MAX * 2 - 1;
    }

    // Train the model
    for (int e = 0; e < num_epochs; e++) {
        for (int i = 0; i < num_images; i++) {
            Image* img = images[i];
            float input[IMG_SIZE];
            memcpy(input, img->pixels, sizeof(float) * IMG_SIZE);
            float output = sigmoid(dot(input, weights, IMG_SIZE));
            float error = output - img->label; // calculate error
            for (int j = 0; j < IMG_SIZE; j++) {
                weights[j] -= learning_rate * error * input[j]; // update weights
            }
        }
    }

    // Print the final weights
    printf("Final weights:\n");
    for (int i = 0; i < IMG_SIZE; i++) {
        printf("%f\t", weights[i]);
        if (i % 28 == 27) {
            printf("\n");
        }
    }
}

int main(int argc, char** argv) {
    // Load training data
    FILE* training_fp = fopen("mnist_train_images.bin", "rb");
    if (!training_fp) {
        fprintf(stderr, "Failed to open file.\n");
        return 1;
    }
    int num_train_images = 60000;
    Image** train_images = malloc(sizeof(Image*) * num_train_images);
    for (int i = 0; i < num_train_images; i++) {
        train_images[i] = loadImage(training_fp);
    }
    fclose(training_fp);

    // Train the model
    train(10, 0.01, train_images, num_train_images);

    // Free memory
    for (int i = 0; i < num_train_images; i++) {
        free(train_images[i]->pixels);
        free(train_images[i]);
    }
    free(train_images);

    return 0;
}