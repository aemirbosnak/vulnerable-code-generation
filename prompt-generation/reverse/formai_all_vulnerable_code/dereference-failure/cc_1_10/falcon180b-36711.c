//Falcon-180B DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_AGE 150

// Struct for a person
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Person;

// Function to compare two people by age
int compare_age(const void *a, const void *b) {
    const Person *person_a = a;
    const Person *person_b = b;

    if (person_a->age < person_b->age) {
        return -1;
    } else if (person_a->age > person_b->age) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print a person's information
void print_person(const Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

// Main function
int main() {
    // Initialize an array of people
    Person people[] = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 20}, {"David", 35}};
    int num_people = sizeof(people) / sizeof(Person);

    // Sort the array by age
    qsort(people, num_people, sizeof(Person), compare_age);

    // Print the sorted array
    printf("Sorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    // Search for a person by name
    char search_name[MAX_NAME_LEN] = "Bob";
    Person *found_person = bsearch(&search_name, people, num_people, sizeof(Person), compare_age);

    if (found_person!= NULL) {
        printf("\nFound person: ");
        print_person(found_person);
    } else {
        printf("\nPerson not found.\n");
    }

    return 0;
}