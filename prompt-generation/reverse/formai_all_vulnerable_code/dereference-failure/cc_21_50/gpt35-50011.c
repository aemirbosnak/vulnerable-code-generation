//FormAI DATASET v1.0 Category: Image Classification system ; Style: shocked
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    int images[100][784]; 
    int labels[100];
    int test_images[20][784];
    int test_labels[20]; 
    int num_of_images = 100;
    int num_of_test_images = 20;
    int num_of_pixels = 784;
    
    // Reading data from files
    FILE *fp1, *fp2, *fp3, *fp4;
    fp1 = fopen("training_images.txt", "r"); 
    fp2 = fopen("training_labels.txt", "r"); 
    fp3 = fopen("test_images.txt", "r"); 
    fp4 = fopen("test_labels.txt", "r"); 
    
    if (fp1 == NULL || fp2 == NULL || fp3 == NULL || fp4 == NULL){
        printf("Error opening the files!\n");
        exit(1);
    }
    
    // Storing the data in arrays
    for(int i=0; i<num_of_images; i++) {
        for(int j=0; j<num_of_pixels; j++) {
            fscanf(fp1, "%d", &images[i][j]); 
        }
        fscanf(fp2, "%d", &labels[i]); 
    }
    
    for(int i=0; i<num_of_test_images; i++) {
        for(int j=0; j<num_of_pixels; j++) {
            fscanf(fp3, "%d", &test_images[i][j]); 
        }
        fscanf(fp4, "%d", &test_labels[i]); 
    }
    
    // Closing the files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    
    // Initializing the weights and biases randomly
    double weights[10][784];
    double biases[10];
    srand(time(NULL));
    
    for(int i=0; i<10; i++) {
        biases[i] = ((double)rand()/(double)RAND_MAX) * 2 - 1;
        for(int j=0; j<784; j++) {
            weights[i][j] = ((double)rand()/(double)RAND_MAX) * 2 - 1;
        }
    }
    
    // Training the model
    int epochs = 50;
    double learning_rate = 0.01;
    
    for(int e=0; e<epochs; e++) {
        for(int i=0; i<num_of_images; i++) {
            double activations[10];
            double outputs[10];
            
            for(int j=0; j<10; j++) {
                activations[j] = biases[j];
                for(int k=0; k<784; k++) {
                    activations[j] += images[i][k] * weights[j][k];
                }
                outputs[j] = 1.0 / (1.0 + exp(-activations[j])); // sigmoid activation function
            }
            
            int target_label = labels[i];
            double target_output[10];
            for(int j=0; j<10; j++) {
                if(j == target_label) {
                    target_output[j] = 1;
                } else {
                    target_output[j] = 0;
                }
            }
            
            double errors[10];
            for(int j=0; j<10; j++) {
                errors[j] = (outputs[j] - target_output[j]) * (outputs[j] * (1 - outputs[j]));
                biases[j] -= learning_rate * errors[j];
                for(int k=0; k<784; k++) {
                    weights[j][k] -= learning_rate * errors[j] * images[i][k];
                }
            }
        }
        
        // Evaluating the model
        int correct_predictions = 0;
        for(int i=0; i<num_of_test_images; i++) {
            double activations[10];
            double outputs[10];
            
            for(int j=0; j<10; j++) {
                activations[j] = biases[j];
                for(int k=0; k<784; k++) {
                    activations[j] += test_images[i][k] * weights[j][k];
                }
                outputs[j] = 1.0 / (1.0 + exp(-activations[j])); // sigmoid activation function
            }
            
            int predicted_label = 0;
            for(int j=0; j<10; j++) {
                if(outputs[j] > outputs[predicted_label]) {
                    predicted_label = j;
                }
            }
            
            if(predicted_label == test_labels[i]) {
                correct_predictions++;
            }
        }
        printf("Epoch %d, Accuracy: %.2f%%\n", e+1, (double)correct_predictions/num_of_test_images*100);
    }
    
    return 0; 
}