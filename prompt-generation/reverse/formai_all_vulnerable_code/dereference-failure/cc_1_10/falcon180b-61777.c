//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

Person *create_person(char *name, int age) {
    Person *person = (Person *) malloc(sizeof(Person));
    if (person == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    person->name = strdup(name);
    person->age = age;
    return person;
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

int compare_name(const void *a, const void *b) {
    Person *person1 = *(Person **) a;
    Person *person2 = *(Person **) b;
    return strcmp(person1->name, person2->name);
}

int compare_age(const void *a, const void *b) {
    Person *person1 = *(Person **) a;
    Person *person2 = *(Person **) b;
    return person1->age - person2->age;
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main() {
    int n, m, i;
    scanf("%d %d", &n, &m);
    Person **people = (Person **) malloc(n * sizeof(Person *));
    for (i = 0; i < n; i++) {
        char name[MAX_SIZE];
        scanf("%s", name);
        people[i] = create_person(name, i + 1);
    }
    qsort(people, n, sizeof(Person *), compare_age);
    printf("Sorted by age:\n");
    for (i = 0; i < n; i++) {
        print_person(people[i]);
    }
    qsort(people, n, sizeof(Person *), compare_name);
    printf("\nSorted by name:\n");
    for (i = 0; i < n; i++) {
        print_person(people[i]);
    }
    for (i = 0; i < n; i++) {
        delete_person(people[i]);
    }
    free(people);
    return 0;
}