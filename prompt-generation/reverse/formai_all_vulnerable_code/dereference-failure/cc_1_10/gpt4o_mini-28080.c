//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define INITIAL_CAPACITY 5

// Structure to hold information about a person
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

// Dynamic array structure
typedef struct {
    Person *data;
    size_t size;
    size_t capacity;
} DynamicArray;

// Function to create a new dynamic array
DynamicArray* createDynamicArray() {
    DynamicArray *array = malloc(sizeof(DynamicArray));
    if (!array) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    array->data = malloc(INITIAL_CAPACITY * sizeof(Person));
    if (!array->data) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
    return array;
}

// Function to resize the dynamic array
void resizeArray(DynamicArray *array) {
    array->capacity *= 2;
    Person *newData = realloc(array->data, array->capacity * sizeof(Person));
    if (!newData) {
        printf("Failed to resize array!\n");
        free(array->data);
        free(array);
        exit(EXIT_FAILURE);
    }
    array->data = newData;
}

// Function to add a person to the array
void addPerson(DynamicArray *array, const char *name, int age) {
    if (array->size >= array->capacity) {
        resizeArray(array);
    }
    strcpy(array->data[array->size].name, name);
    array->data[array->size].age = age;
    array->size++;
}

// Function to print all people in the array
void printPeople(const DynamicArray *array) {
    printf("People in the dynamic array:\n");
    for (size_t i = 0; i < array->size; i++) {
        printf("Name: %s, Age: %d\n", array->data[i].name, array->data[i].age);
    }
}

// Function to free the dynamic array
void freeDynamicArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

// Main function
int main() {
    DynamicArray *people = createDynamicArray();
    
    // Adding some people
    addPerson(people, "Alice", 30);
    addPerson(people, "Bob", 25);
    addPerson(people, "Charlie", 35);
    addPerson(people, "Diana", 28);
    addPerson(people, "Edward", 40);
    addPerson(people, "Fiona", 22); // This will trigger a resize

    // Print all the people
    printPeople(people);

    // Free the dynamically allocated memory
    freeDynamicArray(people);
    return 0;
}