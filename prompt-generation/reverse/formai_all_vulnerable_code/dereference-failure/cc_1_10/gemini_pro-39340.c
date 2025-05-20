//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Data structure to store a single data point
typedef struct {
    int age;
    int gender; // 0 for male, 1 for female
    double height;
    double weight;
} DataPoint;

// Data structure to store a dataset
typedef struct {
    DataPoint *dataPoints;
    int numDataPoints;
} Dataset;

// Function to create a new dataset
Dataset *createDataset(int numDataPoints) {
    Dataset *dataset = (Dataset *)malloc(sizeof(Dataset));
    dataset->dataPoints = (DataPoint *)malloc(sizeof(DataPoint) * numDataPoints);
    dataset->numDataPoints = numDataPoints;
    return dataset;
}

// Function to free the memory allocated for a dataset
void freeDataset(Dataset *dataset) {
    free(dataset->dataPoints);
    free(dataset);
}

// Function to add a data point to a dataset
void addDataPoint(Dataset *dataset, DataPoint dataPoint) {
    dataset->dataPoints[dataset->numDataPoints++] = dataPoint;
}

// Function to print a dataset
void printDataset(Dataset *dataset) {
    for (int i = 0; i < dataset->numDataPoints; i++) {
        DataPoint dataPoint = dataset->dataPoints[i];
        printf("Data point %d:\n", i);
        printf("Age: %d\n", dataPoint.age);
        printf("Gender: %d\n", dataPoint.gender);
        printf("Height: %.2f\n", dataPoint.height);
        printf("Weight: %.2f\n\n", dataPoint.weight);
    }
}

// Function to find the mean of a dataset
double mean(Dataset *dataset, int attribute) {
    double sum = 0;
    for (int i = 0; i < dataset->numDataPoints; i++) {
        DataPoint dataPoint = dataset->dataPoints[i];
        switch (attribute) {
            case 0:
                sum += dataPoint.age;
                break;
            case 1:
                sum += dataPoint.gender;
                break;
            case 2:
                sum += dataPoint.height;
                break;
            case 3:
                sum += dataPoint.weight;
                break;
        }
    }
    return sum / dataset->numDataPoints;
}

// Function to find the variance of a dataset
double variance(Dataset *dataset, int attribute) {
    double meanValue = mean(dataset, attribute);
    double sum = 0;
    for (int i = 0; i < dataset->numDataPoints; i++) {
        DataPoint dataPoint = dataset->dataPoints[i];
        double difference = dataPoint.age - meanValue;
        sum += difference * difference;
    }
    return sum / dataset->numDataPoints;
}

// Function to find the standard deviation of a dataset
double standardDeviation(Dataset *dataset, int attribute) {
    return sqrt(variance(dataset, attribute));
}

// Function to find the covariance between two attributes of a dataset
double covariance(Dataset *dataset, int attribute1, int attribute2) {
    double meanValue1 = mean(dataset, attribute1);
    double meanValue2 = mean(dataset, attribute2);
    double sum = 0;
    for (int i = 0; i < dataset->numDataPoints; i++) {
        DataPoint dataPoint = dataset->dataPoints[i];
        double difference1 = dataPoint.age - meanValue1;
        double difference2 = dataPoint.gender - meanValue2;
        sum += difference1 * difference2;
    }
    return sum / dataset->numDataPoints;
}

// Function to find the correlation between two attributes of a dataset
double correlation(Dataset *dataset, int attribute1, int attribute2) {
    double covarianceValue = covariance(dataset, attribute1, attribute2);
    double standardDeviation1 = standardDeviation(dataset, attribute1);
    double standardDeviation2 = standardDeviation(dataset, attribute2);
    return covarianceValue / (standardDeviation1 * standardDeviation2);
}

int main() {
    // Create a new dataset
    Dataset *dataset = createDataset(100);

    // Add data points to the dataset
    for (int i = 0; i < 100; i++) {
        DataPoint dataPoint;
        dataPoint.age = rand() % 100;
        dataPoint.gender = rand() % 2;
        dataPoint.height = rand() % 200;
        dataPoint.weight = rand() % 100;
        addDataPoint(dataset, dataPoint);
    }

    // Print the dataset
    printDataset(dataset);

    // Find the mean of the dataset
    double meanAge = mean(dataset, 0);
    double meanGender = mean(dataset, 1);
    double meanHeight = mean(dataset, 2);
    double meanWeight = mean(dataset, 3);

    // Find the variance of the dataset
    double varianceAge = variance(dataset, 0);
    double varianceGender = variance(dataset, 1);
    double varianceHeight = variance(dataset, 2);
    double varianceWeight = variance(dataset, 3);

    // Find the standard deviation of the dataset
    double standardDeviationAge = standardDeviation(dataset, 0);
    double standardDeviationGender = standardDeviation(dataset, 1);
    double standardDeviationHeight = standardDeviation(dataset, 2);
    double standardDeviationWeight = standardDeviation(dataset, 3);

    // Find the covariance between the attributes of the dataset
    double covarianceAgeGender = covariance(dataset, 0, 1);
    double covarianceAgeHeight = covariance(dataset, 0, 2);
    double covarianceAgeWeight = covariance(dataset, 0, 3);
    double covarianceGenderHeight = covariance(dataset, 1, 2);
    double covarianceGenderWeight = covariance(dataset, 1, 3);
    double covarianceHeightWeight = covariance(dataset, 2, 3);

    // Find the correlation between the attributes of the dataset
    double correlationAgeGender = correlation(dataset, 0, 1);
    double correlationAgeHeight = correlation(dataset, 0, 2);
    double correlationAgeWeight = correlation(dataset, 0, 3);
    double correlationGenderHeight = correlation(dataset, 1, 2);
    double correlationGenderWeight = correlation(dataset, 1, 3);
    double correlationHeightWeight = correlation(dataset, 2, 3);

    // Print the results
    printf("Mean age: %.2f\n", meanAge);
    printf("Mean gender: %.2f\n", meanGender);
    printf("Mean height: %.2f\n", meanHeight);
    printf("Mean weight: %.2f\n\n", meanWeight);
    printf("Variance age: %.2f\n", varianceAge);
    printf("Variance gender: %.2f\n", varianceGender);
    printf("Variance height: %.2f\n", varianceHeight);
    printf("Variance weight: %.2f\n\n", varianceWeight);
    printf("Standard deviation age: %.2f\n", standardDeviationAge);
    printf("Standard deviation gender: %.2f\n", standardDeviationGender);
    printf("Standard deviation height: %.2f\n", standardDeviationHeight);
    printf("Standard deviation weight: %.2f\n\n", standardDeviationWeight);
    printf("Covariance age, gender: %.2f\n", covarianceAgeGender);
    printf("Covariance age, height: %.2f\n", covarianceAgeHeight);
    printf("Covariance age, weight: %.2f\n", covarianceAgeWeight);
    printf("Covariance gender, height: %.2f\n", covarianceGenderHeight);
    printf("Covariance gender, weight: %.2f\n", covarianceGenderWeight);
    printf("Covariance height, weight: %.2f\n\n", covarianceHeightWeight);
    printf("Correlation age, gender: %.2f\n", correlationAgeGender);
    printf("Correlation age, height: %.2f\n", correlationAgeHeight);
    printf("Correlation age, weight: %.2f\n", correlationAgeWeight);
    printf("Correlation gender, height: %.2f\n", correlationGenderHeight);
    printf("Correlation gender, weight: %.2f\n", correlationGenderWeight);
    printf("Correlation height, weight: %.2f\n", correlationHeightWeight);

    // Free the memory allocated for the dataset
    freeDataset(dataset);

    return 0;
}