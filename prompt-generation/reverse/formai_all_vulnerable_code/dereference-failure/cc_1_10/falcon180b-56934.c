//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure of each element in the array
typedef struct {
    char *name;
    int age;
} Person;

// Function to compare two Person structures based on their age
int compare(const void *a, const void *b) {
    Person *personA = (Person *) a;
    Person *personB = (Person *) b;

    if (personA->age < personB->age) {
        return -1;
    } else if (personA->age > personB->age) {
        return 1;
    } else {
        return 0;
    }
}

// Function to search for a person in the array based on their name
Person* search(Person *array, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i].name, name) == 0) {
            return &array[i];
        }
    }
    return NULL;
}

int main() {
    // Initialize the array of Person structures
    Person *array = (Person *) malloc(MAX_SIZE * sizeof(Person));
    int size = 0;

    // Add some people to the array
    array[size].name = "Alice";
    array[size].age = 25;
    size++;

    array[size].name = "Bob";
    array[size].age = 30;
    size++;

    array[size].name = "Charlie";
    array[size].age = 35;
    size++;

    // Sort the array by age
    qsort(array, size, sizeof(Person), compare);

    // Search for a person by name
    Person *person = search(array, size, "Bob");

    if (person!= NULL) {
        printf("Found %s, age %d\n", person->name, person->age);
    } else {
        printf("Could not find %s\n", "Bob");
    }

    return 0;
}