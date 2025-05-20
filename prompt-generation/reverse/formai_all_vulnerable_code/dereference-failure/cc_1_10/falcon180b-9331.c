//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void insert(Person *people, int *size, Person person) {
    if (*size >= MAX_SIZE) {
        printf("Error: table is full\n");
        return;
    }

    int i = 0;
    while (i < *size && strcmp(people[i].name, person.name)!= 0) {
        i++;
    }

    if (i == *size) {
        (*size)++;
    }

    strcpy(people[i].name, person.name);
    people[i].age = person.age;
}

void delete(Person *people, int *size, char *name) {
    int i = 0;
    while (i < *size && strcmp(people[i].name, name)!= 0) {
        i++;
    }

    if (i == *size) {
        printf("Error: person not found\n");
        return;
    }

    (*size)--;
    for (int j = i; j < *size; j++) {
        strcpy(people[j].name, people[j + 1].name);
        people[j].age = people[j + 1].age;
    }
}

void search(Person *people, int size, char *name) {
    int i = 0;
    while (i < size && strcmp(people[i].name, name)!= 0) {
        i++;
    }

    if (i == size) {
        printf("Person not found\n");
        return;
    }

    printf("Name: %s\n", people[i].name);
    printf("Age: %d\n", people[i].age);
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));
    int size = 0;

    insert(people, &size, (Person) {"John", 25});
    insert(people, &size, (Person) {"Mary", 30});
    insert(people, &size, (Person) {"Bob", 20});

    search(people, size, "John");
    search(people, size, "Mary");
    search(people, size, "Bob");

    delete(people, &size, "John");
    delete(people, &size, "Mary");
    delete(people, &size, "Bob");

    free(people);

    return 0;
}