//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to hold the data to be sorted
struct Person {
    int age;
    char name[20];
};

// Define a function to compare two structs
int compare(const void *a, const void *b) {
    struct Person *personA = (struct Person *)a;
    struct Person *personB = (struct Person *)b;
    if (personA->age < personB->age) {
        return -1;
    } else if (personA->age > personB->age) {
        return 1;
    } else {
        return strcmp(personA->name, personB->name);
    }
}

// Define the main function
int main() {
    // Generate some random data to be sorted
    struct Person data[5] = {
        {18, "Alice"},
        {25, "Bob"},
        {30, "Charlie"},
        {40, "David"},
        {19, "Eve"}
    };

    // Generate a random number of elements to sort
    int numElements = rand() % 5 + 1;

    // Create an array to hold the sorted data
    struct Person *sortedData = calloc(numElements, sizeof(struct Person));

    // Sort the data using quicksort
    qsort(data, numElements, sizeof(struct Person), compare);

    // Print the sorted data
    for (int i = 0; i < numElements; i++) {
        printf("%d %s\n", sortedData[i].age, sortedData[i].name);
    }

    return 0;
}