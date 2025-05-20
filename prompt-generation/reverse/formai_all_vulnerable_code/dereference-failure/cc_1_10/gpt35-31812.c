//FormAI DATASET v1.0 Category: Image Classification system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMG_SIZE 784 // Size of input image
#define NUM_CLASSES 10 // Number of classes/categories

// Structure for holding training data
typedef struct {
  double* data;
  int class;
} TrainingData;

// Function to load training data from file
void loadTrainingData(char* filename, int numImages, TrainingData* data)
{
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error loading training data file.\n");
    exit(1);
  }
  
  char buffer[256];
  for (int i = 0; i < numImages; i++) {
    // Read data row by row
    fgets(buffer, 256, file);
    char* token = strtok(buffer, ",");
    data[i].class = atoi(token);
    data[i].data = (double*)malloc(sizeof(double) * IMG_SIZE);
    for (int j = 0; j < IMG_SIZE; j++) {
      token = strtok(NULL, ",");
      data[i].data[j] = atof(token);
    }
  }
  
  fclose(file);
}

// Function to calculate distance between two images
double distance(double* img1, double* img2)
{
  double sum = 0.0;
  for (int i = 0; i < IMG_SIZE; i++) {
    sum += pow((img1[i] - img2[i]), 2);
  }
  return sqrt(sum);
}

// Function to classify an image
int classify(double* img, TrainingData* trainingData, int numTrainingData)
{
  int* classCounts = (int*)calloc(NUM_CLASSES, sizeof(int));
  for (int i = 0; i < numTrainingData; i++) {
    double dist = distance(img, trainingData[i].data);
    classCounts[trainingData[i].class]++;
  }
  int maxIndex = 0;
  for (int i = 0; i < NUM_CLASSES; i++) {
    if (classCounts[i] > classCounts[maxIndex]) maxIndex = i;
  }
  free(classCounts);
  return maxIndex;
}

int main()
{
  // Load training data
  int numTrainingImages = 5000;
  TrainingData* trainingData = (TrainingData*)malloc(sizeof(TrainingData) * numTrainingImages);
  loadTrainingData("training_data.csv", numTrainingImages, trainingData);
  
  // Load test data
  int numTestImages = 100;
  TrainingData* testData = (TrainingData*)malloc(sizeof(TrainingData) * numTestImages);
  loadTrainingData("test_data.csv", numTestImages, testData);
  
  // Classify test images
  int numCorrect = 0;
  for (int i = 0; i < numTestImages; i++) {
    int predictedClass = classify(testData[i].data, trainingData, numTrainingImages);
    if (predictedClass == testData[i].class) numCorrect++;
  }
  
  // Output results
  printf("Number of test images classified correctly: %d/%d\n", numCorrect, numTestImages);
  
  // Free memory
  for (int i = 0; i < numTrainingImages; i++) {
    free(trainingData[i].data);
  }
  free(trainingData);
  for (int i = 0; i < numTestImages; i++) {
    free(testData[i].data);
  }
  free(testData);
  
  return 0;
}