//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

Person people[MAX_SIZE];
int num_people = 0;

void add_person(char *name, int age) {
    if (num_people >= MAX_SIZE) {
        printf("Error: Cannot add more than %d people.\n", MAX_SIZE);
        return;
    }
    people[num_people].name = malloc(strlen(name) + 1);
    strcpy(people[num_people].name, name);
    people[num_people].age = age;
    num_people++;
}

void remove_person(char *name) {
    int i;
    for (i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            free(people[i].name);
            people[i] = people[num_people - 1];
            num_people--;
            return;
        }
    }
    printf("Error: Person not found.\n");
}

void search_person(char *name) {
    int i;
    for (i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found person: %s, age: %d\n", people[i].name, people[i].age);
            return;
        }
    }
    printf("Error: Person not found.\n");
}

int main() {
    add_person("Alice", 25);
    add_person("Bob", 30);
    add_person("Charlie", 35);
    search_person("Alice");
    remove_person("Bob");
    search_person("Bob");
    return 0;
}