//Falcon-180B DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

void print_person(const Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int compare_names(const void* a, const void* b) {
    const Person* person_a = (const Person*)a;
    const Person* person_b = (const Person*)b;

    return strcmp(person_a->name, person_b->name);
}

int main() {
    Person* people = NULL;
    int num_people = 0;

    while (1) {
        printf("Enter a name (or press enter to finish):\n");
        char input[MAX_NAME_LENGTH];
        fgets(input, MAX_NAME_LENGTH, stdin);

        if (input[0] == '\0') {
            break;
        }

        Person* new_person = (Person*)malloc(sizeof(Person));
        strcpy(new_person->name, input);
        printf("Enter age for %s:\n", input);
        scanf("%d", &new_person->age);

        people = (Person*)realloc(people, sizeof(Person) * (num_people + 1));
        people[num_people] = *new_person;
        num_people++;
    }

    qsort(people, num_people, sizeof(Person), compare_names);

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    free(people);
    return 0;
}