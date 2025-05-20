//Falcon-180B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold our data
typedef struct {
    int value;
    char* name;
} Data;

// Function to allocate memory for a new Data struct
Data* createData(int value, char* name) {
    Data* newData = (Data*) malloc(sizeof(Data));
    if (newData == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    
    newData->value = value;
    newData->name = (char*) malloc(strlen(name) + 1);
    if (newData->name == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    
    strcpy(newData->name, name);
    
    return newData;
}

// Function to free memory allocated for a Data struct
void freeData(Data* data) {
    free(data->name);
    free(data);
}

// Function to print the contents of a Data struct
void printData(Data* data) {
    printf("Value: %d\n", data->value);
    printf("Name: %s\n", data->name);
}

// Main function
int main() {
    Data* data1 = createData(42, "Alice");
    Data* data2 = createData(24, "Bob");
    Data* data3 = createData(36, "Charlie");
    
    printData(data1);
    printData(data2);
    printData(data3);
    
    freeData(data1);
    freeData(data2);
    freeData(data3);
    
    return 0;
}