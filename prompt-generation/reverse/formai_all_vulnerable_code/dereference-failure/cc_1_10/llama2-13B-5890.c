//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Define some constants and variables
#define MAX_NAME_LEN 20
#define MAX_AGE 100
#define MIN_AGE 18
#define MAX_HEIGHT 2.0
#define MIN_HEIGHT 1.5
#define MAX_WEIGHT 100.0
#define MIN_WEIGHT 50.0

// Structure to hold person information
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    double height;
    double weight;
} person_t;

// Function to create a new person
person_t* create_person(char* name, int age, double height, double weight) {
    person_t* p = malloc(sizeof(person_t));
    strcpy(p->name, name);
    p->age = age;
    p->height = height;
    p->weight = weight;
    return p;
}

// Function to print a person's information
void print_person(person_t* p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %f\n", p->height);
    printf("Weight: %f\n", p->weight);
}

// Main function
int main() {
    // Create some people
    person_t* p1 = create_person("Alice", 25, 1.7, 55.0);
    person_t* p2 = create_person("Bob", 30, 1.85, 75.0);
    person_t* p3 = create_person("Charlie", 20, 1.65, 60.0);

    // Print each person's information
    print_person(p1);
    print_person(p2);
    print_person(p3);

    // Calculate the average height and weight for each person
    double avg_height = (p1->height + p2->height + p3->height) / 3.0;
    double avg_weight = (p1->weight + p2->weight + p3->weight) / 3.0;

    // Print the averages
    printf("Average height: %f\n", avg_height);
    printf("Average weight: %f\n", avg_weight);

    // Free the memory for each person
    free(p1);
    free(p2);
    free(p3);

    return 0;
}