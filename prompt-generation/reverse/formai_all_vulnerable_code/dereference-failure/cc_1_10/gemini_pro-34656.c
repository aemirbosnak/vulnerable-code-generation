//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *occupation;
} Person;

typedef struct {
    Person *people;
    int size;
    int capacity;
} Directory;

Directory *createDirectory() {
    Directory *directory = malloc(sizeof(Directory));
    directory->people = malloc(sizeof(Person) * 10);
    directory->size = 0;
    directory->capacity = 10;
    return directory;
}

void addPerson(Directory *directory, Person person) {
    if (directory->size == directory->capacity) {
        directory->capacity *= 2;
        directory->people = realloc(directory->people, sizeof(Person) * directory->capacity);
    }
    directory->people[directory->size++] = person;
}

void printDirectory(Directory *directory) {
    for (int i = 0; i < directory->size; i++) {
        Person person = directory->people[i];
        printf("Name: %s\n", person.name);
        printf("Age: %d\n", person.age);
        printf("Occupation: %s\n\n", person.occupation);
    }
}

int main() {
    Directory *directory = createDirectory();

    Person person1 = {"John Doe", 30, "Software Engineer"};
    addPerson(directory, person1);

    Person person2 = {"Jane Doe", 25, "Doctor"};
    addPerson(directory, person2);

    Person person3 = {"Bob Smith", 40, "Teacher"};
    addPerson(directory, person3);

    printDirectory(directory);

    return 0;
}