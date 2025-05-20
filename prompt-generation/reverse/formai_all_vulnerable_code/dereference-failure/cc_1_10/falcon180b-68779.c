//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
} person;

person *create_person(char *name, int age, float weight, float height) {
    person *p = malloc(sizeof(person));
    if (p == NULL) {
        printf("Error: Unable to allocate memory.\n");
        exit(1);
    }
    strcpy(p->name, name);
    p->age = age;
    p->weight = weight;
    p->height = height;
    return p;
}

void display_person(person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Weight: %.2f\n", p->weight);
    printf("Height: %.2f\n", p->height);
}

float bmi(person *p) {
    return p->weight / (p->height * p->height);
}

int main() {
    person *p1 = create_person("John Doe", 25, 80.0, 1.8);
    person *p2 = create_person("Jane Smith", 30, 65.0, 1.7);

    display_person(p1);
    display_person(p2);

    float bmi1 = bmi(p1);
    float bmi2 = bmi(p2);

    printf("BMI of %s: %.2f\n", p1->name, bmi1);
    printf("BMI of %s: %.2f\n", p2->name, bmi2);

    return 0;
}