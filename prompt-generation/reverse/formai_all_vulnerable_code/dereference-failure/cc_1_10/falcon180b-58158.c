//Falcon-180B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int height;
    int weight;
} Person;

void createPerson(Person *person) {
    person->name = (char *) malloc(MAX_SIZE * sizeof(char));
    person->age = 0;
    person->height = 0;
    person->weight = 0;
}

void setName(Person *person, char *name) {
    strcpy(person->name, name);
}

void setAge(Person *person, int age) {
    person->age = age;
}

void setHeight(Person *person, int height) {
    person->height = height;
}

void setWeight(Person *person, int weight) {
    person->weight = weight;
}

void printPerson(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %d\n", person->height);
    printf("Weight: %d\n", person->weight);
}

int main() {
    Person person;
    createPerson(&person);
    setName(&person, "John Doe");
    setAge(&person, 30);
    setHeight(&person, 180);
    setWeight(&person, 80);
    printPerson(&person);
    free(person.name);
    return 0;
}