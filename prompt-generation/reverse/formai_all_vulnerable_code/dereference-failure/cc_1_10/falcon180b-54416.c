//Falcon-180B DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char *name;
    int age;
} Person;

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    char input_buffer[MAX_STRING_LENGTH];
    Person *person = NULL;

    printf("Enter a person's name: ");
    if (fgets(input_buffer, MAX_STRING_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read input.\n");
        exit(EXIT_FAILURE);
    }

    person = (Person *) malloc(sizeof(Person));
    if (person == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for person.\n");
        exit(EXIT_FAILURE);
    }

    person->name = strdup(input_buffer);
    if (person->name == NULL) {
        fprintf(stderr, "Error: Failed to duplicate name.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter a person's age: ");
    if (fgets(input_buffer, MAX_STRING_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read input.\n");
        exit(EXIT_FAILURE);
    }

    person->age = atoi(input_buffer);

    print_person(person);

    free(person->name);
    free(person);

    return 0;
}