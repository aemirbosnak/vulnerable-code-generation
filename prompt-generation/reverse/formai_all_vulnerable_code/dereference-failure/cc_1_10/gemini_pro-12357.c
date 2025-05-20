//GEMINI-pro DATASET v1.0 Category: Educational ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    bool is_happy;
} Person;

// Create a new person with the given name and age
Person* create_person(char* name, int age, bool is_happy) {
    Person* person = malloc(sizeof(Person));
    strcpy(person->name, name);
    person->age = age;
    person->is_happy = is_happy;
    return person;
}

// Print the details of the given person
void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Is happy: %s\n", person->is_happy ? "Yes" : "No");
}

// Get a random number between min and max
int get_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Create an array of 10 people
    Person* people[10];

    // Initialize the people array with random data
    for (int i = 0; i < 10; i++) {
        char* names[] = {"Alice", "Bob", "Carol", "Dave", "Eve", "Frank", "George", "Helen", "Ian", "Jack"};
        people[i] = create_person(names[i], get_random(18, 65), get_random(0, 1));
    }

    // Print the details of each person
    for (int i = 0; i < 10; i++) {
        print_person(people[i]);
        printf("\n");
    }

    return 0;
}