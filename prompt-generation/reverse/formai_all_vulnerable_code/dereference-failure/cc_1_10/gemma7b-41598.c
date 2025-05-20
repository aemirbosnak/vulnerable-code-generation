//Gemma-7B DATASET v1.0 Category: Temperature monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MEASUREMENTS 1024

typedef struct Measurement {
    double value;
    struct Measurement* next;
} Measurement;

Measurement* createMeasurement(double value) {
    Measurement* newMeasurement = malloc(sizeof(Measurement));
    newMeasurement->value = value;
    newMeasurement->next = NULL;
    return newMeasurement;
}

void addMeasurement(Measurement* head, double value) {
    Measurement* newMeasurement = createMeasurement(value);
    if (head) {
        head->next = newMeasurement;
    } else {
        head = newMeasurement;
    }
}

double calculateAverage(Measurement* head) {
    double sum = 0.0;
    int count = 0;
    for (Measurement* current = head; current; current = current->next) {
        sum += current->value;
        count++;
    }
    return sum / count;
}

int main() {
    Measurement* measurements = NULL;
    addMeasurement(measurements, 25.0);
    addMeasurement(measurements, 27.0);
    addMeasurement(measurements, 29.0);
    addMeasurement(measurements, 31.0);

    double average = calculateAverage(measurements);

    printf("The average temperature is: %.2lf\n", average);

    return 0;
}