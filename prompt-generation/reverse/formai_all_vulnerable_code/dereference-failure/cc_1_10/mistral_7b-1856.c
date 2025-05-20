//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_PERSONS 10

typedef struct Person {
    char name[MAX_NAME_LENGTH];
    int age;
    struct Person *next;
} Person;

Person *persons = NULL;
int current_time = 0;

void print_persons() {
    Person *current = persons;
    printf("Current time: %d\n", current_time);
    printf("Persons alive:\n");
    while (current != NULL) {
        printf("%s (%d years)\n", current->name, current->age);
        current = current->next;
    }
    printf("\n");
}

void add_person(char *name, int age) {
    Person *new_person = (Person *) malloc(sizeof(Person));
    strcpy(new_person->name, name);
    new_person->age = age;
    new_person->next = persons;
    persons = new_person;
}

void time_travel(int num_years) {
    int i;
    for (i = 0; i < num_years; i++) {
        current_time += 10; // 10 years per iteration
        for (Person *current = persons; current != NULL; current = current->next) {
            current->age += 10;
        }
    }
}

int main() {
    add_person("Romeo", 16);
    add_person("Juliet", 13);

    print_persons();

    time_travel(5);

    print_persons();

    time_travel(15);

    print_persons();

    return 0;
}