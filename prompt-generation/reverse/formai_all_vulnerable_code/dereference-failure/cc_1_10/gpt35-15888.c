//FormAI DATASET v1.0 Category: Data mining ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// define the structure for a data point
typedef struct {
    int x;
    int y;
    float value;
} DataPoint;

// define a function to generate random data points
DataPoint* generateDataPoints(int n) {
    DataPoint* points = (DataPoint*)malloc(sizeof(DataPoint) * n);
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        points[i].x = rand() % 100; // random x value between 0 and 99
        points[i].y = rand() % 100; // random y value between 0 and 99
        points[i].value = (float)(rand() % 1000) / 1000.0; // random value between 0 and 0.999
    }
    return points;
}

int main() {
    int n = 100; // number of data points
    DataPoint* points = generateDataPoints(n); // generate random data points
    
    // print the original data points
    printf("Original Data Points:\n");
    printf("---------------------\n");
    for(int i = 0; i < n; i++) {
        printf("(%d,%d): %.3f\n", points[i].x, points[i].y, points[i].value);
    }
    
    // find the data point with the highest value
    float maxValue = 0;
    int maxIndex = 0;
    for(int i = 0; i < n; i++) {
        if(points[i].value > maxValue) {
            maxValue = points[i].value;
            maxIndex = i;
        }
    }
    
    // print the data point with the highest value
    printf("\nData Point with Highest Value:\n");
    printf("--------------------------------\n");
    printf("(%d,%d): %.3f\n", points[maxIndex].x, points[maxIndex].y, points[maxIndex].value);
    
    // find the average value of all data points
    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += points[i].value;
    }
    float avgValue = sum / n;
    
    // print the average value
    printf("\nAverage Value of Data Points: %.3f\n", avgValue);
    
    // free the memory allocated for the data points
    free(points);
    return 0;
}