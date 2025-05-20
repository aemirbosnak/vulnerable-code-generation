//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

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

void destroy_person(Person *person) {
    free(person->name);
    free(person);
}

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_ages(const void *a, const void *b) {
    Person *person_a = *(Person **)a;
    Person *person_b = *(Person **)b;
    return person_a->age - person_b->age;
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    while (1) {
        printf("Enter name and age (or type 'exit' to quit): ");
        char input[100];
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        char *name = strtok(input, " ");
        int age = atoi(strtok(NULL, " "));

        Person *person = create_person(name, age);
        people[num_people++] = person;
    }

    qsort(people, num_people, sizeof(Person *), compare_ages);

    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
        destroy_person(people[i]);
    }

    return 0;
}