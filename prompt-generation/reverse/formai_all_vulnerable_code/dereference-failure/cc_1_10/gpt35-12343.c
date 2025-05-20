//FormAI DATASET v1.0 Category: Image Classification system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_IMAGES 1000
#define IMAGE_SIZE 28*28
#define NUM_CLASSES 10

// Function to read the MNIST dataset
void read_mnist_dataset(char* filename, float* dataset, float* labels) {

    // Open the file
    FILE* fp = fopen(filename, "rb");

    // Check if the file was opened successfully
    if(!fp) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read the magic number
    int magic_number;
    fread(&magic_number, sizeof(int), 1, fp);

    // Read the number of images
    int num_images;
    fread(&num_images, sizeof(int), 1, fp);

    // Read the number of rows and columns
    int num_rows, num_cols;
    fread(&num_rows, sizeof(int), 1, fp);
    fread(&num_cols, sizeof(int), 1, fp);

    // Loop through all the images
    for(int i=0; i<num_images; i++) {

        // Read the label
        fread(&labels[i], sizeof(float), 1, fp);

        // Read the image pixels
        for(int j=0; j<IMAGE_SIZE; j++) {
            unsigned char pixel;
            fread(&pixel, sizeof(unsigned char), 1, fp);
            dataset[i*IMAGE_SIZE+j] = (float)pixel / 255.0;
        }
    }

    // Close the file
    fclose(fp);
}

// Function to generate the weight matrix
float* generate_weight_matrix(int num_classes, int num_features) {

    // Allocate memory for the weight matrix
    float* weights = (float*)malloc(num_classes*num_features*sizeof(float));

    // Initialize the weights to random values
    for(int i=0; i<num_classes*num_features; i++) {
        weights[i] = ((float)rand()/(float)RAND_MAX)*0.01;
    }

    return weights;
}

// Function to perform the matrix multiplication
void matrix_multiply(float* a, float* b, float* c, int m, int n, int p) {

    for(int i=0; i<m; i++) {
        for(int j=0; j<p; j++) {
            float sum = 0;
            for(int k=0; k<n; k++) {
                sum += a[i*n+k]*b[k*p+j];
            }
            c[i*p+j] = sum;
        }
    }
}

// Function to perform the forward propagation
void forward_propagation(float* dataset, float* weights, float* output, int num_images) {

    // Perform the matrix multiplication
    matrix_multiply(dataset, weights, output, num_images, IMAGE_SIZE, NUM_CLASSES);

    // Apply the softmax activation function
    for(int i=0; i<num_images; i++) {
        float max_val = output[i*NUM_CLASSES];
        for(int j=0; j<NUM_CLASSES; j++) {
            output[i*NUM_CLASSES+j] = exp(output[i*NUM_CLASSES+j] - max_val);
        }

        float sum = 0;
        for(int j=0; j<NUM_CLASSES; j++) {
            sum += output[i*NUM_CLASSES+j];
        }

        for(int j=0; j<NUM_CLASSES; j++) {
            output[i*NUM_CLASSES+j] /= sum;
        }
    }
}

// Function to perform the backpropagation
void backpropagation(float* dataset, float* labels, float* output, float* weights, int num_images, float learning_rate) {

    // Compute the error gradients
    for(int i=0; i<num_images; i++) {
        for(int j=0; j<NUM_CLASSES; j++) {
            output[i*NUM_CLASSES+j] -= (j == (int)labels[i]) ? 1.0 : 0.0;
        }
    }

    // Compute the weight gradients
    float* grad = (float*)malloc(NUM_CLASSES*IMAGE_SIZE*sizeof(float));
    matrix_multiply(dataset, output, grad, IMAGE_SIZE, num_images, NUM_CLASSES);

    // Update the weights
    for(int i=0; i<NUM_CLASSES*IMAGE_SIZE; i++) {
        weights[i] -= learning_rate*grad[i];
    }

    // Free the memory
    free(grad);
}

// Main function
int main() {

    // Allocate memory for the dataset and labels
    float* dataset = (float*)malloc(NUM_IMAGES*IMAGE_SIZE*sizeof(float));
    float* labels = (float*)malloc(NUM_IMAGES*sizeof(float));

    // Read the MNIST training dataset
    read_mnist_dataset("mnist_train.dat", dataset, labels);

    // Generate the weight matrix
    float* weights = generate_weight_matrix(NUM_CLASSES, IMAGE_SIZE);

    // Allocate memory for the output array
    float* output = (float*)malloc(NUM_IMAGES*NUM_CLASSES*sizeof(float));

    // Set the learning rate
    float learning_rate = 0.1;

    // Train the model
    for(int epoch=0; epoch<10; epoch++) {

        // Perform forward propagation
        forward_propagation(dataset, weights, output, NUM_IMAGES);

        // Perform backpropagation
        backpropagation(dataset, labels, output, weights, NUM_IMAGES, learning_rate);

        // Compute the accuracy
        int num_correct = 0;
        for(int i=0; i<NUM_IMAGES; i++) {
            float max_val = output[i*NUM_CLASSES];
            int max_idx = 0;
            for(int j=0; j<NUM_CLASSES; j++) {
                if(output[i*NUM_CLASSES+j] > max_val) {
                    max_val = output[i*NUM_CLASSES+j];
                    max_idx = j;
                }
            }

            if(max_idx == (int)labels[i]) {
                num_correct++;
            }
        }

        float accuracy = (float)num_correct / (float)NUM_IMAGES;
        printf("Epoch %d: Accuracy = %f\n", epoch+1, accuracy);
    }

    // Free the memory
    free(dataset);
    free(labels);
    free(weights);
    free(output);

    return 0;
}