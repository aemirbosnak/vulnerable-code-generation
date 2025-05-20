//FormAI DATASET v1.0 Category: Image Classification system ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Function to load image and label data
void load_data(char *filename, int *labels, int **images, int num_images, int num_pixels) {
    FILE *fp = fopen(filename, "rb");
    
    if (fp == NULL) {
        printf("Error: Unable to open file!");
        exit(1);
    }
    
    // Read labels from file
    fread(labels, sizeof(int), num_images, fp);
    
    // Read images from file
    for (int i = 0; i < num_images; i++) {
        images[i] = malloc(sizeof(int) * num_pixels);
        fread(images[i], sizeof(int), num_pixels, fp);
    }
    
    fclose(fp);
}

// Function to classify image
int classify_image(int *image, double **weights, int num_classes, int num_features) {
    double max_score = -99999.0;
    int predicted_class = 0;
    
    for (int i = 0; i < num_classes; i++) {
        double score = 0.0;
        
        for (int j = 0; j < num_features; j++) {
            score += image[j] * weights[i][j];
        }
        
        if (score > max_score) {
            max_score = score;
            predicted_class = i;
        }
    }
    
    return predicted_class;
}

// Main function
int main() {
    int num_classes = 10;
    int num_train_images = 50000;
    int num_test_images = 10000;
    int num_pixels = 784;
    int num_epochs = 50;
    double learning_rate = 0.1;
    int batch_size = 100;
    
    // Allocate memory for train and test data
    int *train_labels = malloc(sizeof(int) * num_train_images);
    int **train_images = malloc(sizeof(int *) * num_train_images);
    int *test_labels = malloc(sizeof(int) * num_test_images);
    int **test_images = malloc(sizeof(int *) * num_test_images);
    
    // Load train and test data from file
    load_data("train_data.bin", train_labels, train_images, num_train_images, num_pixels);
    load_data("test_data.bin", test_labels, test_images, num_test_images, num_pixels);
    
    // Allocate memory for weights and gradients
    double **weights = malloc(sizeof(double *) * num_classes);
    double **gradients = malloc(sizeof(double *) * num_classes);
    
    for (int i = 0; i < num_classes; i++) {
        weights[i] = malloc(sizeof(double) * num_pixels);
        gradients[i] = malloc(sizeof(double) * num_pixels);
        
        for (int j = 0; j < num_pixels; j++) {
            weights[i][j] = 0.0;
            gradients[i][j] = 0.0;
        }
    }
    
    // Train model
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        for (int i = 0; i < num_train_images; i += batch_size) {
            // Compute gradients for batch
            for (int j = i; j < i + batch_size && j < num_train_images; j++) {
                int predicted_class = classify_image(train_images[j], weights, num_classes, num_pixels);
                
                for (int k = 0; k < num_pixels; k++) {
                    gradients[predicted_class][k] += train_images[j][k];
                    gradients[train_labels[j]][k] -= train_images[j][k];
                }
            }
            
            // Update weights
            for (int j = 0; j < num_classes; j++) {
                for (int k = 0; k < num_pixels; k++) {
                    weights[j][k] += learning_rate * gradients[j][k];
                    gradients[j][k] = 0.0;
                }
            }
        }
        
        // Evaluate model on test data
        int num_correct = 0;
        
        for (int i = 0; i < num_test_images; i++) {
            int predicted_class = classify_image(test_images[i], weights, num_classes, num_pixels);
            
            if (predicted_class == test_labels[i]) {
                num_correct++;
            }
        }
        
        printf("Epoch %d: Test Accuracy = %.2f%%\n", epoch + 1, (double)num_correct / num_test_images * 100);
    }
    
    // Free memory
    for (int i = 0; i < num_train_images; i++) {
        free(train_images[i]);
    }
    
    for (int i = 0; i < num_test_images; i++) {
        free(test_images[i]);
    }
    
    for (int i = 0; i < num_classes; i++) {
        free(weights[i]);
        free(gradients[i]);
    }
    
    free(train_labels);
    free(train_images);
    free(test_labels);
    free(test_images);
    free(weights);
    free(gradients);
    
    return 0;
}