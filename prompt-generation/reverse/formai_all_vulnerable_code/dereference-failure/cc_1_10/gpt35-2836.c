//FormAI DATASET v1.0 Category: Image Classification system ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Function to read image data from file
int* readImageData(char *filename, int size) {
    int *imageData = (int *) malloc(size * sizeof(int)); // Allocate memory for image data
    FILE *file = fopen(filename, "r"); // Open image data file
    
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    int i;
    for (i = 0; i < size; i++) {
        fscanf(file, "%d", &imageData[i]); // Read image data from file
    }
    
    fclose(file); // Close file
    return imageData; // Return image data
}

// Function to classify image based on histogram of pixel intensities
int classifyImage(int *imageData, int size) {
    int i, histogram[256] = {0}; // Initialize histogram to all zeroes
    
    // Calculate histogram of pixel intensities
    for (i = 0; i < size; i++) {
        histogram[imageData[i]]++;
    }
    
    // Determine class based on histogram
    if (histogram[0] > size / 2) {
        return 0; // Class 0
    } else if (histogram[255] > size / 2) {
        return 1; // Class 1
    } else {
        return 2; // Class 2
    }
}

int main() {
    int size = 10000; // Size of image data
    char filename[] = "image_data.txt";
    int *imageData = readImageData(filename, size); // Read image data from file
    int class = classifyImage(imageData, size); // Classify image
    
    printf("Image classified as class %d\n", class); // Print classification result
    
    free(imageData); // Free allocated memory for image data
    return 0;
}