//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    int weight;
    int height;
    int bmi;
} Person;

void print_person(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Weight: %d\n", person.weight);
    printf("Height: %d\n", person.height);
    printf("BMI: %d\n", person.bmi);
}

int is_valid_name(char* name) {
    int i = 0;
    while (name[i]!= '\0') {
        if (!isalpha(name[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int is_valid_age(int age) {
    return age >= 0 && age <= 150;
}

int is_valid_weight(int weight) {
    return weight >= 0 && weight <= 1000;
}

int is_valid_height(int height) {
    return height >= 0 && height <= 300;
}

int is_valid_bmi(int bmi) {
    return bmi >= 0 && bmi <= 100;
}

int main() {
    Person person;
    char name[MAX_SIZE];
    printf("Enter your name: ");
    scanf("%s", name);
    while (!is_valid_name(name)) {
        printf("Invalid name. Please enter a valid name: ");
        scanf("%s", name);
    }
    strcpy(person.name, name);

    int age;
    while (!is_valid_age(age)) {
        printf("Enter your age: ");
        scanf("%d", &age);
    }
    person.age = age;

    int weight;
    while (!is_valid_weight(weight)) {
        printf("Enter your weight: ");
        scanf("%d", &weight);
    }
    person.weight = weight;

    int height;
    while (!is_valid_height(height)) {
        printf("Enter your height: ");
        scanf("%d", &height);
    }
    person.height = height;

    person.bmi = (person.weight / (person.height * person.height)) * 100;

    print_person(person);

    return 0;
}