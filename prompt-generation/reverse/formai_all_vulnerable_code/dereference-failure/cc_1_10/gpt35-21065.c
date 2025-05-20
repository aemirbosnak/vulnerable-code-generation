//FormAI DATASET v1.0 Category: Image Classification system ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for the image dimensions and number of classes
#define NUM_ROWS 28
#define NUM_COLS 28
#define NUM_CLASSES 10

// Define a structure for the image data
typedef struct {
    int label;
    double pixels[NUM_ROWS * NUM_COLS];
} IMAGE;

// Define a structure for the neural network weights and biases
typedef struct {
    double w[NUM_CLASSES][NUM_ROWS * NUM_COLS];
    double b[NUM_CLASSES];
} NETWORK;

// Define a sigmoid activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Define a function to load the MNIST image data
int load_mnist_data(const char* filename, IMAGE* images, int num_images) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open file %s\n", filename);
        return 0;
    }
    
    // Read the header information from the file
    int magic_number, num_items, num_rows, num_cols;
    fread(&magic_number, sizeof(int), 1, file);
    fread(&num_items, sizeof(int), 1, file);
    fread(&num_rows, sizeof(int), 1, file);
    fread(&num_cols, sizeof(int), 1, file);
    printf("Loaded MNIST data with dimensions %d x %d x %d\n", num_items, num_rows, num_cols);
    
    // Verify that the image dimensions match the expected values
    if (num_rows != NUM_ROWS || num_cols != NUM_COLS) {
        printf("Invalid image dimensions: %dx%d (expected %dx%d)\n", num_rows, num_cols, NUM_ROWS, NUM_COLS);
        return 0;
    }
    
    // Read the image data from the file
    unsigned char buffer[NUM_ROWS * NUM_COLS];
    for (int i = 0; i < num_images; i++) {
        fread(&buffer, sizeof(unsigned char), NUM_ROWS * NUM_COLS, file);
        images[i].label = buffer[0];
        for (int j = 0; j < NUM_ROWS * NUM_COLS; j++) {
            images[i].pixels[j] = (double) buffer[j+1] / 255.0;
        }
    }
    
    fclose(file);
    return 1;
}

// Define a function to initialize the neural network weights and biases
void init_network(NETWORK* net) {
    // Initialize the weights to random values between -0.5 and 0.5
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_ROWS * NUM_COLS; j++) {
            net->w[i][j] = ((double) rand() / RAND_MAX) - 0.5;
        }
    }
    
    // Initialize the biases to zero
    for (int i = 0; i < NUM_CLASSES; i++) {
        net->b[i] = 0.0;
    }
}

// Define a function to make a prediction using the neural network
int predict(NETWORK* net, double* pixels) {
    // Calculate the weighted sum for each class
    double weighted_sums[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        double sum = 0.0;
        for (int j = 0; j < NUM_ROWS * NUM_COLS; j++) {
            sum += net->w[i][j] * pixels[j];
        }
        weighted_sums[i] = sum + net->b[i];
    }
    
    // Use the softmax function to convert the weighted sums into probabilities
    double probabilities[NUM_CLASSES];
    double sum = 0.0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        probabilities[i] = exp(weighted_sums[i]);
        sum += probabilities[i];
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        probabilities[i] /= sum;
    }
    
    // Return the class with the highest probability
    int predicted_label = 0;
    double max_prob = 0.0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (probabilities[i] > max_prob) {
            predicted_label = i;
            max_prob = probabilities[i];
        }
    }
    return predicted_label;
}

int main() {
    // Load the MNIST image data
    IMAGE train_images[60000];
    int num_train_images = load_mnist_data("train-images-idx3-ubyte", train_images, 60000);
    IMAGE test_images[10000];
    int num_test_images = load_mnist_data("t10k-images-idx3-ubyte", test_images, 10000);
    if (!num_train_images || !num_test_images) {
        return 1;
    }
    
    // Initialize the neural network
    NETWORK net;
    init_network(&net);
    
    // Train the neural network using stochastic gradient descent
    int num_epochs = 10;
    int batch_size = 100;
    int num_batches = num_train_images / batch_size;
    double learning_rate = 0.1;
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        printf("Training epoch %d...\n", epoch+1);
        for (int batch = 0; batch < num_batches; batch++) {
            // Pick a random batch of images and labels
            int start_index = batch * batch_size;
            IMAGE batch_images[batch_size];
            for (int i = 0; i < batch_size; i++) {
                int index = start_index + i;
                batch_images[i] = train_images[index];
            }
            
            // Initialize the gradient values for the weights and biases
            double gradient_w[NUM_CLASSES][NUM_ROWS * NUM_COLS];
            double gradient_b[NUM_CLASSES];
            for (int i = 0; i < NUM_CLASSES; i++) {
                for (int j = 0; j < NUM_ROWS * NUM_COLS; j++) {
                    gradient_w[i][j] = 0.0;
                }
                gradient_b[i] = 0.0;
            }
            
            // Compute the gradient for each image in the batch
            for (int i = 0; i < batch_size; i++) {
                IMAGE image = batch_images[i];
                double pixels[NUM_ROWS * NUM_COLS];
                for (int j = 0; j < NUM_ROWS * NUM_COLS; j++) {
                    pixels[j] = image.pixels[j];
                }
                int label = image.label;
                
                // Compute the predicted probabilities
                double weighted_sums[NUM_CLASSES];
                double probabilities[NUM_CLASSES];
                double sum = 0.0;
                for (int i = 0; i < NUM_CLASSES; i++) {
                    double w_sum = 0.0;
                    for (int j = 0; j < NUM_ROWS * NUM_COLS; j++) {
                        w_sum += net.w[i][j] * pixels[j];
                    }
                    weighted_sums[i] = w_sum + net.b[i];
                    probabilities[i] = sigmoid(weighted_sums[i]);
                    sum += probabilities[i];
                }
                
                // Compute the gradient of the loss function with respect to the weighted sums
                double dL_dSums[NUM_CLASSES];
                for (int i = 0; i < NUM_CLASSES; i++) {
                    if (i == label) {
                        dL_dSums[i] = probabilities[i] - 1.0;
                    } else {
                        dL_dSums[i] = probabilities[i];
                    }
                }
                
                // Compute the gradient of the loss function with respect to the weights and biases
                for (int i = 0; i < NUM_CLASSES; i++) {
                    for (int j = 0; j < NUM_ROWS * NUM_COLS; j++) {
                        gradient_w[i][j] += dL_dSums[i] * pixels[j];
                    }
                    gradient_b[i] += dL_dSums[i];
                }
            }
            
            // Update the weights and biases based on the computed gradients
            for (int i = 0; i < NUM_CLASSES; i++) {
                for (int j = 0; j < NUM_ROWS * NUM_COLS; j++) {
                    net.w[i][j] -= (learning_rate / batch_size) * gradient_w[i][j];
                }
                net.b[i] -= (learning_rate / batch_size) * gradient_b[i];
            }
        }
        
        // Evaluate the performance of the neural network on the test data
        int num_correct = 0;
        for (int i = 0; i < num_test_images; i++) {
            IMAGE image = test_images[i];
            double pixels[NUM_ROWS * NUM_COLS];
            for (int j = 0; j < NUM_ROWS * NUM_COLS; j++) {
                pixels[j] = image.pixels[j];
            }
            int label = predict(&net, pixels);
            if (label == image.label) {
                num_correct++;
            }
        }
        double accuracy = (double) num_correct / num_test_images;
        printf("Test accuracy after epoch %d: %.2f%%\n", epoch+1, accuracy * 100.0);
    }
    
    return 0;
}