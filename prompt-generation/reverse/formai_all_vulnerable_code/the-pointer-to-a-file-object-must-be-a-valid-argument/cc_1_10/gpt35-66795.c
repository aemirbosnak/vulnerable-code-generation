//FormAI DATASET v1.0 Category: Image Classification system ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_SIZE 784
#define NUM_CLASSES 10
#define HIDDEN_SIZE 128
#define LEARNING_RATE 0.1

// Activation function
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// Gradient of the activation function
double sigmoid_derivative(double x) {
    return x * (1 - x);
}

// Generate random number between -1 and 1
double random_weight() {
    return ((double)rand() / RAND_MAX) * 2 - 1;
}

// Initialize weights with random values
void initialize_weights(double weights[HIDDEN_SIZE][INPUT_SIZE + 1]) {
    for(int i = 0; i < HIDDEN_SIZE; i++) {
        for(int j = 0; j < INPUT_SIZE + 1; j++) {
            weights[i][j] = random_weight();
        }
    }
}

// Forward propagation step
void forward_propagation(double input[INPUT_SIZE], double hidden[HIDDEN_SIZE], double output[NUM_CLASSES], double weights[HIDDEN_SIZE][INPUT_SIZE + 1]) {
    // Calculate hidden layer
    for(int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = weights[i][INPUT_SIZE];
        for(int j = 0; j < INPUT_SIZE; j++) {
            sum += input[j] * weights[i][j];
        }
        hidden[i] = sigmoid(sum);
    }
    
    // Calculate output layer
    for(int i = 0; i < NUM_CLASSES; i++) {
        double sum = weights[HIDDEN_SIZE - 1][INPUT_SIZE];
        for(int j = 0; j < HIDDEN_SIZE; j++) {
            sum += hidden[j] * weights[HIDDEN_SIZE - 1][j];
        }
        output[i] = sigmoid(sum);
    }
}

// Back propagation step
void back_propagation(double input[INPUT_SIZE], int label, double hidden[HIDDEN_SIZE], double output[NUM_CLASSES], double weights[HIDDEN_SIZE][INPUT_SIZE + 1]) {
    // Calculate error in the output layer
    double output_error[NUM_CLASSES];
    for(int i = 0; i < NUM_CLASSES; i++) {
        if(i == label) {
            output_error[i] = output[i] - 1;
        } else {
            output_error[i] = output[i];
        }
    }
    
    // Calculate error in the hidden layer
    double hidden_error[HIDDEN_SIZE];
    for(int i = 0; i < HIDDEN_SIZE; i++) {
        double error = 0;
        for(int j = 0; j < NUM_CLASSES; j++) {
            error += output_error[j] * weights[HIDDEN_SIZE - 1][i];
        }
        hidden_error[i] = error * sigmoid_derivative(hidden[i]);
    }
    
    // Update weights connecting hidden layer with output layer
    for(int i = 0; i < NUM_CLASSES; i++) {
        for(int j = 0; j < HIDDEN_SIZE; j++) {
            weights[HIDDEN_SIZE - 1][j] -= LEARNING_RATE * output_error[i] * hidden[j];
        }
        weights[HIDDEN_SIZE - 1][INPUT_SIZE] -= LEARNING_RATE * output_error[i];
    }
    
    // Update weights connecting input layer with hidden layer
    for(int i = 0; i < HIDDEN_SIZE; i++) {
        for(int j = 0; j < INPUT_SIZE; j++) {
            weights[i][j] -= LEARNING_RATE * hidden_error[i] * input[j];
        }
        weights[i][INPUT_SIZE] -= LEARNING_RATE * hidden_error[i];
    }
}

// Predict label for given input example
int predict(double input[INPUT_SIZE], double weights[HIDDEN_SIZE][INPUT_SIZE + 1]) {
    double hidden[HIDDEN_SIZE];
    double output[NUM_CLASSES];
    forward_propagation(input, hidden, output, weights);
    
    int max_index = 0;
    double max_value = output[0];
    for(int i = 1; i < NUM_CLASSES; i++) {
        if(output[i] > max_value) {
            max_index = i;
            max_value = output[i];
        }
    }
    
    return max_index;
}

// Train the neural network with the given dataset
void train(double dataset[][INPUT_SIZE + 1], int labels[], int num_examples, int num_epochs, double weights[HIDDEN_SIZE][INPUT_SIZE + 1]) {
    for(int epoch = 0; epoch < num_epochs; epoch++) {
        double total_loss = 0;
        for(int example = 0; example < num_examples; example++) {
            double input[INPUT_SIZE];
            for(int i = 0; i < INPUT_SIZE; i++) {
                input[i] = dataset[example][i];
            }
            int label = labels[example];
            
            double hidden[HIDDEN_SIZE];
            double output[NUM_CLASSES];
            forward_propagation(input, hidden, output, weights);
            
            double example_loss = 0;
            for(int i = 0; i < NUM_CLASSES; i++) {
                if(i == label) {
                    example_loss += pow(output[i] - 1, 2);
                } else {
                    example_loss += pow(output[i], 2);
                }
            }
            
            total_loss += example_loss;
            
            back_propagation(input, label, hidden, output, weights);
        }
        printf("Epoch %d: Loss = %.4f\n", epoch + 1, total_loss / num_examples);
    }
}

int main() {
    // Download MNIST dataset in CSV format and store it in a 60000 x 785 double array
    // The first column contains the label and the rest of the columns contain the pixel values
    double dataset_train[60000][INPUT_SIZE + 1];
    FILE* fp_train = fopen("mnist_train.csv", "r");
    char line[10000];
    int num_examples_train = 0;
    while(fgets(line, sizeof(line), fp_train)) {
        char* token = strtok(line, ",");
        int label = atoi(token);
        dataset_train[num_examples_train][0] = label;
        for(int i = 1; i < INPUT_SIZE + 1; i++) {
            token = strtok(NULL, ",");
            double value = atof(token);
            dataset_train[num_examples_train][i] = value;
        }
        num_examples_train++;
    }
    fclose(fp_train);
    
    // Split the dataset into training and validation sets (80% and 20% respectively)
    int num_examples_train_80 = (int)(num_examples_train * 0.8);
    double dataset_train_80[num_examples_train_80][INPUT_SIZE + 1];
    double dataset_val[num_examples_train - num_examples_train_80][INPUT_SIZE + 1];
    int labels_train_80[num_examples_train_80];
    int labels_val[num_examples_train - num_examples_train_80];
    for(int i = 0; i < num_examples_train_80; i++) {
        for(int j = 0; j < INPUT_SIZE + 1; j++) {
            dataset_train_80[i][j] = dataset_train[i][j];
        }
        labels_train_80[i] = (int)dataset_train[i][0];
    }
    for(int i = num_examples_train_80; i < num_examples_train; i++) {
        for(int j = 0; j < INPUT_SIZE + 1; j++) {
            dataset_val[i - num_examples_train_80][j] = dataset_train[i][j];
        }
        labels_val[i - num_examples_train_80] = (int)dataset_train[i][0];
    }
    
    // Initialize weights
    double weights[HIDDEN_SIZE][INPUT_SIZE + 1];
    initialize_weights(weights);
    
    // Train the neural network
    int num_epochs = 10;
    train(dataset_train_80, labels_train_80, num_examples_train_80, num_epochs, weights);
    
    // Evaluate the model on the validation set
    int num_examples_val = num_examples_train - num_examples_train_80;
    int num_correct = 0;
    for(int example = 0; example < num_examples_val; example++) {
        double input[INPUT_SIZE];
        for(int i = 0; i < INPUT_SIZE; i++) {
            input[i] = dataset_val[example][i + 1] / 255;
        }
        int label = labels_val[example];
        
        int prediction = predict(input, weights);
        if(prediction == label) {
            num_correct++;
        }
    }
    printf("Accuracy on validation set: %.2f%%\n", (double)num_correct / num_examples_val * 100);
    
    return 0;
}