//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

struct person {
    char name[MAX_NAME_LENGTH];
    int age;
};

int main() {
    struct person *person1, *person2;
    int result;

    // Create two persons
    person1 = (struct person *)malloc(sizeof(struct person));
    person2 = (struct person *)malloc(sizeof(struct person));

    // Set their names and ages
    strcpy(person1->name, "Cupid");
    person1->age = 25;
    strcpy(person2->name, "Psyche");
    person2->age = 22;

    // Calculate their compatibility
    result = compare_ages(person1, person2);
    if (result == 0) {
        printf("Their ages match perfectly! They are compatible.\n");
    } else if (result > 0) {
        printf("Person 1 is older than Person 2, but not by much. They are still compatible.\n");
    } else {
        printf("Person 1 is significantly older than Person 2. They are not compatible.\n");
    }

    // Free memory
    free(person1);
    free(person2);

    return 0;
}

// Function to compare two persons' ages
int compare_ages(struct person *person1, struct person *person2) {
    int result;

    // Calculate the difference in their ages
    result = abs(person1->age - person2->age);

    // Return the result
    return result;
}