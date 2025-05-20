//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the list
#define MAX_SIZE 100

// Define the structure of each element in the list
typedef struct {
    char *name;
    int age;
} Person;

// Define the list of people
Person people[MAX_SIZE];
int num_people = 0;

// Function to add a person to the list
void add_person(char *name, int age) {
    if (num_people >= MAX_SIZE) {
        printf("Error: List is full.\n");
        return;
    }
    people[num_people].name = malloc(strlen(name) + 1);
    strcpy(people[num_people].name, name);
    people[num_people].age = age;
    num_people++;
}

// Function to search for a person in the list
Person *search_person(char *name) {
    int i;
    for (i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            return &people[i];
        }
    }
    return NULL;
}

// Function to print the list of people
void print_list() {
    int i;
    for (i = 0; i < num_people; i++) {
        printf("%s, %d\n", people[i].name, people[i].age);
    }
}

// Main function
int main() {
    add_person("Alice", 25);
    add_person("Bob", 30);
    add_person("Charlie", 35);
    add_person("David", 40);
    print_list();
    Person *person = search_person("Bob");
    if (person!= NULL) {
        printf("Found %s, age %d\n", person->name, person->age);
    } else {
        printf("Not found\n");
    }
    return 0;
}