//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

Person *create_person(char *name, int age) {
    Person *person = (Person *)malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    return person;
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int compare_ages(const void *a, const void *b) {
    Person *person_a = *(Person **)a;
    Person *person_b = *(Person **)b;

    return person_a->age - person_b->age;
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    char input[100];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *name = strtok(input, ",");
        int age = atoi(strtok(NULL, ","));

        Person *person = create_person(name, age);
        people[num_people++] = person;
    }

    qsort(people, num_people, sizeof(Person *), compare_ages);

    printf("Sorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    return 0;
}