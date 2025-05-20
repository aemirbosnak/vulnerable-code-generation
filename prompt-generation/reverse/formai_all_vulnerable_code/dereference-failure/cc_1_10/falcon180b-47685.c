//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

Person *people = NULL;
int num_people = 0;

void add_person(char *name, int age) {
    Person *new_person = (Person *) malloc(sizeof(Person));
    if (new_person == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    strcpy(new_person->name, name);
    new_person->age = age;

    people = (Person *) realloc(people, sizeof(Person) * ++num_people);
    if (people == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    people[num_people - 1] = *new_person;
}

void search_people(char *name) {
    int i;
    for (i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found person with name %s and age %d\n", people[i].name, people[i].age);
        }
    }
}

int main() {
    add_person("Alice", 25);
    add_person("Bob", 30);
    add_person("Charlie", 35);

    search_people("Alice");
    search_people("David");

    return 0;
}