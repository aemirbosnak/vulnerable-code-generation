//Falcon-180B DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    char gender;
} Person;

void create_person(Person *person, char *name, int age, char gender) {
    person->name = malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
    person->gender = gender;
}

void display_person(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Gender: %c\n", person.gender);
}

void delete_person(Person *person) {
    free(person->name);
    memset(person, 0, sizeof(Person));
}

int main() {
    Person person[MAX_SIZE];
    int count = 0;

    while (count < MAX_SIZE) {
        char name[50];
        int age;
        char gender;

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter age: ");
        scanf("%d", &age);

        printf("Enter gender (M/F): ");
        scanf(" %c", &gender);

        create_person(&person[count], name, age, gender);
        count++;
    }

    printf("\nList of people:\n");

    for (int i = 0; i < count; i++) {
        display_person(person[i]);
    }

    for (int i = 0; i < count; i++) {
        delete_person(&person[i]);
    }

    return 0;
}