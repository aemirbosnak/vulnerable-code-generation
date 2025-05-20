//Falcon-180B DATASET v1.0 Category: Memory management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void init_person(Person *person, char *name, int age) {
    person->name = malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
}

void destroy_person(Person *person) {
    free(person->name);
    person->name = NULL;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        char name[20];
        int age;

        printf("Enter name (max 20 characters): ");
        scanf("%s", name);

        printf("Enter age: ");
        scanf("%d", &age);

        if (num_people >= MAX_SIZE) {
            printf("Error: Maximum number of people reached.\n");
        } else {
            init_person(&people[num_people], name, age);
            num_people++;
        }
    }

    printf("List of people:\n");

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    free(people);
    return 0;
}