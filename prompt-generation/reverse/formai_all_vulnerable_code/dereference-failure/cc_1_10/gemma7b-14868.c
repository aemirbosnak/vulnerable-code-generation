//Gemma-7B DATASET v1.0 Category: Data mining ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA_POINTS 1000

typedef struct DataPoint {
    int index;
    char name[50];
    float value;
    struct DataPoint* next;
} DataPoint;

DataPoint* insertDataPoint(DataPoint* head, int index, char* name, float value) {
    DataPoint* newPoint = malloc(sizeof(DataPoint));
    newPoint->index = index;
    strcpy(newPoint->name, name);
    newPoint->value = value;
    newPoint->next = NULL;

    if (head == NULL) {
        head = newPoint;
    } else {
        head->next = newPoint;
    }

    return head;
}

void printDataPoints(DataPoint* head) {
    DataPoint* currentPoint = head;
    while (currentPoint) {
        printf("Index: %d, Name: %s, Value: %.2f\n", currentPoint->index, currentPoint->name, currentPoint->value);
        currentPoint = currentPoint->next;
    }
}

int main() {
    DataPoint* head = NULL;

    // Insert some data points
    insertDataPoint(head, 0, "John Doe", 100.0);
    insertDataPoint(head, 1, "Jane Doe", 200.0);
    insertDataPoint(head, 2, "Bill Smith", 300.0);

    // Print the data points
    printDataPoints(head);

    return 0;
}