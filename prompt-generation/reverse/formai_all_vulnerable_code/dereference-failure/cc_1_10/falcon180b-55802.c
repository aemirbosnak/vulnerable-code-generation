//Falcon-180B DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

Person *people = NULL;
int num_people = 0;

void add_person(char *name, int age) {
    Person *new_person = malloc(sizeof(Person));
    if (new_person == NULL) {
        printf("Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }
    new_person->name = strdup(name);
    new_person->age = age;
    people = realloc(people, sizeof(Person) * ++num_people);
    people[num_people - 1] = *new_person;
    free(new_person);
}

void print_people() {
    for (int i = 0; i < num_people; i++) {
        printf("%s (%d)\n", people[i].name, people[i].age);
    }
}

void search_people(char *name) {
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found %s (%d)\n", people[i].name, people[i].age);
            return;
        }
    }
    printf("Not found\n");
}

int main() {
    add_person("Alice", 25);
    add_person("Bob", 30);
    add_person("Charlie", 20);
    print_people();
    search_people("Bob");
    search_people("Dave");
    return 0;
}