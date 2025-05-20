//FormAI DATASET v1.0 Category: Image Classification system ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// define the number of classes and images for our classification system
#define NUM_CLASSES 5
#define NUM_IMAGES 20

// define the structure for storing an image
typedef struct {
    int pixels[28][28];
    int label;
} Image;

// define the structure for storing the weights and biases of our neural network
typedef struct {
    float weights[28*28][NUM_CLASSES];
    float biases[NUM_CLASSES];
} Model;

// function to load images and labels from files
void load_data(char *filename_images, char *filename_labels, Image images[]) {
    // open image file
    FILE *file_images = fopen(filename_images, "rb");
    if (!file_images) {
        perror("Error opening image file");
        exit(1);
    }

    // open label file
    FILE *file_labels = fopen(filename_labels, "rb");
    if (!file_labels) {
        perror("Error opening label file");
        exit(1);
    }

    // read header information
    unsigned char buffer[16];
    fread(buffer, sizeof(char), 16, file_images);

    // read images and labels
    for (int i = 0; i < NUM_IMAGES; i++) {
        // read image pixels
        int pixel;
        for (int j = 0; j < 28*28; j++) {
            fread(&pixel, sizeof(char), 1, file_images);
            images[i].pixels[j/28][j%28] = pixel;
        }

        // read label
        fread(&images[i].label, sizeof(char), 1, file_labels);
    }

    // close files
    fclose(file_images);
    fclose(file_labels);
}

// function to initialize model weights and biases
void init_model(Model *model) {
    // initialize weights
    for (int i = 0; i < 28*28; i++) {
        for (int j = 0; j < NUM_CLASSES; j++) {
            model->weights[i][j] = ((float)rand()/(float)RAND_MAX) * 2.0 - 1.0;
        }
    }

    // initialize biases
    for (int i = 0; i < NUM_CLASSES; i++) {
        model->biases[i] = ((float)rand()/(float)RAND_MAX) * 2.0 - 1.0;
    }
}

// function to compute the output of the neural network for a single image
float* forward_pass(Image image, Model model) {
    // allocate memory for output
    float *output = (float*)malloc(sizeof(float) * NUM_CLASSES);

    // compute dot product of image pixels and weights for each class
    for (int i = 0; i < NUM_CLASSES; i++) {
        float dot_product = 0.0;
        for (int j = 0; j < 28*28; j++) {
            dot_product += (float)image.pixels[j/28][j%28] * model.weights[j][i];
        }
        output[i] = dot_product + model.biases[i];
    }

    return output;
}

// function to compute the cross-entropy loss for a single image
float loss(Image image, Model model) {
    float *output = forward_pass(image, model);
    float loss = 0.0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (i == image.label) {
            loss -= log(output[i]);
        } else {
            loss -= log(1.0 - output[i]);
        }
    }
    free(output);
    return loss;
}

// function to compute the accuracy of the model on a set of images
float accuracy(Image images[], Model model) {
    int num_correct = 0;
    for (int i = 0; i < NUM_IMAGES; i++) {
        float *output = forward_pass(images[i], model);
        int predicted_label = 0;
        float max_output = output[0];
        for (int j = 1; j < NUM_CLASSES; j++) {
            if (output[j] > max_output) {
                predicted_label = j;
                max_output = output[j];
            }
        }
        free(output);
        if (predicted_label == images[i].label) {
            num_correct++;
        }
    }
    return (float)num_correct / (float)NUM_IMAGES;
}

// function to train the model using backpropagation and stochastic gradient descent
void train_model(Image images[], Model *model, float learning_rate, int num_epochs) {
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        for (int i = 0; i < NUM_IMAGES; i++) {
            // compute gradients for weights and biases
            float *output = forward_pass(images[i], *model);
            float dLdoutput[NUM_CLASSES] = {0.0};
            if (images[i].label == 0) {
                dLdoutput[0] = -1.0 / output[0];
            } else {
                dLdoutput[0] = 1.0 / (1.0 - output[0]);
            }
            for (int j = 1; j < NUM_CLASSES; j++) {
                if (j == images[i].label) {
                    dLdoutput[j] = 1.0 / output[j];
                } else {
                    dLdoutput[j] = -1.0 / (1.0 - output[j]);
                }
            }
            float doutputdinput[NUM_CLASSES][28*28] = {0.0};
            for (int j = 0; j < NUM_CLASSES; j++) {
                for (int k = 0; k < 28*28; k++) {
                    doutputdinput[j][k] = images[i].pixels[k/28][k%28];
                }
            }
            float gradients_weights[28*28][NUM_CLASSES] = {0.0};
            float gradients_biases[NUM_CLASSES] = {0.0};
            for (int j = 0; j < NUM_CLASSES; j++) {
                for (int k = 0; k < 28*28; k++) {
                    gradients_weights[k][j] = dLdoutput[j] * doutputdinput[j][k];
                }
                gradients_biases[j] = dLdoutput[j];
            }
            free(output);

            // update weights and biases using gradients and learning rate
            for (int j = 0; j < 28*28; j++) {
                for (int k = 0; k < NUM_CLASSES; k++) {
                    model->weights[j][k] -= learning_rate * gradients_weights[j][k];
                }
            }
            for (int j = 0; j < NUM_CLASSES; j++) {
                model->biases[j] -= learning_rate * gradients_biases[j];
            }
        }
    }
}

int main() {
    // load training data
    Image training_images[NUM_IMAGES];
    load_data("train-images.idx3-ubyte", "train-labels.idx1-ubyte", training_images);

    // initialize model
    Model model;
    init_model(&model);

    // train model
    train_model(training_images, &model, 0.01, 10);

    // load test data
    Image test_images[NUM_IMAGES];
    load_data("t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte", test_images);

    // compute accuracy on test data
    float acc = accuracy(test_images, model);
    printf("Accuracy: %f\n", acc);

    return 0;
}