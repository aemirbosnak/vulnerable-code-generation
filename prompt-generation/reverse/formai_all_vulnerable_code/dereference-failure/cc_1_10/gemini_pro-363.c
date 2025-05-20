//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int age;
    int weight;
    int height;
    int steps;
    int calories;
    int distance;
    int heart_rate;
} person;

person *create_person(char *name, int age, int weight, int height) {
    person *p = malloc(sizeof(person));
    p->name = strdup(name);
    p->age = age;
    p->weight = weight;
    p->height = height;
    p->steps = 0;
    p->calories = 0;
    p->distance = 0;
    p->heart_rate = 0;
    return p;
}

void destroy_person(person *p) {
    free(p->name);
    free(p);
}

void print_person(person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Weight: %d\n", p->weight);
    printf("Height: %d\n", p->height);
    printf("Steps: %d\n", p->steps);
    printf("Calories: %d\n", p->calories);
    printf("Distance: %d\n", p->distance);
    printf("Heart rate: %d\n", p->heart_rate);
}

void update_person(person *p, int steps, int calories, int distance, int heart_rate) {
    p->steps += steps;
    p->calories += calories;
    p->distance += distance;
    p->heart_rate += heart_rate;
}

int main() {
    person *p = create_person("John Doe", 30, 80, 180);
    // Simulate some activity
    update_person(p, 10000, 500, 5, 100);
    // Print the results
    print_person(p);
    // Destroy the person
    destroy_person(p);
    return 0;
}