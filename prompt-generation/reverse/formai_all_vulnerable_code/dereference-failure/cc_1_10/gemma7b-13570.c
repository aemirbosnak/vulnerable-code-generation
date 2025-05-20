//Gemma-7B DATASET v1.0 Category: Data mining ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA_POINTS 1000

typedef struct DataPoint {
    int index;
    double value;
    struct DataPoint* next;
} DataPoint;

DataPoint* createDataPoint(int index, double value) {
    DataPoint* newPoint = (DataPoint*)malloc(sizeof(DataPoint));
    newPoint->index = index;
    newPoint->value = value;
    newPoint->next = NULL;
    return newPoint;
}

void insertDataPoint(DataPoint* head, int index, double value) {
    DataPoint* newPoint = createDataPoint(index, value);
    if (head == NULL) {
        head = newPoint;
    } else {
        DataPoint* currentPoint = head;
        while (currentPoint->next) {
            currentPoint = currentPoint->next;
        }
        currentPoint->next = newPoint;
    }
}

double calculateMean(DataPoint* head) {
    double sum = 0.0;
    int count = 0;
    DataPoint* currentPoint = head;
    while (currentPoint) {
        sum += currentPoint->value;
        count++;
        currentPoint = currentPoint->next;
    }
    return sum / count;
}

double calculateStandardDeviation(DataPoint* head) {
    double mean = calculateMean(head);
    double sumSquares = 0.0;
    int count = 0;
    DataPoint* currentPoint = head;
    while (currentPoint) {
        sumSquares += (currentPoint->value - mean) * (currentPoint->value - mean);
        count++;
        currentPoint = currentPoint->next;
    }
    return sqrt(sumSquares / count);
}

int main() {
    DataPoint* head = NULL;
    insertDataPoint(head, 0, 10.0);
    insertDataPoint(head, 1, 12.0);
    insertDataPoint(head, 2, 14.0);
    insertDataPoint(head, 3, 16.0);

    double mean = calculateMean(head);
    double stdDev = calculateStandardDeviation(head);

    printf("Mean: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", stdDev);

    return 0;
}