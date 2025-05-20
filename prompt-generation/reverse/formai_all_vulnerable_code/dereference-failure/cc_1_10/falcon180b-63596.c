//Falcon-180B DATASET v1.0 Category: Sorting ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct for our data
typedef struct {
    int id;
    char name[64];
    float value;
} Data;

// Function to compare two Data structs
int compare(const void *a, const void *b) {
    const Data *dataA = (const Data *)a;
    const Data *dataB = (const Data *)b;
    
    // Sort by ID in ascending order
    if (dataA->id < dataB->id) {
        return -1;
    } else if (dataA->id > dataB->id) {
        return 1;
    } else {
        return 0;
    }
}

// Function to generate random data
void generateData(Data *data, int numElements) {
    srand(time(NULL));
    
    for (int i = 0; i < numElements; i++) {
        data[i].id = rand() % 1000;
        sprintf(data[i].name, "Element %d", i);
        data[i].value = (float)rand() / RAND_MAX;
    }
}

// Function to print the sorted data
void printData(Data *data, int numElements) {
    for (int i = 0; i < numElements; i++) {
        printf("%d: %s - %.2f\n", data[i].id, data[i].name, data[i].value);
    }
}

int main() {
    // Initialize variables
    int numElements = 100;
    Data *data = malloc(sizeof(Data) * numElements);
    
    // Generate random data
    generateData(data, numElements);
    
    // Print unsorted data
    printf("Unsorted Data:\n");
    printData(data, numElements);
    
    // Sort the data using qsort
    qsort(data, numElements, sizeof(Data), compare);
    
    // Print sorted data
    printf("\nSorted Data (by ID):\n");
    printData(data, numElements);
    
    return 0;
}