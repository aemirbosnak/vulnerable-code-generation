//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float height;
    float weight;
    float bmi;
    int steps;
    int calories;
    int distance;
} Person;

Person *create_person(char *name, int age, float height, float weight) {
    Person *person = malloc(sizeof(Person));
    strcpy(person->name, name);
    person->age = age;
    person->height = height;
    person->weight = weight;
    person->bmi = person->weight / (person->height * person->height);
    person->steps = 0;
    person->calories = 0;
    person->distance = 0;
    return person;
}

void track_steps(Person *person, int steps) {
    person->steps += steps;
    person->calories += steps * 0.05;
    person->distance += steps * 0.0005;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %.2f m\n", person->height);
    printf("Weight: %.2f kg\n", person->weight);
    printf("BMI: %.2f\n", person->bmi);
    printf("Steps: %d\n", person->steps);
    printf("Calories: %d\n", person->calories);
    printf("Distance: %.2f km\n", person->distance);
}

int main() {
    Person *person = create_person("John", 25, 1.8, 75);
    track_steps(person, 10000);
    print_person(person);
    return 0;
}