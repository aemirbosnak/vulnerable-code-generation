//FormAI DATASET v1.0 Category: Image Classification system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* This program demonstrates an image classification system using support vector machines (SVM) */
/* The program uses a linear kernel and hinge loss function for training the SVM */

#define IMAGE_SIZE 100 // size of the input image (assume square image)
#define NUM_CLASSES 3 // number of classes to classify images into
#define NUM_TRAINING_IMAGES 500 // number of training images per class
#define NUM_TEST_IMAGES 100 // number of test images per class
#define NUM_FEATURES (IMAGE_SIZE * IMAGE_SIZE) // number of features (assume one feature per pixel)

/* Define struct to hold image data */
typedef struct Image {
    float* data; // array of pixel values
    int label; // image label
} Image;

/* Define struct to hold SVM model parameters */
typedef struct SVM {
    float* weights; // array of SVM weights
    float bias; // SVM bias term
    float c_param; // regularization parameter
} SVM;

/* Function to generate an image with random pixel values and label */
Image generate_image(int label) {
    Image image;
    image.data = (float*) malloc(NUM_FEATURES * sizeof(float));
    image.label = label;
    for (int i = 0; i < NUM_FEATURES; i++) {
        image.data[i] = ((float) rand() / RAND_MAX);
    }
    return image;
}

/* Function to calculate dot product of two vectors */
float vector_dot_product(float* x, float* y, int n) {
    float result = 0.0;
    for (int i = 0; i < n; i++) {
        result += x[i] * y[i];
    }
    return result;
}

/* Function to calculate hinge loss for SVM */
float hinge_loss(float x) {
    if (x > 1.0) {
        return 0.0;
    } else {
        return 1.0 - x;
    }
}

/* Function to train SVM model on a set of images */
void train_svm(Image* images, int num_images, SVM* svm) {
    /* Initialize weights and bias */
    svm->weights = (float*) malloc(NUM_FEATURES * sizeof(float));
    for (int i = 0; i < NUM_FEATURES; i++) {
        svm->weights[i] = 0.0;
    }
    svm->bias = 0.0;

    /* Define optimization parameters */
    float learning_rate = 0.1;
    int max_epochs = 100;

    /* Train SVM using gradient descent */
    for (int epoch = 0; epoch < max_epochs; epoch++) {
        printf("Epoch %d\n", epoch);
        float loss = 0.0;
        for (int i = 0; i < num_images; i++) {
            /* Calculate SVM output and gradient for current image */
            float y = vector_dot_product(svm->weights, images[i].data, NUM_FEATURES) + svm->bias;
            float gradient = 0.0;
            if (images[i].label == 1) {
                gradient = hinge_loss(1.0 - y);
                loss += hinge_loss(1.0 - y);
            } else {
                gradient = hinge_loss(y + 1.0);
                loss += hinge_loss(y + 1.0);
            }
            /* Update weights and bias */
            for (int j = 0; j < NUM_FEATURES; j++) {
                svm->weights[j] += learning_rate * (images[i].data[j] * gradient - svm->c_param * svm->weights[j]);
            }
            svm->bias += learning_rate * gradient;
        }
        printf("Average loss: %f\n", loss / num_images);
    }
}

/* Function to classify a single image using an SVM model */
int classify_image(Image image, SVM svm) {
    float y = vector_dot_product(svm.weights, image.data, NUM_FEATURES) + svm.bias;
    if (y > 0.0) {
        return 1;
    } else {
        return -1;
    }
}

/* Function to test SVM model on a set of images */
void test_svm(Image* images, int num_images, SVM svm) {
    int num_correct = 0;
    for (int i = 0; i < num_images; i++) {
        int prediction = classify_image(images[i], svm);
        if (prediction == images[i].label) {
            num_correct++;
        }
    }
    printf("Accuracy: %.2f%%\n", ((float) num_correct / num_images) * 100.0);
}

int main() {
    /* Generate training and test images */
    Image training_images[NUM_CLASSES * NUM_TRAINING_IMAGES];
    Image test_images[NUM_CLASSES * NUM_TEST_IMAGES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_TRAINING_IMAGES; j++) {
            training_images[i * NUM_TRAINING_IMAGES + j] = generate_image(i + 1);
        }
        for (int j = 0; j < NUM_TEST_IMAGES; j++) {
            test_images[i * NUM_TEST_IMAGES + j] = generate_image(i + 1);
        }
    }

    /* Train and test SVM model */
    SVM svm;
    svm.c_param = 0.1;
    train_svm(training_images, NUM_CLASSES * NUM_TRAINING_IMAGES, &svm);
    test_svm(test_images, NUM_CLASSES * NUM_TEST_IMAGES, svm);

    /* Free memory */
    free(svm.weights);
    for (int i = 0; i < NUM_CLASSES * NUM_TRAINING_IMAGES; i++) {
        free(training_images[i].data);
    }
    for (int i = 0; i < NUM_CLASSES * NUM_TEST_IMAGES; i++) {
        free(test_images[i].data);
    }

    return 0;
}