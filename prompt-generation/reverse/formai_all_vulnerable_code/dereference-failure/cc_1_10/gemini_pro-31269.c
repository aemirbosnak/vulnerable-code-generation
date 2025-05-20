//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple data structure to hold a data point
typedef struct {
    int age;
    char gender;  // 'M' or 'F'
    char occupation[50];
    double salary;
} DataPoint;

// Function to read data from a file
DataPoint* readData(const char* filename, int* numDataPoints) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the number of data points
    fscanf(fp, "%d\n", numDataPoints);

    // Allocate memory for the data points
    DataPoint* dataPoints = (DataPoint*)malloc(*numDataPoints * sizeof(DataPoint));
    if (dataPoints == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Read each data point
    for (int i = 0; i < *numDataPoints; i++) {
        fscanf(fp, "%d %c %s %lf\n", &dataPoints[i].age, &dataPoints[i].gender, dataPoints[i].occupation, &dataPoints[i].salary);
    }

    fclose(fp);

    return dataPoints;
}

// Function to print data points
void printDataPoints(DataPoint* dataPoints, int numDataPoints) {
    for (int i = 0; i < numDataPoints; i++) {
        printf("%d %c %s %lf\n", dataPoints[i].age, dataPoints[i].gender, dataPoints[i].occupation, dataPoints[i].salary);
    }
}

// Function to find the average salary of all data points
double averageSalary(DataPoint* dataPoints, int numDataPoints) {
    double totalSalary = 0.0;
    for (int i = 0; i < numDataPoints; i++) {
        totalSalary += dataPoints[i].salary;
    }
    return totalSalary / numDataPoints;
}

// Function to find the highest salary of all data points
double highestSalary(DataPoint* dataPoints, int numDataPoints) {
    double maxSalary = dataPoints[0].salary;
    for (int i = 1; i < numDataPoints; i++) {
        if (dataPoints[i].salary > maxSalary) {
            maxSalary = dataPoints[i].salary;
        }
    }
    return maxSalary;
}

// Function to find the lowest salary of all data points
double lowestSalary(DataPoint* dataPoints, int numDataPoints) {
    double minSalary = dataPoints[0].salary;
    for (int i = 1; i < numDataPoints; i++) {
        if (dataPoints[i].salary < minSalary) {
            minSalary = dataPoints[i].salary;
        }
    }
    return minSalary;
}

int main() {
    // Read data from file
    int numDataPoints;
    DataPoint* dataPoints = readData("data.txt", &numDataPoints);

    // Print data points
    printf("Data Points:\n");
    printDataPoints(dataPoints, numDataPoints);

    // Find average salary
    double avgSalary = averageSalary(dataPoints, numDataPoints);
    printf("Average salary: %lf\n", avgSalary);

    // Find highest salary
    double maxSalary = highestSalary(dataPoints, numDataPoints);
    printf("Highest salary: %lf\n", maxSalary);

    // Find lowest salary
    double minSalary = lowestSalary(dataPoints, numDataPoints);
    printf("Lowest salary: %lf\n", minSalary);

    // Free memory
    free(dataPoints);

    return 0;
}