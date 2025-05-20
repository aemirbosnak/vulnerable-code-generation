//Falcon-180B DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

Person *createPerson(char *name, int age, char *gender) {
    Person *person = malloc(sizeof(Person));
    if (person == NULL) {
        printf("Failed to allocate memory for person.\n");
        exit(1);
    }

    person->name = malloc(strlen(name) + 1);
    if (person->name == NULL) {
        printf("Failed to allocate memory for name.\n");
        exit(1);
    }
    strcpy(person->name, name);

    person->age = age;

    person->gender = malloc(strlen(gender) + 1);
    if (person->gender == NULL) {
        printf("Failed to allocate memory for gender.\n");
        exit(1);
    }
    strcpy(person->gender, gender);

    return person;
}

void deletePerson(Person *person) {
    free(person->name);
    free(person->gender);
    free(person);
}

int main() {
    Person *person1 = createPerson("John", 25, "Male");
    Person *person2 = createPerson("Jane", 30, "Female");

    printf("Name: %s\nAge: %d\nGender: %s\n", person1->name, person1->age, person1->gender);
    printf("Name: %s\nAge: %d\nGender: %s\n", person2->name, person2->age, person2->gender);

    deletePerson(person1);
    deletePerson(person2);

    return 0;
}