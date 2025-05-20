//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ken Thompson
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
    person->name = (char *)malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
    return person;
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

int main() {
    char input[MAX_SIZE];
    Person *people = NULL;
    int num_people = 0;

    while (fgets(input, MAX_SIZE, stdin)!= NULL) {
        if (num_people >= MAX_SIZE) {
            printf("Error: Too many people.\n");
            break;
        }

        char *name = strtok(input, ",");
        int age = atoi(strtok(NULL, ","));

        Person *person = create_person(name, age);
        people = (Person *)realloc(people, sizeof(Person) * (num_people + 1));
        people[num_people] = *person;
        delete_person(person);
        num_people++;
    }

    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }

    free(people);
    return 0;
}