//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void create_person(Person *person, char *name, int age) {
    person->name = strdup(name);
    person->age = age;
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int compare_persons(Person *p1, Person *p2) {
    if (p1->age > p2->age) {
        return 1;
    } else if (p1->age < p2->age) {
        return -1;
    } else {
        return 0;
    }
}

void bubble_sort(Person **people, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (compare_persons(people[j], people[j + 1]) > 0) {
                Person *temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

int main() {
    Person *people[MAX_SIZE];
    int size = 0;

    while (1) {
        printf("Enter name and age (or type 'exit' to finish):\n");
        scanf("%s %d", people[size]->name, &people[size]->age);

        if (strcmp(people[size]->name, "exit") == 0) {
            break;
        }

        size++;
        if (size >= MAX_SIZE) {
            printf("Error: maximum number of people reached.\n");
            exit(1);
        }
    }

    bubble_sort(people, size);

    printf("Sorted list:\n");
    for (int i = 0; i < size; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < size; i++) {
        delete_person(people[i]);
    }

    return 0;
}