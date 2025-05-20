//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

Person *createPerson(char *name, int age) {
    Person *person = malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    return person;
}

int cmp_name(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int cmp_age(const void *a, const void *b) {
    Person *p1 = *(Person **)a;
    Person *p2 = *(Person **)b;
    return p1->age - p2->age;
}

void printPerson(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

void freePerson(Person *person) {
    free(person->name);
    free(person);
}

int main() {
    int n;
    scanf("%d", &n);

    Person **people = malloc(n * sizeof(Person *));

    for (int i = 0; i < n; i++) {
        char name[MAX_SIZE];
        scanf("%s", name);
        int age;
        scanf("%d", &age);

        people[i] = createPerson(name, age);
    }

    qsort(people, n, sizeof(Person *), cmp_age);

    printf("Sorted by age:\n");
    for (int i = 0; i < n; i++) {
        printPerson(people[i]);
    }

    qsort(people, n, sizeof(Person *), cmp_name);

    printf("\nSorted by name:\n");
    for (int i = 0; i < n; i++) {
        printPerson(people[i]);
    }

    for (int i = 0; i < n; i++) {
        freePerson(people[i]);
    }
    free(people);

    return 0;
}