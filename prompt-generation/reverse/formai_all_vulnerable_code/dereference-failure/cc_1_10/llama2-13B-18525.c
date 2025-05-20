//LLAMA2-13B DATASET v1.0 Category: Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100
#define MAX_HEIGHT 2.0

// Define a struct to hold person information
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    double height;
} person_t;

// Function to create a new person
person_t* create_person(char* name, int age, double height) {
    person_t* p = malloc(sizeof(person_t));
    strcpy(p->name, name);
    p->age = age;
    p->height = height;
    return p;
}

// Function to print a person's information
void print_person(person_t* p) {
    printf("Name: %s\nAge: %d\nHeight: %f\n", p->name, p->age, p->height);
}

// Function to calculate and print the average height of a list of people
void print_avg_height(person_t** people, int num_people) {
    double sum_height = 0;
    for (int i = 0; i < num_people; i++) {
        sum_height += people[i]->height;
    }
    printf("Average Height: %f\n", sum_height / num_people);
}

int main() {
    // Create some people
    person_t* p1 = create_person("Alice", 25, 1.65);
    person_t* p2 = create_person("Bob", 30, 1.80);
    person_t* p3 = create_person("Charlie", 35, 1.90);

    // Add them to a list
    person_t** people = malloc(sizeof(person_t*) * 3);
    people[0] = p1;
    people[1] = p2;
    people[2] = p3;

    // Print each person's information
    for (int i = 0; i < 3; i++) {
        print_person(people[i]);
    }

    // Calculate and print the average height of the list
    print_avg_height(people, 3);

    return 0;
}