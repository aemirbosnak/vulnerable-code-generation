//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void create_person(Person *person, char *name, int age) {
    person->name = strdup(name);
    person->age = age;
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    create_person(people[num_people++], "Alice", 25);
    create_person(people[num_people++], "Bob", 30);
    create_person(people[num_people++], "Charlie", 20);
    create_person(people[num_people++], "David", 28);

    qsort(people, num_people, sizeof(Person *), compare_names);

    printf("Sorted by name:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    Person *alice = people[0];
    Person *bob = people[1];
    Person *charlie = people[2];
    Person *david = people[3];

    printf("\nDeleting Alice and Bob...\n");
    delete_person(alice);
    delete_person(bob);

    qsort(people, num_people - 2, sizeof(Person *), compare_names);

    printf("\nSorted by name after deleting Alice and Bob:\n");
    for (int i = 0; i < num_people - 2; i++) {
        print_person(people[i]);
    }

    return 0;
}