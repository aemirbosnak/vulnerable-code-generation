//Gemma-7B DATASET v1.0 Category: Data mining ; Style: interoperable
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

DataPoint* insertDataPoint(DataPoint* head, double value) {
    DataPoint* newPoint = malloc(sizeof(DataPoint));
    newPoint->value = value;
    newPoint->next = NULL;

    if (head == NULL) {
        head = newPoint;
    } else {
        head->next = newPoint;
    }

    return head;
}

double calculateMean(DataPoint* head) {
    double total = 0.0;
    int count = 0;

    while (head) {
        total += head->value;
        count++;
        head = head->next;
    }

    return total / count;
}

double calculateStandardDeviation(DataPoint* head) {
    double mean = calculateMean(head);
    double totalVariance = 0.0;
    int count = 0;

    while (head) {
        totalVariance += (head->value - mean) * (head->value - mean);
        count++;
        head = head->next;
    }

    return sqrt(totalVariance / count);
}

int main() {
    DataPoint* head = NULL;

    // Insert some data points
    insertDataPoint(head, 10.0);
    insertDataPoint(head, 12.0);
    insertDataPoint(head, 14.0);
    insertDataPoint(head, 16.0);

    // Calculate the mean
    double mean = calculateMean(head);

    // Calculate the standard deviation
    double stdDev = calculateStandardDeviation(head);

    // Print the results
    printf("Mean: %.2lf\n", mean);
    printf("Standard deviation: %.2lf\n", stdDev);

    return 0;
}